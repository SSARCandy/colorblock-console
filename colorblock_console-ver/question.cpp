#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "question.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

const WORD colors[] =
{
	0x9A, 0x9C, 0x9E, 
	0xA9, 0xAC, 0xAE,
	0xC9, 0xCA, 0xCE, 
	0xE9, 0xEA, 0xEC
};

void clears(Question *Q, int amount)
{
	int i, j;
	for (i = 0; i<amount; i++)
	{
		for (j = 0; j<10; j++)
		{
			Q[i].W[j] = '\0';
		}
		Q[i].color = 0;
		Q[i].answer = '\0';
	}
}


void problems(Question *Q, int amount)
{
	int i = 0, words = 0, color;
	char word[4][10] = { "  Red   ", "  Green ", " Yellow ", "  Blue  " };

	for (i = 0; i<amount; i++)
	{
		words = rand() % 4;
		if (words == 0)
		{
			strcpy_s(Q[i].W, word[0]);
			color = rand() % 6;
			if (color == 0)
			{
				Q[i].color = 0;
				Q[i].answer = '3';
			}
			if (color == 1)
			{
				Q[i].color = 2;
				Q[i].answer = '2';
			}
			if (color == 2)
			{
				Q[i].color = 3;
				Q[i].answer = '3';
			}
			if (color == 3)
			{
				Q[i].color = 5;
				Q[i].answer = '4';
			}
			if (color == 4)
			{
				Q[i].color = 9;
				Q[i].answer = '2';
			}
			if (color == 5)
			{
				Q[i].color = 10;
				Q[i].answer = '4';
			}
		}
		else if (words == 1)
		{
			strcpy_s(Q[i].W, word[1]);
			color = rand() % 6;
			if (color == 0)
			{
				Q[i].color = 1;
				Q[i].answer = '3';
			}
			if (color == 1)
			{
				Q[i].color = 2;
				Q[i].answer = '1';
			}
			if (color == 2)
			{
				Q[i].color = 6;
				Q[i].answer = '3';
			}
			if (color == 3)
			{
				Q[i].color = 8;
				Q[i].answer = '4';
			}
			if (color == 4)
			{
				Q[i].color = 9;
				Q[i].answer = '1';
			}
			if (color == 5)
			{
				Q[i].color = 11;
				Q[i].answer = '4';
			}
		}
		else if (words == 2)
		{
			strcpy_s(Q[i].W, word[2]);
			color = rand() % 6;
			if (color == 0)
			{
				Q[i].color = 0;
				Q[i].answer = '1';
			}
			if (color == 1)
			{
				Q[i].color = 1;
				Q[i].answer = '2';
			}
			if (color == 2)
			{
				Q[i].color = 3;
				Q[i].answer = '1';
			}
			if (color == 3)
			{
				Q[i].color = 4;
				Q[i].answer = '4';
			}
			if (color == 4)
			{
				Q[i].color = 6;
				Q[i].answer = '2';
			}
			if (color == 5)
			{
				Q[i].color = 7;
				Q[i].answer = '4';
			}
		}
		else
		{
			strcpy_s(Q[i].W, word[3]);
			color = rand() % 6;
			if (color == 0)
			{
				Q[i].color = 4;
				Q[i].answer = '4';
			}
			if (color == 1)
			{
				Q[i].color = 5;
				Q[i].answer = '1';
			}
			if (color == 2)
			{
				Q[i].color = 7;
				Q[i].answer = '3';
			}
			if (color == 3)
			{
				Q[i].color = 8;
				Q[i].answer = '2';
			}
			if (color == 4)
			{
				Q[i].color = 10;
				Q[i].answer = '1';
			}
			if (color == 5)
			{
				Q[i].color = 11;
				Q[i].answer = '2';
			}
		}
	}
}


