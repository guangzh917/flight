#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

struct flights *new(char *n, char *f, char *t, char *d, char *ti, int price, char *ty)//新结点
{
	struct flights *node = (struct flights *)malloc(sizeof(struct flights));
	if(node != NULL)
	{
		node->next = NULL;
		node->prev = NULL;
		strcpy(node->number, n);
		strcpy(node->from, f);
		strcpy(node->terminal, t);
		strcpy(node->time, d);
		strcpy(node->duration, ti);
		node->price = price;
		strcpy(node->type, ty);
	}
	return node;
}

void acquire(struct flights *root, FILE *fp)//把文件里面的航班信息载入到链表中
{
	//char number[7], from[20], terminal[20], time[18], duration[6], price[5], type[2];
	char number[7], from[20], terminal[20], time[18], duration[7], type[2];
	int price;
	char *n=number, *f=from, *t=terminal, *d=time, *ti=duration, *ty=type;
	fseek(fp, 0, SEEK_SET);
	while(fscanf(fp, "%s %s %s %s %s %d %s", n, f, t, d, ti, &price, ty) != -1)
	{
		struct flights *node = new(n, f, t, d, ti, price, ty);
		if(node != NULL)
		{
			node->next = root;
			node->prev = root->prev;
			root->prev->next = node;
			root->prev = node;
		}
		else
		{
			printf("Insert failed !");
		}
	}
	//printf("航班信息载入成功！\n");
}

void insert(struct flights *root)//双向循环链表尾部插入
{
	//char number[7], from[20], terminal[20], time[18], duration[6], price[5], type[2];
	char number[7], from[20], terminal[20], time[18], duration[7], type[2];
	int price;
	char *n=number, *f=from, *t=terminal, *d=time, *ti=duration, *ty=type;
	printf("\n请输入新航班信息：\n");

	printf("航班号： ");
	scanf("%s", n);
	while(getchar() != '\n');
	while(strlen(n)!= 6)
	{
		printf("Please enter the six flight number information(A00000/B00000) : ");
		scanf("%s", n);
		while(getchar() != '\n');
	}
	printf("出发城市： ");
	scanf("%s", f);
	while(getchar() != '\n');
	printf("到达城市： ");
	scanf("%s", t);
	while(getchar() != '\n');

	printf("日期： ");
	scanf("%s", d);
	while(getchar() != '\n');
	while(strlen(d)!= 16)
	{
		printf("Please enter the correct flight time(2015/xx/xx-00:00) : ");
		scanf("%s", d);
		while(getchar() != '\n');
	}
	
	printf("时间： ");
	scanf("%s", ti);
	while(getchar() != '\n');
	while(strlen(ti) > 6)
	{
		printf("Please enter the correct flight duration(xxhxx') : ");
		scanf("%s", ti);
		while(getchar() != '\n');
	}

	printf("票价（￥）： ");
	scanf("%d", &price);
	while(getchar() != '\n');
	while(price > 9999 || price < 0)
	{
		printf("Please input the correct price(Less than 9999 yuan) : ");
		scanf("%d", &price);
		while(getchar() != '\n');
	}
	printf("航班类型： ");
	scanf("%s", ty);
	while(getchar() != '\n');
	while(strlen(ty) > 1)
	{
		printf("Please input the correct type(A/B) : ");
		scanf("%s", ty);
		while(getchar() != '\n');
	}
	

	printf("您输入的新航班信息为：\n");
	printf("航班号： %s\n\t出发城市： %-4s\t到达城市： %-4s\t日期： %s\n\t时间： %-4s\t\t票价（￥）： %-4d\t航班类型： %s\n", 
			n, f, t, d, ti, price, ty);	
	
	printf("Confirm the new?( y / n )");
	char key;
	scanf("%c", &key);
	while(getchar() != '\n');
	if(key == 'y')
	{		
		struct flights *node = new(n, f, t, d, ti, price, ty);
		if(node != NULL)
		{
			node->next = root;
			node->prev = root->prev;
			root->prev->next = node;
			root->prev = node;
			printf("新航班信息录入成功！\n");
		}
	}
	else
	{
		printf("Insert failed !");
	}
}

int display(struct flights *root)//从头到尾显示当前链表，前驱显示
{
	struct flights *p = root;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
	printf("‖                              Flight information list                        ‖\n");
	printf("‖=============================================================================‖\n");
	printf("‖number  from         terminal      time              duration price(￥) type ‖\n");
	printf("‖═════════════════════════════════════════════════════════════════════════════‖\n");
	while(p->next != root)
	{
	printf("‖%-7s %-12s %-13s %-17s %-8s %-9d %-5s‖\n", 
			p->next->number, p->next->from, p->next->terminal, p->next->time, 
			p->next->duration, p->next->price, p->next->type);
		p = p->next;
	}
	return 0;
}

