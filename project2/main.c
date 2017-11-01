#include <stdio.h>
#include <string.h>
#include "operations.h"



int main() {
	int select;

	product **list;

    while (1) {
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
            showList(list);
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