int print_sec(time_t &start_time, Question *Q, int i)
{
	static int sec = 0, score = 0, combo = 0, total_time = 30;
	char inputans = '\0';
	time_t tmp_time;
	time(&tmp_time);

	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	if (sec < total_time)
	{
		system("cls");
		sec = (int)difftime(tmp_time, start_time);

		printInfo();

		printf("\n\t\t\t   Time left :%3d sec\n"
			"\n\t\t\t    ", total_time - sec);

		SetConsoleTextAttribute(hstdout, colors[Q[i].color]);
		printf("%s", Q[i].W);
		SetConsoleTextAttribute(hstdout, 0x0F);

		printf(" : ");
		if (sec > total_time) { return -2; }
	//	scanf_s(" %c", &inputans);
		
		inputans = _getch();
		if (inputans == '0' || inputans == '/');
		else
		{
			switch ((inputans = _getch()))
			{
			case KEY_UP:
				inputans = '1';
				break;
			case KEY_LEFT:
				inputans = '4';
				break;
			case KEY_DOWN:
				inputans = '2';
				break;
			case KEY_RIGHT:
				inputans = '3';
				break;
			default:
				//cout << endl << "null" << endl;  // key left
				break;
			}
		}

		if (inputans == '0')
		{
			return -1;
		}

		if (inputans == Q[i].answer || inputans == '/')
		{
			SetConsoleTextAttribute(hstdout, 0x0A);
			printf("Correct!");
			SetConsoleTextAttribute(hstdout, 0x0F);
			printf("\n");

			combo++;
			if (combo == 5)
			{
				total_time = total_time + 5;
				printf("\t\t\t   !! Bonus Time +5 s !!");
				combo = 0;
				Sleep(150);
			}
			Sleep(300);
			return ++score;
		}
		else
		{
			SetConsoleTextAttribute(hstdout, 0x0C);
			printf("Wrong!");
			SetConsoleTextAttribute(hstdout, 0x0F);
			printf("\n");

			combo = 0;
			Sleep(300);
			return 0;
		}
	}

	return -2;
}

void printInfo()
{
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	printf("=======================================================================\n"
		"\t              !!  Welcome to ");
	SetConsoleTextAttribute(hstdout, 0x0C);
	printf("C");
	SetConsoleTextAttribute(hstdout, 0x0A);
	printf("O");
	SetConsoleTextAttribute(hstdout, 0x09);
	printf("L");
	SetConsoleTextAttribute(hstdout, 0x0E);
	printf("O");
	SetConsoleTextAttribute(hstdout, 0x08);
	printf("R");
	SetConsoleTextAttribute(hstdout, 0x0F);
	printf(" - ");
	SetConsoleTextAttribute(hstdout, 0x06);
	printf("B");
	SetConsoleTextAttribute(hstdout, 0x05);
	printf("L");
	SetConsoleTextAttribute(hstdout, 0x04);
	printf("O");
	SetConsoleTextAttribute(hstdout, 0x03);
	printf("C");
	SetConsoleTextAttribute(hstdout, 0x02);
	printf("K");
	SetConsoleTextAttribute(hstdout, 0x0F);
	printf(" !! \n");


	printf("=============================Introduction==============================\n"
		"\t   Answer the color that didn't appear in Questions.                 \n"
		"\t       You have 60 sec to answer these questions.                    \n"
		"\t  You will get bonus time if you get 10 combo corrects.              \n"
		"\t                      ¡°How To Play:                                 \n");
	SetConsoleTextAttribute(hstdout, 0x0F);
	printf("\t\t\t\t    ");
	SetConsoleTextAttribute(hstdout, 0xC0);
	printf("¡ô");

	SetConsoleTextAttribute(hstdout, 0x0F);
	printf("\n\t\t\t\t  ");
	SetConsoleTextAttribute(hstdout, 0x90);
	printf("¡ö");
	SetConsoleTextAttribute(hstdout, 0xA0);
	printf("¡õ");
	SetConsoleTextAttribute(hstdout, 0xE0);
	printf("¡÷");
	SetConsoleTextAttribute(hstdout, 0x0F);
	printf("\n");


	printf("\t                Use arrow keys to answer.                    \n"
		"\t                Input 0 to end this game.                            \n"
		"=======================================================================\n");

}