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
	//총점 평균 계산
	for (int i = 0; i < size; i++)
	{
		exam[i].tot = exam[i].kor + exam[i].eng + exam[i].mat;
		exam[i].avg = exam[i].tot / 3.0;
	}
	//순위 계산
	//총점기준계산
	for (int base = 0; base < size; base++)
	{
		exam[base].rank = 1;//exam[i].tot
		for (int j = 0; j < size; j++) 
		{
			// 기준총점 < 비교할총점
			if (exam[base].tot < exam[j].tot)
			{
				exam[base].rank++;
			}
		}
	}
}

//점수입력함수
void input(Exam exam[3], int size)
{
	puts("시험 점수를 입력해주세요!");
	for (int i = 0; i < size; i++)
	{
		printf("%d번 학생 국어:", i + 1);
		scanf_s("%d", &exam[i].kor);
		printf("%d번 학생 영어:", i + 1);
		scanf_s("%d", &exam[i].eng);
		printf("%d번 학생 수학:", i + 1);
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
	//두점의 거리는?
	int a = p1.x - p2.x;//x의 거리
	int b = p1.y - p2.y;//y의 거리

	double distance = sqrt((double)a * a + b * b);

	printf("두 점의 거리는 : %g\n", distance);
}
//*/

/*
#include<stdio.h>
#include<string.h>
//사용자 정의 데이터 타입
//구조체
typedef struct //생략가능
{
	//구조체 구성요소 : 멤버
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
}BOOk;

//배열:   데이터의 집합, 동일한데이터 타입의 집합
//구조체: 데이터의 집합, 연관있는 데이터의 집합,모든데이터 타입을 허용

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
	// . 멤버접근연산자
	book.book_id = 101;
	//strcpy(book.title ,"c programming");
	strcpy_s(book.title,sizeof(book.title), "c programming");
	strcpy_s(book.author, sizeof(book.author), "cho");
	strcpy_s(book.subject, sizeof(book.subject), "c tutorial");
	
	//구조체의 함수전달시 일반변수처리하는거랑 똑같다.
	display(book);

	display2(&book);
	
	

	return 0;
}
//*/