int is_empty(struct flights *root)//空链表判断
{
	return (root->next == root);
}

int delete_flight(struct flights *root)//删除结点
{
	printf("请输入要删除的航班对应的航班号：");
	char num[7];
	char *n = num;
	scanf("%s", n);
	while(getchar() != '\n');
	while(strlen(n)!= 6)
	{
		printf("Please enter the six flight number information(A00000/B00000) : ");
		scanf("%s", n);
		while(getchar() != '\n');
	}
	struct flights *p = root;
	if(is_empty(root))
		return 1;
	while(p->next != root)
	{
		if(strcmp(p->next->number, n) == 0)
		{
			struct flights *del = p->next;
			p->next->next->prev = p;
			p->next = p->next->next;
			free(del);
			printf("删除成功！\n");
			return 0;
		}
		else
		{
			p = p->next;
		}
	}
	printf("对不起，没有此航班信息！\n");
	return 1;
}

int free_flights(struct flights *root)//清空释放链表
{
	struct flights *p = root;
	while(p->next != root)
	{
		p = p->next;
		free(p->prev);
	}
	free(p);
	return 0;
}


int find(struct flights *root, struct flights *root2)//查找对应航班的信息，以及对应航班乘客信息
{
	printf("请输入要查找的航班号：");
	char number[7];
	char *n = number;
	scanf("%s", n);
	while(getchar() != '\n');
	while(strlen(n)!= 6)
	{
		printf("Please enter the six flight number information(A00000/B00000) : ");
		scanf("%s", n);
		while(getchar() != '\n');
	}
	struct flights *p = root;
	while(p->next != root)
	{
		if(strcmp(p->next->number, n) == 0)
		{
			printf("Found it !\n");
			printf("航班号： %s\n\t出发城市： %-4s\t到达城市： %-4s\t日期： %s\n\t时间： %-4s\t\t票价（￥）： %-4d\t航班类型： %s\n", 
				p->next->number, p->next->from, p->next->terminal, 
				p->next->time, p->next->duration, p->next->price, 
				p->next->type);
			display2(root2, n);
			return 0;
		}
		else
			p = p->next;		
	}
	printf("\nNot found !\n");
	return 1;
}

void save(struct flights *root)//链表中的信息是操作后（有可能有修改的）信息，对他进行保存
{
	FILE *fp = fopen ("flights.txt", "w+");
	
	acquire(root, fp);//获取文件 flights.txt 中的航班信息
	
	struct flights *p = root;
	while(p->next != root)
	{
		fprintf(fp, "%s %s %s %s %s %d %s \n", 
				p->next->number, p->next->from, p->next->terminal, p->next->time, 
				p->next->duration, p->next->price, p->next->type);
		p = p->next;
	}
	fclose(fp);
	printf("保存成功！\n");
}

int change(struct flights *root)//更改对应航班的信息
{
	//char number[7], from[20], terminal[20], time[18], duration[6], price[5], type[2];
	char number[7], from[20], terminal[20], time[18], duration[7], type[2];
	int price;
	char *n=number, *f=from, *t=terminal, *d=time, *ti=duration, *ty=type;
	printf("请输入要修改的航班号：");
	char num[7];
	char *k = num;
	scanf("%s", k);
	while(getchar() != '\n');
	while(strlen(k)!= 6)
	{
		printf("Please enter the six flight number information(A00000/B00000) : ");
		scanf("%s", k);
		while(getchar() != '\n');
	}
	struct flights *q = root;
	while(q->next != root)
	{
		if(strcmp(q->next->number, k) == 0)
		{
			printf("航班号： %s\n\t出发城市： %-4s\t到达城市： %-4s\t日期： %s\n\t时间： %-4s\t\t票价（￥）： %-4d\t航班类型： %s\n", 
				q->next->number, q->next->from, q->next->terminal, 
				q->next->time, q->next->duration, q->next->price, 
				q->next->type);
			printf("\n请输入更改信息：\n");

			printf("航班号： ");
			scanf("%s", n);
			while(getchar() != '\n');
			while(strlen(n)!= 6)
			{
				printf("Please enter the six flight number information(A00000/B00000) : ");
				scanf("%s", n);
				while(getchar() != '\n');
			}
			printf("出发城市： ");
			scanf("%s", f);
			while(getchar() != '\n');
			printf("到达城市： ");
			scanf("%s", t);
			while(getchar() != '\n');

			printf("日期： ");
			scanf("%s", d);
			while(getchar() != '\n');
			while(strlen(d)!= 16)
			{
				printf("Please enter the correct flight time(2015/xx/xx-00:00) : ");
				scanf("%s", d);
				while(getchar() != '\n');
			}
	
			printf("时间： ");
			scanf("%s", ti);
			while(getchar() != '\n');
			while(strlen(ti) > 6)
			{
				printf("Please enter the correct flight duration(xxhxx') : ");
				scanf("%s", ti);
				while(getchar() != '\n');
			}

			printf("票价（￥）： ");
			scanf("%d", &price);
			while(getchar() != '\n');
			while(price > 9999 || price < 0)
			{
				printf("Please input the correct price(Less than 9999 yuan) : ");
				scanf("%d", &price);
				while(getchar() != '\n');
			}
			printf("航班类型： ");
			scanf("%s", ty);
			while(getchar() != '\n');
			while(strlen(ty) > 1)
			{
				printf("Please input the correct type(A/B) : ");
				scanf("%s", ty);
				while(getchar() != '\n');
			}
			printf("您将要把航班%s  的信息更改为：\n", q->next->number);
			printf("航班号： %s\n\t出发城市： %-4s\t到达城市： %-4s\t日期： %s\n\t时间： %-4s\t\t票价（￥）： %-4d\t航班类型： %s\n", 
					n, f, t, d, ti, price, ty);	
			printf("确认修改？( y / n )");
			char key;
			scanf("%c", &key);
			while(getchar() != '\n');
			if(key == 'y')
			{
				strcpy(q->next->number, n);
				strcpy(q->next->from, f);
				strcpy(q->next->terminal, t);
				strcpy(q->next->time, d);
				strcpy(q->next->duration, ti);
				q->next->price = price;
				strcpy(q->next->type, ty);
				printf("信息更改成功！\n");
			}
			else
				printf("信息未修改\n");
			return 0;
		}
		else
			q = q->next;		
	}
	printf("对不起，未找到相关航班信息！\n");
	return 1;
}

