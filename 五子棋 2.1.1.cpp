#include<stdio.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int map[15][15] = { 0 }; //��0��ʾ��λ��1��ʾAl��2��ʾ���
int flag[5][15][15] = { 0 };//����һ����ǵ���ά���飬���Լ�¼ȫ������Ҷ������������һ��Ϊ����
//int cord[15][15] = { 0 };//����ÿһ���flag,����ɾ��

int flag1 = 0;
int x_pos[10], y_pos[10];//��¼ÿһ����λ��֮�󷵻�ǰɾ��
int sum = 0;
int sm[15][15] = { -10000 };//��¼ÿһ�������շ���
int x_now = 7, y_now = 7;

int calcular1(int flag, int record)//��Al�Ĵ�ֺ���
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
			m = 20/2;
			return m;
		}
		if (record == 3)
		{
			m = 5000/3;
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
			m = 1000/3;
			return m;
		}
		if (record == 4)
		{
			m = 3000/4;
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
			m = 200/3;
			return m;
		}
		if (record == 4)
		{
			m = 700/4;
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

int calcular2(int flag, int record)//����ҵĴ�ֺ���
{
	int m = 0;
	if (flag == 0)
	{
		if (record == 1)
		{
			m = 20;
			return m;
		}
		if (record == 2)
		{
			m = 100/2;
			return m;
		}
		if (record == 3)
		{
			m = 400;
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
			m = 200;
			return m;
		}
		if (record == 4)
		{
			m = 800;
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
			m = 50/3;
			return m;
		}
		if (record == 4)
		{
			m = 100/4;
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

int crossing()//���������ж�
{
	int sum_crossing = 0;
	for (int i = 0; i < 15; i++)//ÿһ��
	{
		for (int j = 0; j < 15; j++)//ÿһ��
		{
			if (map[i][j] != 0)//��һ������Ϊ���ķ�ɢ�жϣ������ջ�������ɫ����������
			{
				int colour = map[i][j];
				int m, n;
				int x;
				while (1)//�����ж�
				{
					m = i;
					n = j;
					int record = 1;//��¼ͬ��ɫ��������
					int flag = 0;//���ֵΪ0������ȫΪ�գ����ֵΪ1��һ�����ӣ�Ϊ2��������
					while (1)
					{
						m++;
						if (m > 14)//�߽�ֵ�ж�
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
						m--;
						if (m < 0)//�߽�ֵ�ж�
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
				if (map[i][j] == 1)	sum_crossing = sum_crossing + x;
				else if (map[i][j] == 2)sum_crossing = sum_crossing - x;
			}
		}

	}
	return sum_crossing;
}

int lengthways()//���������ж�
{
	int sum_lenthways = 0;
	for (int i = 0; i < 15; i++)//ÿһ��
	{
		for (int j = 0; j < 15; j++)//ÿһ��
		{
			if (map[i][j] != 0)//��һ������Ϊ���ķ�ɢ�жϣ������ջ�������ɫ����������
			{
				int colour = map[i][j];
				int m, n;
				int x;
				while (1)//�����ж�
				{
					m = i;
					n = j;
					int record = 1;//��¼ͬ��ɫ��������
					int flag = 0;//���ֵΪ0������ȫΪ�գ����ֵΪ1��һ�����ӣ�Ϊ2��������
					while (1)
					{
						n++;
						if (n > 14)//�߽�ֵ�ж�
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
						n--;
						if (n < 0)//�߽�ֵ�ж�
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
				if (map[i][j] == 1)sum_lenthways = sum_lenthways + x;
				else if (map[i][j] == 2)sum_lenthways = sum_lenthways - x;
			}
		}

	}
	return sum_lenthways;
}

int leftline()//���������ж�
{
	int sum_leftline = 0;
	for (int i = 0; i < 15; i++)//ÿһ��
	{
		for (int j = 0; j < 15; j++)//ÿһ��
		{
			if (map[i][j] != 0)//��һ������Ϊ���ķ�ɢ�жϣ������ջ�������ɫ����������
			{
				int colour = map[i][j];
				int m, n;
				int x;
				while (1)//�����ж�
				{
					m = i;
					n = j;
					int record = 1;//��¼ͬ��ɫ��������
					int flag = 0;//���ֵΪ0������ȫΪ�գ����ֵΪ1��һ�����ӣ�Ϊ2��������
					while (1)
					{
						n++;
						m++;
						if (n > 14 || m > 14)//�߽�ֵ�ж�
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
						n--;
						m--;
						if (n < 0 || m < 0)//�߽�ֵ�ж�
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
				if (map[i][j] == 1)sum_leftline = sum_leftline + x;
				else if (map[i][j] == 2)sum_leftline = sum_leftline - x;
			}
		}
	}
	return sum_leftline;
}
int rightline()//���������ж�
{
	int sum_rightline = 0;
	for (int i = 0; i < 15; i++)//ÿһ��
	{
		for (int j = 0; j < 15; j++)//ÿһ��
		{
			if (map[i][j] != 0)//��һ������Ϊ���ķ�ɢ�жϣ������ջ�������ɫ����������
			{
				int colour = map[i][j];
				int m, n;
				int x;
				while (1)//�����ж�
				{
					m = i;
					n = j;
					int record = 1;//��¼ͬ��ɫ��������
					int flag = 0;//���ֵΪ0������ȫΪ�գ����ֵΪ1��һ�����ӣ�Ϊ2��������
					while (1)
					{
						m++;
						n--;
						if (m > 14 || n < 0)//�߽�ֵ�ж�
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
						m--;
						n++;
						if (m < 0 || n>0)//�߽�ֵ�ж�
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
				if (map[i][j] == 1)sum_rightline = sum_rightline + x;
				else if (map[i][j] == 2)sum_rightline = sum_rightline - x;
			}
		}

	}
	return sum_rightline;
}


int win(int n)//�ж���Ӯ
{
	int s = 1;
	for (int i = 0; i < 15; i++)//���
	{
		for (int j = 0; j < 15; j++)
		{
			if (map[i][j] == n)
			{
				int colour = map[i][j];
				int m = i, n = j;

				while (1)
				{
					m++;
					if (m > 14)//�߽�ֵ�ж�
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
					m--;
					if (m < 0)//�߽�ֵ�ж�
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

	for (int i = 0; i < 15; i++)//����
	{
		for (int j = 0; j < 15; j++)
		{
			if (map[i][j] == n)
			{
				int colour = map[i][j];
				int m = i, n = j;

				while (1)
				{
					n++;

					if (n > 14)//�߽�ֵ�ж�
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
						n--;
						if (n < 0)//�߽�ֵ�ж�
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
	for (int i = 0; i < 15; i++)//leftline
	{
		for (int j = 0; j < 15; j++)
		{
			if (map[i][j] == n)
			{
				int colour = map[i][j];
				int m = i, n = j;

				while (1)
				{
					m++;
					n--;
					if (m > 14 || n < 0)//�߽�ֵ�ж�
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
						m--;
						n++;
						if (m < 0 || n>14)//�߽�ֵ�ж�
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
	for (int i = 0; i < 15; i++)//rightline
	{
		for (int j = 0; j < 15; j++)
		{
			if (map[i][j] == n)
			{
				int colour = map[i][j];
				int m = i, n = j;

				while (1)
				{
					m++;
					n++;
					if (m > 14 || n > 14)//�߽�ֵ�ж�
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
						m--;
						n--;
						if (m < 0 || n < 0)//�߽�ֵ�ж�
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
	return 0;
}


int tree(int x, int depth)
{
	depth++;
	int sum1 = 10000000, sum2 = -10000000;
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
		flag1 = 0;//��¼�Ƿ�ȫ�ֵ�flag[][]��Ϊ1
		if (depth == 2)
		{
			sum = 0;
			sum = sum + leftline();
			sum = sum + rightline();
			sum = sum + crossing();
			sum = sum + lengthways();
			map[x_pos[depth]][y_pos[depth]] = 0;
			return sum;
		}
		sum = tree(3 - x, depth);
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (flag[depth + 1][i][j] == 0)
				{
					flag1 = 1;//�������ĳ��λ��flag��Ϊ0
				}
			}
		}
		if (x == 1)
		{
			sum1 = min(sum, sum1);
		}
		else if (x == 2)
		{
			sum2 = max(sum, sum2);
		}
		if (flag1 == 0 )
		{

			flag1 = 1;
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
				return sum1;
			}
			else if (x == 2)
			{
				return sum2;
			}
		}
		/*if (flag1 == 0 && depth != 1)
		{

			flag1 = 1;
			map[x_pos[depth]][y_pos[depth]] = 0;
			if (x == 1)
			{
				return sum1;
			}
			else if (x == 2)
			{
				return sum2;
			}
		}
		else if (flag1 == 0 && depth == 1)
		{
			map[x_pos[depth]][y_pos[depth]] = 0;
			sm[x_pos[1]][y_pos[1]] = sum1;
			return sm[x_pos[1]][y_pos[1]];
		}*/

	}
}
void traverse()//�ȸ������̣���������б������������������������Ĳ㣬�Ȳ�д��֦//���Բ��������̣�ֻ��Ҫÿһ������֮��ɾȥ����
{

	int t = -1000000;
	while (1)
	{
		flag1 = 0;
		sum = tree(1, 0);
		if (t < sum)
		{
			x_now = x_pos[1];
			y_now = y_pos[1];
		}
		t = max(t, sum);
		/*for (int i = 2; i < 5; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				for (int z = 0; z < 15; z++)
				{
					flag[i][j][z] = 0;
				}
			}
		}*/
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (flag[1][i][j] == 0)
				{
					flag1 = 1;
					break;//�������ĳ��λ��flag��Ϊ0
				}
				else
					flag1 = 0;
			}
			/*if (flag1 == 1)break;*/
		}
		
		if (flag1 == 0)
		{
			break;
		}//�õ���������λ�ü�x_now,y_now
	}
}


void drawback()
{

	IMAGE img;
	int step = 40;
	initgraph(800, 700);
	/*loadimage(&img, L"����.jpeg", 800, 700, 1);
	putimage(0, 0, &img);*/
	setbkcolor(GREEN);
	cleardevice();
	setlinecolor(RGB(0, 0, 0));
	for (int i = 0; i < 16; i++)
	{
		line(i * step, 1 * step, i * step, 15 * step);
		line(1 * step, i * step, 15 * step, i * step);
	}
	/*int x=40, y=40;
	while (1)
	{

		setfillcolor(BLACK);
		setcolor(BLACK);
		fillcircle(x, y, 20);
		x += 40;
		y += 40;
	}*/
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

void start1()//���ѡ������
{
	int a = -1;
	play();
	setfillcolor(BLACK);
	setcolor(BLACK);
	fillcircle((x_now + 1) * 40, (y_now + 1) * 40, 20);
	map[x_now][y_now] = 2;
	x_now++;
	y_now++;
	setfillcolor(WHITE);
	setcolor(WHITE);
	fillcircle((x_now + 1) * 40, (y_now + 1) * 40, 20);
	map[x_now][y_now] = 1;
	while (1)
	{
		a = win(1);
		if (a == 1)
		{
			TCHAR s[] = _T("����ʤ��");
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
			TCHAR s[] = _T("����ʤ��");
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
		sm[15][15] = { -10000 };

	}
}
void start2()//���ѡ�����
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
			TCHAR s[] = _T("����ʤ��");
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
			TCHAR s[] = _T("����ʤ��");
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
		sm[15][15] = { -10000 };
	}
}

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
