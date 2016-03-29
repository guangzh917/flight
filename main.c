/**********************************************
 *  File Name: main.c
 *  Created  @ 2015-08-21 09:33
 *  Author   : guangzh
 *  E-mail   : 55283610@qq.com
 **********************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "function.h"

int main(void)
{
//===========================================航班信息===========================================
	struct flights *flink = (struct flights *)malloc(sizeof(struct flights));//航班信息
	if(flink != NULL)
	{
		flink->next = flink;
		flink->prev = flink;
	}
//===========================================乘客信息===========================================
	struct flights *flink2 = (struct flights *)malloc(sizeof(struct flights));
	if(flink2 != NULL)
	{
		flink2->next = flink2;
		flink2->prev = flink2;
	}
//==============================================================================================
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\tWELCOME TO LEWIES FLIGHTS SYSTEM !\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	printf("\n\tPlease select a login( Administrator[a/A] / visitor[v/V] ) :  ");

	char s;
	fflush(stdin);
	scanf("%c", &s);
	while(getchar() != '\n');
	while(s != 'a' && s != 'A' && s != 'v' && s != 'V')
	{
		printf("Please input again : ");
		scanf("%c", &s);
		while(getchar() != '\n');
	}
	printf("\n");

	if(s == 'a' || s == 'A')
		Administrator(flink, flink2);//Administrator(flink);

	if(s == 'v' || s == 'V')
		visitor(flink, flink2);//visitor(flink);

	printf("Exit the success!\n");
	free_flights(flink);
	free_flights(flink2);
	return 0;
}

