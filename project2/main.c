#include <stdio.h>
#include <string.h>
#include "operations.h"



int main() {
	int select;

	product** list;
	product* head;

    while (1) {
        displayMenu();
        scanf("%d", &select);

        if (select == 1) {
            head = prepend(head);
            head = check_duplicate(head);
        }
        else if (select == 2) {
            if (head != NULL) {
                char name[N];
                float quantity;
                printf("===== Purchase Item =====\n");
                printf("Item name: ");
                scanf("%s", &name);
                printf("Item quantity: ");
                scanf("%f", &quantity);

                // If the item is found in the shop,
                // purchase the item
                if (doesItemExist(head, name) == 1) {
                    product* current = findItem(head, name);

                    // The customer can only buy as much as
                    // what's in stock
                    if (current->quantity_value <= quantity) {
                        quantity = current->quantity_value;
                    }

                    current->quantity_value = purchase(current, quantity);

                    float sale = quantity * current->price_value;
                    printf("You bought %g %s for $%.2f\n", quantity, current->name, sale);
                    printf("=========================\n\n");

                    // TODO: AUTODELETE IF NO STOCK
                    // If there is no more of item, remove it from the inventory
                    if (current->quantity_value == 0) {
                        head = rmItem(head, current);
                    }
                }
                // If the item is not found at the shop,
                // alert the customer.
                else {
                    printf("Sorry, we do not carry %s\n", name);
                    printf("=========================\n\n");
                }
            }
            else {
                printf("There are no items in the shop!\n");
                printf("=========================\n\n");
            }
        }
        else if (select == 3) {
            char name[N];
            printf("===== Check Price =====\n");
            printf("Item: ");
            scanf("%s", &name);

            if (doesItemExist(head, name) == 1) {
                product* current = findItem(head, name);
                printf("%s is $%.2f %s\n", name, current->price_value, current->price_unit);
                printf("=======================\n");
            }
            else {
                printf("Sorry, we do not carry %s\n", name);
                printf("=========================\n\n");
            }

        }
        else if (select == 4) {

        }
        else if (select == 5) {

        }
        else if (select == 6) {

        }
        else if (select == 7) {
            showList(head);
        }
        else if (select == 8) {
            printf("Goodbye\n");
            break;
        }
        else {
            printf("Please select ");
        }
    }

	return 0;
}
