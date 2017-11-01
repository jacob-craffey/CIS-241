#include <stdio.h>
#include "operations.h"

// insert a node to the list
int insert(product **l, product node) {

    l = &node.next;

    product new_product;

	printf("\n1: Add product to store\n");
	printf("Product name: ");
	scanf("%s", new_product.name);
	printf("Product quantity: ");
	scanf("%f", &new_product.quantity_value);
	printf("Product unit: ");
	scanf("%s", new_product.quantity_unit);
	printf("Price value: ");
	scanf("%f", &new_product.price_value);
	printf("Price unit: ");
	scanf("%s", new_product.price_unit);

    node.next = &new_product;

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

// displays main menu
void displayMenu() {
    printf("\n");
    printf("===================================================================\n");
	printf("Welcome to Jacob Craffey grocery store!\n");
	printf("Please let me know what you want to do according to the menu below:\n");
	printf("===================================================================\n");
	printf("1: Add product to store              2: Purchase product from store\n");
	printf("3: Check price of a product          4: Show products in store\n");
	printf("5: Clean up a product from store     6: Find product\n");
	printf("7: Inventory                         8: Done for today\n");
	printf("-------------------------------------------------------------------\n");
	printf("\nWhat do you want to do?\n");
}

// the job starts here, start with loading data from
// the file data, and perform the functions by calling
// related functions.  Ends at saving data to the file data.
int doIt(char data[]) {

	return 0;
}