void sort_time(struct flights *root)//排序1：按照航班起飞时间进行排序
{
	char temp[20];
	int tp;
	struct flights *p=root;
	struct flights *q=root->next;
	while(p->next != root)
	{		
		while(q->next != root)
		{	
			if(strcmp(p->next->time, q->next->time) > 0)
			{
				strcpy(temp, p->next->number);
				strcpy(p->next->number, q->next->number);
				strcpy(q->next->number, temp);
				
				strcpy(temp, p->next->from);
				strcpy(p->next->from, q->next->from);
				strcpy(q->next->from, temp);
				
				strcpy(temp, p->next->terminal);
				strcpy(p->next->terminal, q->next->terminal);
				strcpy(q->next->terminal, temp);
				
				strcpy(temp, p->next->time);
				strcpy(p->next->time, q->next->time);
				strcpy(q->next->time, temp);
				
				strcpy(temp, p->next->duration);
				strcpy(p->next->duration, q->next->duration);
				strcpy(q->next->duration, temp);
				
				tp = p->next->price;
				p->next->price = q->next->price;
				q->next->price = tp;
				
				strcpy(temp, p->next->type);
				strcpy(p->next->type, q->next->type);
				strcpy(q->next->type, temp);
			}
			q = q->next;
		}
		p = p->next;
		q = p->next;
	}
	printf("操作成功！\n");
}

void sort_price(struct flights *root)//排序2：按照航班对应机票价格进行排序
{
	char temp[20];
	int tp;
	struct flights *p=root;
	struct flights *q=root->next;
	while(p->next != root)
	{		
		while(q->next != root)
		{	
			if(p->next->price > q->next->price)
			{
				strcpy(temp, p->next->number);
				strcpy(p->next->number, q->next->number);
				strcpy(q->next->number, temp);
				
				strcpy(temp, p->next->from);
				strcpy(p->next->from, q->next->from);
				strcpy(q->next->from, temp);
				
				strcpy(temp, p->next->terminal);
				strcpy(p->next->terminal, q->next->terminal);
				strcpy(q->next->terminal, temp);
				
				strcpy(temp, p->next->time);
				strcpy(p->next->time, q->next->time);
				strcpy(q->next->time, temp);
				
				strcpy(temp, p->next->duration);
				strcpy(p->next->duration, q->next->duration);
				strcpy(q->next->duration, temp);
				
				tp = p->next->price;
				p->next->price = q->next->price;
				q->next->price = tp;
				
				strcpy(temp, p->next->type);
				strcpy(p->next->type, q->next->type);
				strcpy(q->next->type, temp);
			}
			q = q->next;
		}
		p = p->next;
		q = p->next;
	}
	printf("操作成功！\n");
}

