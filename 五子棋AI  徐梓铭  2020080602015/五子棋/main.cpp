#include<stdio.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include"f.h"

int main()
{
	int n;
	printf("��ѡ������/���֣�����Ϊ����������1������Ϊ����������2\n");
	scanf("%d", &n);
	drawback();
	if (n == 1)
	{
		start1();
	}
	if (n == 2)
	{
		start2();
	}


	getch();
	closegraph();
	return 0;
}