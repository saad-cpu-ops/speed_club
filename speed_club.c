#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define RESET "\033[0m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"
#define GREEN "\033[32m"


int main(){


time_t start_time, end_time;
double time_taken;

char sentence[] = "the eqador first and last sany cloth";

    printf(BOLD CYAN);
    printf("  ____              _   \n");
    printf(" / ___|  __ _ _ __ | | _____ \n");
    printf("| |  _  / _` | '_ \\| |/ / __|\n");
    printf("| |_| | (_| | | | |   <\\__ \\\n");
    printf(" \\____|\\__,_|_| |_|_|\\_\\___/\n");
    printf(RESET);

    printf(GREEN "Welcome to Saad.exe CLI Tool!\n\n" RESET);


printf("Please Repeat the words fast as possible\n");
printf("Loading....**************\n");



	printf("**%s**\n", sentence);

	char user_input[100];
	start_time = time(NULL);
	fgets(user_input, sizeof(user_input), stdin);
	end_time = time(NULL);
	user_input[strcspn(user_input, "\n")] = 0;
	printf("You typed:(--%s--)\n", user_input);

	time_taken = difftime(end_time, start_time);
	printf("You took --%.f-- seconds to type the sentence.\n", time_taken);

	int correct_chars = 0;
	int length = strlen(sentence);
	int input_length = strlen(user_input);

	for(int i = 0; i < length && i < input_length; i++) {
    	if(sentence[i] == user_input[i]) {
        correct_chars++;
    	}
	}

	// Accuracy percentage:
	double accuracy = ((double)correct_chars / length) * 100;
	printf("Accuracy: %.2f%%\n", accuracy);
	
return 0;
}
