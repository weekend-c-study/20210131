#include<stdio.h>
#include<string.h>
typedef struct
{
	char name[20];
	int kor;
	int eng;
	int mat;
	int tot;
	double avg;
	int rank;

}Exam;
      // Exam* exam
void disp(Exam exam[], int size)
{
	printf("----------------------------------------------------\n");
	printf("name\tkor\teng\tmat\ttot\tavg\trank\n");
	printf("----------------------------------------------------\n");
	for (int i = 0; i < size; i++)
	{
		printf("%s\t%3d\t%3d\t%3d\t%3d\t%.1f\t%4d\n", 
			exam[i].name, exam[i].kor, exam[i].eng,
			exam[i].mat, exam[i].tot, exam[i].avg, exam[i].rank);
	}
}
void totAndAvgFunc(Exam exam[3], int size)
{
	//���� ��� ���
	for (int i = 0; i < size; i++)
	{
		exam[i].tot = exam[i].kor + exam[i].eng + exam[i].mat;
		exam[i].avg = exam[i].tot / 3.0;
	}
	//���� ���
	//�������ذ��
	for (int base = 0; base < size; base++)
	{
		exam[base].rank = 1;//exam[i].tot
		for (int j = 0; j < size; j++) 
		{
			// �������� < ��������
			if (exam[base].tot < exam[j].tot)
			{
				exam[base].rank++;
			}
		}
	}
}

//�����Է��Լ�
void input(Exam exam[3], int size)
{
	puts("���� ������ �Է����ּ���!");
	for (int i = 0; i < size; i++)
	{
		printf("%d�� �л� ����:", i + 1);
		scanf_s("%d", &exam[i].kor);
		printf("%d�� �л� ����:", i + 1);
		scanf_s("%d", &exam[i].eng);
		printf("%d�� �л� ����:", i + 1);
		scanf_s("%d", &exam[i].mat);
	}
}

int main()
{
	Exam exam[3];
	//exam[0], exam[1], exam[2]
	strcpy_s(exam[0].name, 20 , "aaaa");
	strcpy_s(exam[1].name, 20, "bbbb");
	strcpy_s(exam[2].name, 20, "cccc");
	//exam[0].kor = 90, exam[0].eng = 80, exam[0].mat = 88;
	//exam[1].kor = 85, exam[1].eng = 95, exam[1].mat = 80;
	//exam[2].kor = 100, exam[2].eng = 70, exam[2].mat = 85;

	//exam[0].tot = 0, exam[0].avg = 0; exam[0].rank = 0;
	//exam[1].tot = 0, exam[1].avg = 0; exam[1].rank = 0;
	//exam[2].tot = 0, exam[2].avg = 0; exam[2].rank = 0;
	input(exam, 3);
	totAndAvgFunc(exam, 3);
	
	disp(exam, 3);

	return 0;
}

/*
#include<stdio.h>
#include<math.h>

typedef struct
{
	int x;
	int y;
}Point;
void process(Point p1, Point p2);
int main()
{
	Point pos1, pos2;
	puts("input x and y for pos1");
	scanf_s("%d %d", &(pos1.x), &pos1.y );

	puts("input x and y for pos2");
	scanf_s("%d %d", &(pos2.x), &pos2.y);


	printf("pos1 : [%d,%d]\n", pos1.x, pos1.y);
	printf("pos2 : [%d,%d]\n", pos2.x, pos2.y);

	process(pos1, pos2);

	return 0;
}

void process(Point p1, Point p2) 
{
	//������ �Ÿ���?
	int a = p1.x - p2.x;//x�� �Ÿ�
	int b = p1.y - p2.y;//y�� �Ÿ�

	double distance = sqrt((double)a * a + b * b);

	printf("�� ���� �Ÿ��� : %g\n", distance);
}
//*/

/*
#include<stdio.h>
#include<string.h>
//����� ���� ������ Ÿ��
//����ü
typedef struct //��������
{
	//����ü ������� : ���
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
}BOOk;

//�迭:   �������� ����, �����ѵ����� Ÿ���� ����
//����ü: �������� ����, �����ִ� �������� ����,��絥���� Ÿ���� ���

//typedef struct Book		BOOK;
void display(BOOk book)
{
	printf("boo_id : %d\n", book.book_id);
	printf("title : %s\n", book.title);
	printf("author : %s\n", book.author);
	printf("subject : %s\n", book.subject);
}

void display2(BOOk* ptr)
{
	//(*ptr).book_id == ptr->book_id
	printf("boo_id : %d\n", (*ptr).book_id);
	printf("title : %s\n", (*ptr).title);
	printf("author : %s\n", ptr->author);
	printf("subject : %s\n", ptr->subject);
	
}
int main()
{
	//struct Book book;
	BOOk book;
	printf("%d", sizeof(book));
	// . ������ٿ�����
	book.book_id = 101;
	//strcpy(book.title ,"c programming");
	strcpy_s(book.title,sizeof(book.title), "c programming");
	strcpy_s(book.author, sizeof(book.author), "cho");
	strcpy_s(book.subject, sizeof(book.subject), "c tutorial");
	
	//����ü�� �Լ����޽� �Ϲݺ���ó���ϴ°Ŷ� �Ȱ���.
	display(book);

	display2(&book);
	
	

	return 0;
}
//*/