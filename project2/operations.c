#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

// finds the duplicate product
product* find_duplicate(product *head) {
    product *current = head;

    while (current != NULL) {
        if (strcmp(head->name, current->name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// checks if the product is already in the shop's inventory
product* check_duplicate(product* head) {
    product *current = head->next;
    char* name = head->name;

    // traverses through the linked list,
    // if matching products are found:
    //   - add the quantity of the new and current product
    //   - store sum in the current product
    //   - delete the duplicated product
    while (current != NULL) {
        if (strcmp(name, current->name) == 0) {
            current->quantity_value += head->quantity_value;
            product* temp = head;
            head = temp->next;
            free(temp);
        }
        current = current->next;
    }
    return head;
}

// insert a node to the list
product* create(product* next) {
    product* new_product = (product*)malloc(sizeof(product));
    char name[N];

    if(new_product == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }

    // store the the products data and create a new node
	printf("\n1: Add product to store\n");
	printf("Product name: ");
    scanf("%s", new_product->name);
	printf("Product quantity: ");
	scanf("%f", &new_product->quantity_value);
	printf("Product unit: ");
	scanf("%s", new_product->quantity_unit);
	printf("Price value: ");
	scanf("%f", &new_product->price_value);
	printf("Price unit: ");
	scanf("%s", new_product->price_unit);

    // points new_product to the 'next' product
    new_product->next = next;

	return new_product;
}

// need the 'next' pointer to point to the 'head' pointer and
// point to the head pointer of the new node.
product* prepend(product* head) {
    product* new_product = create(head);
    head = new_product;
    return head;
}

// remove a node from list
product* rmItem(product *l, product *node) {

    return l;
}

// traverses linked-list and prints all products
// in the shop with their quantity
void showList(product *head) {
    printf("===== Inventory =====\n");
    while (head != NULL) {
        printf("- %g %s\n", head->quantity_value, head->name);
        head = head->next;
    }
    printf("=====================\n");
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
float purchase(product *l, float q) {
    float item_quantity = l->quantity_value;
    float result = item_quantity - q;
    if (result > 0) {
        return result;
    }
	return 0;
}

// check out price of product p from list l
void check_price(product *l, char p[]) {

}

// find a product p from list l
product* findItem(product *l, char p[]) {

    while (l != NULL) {
        if (strcmp(p, l->name) == 0) {
            return l;
        }
        l = l->next;
    }
    return NULL;
}


int doesItemExist(product* head, char p[]) {

    while (head != NULL) {
        if (strcmp(p, head->name) == 0) {
            return 1;
        }
        head = head->next;
    }
    return 0;
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
	printf("===================================================================\n");
	printf("\nWhat do you want to do?\n");
}

// the job starts here, start with loading data from
// the file data, and perform the functions by calling
// related functions.  Ends at saving data to the file data.
int doIt(char data[]) {

	return 0;
}