void sort_number(struct flights *root)//排序3：按照航班号进行排序
{
	char temp[20];
	int tp;
	struct flights *p=root;
	struct flights *q=root->next;
	while(p->next != root)
	{		
		while(q->next != root)
		{	
			if(strcmp(p->next->number, q->next->number) > 0)
			{
				strcpy(temp, p->next->number);
				strcpy(p->next->number, q->next->number);
				strcpy(q->next->number, temp);
				
				strcpy(temp, p->next->from);
				strcpy(p->next->from, q->next->from);
				strcpy(q->next->from, temp);
				
				strcpy(temp, p->next->terminal);
				strcpy(p->next->terminal, q->next->terminal);
				strcpy(q->next->terminal, temp);
				
				strcpy(temp, p->next->time);
				strcpy(p->next->time, q->next->time);
				strcpy(q->next->time, temp);
				
				strcpy(temp, p->next->duration);
				strcpy(p->next->duration, q->next->duration);
				strcpy(q->next->duration, temp);
				
				tp = p->next->price;
				p->next->price = q->next->price;
				q->next->price = tp;
				
				strcpy(temp, p->next->type);
				strcpy(p->next->type, q->next->type);
				strcpy(q->next->type, temp);
			}
			q = q->next;
		}
		p = p->next;
		q = p->next;
	}
	printf("操作成功！\n");
}

void sort(struct flights *root)//对航班按照需要进行排序操作
{
	printf("\t╔════════════════════════╗\n");
	printf("\t‖     1.按航班时间排序   ‖\n");
	printf("\t‖     2.按机票价格排序   ‖\n");
	printf("\t‖     3.按航班编号排序   ‖\n");
	printf("\t╚════════════════════════╝\n");
	printf("Please enter your choice :  ");
	int flag;
	fflush(stdin);
	scanf("%d", &flag);
	while(getchar() != '\n');
	while(flag <= 0 || flag > 3)
	{
		printf("Input is wrong, please input again : ");
		scanf("%d", &flag);
		while(getchar() != '\n');
	}
	switch(flag)
	{
		case 1 :
			sort_time(root);
			break;
		case 2 :
			sort_price(root);
			break;
		case 3 :
			sort_number(root);
			break;
		default:
			break;
	}
}

void menu()//主菜单界面
{
	printf("‖═════════════════════════════════════════════════════════════════════════════‖\n");
	printf("‖ 1. Print all the flight information     5. To find a flight information     ‖\n");
	printf("‖ 2. Insert a new flight information      6. To change the flight information ‖\n");
	printf("‖ 3. To delete a flight information       7. Look for passenger information   ‖\n");
	printf("‖ 4. Rearrangement the flight information 8. Change the passenger information ‖\n");
	printf("‖ 0. Log out                                                                  ‖\n");
	printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\tPlease enter your choice :  ");
}

void menu2()//访客菜单界面
{
	printf("‖═════════════════════════════════════════════════════════════════════════════‖\n");
	printf("‖ 1. Print all the flight information                                         ‖\n");
	printf("‖ 2. Rearrangement the flight information                                     ‖\n");
	printf("‖ 3. To find a flight information                                             ‖\n");
	printf("‖ 4. Look for passenger information                                           ‖\n");
	printf("‖ 0. Log out                                                                  ‖\n");
	printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\tPlease enter your choice :  ");
}


