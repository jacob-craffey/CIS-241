#include <stdio.h>
#include <string.h>
#include "operations.h"

void displayMenu() {
	printf("Welcome to Jacob Craffey grocery store!\n");
	printf("Please let me know what you want to do according to the menu below:\n");
	printf("===================================================================\n");
	printf("1: Add product to store              2: Purchase product from store\n");
	printf("3: Check price of a product          4: Show products in store\n");
	printf("5: Clean up a product from store     6: Find product\n");
	printf("7: Inventory                         8: Done for today\n");
	printf("What do you want to do?\n");
}

int main() {
	int select;

	product **list;

	displayMenu();
	scanf("%d", &select);

	if (select == 1) {
		product node;
		insert(list, node);

	} 
	else if (select == 2) {

	}
	else if (select == 3) {

	}
	else if (select == 4) {

	}
	else if (select == 5) {

	}
	else if (select == 6) {

	}
	else if (select == 7) {

	}
	else if (select == 8) {

	
	} 
	else {
		printf("Please select ")
	}
	return 0;
}