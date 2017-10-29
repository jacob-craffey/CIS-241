
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


int insert(product **l, product node);

void rmItem(product *l, product *node);

void showList(product *l);

int loadData(char inf[], product **l);

int saveData(char outf[], product *l);

float purchase(product *l, char product[], float q);

void check_price(product *l, char p[]);

void findItem(product *l, char p[]);

int doIt(char data[]);



#endif