void Administrator(struct flights *flink, struct flights *flink2)//以管理员身份进入系统
{
	char password[9];
	int n = 5;
	printf("Enter the password for eight : ");
	
	fflush(stdin);
	scanf("%s", password);
	while(getchar() != '\n');
	while(strcmp(password, "12345678") != 0)
	{
		n--;
		if(n == 0)
		{
			printf("You mistyped five times! \n");
			exit(0);
		}
		printf("Password input error, please enter again(%d):", n);
		scanf("%s", password);
		while(getchar() != '\n');
	}
	printf("\tDownload success!\t\n");

	FILE *fp = fopen ("flights.txt", "a+");
	FILE *fp2 = fopen ("flights2.txt", "a+");
	
	acquire(flink, fp);//获取文件 flights.txt 中的航班信息
	acquire(flink2, fp2);//获取文件 flight2s.txt 中的航班对应的乘客信息

	fclose(fp);
	fclose(fp2);

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
	printf("‖**********	            LEWIES FLIGHTS SYSTEM	               *******‖\n");		

	menu();
	int flag;
	char key = 'y';
	fflush(stdin);
	scanf("%d", &flag);
	while(getchar() != '\n');
	while(flag < 0 || flag > 8)
	{
		printf("Input is wrong, please input again : ");
		scanf("%d", &flag);
		while(getchar() != '\n');
	}
	while(flag)
	{
		switch(flag)
		{
			case 1 :display(flink);
				menu();
				scanf("%d", &flag);
				while(getchar() != '\n');
				while(flag < 0 || flag > 8)
				{
					printf("Input is wrong, please input again : ");
					scanf("%d", &flag);
					while(getchar() != '\n');
				}
				break;
			case 2 :while(flag == 2)
				{
					insert(flink);
					printf("continue(y / n): ");
					scanf("%c", &key);
					while(getchar() != '\n');
					if(key != 'y')
					{
						flag = 0;
					}
				}
				menu();
				scanf("%d", &flag);
				while(getchar() != '\n');
				while(flag < 0 || flag > 8)
				{
					printf("Input is wrong, please input again : ");
					scanf("%d", &flag);
					while(getchar() != '\n');
				}
				break;
			case 3 :while(flag == 3)
				{
					delete_flight(flink);
					printf("continue(y / n): ");
					scanf("%c", &key);
					while(getchar() != '\n');
					if(key != 'y')
					{
						flag = 0;
					}
				}
				menu();
				scanf("%d", &flag);
				while(getchar() != '\n');
				while(flag < 0 || flag > 8)
				{
					printf("Input is wrong, please input again : ");
					scanf("%d", &flag);
					while(getchar() != '\n');
				}
				break;
			case 4 :
				sort(flink);
				menu();
				scanf("%d", &flag);
				while(getchar() != '\n');
				while(flag < 0 || flag > 8)
				{
					printf("Input is wrong, please input again : ");
					scanf("%d", &flag);
					while(getchar() != '\n');
				}
				break;
			case 5 :while(flag == 5)
				{
					find(flink, flink2);
					printf("continue(y / n): ");
					scanf("%c", &key);
					while(getchar() != '\n');
					if(key != 'y')
					{
						flag = 0;
					}
				}
				menu();
				scanf("%d", &flag);
				while(getchar() != '\n');
				while(flag < 0 || flag > 8)
				{
					printf("Input is wrong, please input again : ");
					scanf("%d", &flag);
					while(getchar() != '\n');
				}
				break;
			case 6 :while(flag == 6)
				{
					change(flink);
					printf("continue(y / n): ");
					scanf("%c", &key);
					while(getchar() != '\n');
					if(key != 'y')
					{
						flag = 0;
					}
				}
				menu();
				scanf("%d", &flag);
				while(getchar() != '\n');
				while(flag < 0 || flag > 8)
				{
					printf("Input is wrong, please input again : ");
					scanf("%d", &flag);
					while(getchar() != '\n');
				}
				break;
			case 7 :while(flag == 7)
				{
					find2(flink2);
					printf("continue(y / n): ");
					scanf("%c", &key);
					while(getchar() != '\n');
					if(key != 'y')
					{
						flag = 0;
					}
				}
				menu();
				scanf("%d", &flag);
				while(getchar() != '\n');
				while(flag < 0 || flag > 8)
				{
					printf("Input is wrong, please input again : ");
					scanf("%d", &flag);
					while(getchar() != '\n');
				}
				break;
			case 8 :while(flag == 8)
				{
					change_passenger(flink2);
					printf("continue(y / n): ");
					scanf("%c", &key);
					while(getchar() != '\n');
					if(key != 'y')
					{
						flag = 0;
					}
				}
				menu();
				scanf("%d", &flag);
				while(getchar() != '\n');
				while(flag < 0 || flag > 8)
				{
					printf("Input is wrong, please input again : ");
					scanf("%d", &flag);
					while(getchar() != '\n');
				}
				break;
			default:break;
		}
	}

	//char key;
	printf("Save flight information?( s / n) :  ");
	scanf("%c", &key);
	while(getchar() != '\n');
	if(key == 's')
		save(flink);
	else
		printf("Exit without saving !\n");
	printf("Save paseenger information?( s / n) :  ");
	scanf("%c", &key);
	while(getchar() != '\n');
	if(key == 's')
		save2(flink2);
	else
		printf("Exit without saving !\n");
}

