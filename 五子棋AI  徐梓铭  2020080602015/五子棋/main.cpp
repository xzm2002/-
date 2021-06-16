#include<stdio.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include"f.h"

int main()
{
	int n;
	printf("请选择先手/后手：先手为黑子请输入1，后手为白子请输入2\n");
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