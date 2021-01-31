#include<stdio.h>
int main()
{
	FILE* fis=NULL;
	FILE* fos=NULL;

	fopen_s(&fis, "img_1.jpg", "rb");
	char buffer[1024];
	fread_s(buffer, sizeof(buffer),sizeof(char), 1024, fis);


	fclose(fis);

	return 0;
}

/*
#include<stdio.h>
int main()
{
	FILE* fos=NULL;
	fopen_s(&fos, "test02.txt", "wt");
	if(fos != NULL)
	{
		fputc('A', fos);//문자 한글자저장
		fputs("Hello!\n", fos);//문자열 저장
		fputs("Fun C programming\n", fos);

		fclose(fos);
	}
	return 0;
}
//*/

/*
#include<stdio.h>

int main()
{
	FILE* fis=NULL;
	//파일에서 데이터를 읽기위한 스트림 형성
	fopen_s(&fis, "test01.txt","rt");
	if (fis != NULL) {
		int readData;
		while ((readData = fgetc(fis)) != EOF) {

			//fgetc파일에서 더이상  읽어들일 문자자 존재하지 않을때
			//파일의마직일때 EOF(-1) 리턴한다.
			
			printf("%c", readData);
		}
		
		
		fclose(fis);
	}
	else {//파일명일 존재하지 않을때 실행된다.
		puts("파일이 존재하지 않습니다.");
	}
	return 0;
}
//*/

/*
//파일의 입출력
//파일 : 텍스트파일(메모장,한글,엑셀), 바이너리파일(음원,영상,그림)
#include<stdio.h>
int main()
{
	//파일에 데이터 저장하기 위한 스트림
	//FILE* file=fopen("test01.txt","wt");
	FILE* file=NULL;
	fopen_s(&file,"test01.txt", "wt");
	//w 모드인경우 파일이 존재하지 않으면 자동으로 파일을 생성시켜줍니다.
	puts("파일열기!");
	if (file != NULL)
	{
		fputc('a', file);
		fputc('b', file);
		fputc('c', file);

		//종료
		fclose(file);
		puts("파일닫기!");
	}
	else {
		puts("파일이 존재하지 안습니다.");
	}

	return 0;
}
//*/

/*
//열거형(Enumerated type)
#include<stdio.h>
//둘이상의 연관이 있는 이름을 상수로 선언함으로써
//프로그램의 가독성을 높이는데 있다.
typedef enum
{
	//열거형 상수
	//0~ int형으로 표현되는 상수
	Do=1, Re,Mi,Fa,So,La,Ti
}Syllable;
typedef enum
{
	Red=10,Green=20,Blue=30
}Color;
void sound(Syllable tone)
{
	switch(tone)
	{
	case Do:
		puts("도"); break;
	case Re:
		puts("레"); break;
	case Mi:
		puts("미"); break;
	case Fa:
		puts("파"); break;
	case So:
		puts("솔"); break;
	case La:
		puts("라"); break;
	case Ti:
		puts("시"); break;

	}

}
int main()
{
	printf("%d\n", Do);
	printf("%d\n", Re);
	printf("%d\n", Mi);
	printf("%d\n", Fa);
	printf("%d\n", So);
	printf("%d\n", La);
	printf("%d\n", Ti);
	Syllable tone;

	for (tone = Do; tone < Ti; tone++)
	{
		sound(tone);
	}
	
	return 0;
}
//*/

/*
#include<stdio.h>
typedef struct
{
	unsigned short upper;
	unsigned short lower;
}DBsort;

typedef union
{
	int iBuf;
	char bBuf[4];
	DBsort sBuf;
}RDBuf;

int main()
{
	RDBuf buf;
	printf("%d", sizeof(buf));

	puts("정수 입력하세요!");
	scanf_s("%d", &buf.iBuf);

	printf("상위2byte : %u\n", buf.sBuf.upper);
	printf("하위2byte : %u\n", buf.sBuf.lower);
	printf("상위1byte 아스키코드 : %C\n", buf.bBuf[0]);
	printf("하위1byte 아스키코드 : %C\n", buf.bBuf[3]);
	return 0;
}
//*/
/*
#include<stdio.h>
typedef union
{
	unsigned char rgb[4];
	unsigned int code;

}Color;

//색상표현 0~255 == 00 ~ FF
int main()
{
	int input;
	Color c = { 0 };

	printf("Red : ");
	scanf_s("%d", &input);
	c.rgb[2] = (unsigned char)input;

	printf("Green : ");
	scanf_s("%d", &input);
	c.rgb[1] = (unsigned char)input;

	printf("Blue : ");
	scanf_s("%d", &input);
	c.rgb[0] = (unsigned char)input;

	printf("Coler code: 0x%X\n", c.code);

	printf("%d\n", &c.rgb[0]);
	printf("%d\n", &c.rgb[1]);
	printf("%d\n", &c.rgb[2]);
	printf("%d\n", &c.rgb[3]);
	printf("%d\n", &c.code);


	return 0;
}
//*/

/*
//공용체(Union type)
#include<stdio.h>

typedef union
{
	int a;
	double b;
}Utest;

int main()
{
	Utest test;
	printf("%d\n", sizeof(test));//8byte
	printf("%p %p\n", &test.a, &test.b);

	test.a = 10;
	printf("%d\n", test.a);
	test.b = 3.14;
	printf("%g\n", test.b);
	printf("%d\n", test.a);

	return 0;
}
//*/

/*
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
//*/

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