void visitor(struct flights *flink, struct flights *flink2)//以访客身份进入系统
{
	FILE *fp = fopen ("flights.txt", "a+");
	FILE *fp2 = fopen ("flights2.txt", "a+");
	
	acquire(flink, fp);//获取文件 flights.txt 中的航班信息
	acquire(flink2, fp2);//获取文件 flight2s.txt 中的航班对应的乘客信息

	fclose(fp);
	fclose(fp2);

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
	printf("‖********* 	            LEWIES FLIGHTS SYSTEM	             *********‖\n");		

	menu2();
	int flag;
	char key = 'y';
	fflush(stdin);
	scanf("%d", &flag);
	while(getchar() != '\n');
	while(flag < 0 || flag > 4)
	{
		printf("Input is wrong, please input again : ");
		scanf("%d", &flag);
		while(getchar() != '\n');
	}
	while(flag)
	{
		switch(flag)
		{
			case 1 :
				display(flink);
				menu2();
				scanf("%d", &flag);
				while(getchar() != '\n');
				while(flag < 0 || flag > 4)
				{
					printf("Input is wrong, please input again : ");
					scanf("%d", &flag);
					while(getchar() != '\n');
				}
				break;
			case 2 :
				sort(flink);
				menu2();
				scanf("%d", &flag);
				while(getchar() != '\n');
				while(flag < 0 || flag > 4)
				{
					printf("Input is wrong, please input again : ");
					scanf("%d", &flag);
					while(getchar() != '\n');
				}
				break;
			case 3 :while(flag == 3)
				{
					find(flink, flink2);
					printf("continue(y / n): ");
					scanf("%c", &key);
					while(getchar() != '\n');
					if(key != 'y')
					{
						flag = 0;
					}
				}
				menu2();
				scanf("%d", &flag);
				while(getchar() != '\n');
				while(flag < 0 || flag > 4)
				{
					printf("Input is wrong, please input again : ");
					scanf("%d", &flag);
					while(getchar() != '\n');
				}
				break;
			case 4 :while(flag == 4)
				{
					find2(flink2);
					printf("continue(y / n): ");
					scanf("%c", &key);
					while(getchar() != '\n');
					if(key != 'y')
					{
						flag = 0;
					}
				}
				menu2();
				scanf("%d", &flag);
				while(getchar() != '\n');
				while(flag < 0 || flag > 4)
				{
					printf("Input is wrong, please input again : ");
					scanf("%d", &flag);
					while(getchar() != '\n');
				}
				break;
			default:
				break;
		}
	}
}

//=======================================航班对应乘客信息======================================
int display2(struct flights *root, char *n)//从头到尾显示当前链表，前驱显示
{
	struct flights *p = root;
	//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
	printf("‖                      航班：  %s   乘客信息表                            ‖\n", n);
	printf("‖=============================================================================‖\n");
	printf("‖number  ticket       passenger     time              duration price(￥) sex  ‖\n");
	printf("‖═════════════════════════════════════════════════════════════════════════════‖\n");
	while(p->next != root)
	{
		if(strcmp(p->next->number,n) == 0)
		{
			printf("‖%-7s %-12s %-13s %-17s %-8s %-9d %-5s‖\n", 
				p->next->number, p->next->from, p->next->terminal, p->next->time, 
				p->next->duration, p->next->price, p->next->type);
			p = p->next;
		}
		else
			p = p->next;
	}
	printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
	return 0;
}

void save2(struct flights *root2)//链表中的信息是操作后（有可能有修改的）信息，对他进行保存
{
	FILE *fp = fopen ("flights2.txt", "w+");
	
	acquire(root2, fp);//获取文件 flights2.txt 中的航班信息
	
	struct flights *p = root2;
	while(p->next != root2)
	{
		fprintf(fp, "%s %s %s %s %s %d %s \n", 
				p->next->number, p->next->from, p->next->terminal, p->next->time, 
				p->next->duration, p->next->price, p->next->type);
		p = p->next;
	}
	fclose(fp);
	printf("保存成功！\n");
}

int find2(struct flights *root2)//查找航班乘客信息
{
	printf("请输入Ticket(机票)号：");
	char number[20];
	char *n = number;
	scanf("%s", n);
	while(getchar() != '\n');
	while(strlen(n)!= 8)
	{
		printf("Please enter the eight digit number(12300001) : ");
		scanf("%s", n);
		while(getchar() != '\n');
	}
	struct flights *p = root2;
	while(p->next != root2)
	{
		if(strcmp(p->next->from, n) == 0)
		{
			printf("Found it !\n");
			printf("航班号： %s\n\tTicket号： %-4s\t乘客姓名： %-4s\t日期： %s\n\t时间： %-4s\t\t票价（￥）： %-4d\t性别： %s\n", 
				p->next->number, p->next->from, p->next->terminal, 
				p->next->time, p->next->duration, p->next->price, 
				p->next->type);
			return 0;
		}
		else
			p = p->next;		
	}
	printf("\nNot found !\n");
	return 1;
}

void change_passenger(struct flights *root2)//更改乘客信息（针对性更改，新建乘客信息，删除乘客信息）
{
	printf("\t╔════════════════════════╗\n");
	printf("\t‖   1.更改指定乘客信息   ‖\n");
	printf("\t‖   2.新建一个乘客信息   ‖\n");
	printf("\t‖   3.删除指定乘客信息   ‖\n");
	printf("\t‖   4.按照机票号码排序   ‖\n");
	printf("\t╚════════════════════════╝\n");
	printf("Please enter your choice :  ");
	int flag;
	fflush(stdin);
	scanf("%d", &flag);
	while(getchar() != '\n');
	while(flag <= 0 || flag > 4)
	{
		printf("Input is wrong, please input again : ");
		scanf("%d", &flag);
		while(getchar() != '\n');
	}
	switch(flag)
	{
		case 1 :
			change2(root2);//更改指定乘客信息
			break;
		case 2 :
			insert2(root2);//新建一个乘客信息
			break;
		case 3 :
			delete2(root2);//删除指定乘客信息 
			break;
		case 4 :
			sort2(root2);//按照机票号码排序 
			break;
		default:
			break;
	}
}

