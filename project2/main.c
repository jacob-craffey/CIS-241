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
