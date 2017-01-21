#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "question.h"
#define SIZE 100

int main() {
	struct Question Quest[SIZE];
	int i, score = 0, status = 0, acc;
	time_t start_time;

	srand(time(NULL));
	clears(Quest, SIZE);    //clear the Array.
	time(&start_time);      //Get start time.
	problems(Quest, SIZE);  //Fill 1000 questions.

	for (i = 0; i < SIZE; i++) {
		status = print_sec(start_time, Quest, i);
		if (status == -1) {
			break;
		} else if (status == 0) {
			continue;
		} else if (status == -2) {
			printf("\n\t\t\t\tTime is up!\n");
			break;
		} else {
			score = status;
		}
	}

	(i != 0) ? (acc = score * 100 / i) : (acc = 0);

	printf("\n\t\t\t==========!Game is End!=========\n"
		"\t\t\t Total questions:%6d              \n"
		"\t\t\t Correct:%14d                     \n"
		"\t\t\t Wrong:%16d                       \n"
		"\t\t\t Accuracy:%12d%%                  \n"
		"\t\t\t================================\n\n", i, score, i - score, acc);

	system("pause");
	return 0;
}