int change2(struct flights *root2)//更改指定乘客信息
{
	//char number[7], from[20], terminal[20], time[18], duration[6], price[5], type[2];
	char number[7], from[20], terminal[20], time[18], duration[7], type[2];
	int price;
	char *n=number, *f=from, *t=terminal, *d=time, *ti=duration, *ty=type;
	printf("请输入要修改的乘客机票号码：");
	char num[10];
	char *k = num;

	scanf("%s", k);
	while(getchar() != '\n');
	while(strlen(k)!= 8)
	{
		printf("Please enter the eight digit number(12300001) : ");
		scanf("%s", k);
		while(getchar() != '\n');
	}
	struct flights *q = root2;
	while(q->next != root2)
	{
		if(strcmp(q->next->from, k) == 0)
		{
			printf("航班号： %s\n\t机票号码： %-4s\t乘客姓名： %-4s\t日期： %s\n\t时间： %-4s\t\t票价（￥）： %-4d\t性别： %s\n", 
				q->next->number, q->next->from, q->next->terminal, 
				q->next->time, q->next->duration, q->next->price, 
				q->next->type);
			printf("\n请输入更改信息：\n");

			printf("航班号： ");
			scanf("%s", n);
			while(getchar() != '\n');
			while(strlen(n)!= 6)
			{
				printf("Please enter the six flight number information(A00000/B00000) : ");
				scanf("%s", n);
				while(getchar() != '\n');
			}
			printf("机票号码： ");
			scanf("%s", f);
			while(getchar() != '\n');
			while(strlen(f)!= 8)
			{
				printf("Please enter the eight digit number(12300001) : ");
				scanf("%s", f);
				while(getchar() != '\n');
			}

			printf("乘客姓名： ");
			scanf("%s", t);
			while(getchar() != '\n');

			printf("日期： ");
			scanf("%s", d);
			while(getchar() != '\n');
			while(strlen(d)!= 16)
			{
				printf("Please enter the correct flight time(2015/xx/xx-00:00) : ");
				scanf("%s", d);
				while(getchar() != '\n');
			}
	
			printf("时间： ");
			scanf("%s", ti);
			while(getchar() != '\n');
			while(strlen(ti) > 6)
			{
				printf("Please enter the correct flight duration(xxhxx') : ");
				scanf("%s", ti);
				while(getchar() != '\n');
			}

			printf("票价（￥）： ");
			scanf("%d", &price);
			while(getchar() != '\n');
			while(price > 9999 || price < 0)
			{
				printf("Please input the correct price(Less than 9999 yuan) : ");
				scanf("%d", &price);
				while(getchar() != '\n');
			}
			printf("性别： ");
			scanf("%s", ty);
			while(getchar() != '\n');
			while(strlen(ty) > 1)
			{
				printf("Please input the correct type(A/B) : ");
				scanf("%s", ty);
				while(getchar() != '\n');
			}
			printf("您将要把ticket为%s  的信息更改为：\n", q->next->from);
			printf("航班号： %s\n\t机票号码： %-4s\t乘客姓名： %-4s\t日期： %s\n\t时间： %-4s\t\t票价（￥）： %-4d\t性别： %s\n", 
					n, f, t, d, ti, price, ty);	
			printf("确认修改？( y / n )");
			char key;
			scanf("%c", &key);
			while(getchar() != '\n');
			if(key == 'y')
			{
				strcpy(q->next->number, n);
				strcpy(q->next->from, f);
				strcpy(q->next->terminal, t);
				strcpy(q->next->time, d);
				strcpy(q->next->duration, ti);
				q->next->price = price;
				strcpy(q->next->type, ty);
				printf("信息更改成功！\n");
			}
			else
				printf("信息未修改\n");
			return 0;
		}
		else
			q = q->next;		
	}
	printf("对不起，未找到相关航班信息！\n");
	return 1;
}

