struct Question {
	char W[10];
	int color;
	char answer;
};
void problems(Question *Q, int amount);
void clears(Question *Q, int amount);
void printInfo();int print_sec(time_t &start_time, Question *Q, int i);
