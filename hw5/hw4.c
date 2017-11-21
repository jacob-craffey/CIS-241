/*
 * sequentialPartition.c
 * Solve the Partition problem sequentially.
 * https://en.wikipedia.org/wiki/Partition_problem
 * This code works for multisets of up to 32 elements
 * The input is expected to be as follows:
 * The first line will contain n, the number of elements in the multiset
 * The remaining n lines will contain the n values, one per line
 */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <mpi.h>

int sumValuesBitsIn0 ( unsigned int value, int n, int *array) {
  int result = 0;
  unsigned int mask = 1;
  for(int i = 0;i < n;i++) {
    if ((mask & value) == 0) {
      result = result + array[i];
    }
    mask = mask * 2;
  }
  return result;
}

int sumValuesBitsIn1 ( unsigned int value, int n, int *array) {
  int result = 0;
  unsigned int mask = 1;
  for(int i = 0;i < n;i++) {
    if ((mask & value) != 0) {
      result = result + array[i];
    }
    mask = mask * 2;
  }
  return result;
}

int evaluatePartition( unsigned int value, int n, int *array) {
  if (sumValuesBitsIn0(value,n,array) == sumValuesBitsIn1(value,n,array))
    return 1;
  else
    return 0;
}

void printResults(unsigned int value,int n,int *array) 
{
  printf("Solution:\n");
  printf("First partition: ") ;
  unsigned int mask = 1;
  int sum = 0;
  for(int i = 0;i < n;i++) {
    if ((mask & value) != 0) {
      printf("%d ",array[i]);
      sum = sum + array[i];
    }
    mask = mask * 2;
  }
  printf(" sum: %d \n",sum);
  printf("Second partition: ") ;
  mask = 1;
  sum = 0;
  for(int i = 0;i < n;i++) {
    if ((mask & value) == 0) {
      printf("%d ",array[i]);
      sum = sum + array[i];
    }
    mask = mask * 2;
  }
  printf(" sum: %d \n",sum);
}


int main() {

  MPI_Status status;
  int myRank;
  int numProcesses;

  int n;
  int *array;

  scanf("%d",&n);

  printf("The value of n is %d\n",n);
  array = (int *) malloc (n * sizeof(int));
  for(int i = 0;i < n;i++) {
    scanf("%d",&array[i]);
  }
  printf("The read values are: \n");
  for(int i = 0;i < n;i++) {
    printf("%d ",array[i]);
  }
  printf("\n");

  // Initialize all the nodes
  // Find the rank of every node
  // Find the total number of processes that are active
  MPI_Init(&array);
  MPI_Comm_rank(MPI_COMM_WORLD,&myRank);
  MPI_Comm_size(MPI_COMM_WORLD, &numProcesses);

  unsigned int nPartitions = 1;
  for(int i = 0;i < n;i++) {
    nPartitions = nPartitions * 2;
  }
  // printf("The number of possible partitions is: %d\n",nPartitions);
  // Only half of all possible partitions need be examined
  // The second half is symmetrical to the first half
  nPartitions = nPartitions / 2;

  int solutionFound = 0;
  int solution = -1;
  for(unsigned int i = 1;i < (nPartitions);i++) {
    if (evaluatePartition( i,  n, array) == 1) {
      solutionFound = 1;
      solution = i;
    }
  }
  if (solutionFound) {
    printResults(solution, n, array);
  }
  else {
    printf("No solution was found.");
  }
  return 0;
}
 
