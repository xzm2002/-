#include<stdio.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int map[15][15] = { 0 }; //用0表示空位，1表示Al，2表示玩家
int flag[5][15][15] = { 0 };//定义一个标记的三维数组，用以记录全部的子叶被遍历过，第一个为层数
int flag1 = 0;
int x_pos[10], y_pos[10];//记录每一步的位置之后返回前删子
int sum = 0;
int x_now = 7, y_now = 7;
int x_1 = 0, y_1 = 0, x_2 = 0, y_2 = 0;
int t[15] = { 0 };
int sum1[5] = { 0 }, sum2[5] = { 0 };
void reduction()//对遍历的位置进行剪枝
{
	x_1=15, y_1=15, x_2=0, y_2=0;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (map[i][j] != 0)
			{
				if (i < x_1) x_1 = i;
				if (j < y_1) y_1 = j;
			}
		}
	}
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (map[i][j] != 0)
			{
				if(i>x_2) x_2 = i;
				if(j>y_2) y_2 = j;
			
			}
		}
	}
	x_1 = x_1 - 1;
	if (x_1 < 0) x_1 = 0;
	y_1 = y_1 - 1;
	if (y_1 < 0) y_1 = 0;
	x_2 = x_2 + 1;
	if (x_2 > 14) x_2 = 14;
	y_2 = y_2 + 1;
	if (y_2 > 14) y_2 = 14;
}
int calcular1(int flag, int record)//对Al的打分函数
{
	int m = 0;
	if (flag == 0)
	{
		if (record == 1)
		{
			m = 6;
			return m;
		}
		if (record == 2)
		{
			m = 20;
			return m;
		}
		if (record == 3)
		{
			m = 5000;
			return m;
		}
		if (record == 4)
		{
			m = 100000;
			return m;
		}
		if (record == 5)
		{
			m = 100000;
			return m;
		}
		else
			return m;
	}
	if (flag == 1)
	{

		if (record == 2)
		{
			m = 3;
			return m;
		}
		if (record == 3)
		{
			m = 1000;
			return m;
		}
		if (record == 4)
		{
			m = 3000;
			return m;
		}
		if (record == 5)
		{
			m = 100000;
			return m;
		}
		else
			return m;
	}
	if (flag == 2)
	{
		if (record == 3)
		{
			m = 200;
			return m;
		}
		if (record == 4)
		{
			m = 700;
			return m;
		}
		if (record == 5)
		{
			m = 100000;
			return m;
		}
		else
			return m;
	}
}
int calcular2(int flag, int record)//对玩家的打分函数
{
	int m = 0;
	if (flag == 0)
	{
		if (record == 1)
		{
			m = 10;
			return m;
		}
		if (record == 2)
		{
			m = 30;
			return m;
		}
		if (record == 3)
		{
			m = 10000;
			return m;
		}
		if (record == 4)
		{
			m = 10000000;
			return m;
		}
		if (record == 5)
		{
			m = 10000000;
			return m;
		}
		else
			return m;
	}
	if (flag == 1)
	{

		if (record == 2)
		{
			m = 5;
			return m;
		}
		if (record == 3)
		{
			m = 2000;
			return m;
		}
		if (record == 4)
		{
			m = 8000;
			return m;
		}
		if (record == 5)
		{
			m = 100000;
			return m;
		}
		else
			return m;
	}
	if (flag == 2)
	{
		if (record == 3)
		{
			m = 500;
			return m;
		}
		if (record == 4)
		{
			m = 1000;
			return m;
		}
		if (record == 5)
		{
			m = 100000;
			return m;
		}
		else
			return m;
	}
}
int value()
{
	int f=1;//记录方向 1为横向 2为纵向 3为左斜向 4为右斜向
 	int sum = 0;
	while (1)
	{
		for (int i = 0; i < 15; i++)//每一列
		{
			for (int j = 0; j < 15; j++)//每一行
			{
				if (map[i][j] != 0)//以一个棋子为中心发散判断，遇到空或其他颜色的棋子跳出
				{
					int colour = map[i][j];
					int m, n;
					int x;
					while (1)//横向判断
					{
						m = i;
						n = j;
						int record = 1;//记录同颜色的棋子数
						int flag = 0;//如果值为0则两边全为空，如果值为1有一边有子，为2两边有子
						while (1)
						{
							if (f == 1) m++;
							else if (f == 2) n++;
							else if (f == 3) { m++; n++; }
							else if (f == 4) { m++; n--; }
					
							if (n > 14 || m > 14|| m < 0 || n < 0)//边界值判断
							{
								flag++;
								break;
							}
							else
							{
								if (map[m][n] == colour)
								{
									record++;
								}
								else if (map[m][n] == 3 - colour)
								{
									flag++;
									break;
								}
								else if (map[m][n] == 0)
								{
									break;
								}
							}
						}
						m = i;
						n = j;
						while (1)
						{
							if (f == 1) m--;
							else if (f == 2) n--;
							else if (f == 3) { m--; n--; }
							else if (f == 4) { m--; n++; }
							if (n > 14 || m > 14 || m < 0 || n < 0)//边界值判断
							{
								flag++;
								break;
							}
							else
							{
								if (map[m][n] == colour)
								{
									record++;
								}
								else if (map[m][n] == 3 - colour)
								{
									flag++;
									break;
								}
								else if (map[m][n] == 0)
								{
									break;
								}

							}
						}
						if (map[i][j] == 1)
						{
							x = calcular1(flag, record);
						}
						if (map[i][j] == 2)
						{
							x = calcular2(flag, record);
						}
						break;
					}
					if (map[i][j] == 1)	sum = sum + x;
					else if (map[i][j] == 2)sum = sum - x;
				}
			}

		}
		f++;
		if (f == 5) { break; }
	}
	return sum;
}
int win(int n)//判断输赢
{
	int s = 1;
	int f = 1;//记录方向
	while (1)
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (map[i][j] == n)
				{
					int colour = map[i][j];
					int m = i, n = j;

					while (1)
					{
						if (f == 1) m++;
						else if (f == 2) n++;
						else if (f == 3) { m++; n--; }
						else if (f == 4) { m++; n++; }
						if (n > 14 || m > 14 || m < 0 || n < 0)//边界值判断
						{
							break;
						}
						else
						{
							if (map[m][n] == colour)
							{
								s++;
							}
							else
							{
								break;
							}
						}
					}
					m = i;
					n = j;
					while (1)
					{
						if (f == 1) m--;
						else if (f == 2) n--;
						else if (f == 3) { m--; n++; }
						else if (f == 4) { m--; n--; }
						if (n > 14 || m > 14 || m < 0 || n < 0)//边界值判断
						{
							break;
						}
						else
						{
							if (map[m][n] == colour)
							{
								s++;
							}
							else
							{

								break;
							}
						}
					}

					if (s == 5) return 1;
					s = 1;

				}
			}
		}
		f++;
		if (f == 5) { break; }
	}
	return 0;
}
int tree(int x, int depth)
{
	depth++;
	if (depth == 1) { sum1[1] = 10000000; sum2[1] = -10000000; }
	else { sum1[depth] = sum1[depth - 1]; sum2[depth] = sum2[depth - 1]; }
	if (t[depth] == 0)
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				flag[depth][i][j] = 1;
			}
		}
		reduction();
		for (int i = x_1; i <= x_2; i++)
		{
			for (int j = y_1; j <= y_2; j++)
			{
				flag[depth][i][j] = 0;
			}
		}
		t[depth] = 1;
	}
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (map[i][j] != 0)
				flag[depth][i][j] = 1;
		}
	}
	int c = 0;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{

			if (flag[depth][i][j] == 0)
			{
				map[i][j] = x;
				c = 1;
				x_pos[depth] = i;
				y_pos[depth] = j;
				break;
			}

		}
		if (c == 1)
			break;
	}
	c = 0;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (map[i][j] != 0)
				flag[depth][i][j] = 1;
		}
	}
	while (1)
	{
		flag1 = 0;//记录是否全局的flag[][]都为1
		if (depth == 3)
		{
			sum = value();
			map[x_pos[depth]][y_pos[depth]] = 0;
			return sum;
		}
		sum = tree(3 - x, depth);
		if (x == 1)
		{
			sum1[depth] = min(sum, sum1[depth]);
		}
		else if (x == 2)
		{
			sum2[depth] = max(sum, sum2[depth]);
		}
		if (sum2[depth] >= sum1[depth]) flag[depth + 1][15][15] = { 0 };
		flag1 = 0;
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (flag[depth + 1][i][j] == 0)
				{
					flag1 = 1;//如果存在某个位置flag不为0
				}
			}
		}
		if (flag1 == 0 )
		{

			flag1 = 1;
			t[depth+1] = 0;
			map[x_pos[depth]][y_pos[depth]] = 0;
			for (int i = depth+1; i < 5; i++)
			{
				for (int j = 0; j < 15; j++)
				{
					for (int z = 0; z < 15; z++)
					{
						flag[i][j][z] = 0;
					}
				}
			}
			if (x == 1)
			{
				return sum1[depth];
			}
			else if (x == 2)
			{
				return sum2[depth];
			}
		}
		

	}
}
void traverse()//先复制棋盘，再下棋进行遍历。遍历树，打算先深搜四层，先不写剪枝//可以不复制棋盘，只需要每一步评分之后删去棋子
{

	int h = -1000000;
	while (1)
	{
		flag1 = 0;
		sum = tree(1, 0);
		if (h < sum)
		{
			x_now = x_pos[1];
			y_now = y_pos[1];
		}
		h = max(h, sum);
		
		flag1 = 0;
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (flag[1][i][j] == 0)
				{
					flag1 = 1;
					break;//如果存在某个位置flag不为0
				}
			}
			if (flag1 == 1)break;
		}
		
		if (flag1 == 0)
		{
			t[1] = 0;
			break;
		}//得到分数最大的位置即x_now,y_now
	}
}
void drawback()
{

	IMAGE img;
	int step = 40;
	initgraph(800, 700);
	/*loadimage(&img, L"背景.jpeg", 800, 700, 1);
	putimage(0, 0, &img);*/
	setbkcolor(GREEN);
	cleardevice();
	setlinecolor(RGB(0, 0, 0));
	for (int i = 0; i < 16; i++)
	{
		line(i * step, 1 * step, i * step, 15 * step);
		line(1 * step, i * step, 15 * step, i * step);
	}
}
void play()
{
	char input;
	while (1)
	{
		if (kbhit())
		{
			input = getch();
			if (input == 'a')
			{
				x_now--;
			}
			else if (input == 'd')
			{
				x_now++;
			}
			else if (input == 'w')
			{
				y_now--;
			}
			else if (input == 's')
			{
				y_now++;
			}
			else if (input == 'z')
			{
				break;
			}
		}
	}
}
void start1()//玩家选择先手
{
	int a = -1;
	play();
	setfillcolor(BLACK);
	setcolor(BLACK);
	fillcircle((x_now + 1) * 40, (y_now + 1) * 40, 20);
	map[x_now][y_now] = 2;
	x_now++;
	setfillcolor(WHITE);
	setcolor(WHITE);
	fillcircle((x_now + 1) * 40, (y_now + 1) * 40, 20);
	map[x_now][y_now] = 1;
	while (1)
	{
		a = win(1);
		if (a == 1)
		{
			TCHAR s[] = _T("白子胜利");
			outtextxy(250, 650, s);
			getch();
			closegraph();
		}
		play();
		setfillcolor(BLACK);
		setcolor(BLACK);
		fillcircle((x_now + 1) * 40, (y_now + 1) * 40, 20);
		map[x_now][y_now] = 2;
		int a = win(2);
		if (a == 1)
		{
			TCHAR s[] = _T("黑子胜利");
			outtextxy(250, 650, s);
			getch();
			closegraph();
		}
		traverse();
		setfillcolor(WHITE);
		setcolor(WHITE);
		fillcircle((x_now + 1) * 40, (y_now + 1) * 40, 20);
		map[x_now][y_now] = 1;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				for (int z = 0; z < 15; z++)
				{
					flag[i][j][z] = 0;
				}
			}
		}

	}
}
void start2()//玩家选择后手
{
	int a = -1;
	setfillcolor(BLACK);
	setcolor(BLACK);
	fillcircle((x_now + 1) * 40, (y_now + 1) * 40, 20);
	map[x_now][y_now] = 1;
	while (1)
	{
		
		play();
		setfillcolor(WHITE);
		setcolor(WHITE);
		fillcircle((x_now + 1) * 40, (y_now + 1) * 40, 20);
		map[x_now][y_now] = 2;
		int a = win(2);
		if (a == 1)
		{
			TCHAR s[] = _T("白子胜利");
			outtextxy(250, 650, s);
			getch();
			closegraph();
		}
		traverse();
		setfillcolor(BLACK);
		setcolor(BLACK);
		fillcircle((x_now + 1) * 40, (y_now + 1) * 40, 20);
		map[x_now][y_now] = 1;
		a = win(1);
		if (a == 1)
		{
			TCHAR s[] = _T("黑子胜利");
			outtextxy(250, 650, s);
			getch();
			closegraph();
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				for (int z = 0; z < 15; z++)
				{
					flag[i][j][z] = 0;
				}
			}
		}
	}
}
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