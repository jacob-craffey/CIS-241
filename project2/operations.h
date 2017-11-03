
#ifndef OPERATIONS_H_
#define OPERATIONS_H_

#define N 20
struct product {
	char name[N];
	float quantity_value;
	char quantity_unit[N];
	float price_value;
	char price_unit[N];
	struct product *next;
};

typedef struct product product;

product* check_duplicate(product* head);

product* prepend(product* head);

product* create(product* next);

product* rmItem(product *l, product *node);

void showList(product *head);

int loadData(char inf[], product **l);

int saveData(char outf[], product *l);

float purchase(product *l, float q);

void check_price(product *l, char p[]);

product* findItem(product *l, char p[]);

int doesItemExist(product* head, char p[]);

void displayMenu();

int doIt(char data[]);



#endif