void insert2(struct flights *root2)//新建一个乘客信息
{
	//char number[7], from[20], terminal[20], time[18], duration[6], price[5], type[2];
	char number[7], from[20], terminal[20], time[18], duration[7], type[2];
	int price;
	char *n=number, *f=from, *t=terminal, *d=time, *ti=duration, *ty=type;
	printf("\n请输入新航班信息：\n");

	printf("航班号： ");
	scanf("%s", n);
	while(getchar() != '\n');
	while(strlen(n)!= 6)
	{
		printf("Please enter the six flight number information(A00000/B00000) : ");
		scanf("%s", n);
		while(getchar() != '\n');
	}
	printf("机票号码： ");
	scanf("%s", f);
	while(getchar() != '\n');
	while(strlen(f)!= 8)
	{
		printf("Please enter the eight digit number(12300001) : ");
		scanf("%s", f);
		while(getchar() != '\n');
	}

	printf("乘客姓名： ");
	scanf("%s", t);
	while(getchar() != '\n');

	printf("日期： ");
	scanf("%s", d);
	while(getchar() != '\n');
	while(strlen(d)!= 16)
	{
		printf("Please enter the correct flight time(2015/xx/xx-00:00) : ");
		scanf("%s", d);
		while(getchar() != '\n');
	}
	
	printf("时间： ");
	scanf("%s", ti);
	while(getchar() != '\n');
	while(strlen(ti) > 6)
	{
		printf("Please enter the correct flight duration(xxhxx') : ");
		scanf("%s", ti);
		while(getchar() != '\n');
	}

	printf("票价（￥）： ");
	scanf("%d", &price);
	while(getchar() != '\n');
	while(price > 9999 || price < 0)
	{
		printf("Please input the correct price(Less than 9999 yuan) : ");
		scanf("%d", &price);
		while(getchar() != '\n');
	}
	printf("性别： ");
	scanf("%s", ty);
	while(getchar() != '\n');
	while(strlen(ty) > 1)
	{
		printf("Please input the correct type(A/B) : ");
		scanf("%s", ty);
		while(getchar() != '\n');
	}
	

	printf("您输入的新信息为：\n");
	
	printf("航班号： %s\n\t机票号码： %-4s\t乘客姓名： %-4s\t日期： %s\n\t时间： %-4s\t\t票价（￥）： %-4d\t性别： %s\n", 
					n, f, t, d, ti, price, ty);
	printf("Confirm the new?( y / n )");
	char key;
	scanf("%c", &key);
	while(getchar() != '\n');
	if(key == 'y')
	{		
		struct flights *node = new(n, f, t, d, ti, price, ty);
		if(node != NULL)
		{
			node->next = root2;
			node->prev = root2->prev;
			root2->prev->next = node;
			root2->prev = node;
			printf("新乘客信息录入成功！\n");
		}
	}
	else
	{
		printf("Insert failed !");
	}
}

int delete2(struct flights *root2)//删除指定乘客信息 
{
	printf("请输入要删除的乘客机票号：");
	char num[10];
	char *n = num;
	scanf("%s", n);

	scanf("%s", n);
	while(getchar() != '\n');
	while(strlen(n)!= 8)
	{
		printf("Please enter the eight digit number(12300001) : ");
		scanf("%s", n);
		while(getchar() != '\n');
	}
	
	struct flights *p = root2;
	if(is_empty(root2))
		return 1;
	while(p->next != root2)
	{
		if(strcmp(p->next->number, n) == 0)
		{
			struct flights *del = p->next;
			p->next->next->prev = p;
			p->next = p->next->next;
			free(del);
			printf("删除成功！\n");
			return 0;
		}
		else
		{
			p = p->next;
		}
	}
	printf("对不起，没有此乘客信息！\n");
	return 1;
}

void sort2(struct flights *root2)//按照机票号码排序 
{
	char temp[20];
	int tp;
	struct flights *p=root2;
	struct flights *q=root2->next;
	while(p->next != root2)
	{		
		while(q->next != root2)
		{	
			if(strcmp(p->next->from, q->next->from) > 0)
			{
				strcpy(temp, p->next->number);
				strcpy(p->next->number, q->next->number);
				strcpy(q->next->number, temp);
				
				strcpy(temp, p->next->from);
				strcpy(p->next->from, q->next->from);
				strcpy(q->next->from, temp);
				
				strcpy(temp, p->next->terminal);
				strcpy(p->next->terminal, q->next->terminal);
				strcpy(q->next->terminal, temp);
				
				strcpy(temp, p->next->time);
				strcpy(p->next->time, q->next->time);
				strcpy(q->next->time, temp);
				
				strcpy(temp, p->next->duration);
				strcpy(p->next->duration, q->next->duration);
				strcpy(q->next->duration, temp);
				
				tp = p->next->price;
				p->next->price = q->next->price;
				q->next->price = tp;
				
				strcpy(temp, p->next->type);
				strcpy(p->next->type, q->next->type);
				strcpy(q->next->type, temp);
			}
			q = q->next;
		}
		p = p->next;
		q = p->next;
	}
	printf("操作成功！\n");
}





