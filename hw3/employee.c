#include <stdio.h>
#include <stdlib.h>

struct  {
	unsigned int job: 1;
	unsigned int position: 3;
	unsigned int gender: 2;
	unsigned int gNum: 10;
} Employee;

void pack(char *argv[]) {
	Employee.gNum = atoi(argv[1]);
	Employee.gender = atoi(argv[2]);
	Employee.position = atoi(argv[3]);
	Employee.job = atoi(argv[4]);

	printf("\nEncode: %d\n", Employee);
}

unsigned createMask(unsigned a, unsigned b)
{
   unsigned r = 0;
   for (unsigned i=a; i<=b; i++)
       r |= 1 << i;

   return r;
}

void unpack(char *argv[]) {
	unsigned num = atoi(argv[1]);

	const char *gender[3] = {"Female", "Male", "NotTell"};

	const char *position[] = {"Lecturer", "Administration",
	 "IT staff", "Visitor", "Student", "Worker", "Dean", "President"};
	const char *job[] = {"Full time", "Part time"};


	unsigned gNumMask = 32736;
	unsigned genderMask = 48;
	unsigned positionMask = 14;
	unsigned jobMask = 1;

	unsigned gNumResult = (num & gNumMask) >> 5;
	unsigned genderResult = (genderMask & num) >> 4;
	unsigned positionResult = (positionMask & num) >> 1;
	unsigned jobResult = jobMask & num;

	printf("\nG number: %d\n\n", gNumResult);
	printf("Gender: %s\n\n", gender[genderResult]);
	printf("Position: %s\n\n", position[positionResult]);
	printf("Job Type: %s\n\n", job[jobResult]);
}




int main(int argc, char *argv[]) {

	if (argc == 5) {
		pack(argv);
	} 
	else if (argc == 2) {
		unpack(argv);
	} 
	else {
		printf("Please enter valid input.\n");
	}
	return 0;
}