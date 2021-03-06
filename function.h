#ifndef __FUNCTION__
#define __FUNCTION__

struct flights
{
	char number[7];
	char from[20];
	char terminal[20];
	char time[18];
	char duration[7];
	int price;
	char type[2];
	struct flights *next;
	struct flights *prev;
};

void acquire(struct flights *root, FILE *fp);
void insert(struct flights *root);
int display(struct flights *root);
int is_empty(struct flights *root);
int delete_flight(struct flights *root);
int free_flights(struct flights *root);
int find(struct flights *root, struct flights *root2);
void sort(struct flights *root);
void sort_time(struct flights *root);
void sort_price(struct flights *root);
void sort_number(struct flights *root);
void save(struct flights *root);
int change(struct flights *root);
void Administrator(struct flights *flink,struct flights *flink2);
void visitor(struct flights *flink,struct flights *flink2);

void menu();
void menu2();
//==========乘客信息===========
int display2(struct flights *root, char *n);
void save2(struct flights *root2);
int find2(struct flights *root2);
void change_passenger(struct flights *root2);
int change2(struct flights *root2);
void insert2(struct flights *root2);
int delete2(struct flights *root2);
void sort2(struct flights *root2);

#endif
