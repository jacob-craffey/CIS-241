#include <stdio.h>
#include "operations.h"

// insert a node to the list
int insert(product **l, product node) {
	printf("\n1: Add product to store\n");
	printf("Product name: ");
	scanf("%s", node.name);
	prinf("Product quantity: ");
	scanf("%f", node.quantity_value);
	printf("Product unit: ");
	scanf("%s", node.quantity_unit);
	printf("Price value: ");
	scanf("%f", node.price_value);
	printf("Price unit: ");
	scanf("%s", node.price_unit);
	return 0;
}

// remove a node from list
void rmItem(product *l, product *node) {

}

// show list
void showList(product *l) {

}

// load data from file inf
int loadData(char inf[], product **l) {

	return 0;
}

// save data to file outf
int saveData(char outf[], product *l) {

	return 0;
}

// sell product product of quantity q
float purchase(product *l, char product[], float q) {

	return 0;
}

// check out price of product p from list l
void check_price(product *l, char p[]) {

}

// find a product p from list l
void findItem(product *l, char p[]) {

}

// the job starts here, start with loading data from 
// the file data, and perform the functions by calling
// related functions.  Ends at saving data to the file data.
int doIt(char data[]) {

	return 0;
}