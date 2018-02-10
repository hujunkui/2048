#include<stdio.h>
#include<conio.h>
#include <graphics.h>
#include <time.h>
#include <math.h>
/**********ȫ�ֱ�����************/
int i, j;//ѭ������
int count;//�Ʒ�
int  mode=3;//��Ϸģʽ
int temp;//������ά������ֵ�ı���
int arr[5][5];
/**********����������************/
int main();
void chooseMode();//ѡ����Ϸģʽ����
void createMap();//��ʼ����Ϸ����
void startGame();//��Ϸ��ʼ����
void contralDirection(int x);//�������+ͬ������
void direction(int x);//������Ƶ�ʵ��
void contralGame();//��Ϸ���Ƶ�ʵ��  
void rebuild();//��������Ϸʱ�����������µĽ���
void createCube();//���ֲ����������
void createCube1();//��;�����������
void printNumber(int x);//��ӡ���� 0��Ҳ���ǳ�ʼ��С���飩�� 2��4��8��16......
void judge();//�ж���Ӯ
void score();//��ʾ����
void noName(int x);//��֪����ʲô�����ˣ��ӵ㶫���޸���һ��bug

/**********����ʵ����************/
void chooseMode()
{
	setfillcolor(RGB(250, 248, 239));
	solidrectangle(0, 0, 640, 480);
	setfillcolor(RGB(244, 177, 121));
	solidroundrect(140, 60, 500, 160, 15, 15);
	solidroundrect(140, 190, 500, 290, 15, 15);
	solidroundrect(140, 320, 500, 420, 15, 15);
	RECT a{ 140, 60, 500, 160 };
	RECT b{ 140, 190, 500, 290 };
	RECT c{ 140, 320, 500, 420 };
	RECT d{ 140,0,500,60 };
	setbkcolor(RGB(244, 177, 121));
	settextstyle(60, 34, _T("����"));
	drawtext(_T("3��3"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("4��4"), &b, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("5��5"), &c, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(30, 17, _T("����"));
	solidroundrect(192, 12, 452, 52, 15, 15);
	drawtext(_T("2048 by ������"), &d, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(60, 34, _T("����"));
	RECT n{ 14,60,130,420 };
	solidroundrect(14, 60, 130, 420, 15, 15);
	drawtext(_T("���ѡ��ģʽ"), &n, DT_CENTER | DT_WORDBREAK);
	MOUSEMSG m;						
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (m.x >= 140 && m.x <= 500 && m.y >= 60 && m.y <= 160)
			{
				mode = 3;
				break;
			}	
			if (m.x >= 140 && m.x <= 500 && m.y >= 190 && m.y <= 290)
			{
				mode = 4;
				break;
			}
			if (m.x >= 140 && m.x <= 500 && m.y >= 320 && m.y <= 420)
			{
				mode = 5;
				break;
			}	
		}
	}
}
void createMap()
{
	count = 0;
	setfillcolor(RGB(187, 173, 160));
	solidroundrect(140, 60, 500, 420, 15, 15);
	setfillcolor(RGB(205, 193, 180));
	if(mode==3)
	{
		for (i = 0; i <  mode; i++)
		{
			for (j = 0; j <  mode; j++)
			{
				solidroundrect(140 + 9 * (i + 1) + 108 * i, 60 + 9 * (j + 1) + 108 * j, 140 + 9 * (i + 1) + 108 * (i + 1), 60 + 108 * (j + 1) + 9 * (j + 1), 15, 15);
			}
		}
	}
	if (mode == 4)
	{
		for (i = 0; i <  mode; i++)
		{
			for (j = 0; j < mode; j++)
			{
				solidroundrect(140 + 8 * (i + 1) + 80 * i, 60 + 8 * (j + 1) + 80 * j, 140 + 8 * (i + 1) + 80 * (i + 1), 60 + 80 * (j + 1) + 8 * (j + 1), 15, 15);
			}
		}
	}
	if (mode == 5)
	{
		for (i = 0; i <  mode; i++)
		{
			for (j = 0; j < mode; j++)
			{
				solidroundrect(140 + 5 * (i + 1) + 66 * i, 60 + 5 * (j + 1) + 66 * j, 140 + 5 * (i + 1) + 66 * (i + 1), 60 + 66 * (j + 1) + 5 * (j + 1), 15, 15);
			}
		}
	}
	
	for (i = 0; i <  mode; i++)
	{
		for (j = 0; j <  mode; j++)
		{
			arr[i][j] = 0;
		}
	}
	settextstyle(30, 17, _T("����"));
	settextcolor(RGB(245, 249, 241));
	setbkcolor(RGB(143, 122, 102));
	setfillcolor(RGB(143, 122, 102));
	solidroundrect(192, 12, 452, 52, 15, 15);
	RECT a{ 140,0,500,60 };
	drawtext(_T("2048 by ������"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(20, 13, _T("����"));
	RECT m{ 14,60,130,420 };
	solidroundrect(14, 60, 130, 420, 15, 15);
	drawtext(_T("ESC\n\n���˵�\n\n\n�ո��\n\n��ʼ��Ϸ\n\n\nW��\n\nS��\n\nA��\n\nD��"), &m, DT_CENTER | DT_WORDBREAK);
	score();
}
void startGame()
{
	char c = 0;
	int a = 0;
	while (a != 1)
	{
		if(kbhit())
			c = getch();
		switch (c)
		{
		case 27:
			main();
		case ' ':
			createCube();
			a = 1;
		}
	}	
}
void contralDirection(int x)
{
	if (x == 1)
	{
		direction(1);
			for (i = 0; i <  mode; i++)
			{
				for (j = 0; j <  mode-1; j++)
				{
					if (arr[j][i] == arr[j + 1][i])
					{
						arr[j][i] = 2 * arr[j][i];
						count = count + arr[j][i];
						arr[j + 1][i] = 0;
					}
				}
			}
		rebuild();
		direction(1);
	}
	if (x == 2)
	{
		direction(2);
			for (i = mode - 1; i >0; i--)
			{
				for (j = 0; j< mode; j++)
				{
					if (arr[i][j] == arr[i - 1][j])
					{
						arr[i][j] = 2 * arr[i][j];
						count = count + arr[i][j];
						arr[i - 1][j] = 0;
					}
				}
			}
			rebuild();
			direction(2);
	}
	if (x == 3)
	{
		direction(3);
			for (i = 0; i <  mode; i++)
			{
				for (j = 0; j <  mode - 1; j++)
				{
					if (arr[i][j] ==arr[i][j + 1])
					{
						arr[i][j] = 2 * arr[i][j];
						count=count+ arr[i][j];
						arr[i][j + 1] = 0;
					}
				}
			}
			rebuild();
			direction(3);
	}
	if (x == 4)
	{
		direction(4);
			for (i = 0; i <  mode; i++)
			{
				for (j = mode - 1; j > 0; j--)
				{
					if (arr[i][j] ==arr[i][j - 1])
					{
						arr[i][j] = 2 * arr[i][j];
						count=count+ arr[i][j];
						arr[i][j - 1] = 0;
					}
				}
			}
			rebuild();
			direction(4);
	}
}
void direction(int x)
{
	if (x == 1)
	{
		int m = mode - 1;
		while (m != 0)
		{
			m--;
			for (i = 0; i <  mode; i++)
			{
				for (j = 0; j <  mode - 1; j++)
				{
					if (arr[j][i] == 0 && arr[j + 1][i] != 0)
					{
						temp = arr[j + 1][i];
						arr[j + 1][i] = arr[j][i];
						arr[j][i] = temp;
						temp = 0;
					}
				}
			}
			rebuild();
		}
	}
	if (x == 2)
	{
		int m = mode - 1;
		while (m != 0)
		{
			m--;
			for (i = mode - 1; i > 0; i--)
			{
				for (j = 0; j <  mode; j++)
				{
					if (arr[i][j] == 0 && arr[i - 1][j] != 0)
					{
						temp = arr[i - 1][j];
						arr[i - 1][j] = arr[i][j];
						arr[i][j] = temp;
						temp = 0;
					}
				}
			}
			rebuild();
		}
	}
	if (x == 3)
	{
		int m = mode - 1;
		while (m != 0)
		{
			m--;
			for (i = 0; i < mode; i++)
			{
				for (j = 0; j <  mode - 1; j++)
				{
					if (arr[i][j] == 0 && arr[i][j + 1] != 0)
					{
						temp = arr[i][j + 1];
						arr[i][j + 1] = arr[i][j];
						arr[i][j] = temp;
						temp = 0;
					}
				}
			}
			rebuild();
		}
	}
	if (x == 4)
	{
		int m = mode - 1;
		while (m != 0)
		{
			m--;
			for (i = 0; i < mode; i++)
			{
				for (j = mode - 1; j > 0; j--)
				{
					if (arr[i][j] == 0 && arr[i][j - 1] != 0)
					{
						temp = arr[i][j - 1];
						arr[i][j - 1] = arr[i][j];
						arr[i][j] = temp;
						temp = 0;
					}
				}
			}
			rebuild();
		}
	}
}
void contralGame()
{
	char c = 0;
	while (1)
	{
		c = 0;
		if (kbhit())
			c = getch();
		switch(c)
		{
		case 27:
			main();
		case 'w':
			noName(1);
			break;
		case 's':
			noName(2);
			break;
		case 'a':
			noName(3);
			break;
		case 'd':
			noName(4);
			break;
		case' ':
			createMap();
			createCube();
		}
	}
}
void rebuild()
{
	for (i = 0; i <  mode; i++)//����ѭ����������
	{
		for (j = 0; j <  mode; j++)
		{ 
			if (arr[i][j] == 0)
				printNumber(0);
			for (int m = 1; m < 20; m++)
			{
				if (arr[i][j] == pow(2,m)) 
					printNumber(pow(2, m));
			}
		}
	}
}
void createCube()
{
	srand((unsigned)time(NULL));
	i = rand() % mode;
	j = rand() % mode;
	arr[i][j] = 2;
	printNumber(2);
	createCube1();
}
void createCube1()
{
	int m;
	int n = 0;
	for (i = 0; i <  mode; i++)
	{
		for (j = 0; j <  mode; j++)
		{
			if (arr[i][j] == 0)
				n++;//�ж��Ƿ��п�λ
		}
	}
	if (n >= 1)
	{
		srand((unsigned)time(NULL));
		i = rand() % mode;
		j = rand() % mode;
		m = rand() % 10;
		while (arr[i][j] != 0)
		{
			i = rand() % mode;
			j = rand() % mode;
		}
		arr[i][j] = 2;
		if (m > 0)
		{
			arr[i][j] = 2;
			printNumber(2);
		}
		else
		{
			arr[i][j] = 4;
			printNumber(4);
		}
	}
}
void judge()
{
	int s = 0;
	int p = 0;
	for (i = 0; i <  mode - 1; i++)
	{
		for (j = 0; j <  mode - 1; j++)
		{
			if (arr[i][j] != 0 && arr[i + 1][j] != 0 && arr[i][j + 1] != 0 && arr[i + 1][j + 1] != 0)
			{
				if(arr[mode - 4][mode - 1]!=arr[mode - 3][mode - 1]&& arr[mode - 2][mode -1] != arr[mode - 3][mode -1]&& arr[mode - 2][mode - 1] != arr[mode - 1][mode - 1]&& arr[mode - 1][mode - 1] != arr[mode - 1][mode - 2])
				s++;
			}
		}
	}
	for (i = 0; i <  mode - 1; i++)
	{
		for (j = 0; j <  mode - 1; j++)
		{
			if (arr[i][j] != arr[i + 1][j] && arr[i][j] != arr[i][j + 1])
				p++;
		}
	}
	for (i =0; i <  mode; i++)
	{
		for (j = 0; j <  mode; j++)
		{
			if (arr[i][j] == 131072)
			{
				RECT r{ 140,60,500,420 };
				settextstyle(60, 34, _T("����"));
				settextcolor(RGB(249, 246, 242));
				setbkcolor(RGB(224, 186, 1));
				drawtext(_T("�㿪���˰�"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			}
		}
	}
	if (s == pow(mode-1,2) && p == pow(mode - 1, 2))
	{
		RECT r{ 140,60,500,420 };
		settextstyle(50, 35, _T("����"));
		settextcolor(RGB(249, 246, 242));
		setbkcolor(RGB(224, 186, 1));
		drawtext(_T("Game Over"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
}
void printNumber(int x)
{
	int g, h;
	if (mode == 3)
	{
		g = 9;
		h = 108;
	}
	if (mode == 4)
	{
		g = 8;
		h = 80;
	}
	if (mode == 5)
	{
		g = 5;
		h = 66;
	}
	if (x == 0)
	{
		setfillcolor(RGB(205, 193, 180));
		solidroundrect(140 + g * (j + 1) +h * j, 60 + g * (i + 1) + h * i, 140 +g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1), 15, 15);
	}
	if (x == 2)
	{
		setfillcolor(RGB(237, 228, 218));
		solidroundrect(140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1), 15, 15);
		RECT a{ 140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1) };
		settextstyle(50, 30, _T("����"));
		settextcolor(RGB(118, 110, 101));
		setbkcolor(RGB(237, 228, 218));
		drawtext(_T("2"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (x == 4)
	{
		setfillcolor(RGB(237, 224, 200));
		solidroundrect(140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1), 15, 15);
		RECT a{ 140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1) };
		settextstyle(50, 30, _T("����"));
		settextcolor(RGB(118, 110, 101));
		setbkcolor(RGB(237, 224, 200));
		drawtext(_T("4"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (x == 8)
	{
		setfillcolor(RGB(242, 177, 121));
		solidroundrect(140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1), 15, 15);
		RECT a{ 140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1) };
		settextstyle(50, 30, _T("����"));
		settextcolor(RGB(249, 246, 242));
		setbkcolor(RGB(242, 177, 121));
		drawtext(_T("8"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (x == 16)
	{
		setfillcolor(RGB(245, 145, 99));
		solidroundrect(140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1), 15, 15);
		RECT a{ 140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1) };
		settextstyle(50, 30, _T("����"));
		settextcolor(RGB(249, 246, 242));
		setbkcolor(RGB(245, 145, 99));
		drawtext(_T("16"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (x == 32)
	{
		setfillcolor(RGB(246, 125, 95));
		solidroundrect(140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1), 15, 15);
		RECT a{ 140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1) };
		settextstyle(50, 30, _T("����"));
		settextcolor(RGB(249, 246, 242));
		setbkcolor(RGB(246, 125, 95));
		drawtext(_T("32"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (x == 64)
	{
		setfillcolor(RGB(246, 94, 59));
		solidroundrect(140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1), 15, 15);
		RECT a{ 140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1) };
		settextstyle(50, 30, _T("����"));
		settextcolor(RGB(249, 246, 242));
		setbkcolor(RGB(246, 94, 59));
		drawtext(_T("64"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (x == 128)
	{
		setfillcolor(RGB(237, 207, 114));
		solidroundrect(140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1), 15, 15);
		RECT a{ 140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1) };
		settextstyle(40, 22, _T("����"));
		settextcolor(RGB(249, 246, 242));
		setbkcolor(RGB(237, 207, 114));
		drawtext(_T("128"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (x == 256)
	{
		setfillcolor(RGB(237, 204, 97));
		solidroundrect(140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1), 15, 15);
		RECT a{ 140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1) };
		settextstyle(40, 22, _T("����"));
		settextcolor(RGB(249, 246, 242));
		setbkcolor(RGB(237, 204, 97));
		drawtext(_T("256"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (x == 512)
	{
		setfillcolor(RGB(237, 200, 80));
		solidroundrect(140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1), 15, 15);
		RECT a{ 140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1) };
		settextstyle(40, 22, _T("����"));
		settextcolor(RGB(249, 246, 242));
		setbkcolor(RGB(237, 200, 80));
		drawtext(_T("512"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (x == 1024)
	{
		setfillcolor(RGB(237, 197, 63));
		solidroundrect(140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1), 15, 15);
		RECT a{ 140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1) };
		settextstyle(30, 17, _T("����"));
		settextcolor(RGB(249, 246, 242));
		setbkcolor(RGB(237, 197, 63));
		drawtext(_T("1024"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (x == 2048)
	{
		setfillcolor(RGB(224, 186, 1));
		solidroundrect(140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1), 15, 15);
		RECT a{ 140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1) };
		settextstyle(30, 17, _T("����"));
		settextcolor(RGB(249, 246, 242));
		setbkcolor(RGB(224, 186, 1));
		drawtext(_T("2048"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (x == 4096)
	{
		setfillcolor(RGB(0, 120, 0));
		solidroundrect(140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1), 15, 15);
		RECT a{ 140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1) };
		settextstyle(30, 17, _T("����"));
		settextcolor(RGB(249, 246, 242));
		setbkcolor(RGB(0, 120, 0));
		drawtext(_T("4096"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (x == 8192)
	{
		setfillcolor(RGB(0, 150, 0));
		solidroundrect(140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1), 15, 15);
		RECT a{ 140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1) };
		settextstyle(30, 17, _T("����"));
		settextcolor(RGB(249, 246, 242));
		setbkcolor(RGB(0, 150, 0));
		drawtext(_T("8192"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (x == 16384)
	{
		setfillcolor(RGB(0, 180, 0));
		solidroundrect(140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1), 15, 15);
		RECT a{ 140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1) };
		settextstyle(30, 17, _T("����"));
		settextcolor(RGB(249, 246, 242));
		setbkcolor(RGB(0, 180, 0));
		drawtext(_T("16384"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (x == 32768)
	{
		setfillcolor(RGB(0, 210, 0));
		solidroundrect(140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1), 15, 15);
		RECT a{ 140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1) };
		settextstyle(30, 17, _T("����"));
		settextcolor(RGB(249, 246, 242));
		setbkcolor(RGB(0, 210, 0));
		drawtext(_T("32768"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (x == 65536)
	{
		setfillcolor(RGB(0, 240, 0));
		solidroundrect(140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1), 15, 15);
		RECT a{ 140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1) };
		settextstyle(30, 17, _T("����"));
		settextcolor(RGB(249, 246, 242));
		setbkcolor(RGB(0, 240, 0));
		drawtext(_T("65536"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (x == 131072)
	{
		setfillcolor(RGB(0, 255, 0));
		solidroundrect(140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1), 15, 15);
		RECT a{ 140 + g * (j + 1) + h * j, 60 + g * (i + 1) + h * i, 140 + g * (j + 1) + h * (j + 1), 60 + h * (i + 1) + g * (i + 1) };
		settextstyle(20, 12, _T("����"));
		settextcolor(RGB(249, 246, 242));
		setbkcolor(RGB(0, 255, 0));
		drawtext(_T("131072"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
}
void score()
{
	settextstyle(30, 17, _T("����"));
	settextcolor(RGB(245, 249, 241));
	setbkcolor(RGB(187, 172, 160));
	setfillcolor(RGB(187, 172, 160));
	solidroundrect(514, 160, 629, 324, 15, 15);
	RECT w{ 514, 170, 629, 240 };
	drawtext(_T("����"), &w, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT m{ 514, 170, 629, 240 };
	TCHAR s[10];
	_stprintf(s, _T("%d"), count);
	RECT x{ 514, 230, 629, 310 };
	drawtext(_T(s), &x, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
void noName(int x)
{
	int t = 0;
	int arr1[5][5];
	for (i = 0; i < mode; i++)
	{
		for (j = 0; j < mode; j++)
		{
			arr1[i][j] = arr[i][j];
		}
	}
	contralDirection(x);
	for (i = 0; i < mode; i++)
	{
		for (j = 0; j < mode; j++)
		{
			if (arr1[i][j] == arr[i][j])
			{
				t++;
			}
		}
	}
	if (t != pow(mode,2))
	{
		Sleep(150);
		createCube1();
		score();
		judge();
	}
	judge();
}
int main()
{
	initgraph(640, 480);
	chooseMode();
	createMap();
	startGame();
	contralGame();
	getch();
	closegraph();
	return 0;
}