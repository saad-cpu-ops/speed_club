#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RESET "\033[0m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"
#define GREEN "\033[32m"

static int ask_again(void) { 
    char line[16]; 
    while (1) { 
        printf("Do you want try again?(y/n): "); 
        if(!fgets(line, sizeof line, stdin)) return 0; 
        if(line[0] == 'y' || line[0] == 'Y') return 1; 
        if(line[0] == 'n' || line[0] == 'N') return 0;
        printf("Please enter (y/Y OR n/N)\n");
    } 
}

int main() {
    // Seed RNG once here
    srand(time(NULL));

    while(1) {
        // Sentences array
        const char *sentences[] = {
            "The quick brown fox jumps over the lazy dog",
            "Typing tests make your fingers smarter",
            "Crazy zebras jumped over a wizard's fence",
            "Linux is not just an OS, it's a mindset",
            "Pack my box with five dozen liquor jugs",
            "C programming is powerful and fun",
            "I typed this line perfectly fast",
            "Debugging is like being a detective in code",
            "Speed typing tests your real reaction time",
            "Never trust a computer you can't throw out a window"
        };

        int num_sentences = sizeof(sentences) / sizeof(sentences[0]);
        const char *sentence = sentences[rand() % num_sentences]; // Pick a random one

        // Intro banner
        printf(BOLD CYAN);
        printf("   _______.     ___           ___       _______       _______ ___   ___  _______ \n");
        printf("    /       |    /   \\         /   \\     |       \\     |   ____|\\  \\ /  / |   ____|\n");
        printf("   |   (----`   /  ^  \\       /  ^  \\    |  .--.  |    |  |__    \\  V  /  |  |__   \n");
        printf("    \\   \\      /  /_\\  \\     /  /_\\  \\   |  |  |  |    |   __|    >   <   |   __|  \n");
        printf(".----)   |    /  _____  \\   /  _____  \\  |  '--'  | __ |  |____  /  .  \\  |  |____ \n");
        printf("|_______/    /__/     \\__\\ /__/     \\__\\ |_______/ (__)|_______|/__/ \\__\\ |_______|\n");
        printf(RESET);

        printf(GREEN "Welcome to Saad's Speed Typing Club!\n" RESET);
        printf("Repeat the sentence as fast and accurately as possible.\n\n");

        // Display sentence
        printf("Typing challenge:\n");
        printf(BOLD CYAN "\"%s\"\n\n" RESET, sentence);

        // User input
        char user_input[300];
        time_t start_time = time(NULL);

        printf("Start typing: ");
        fgets(user_input, sizeof(user_input), stdin);
        time_t end_time = time(NULL);

        // Remove newline
        user_input[strcspn(user_input, "\n")] = '\0';

        // Time taken
        double time_taken = difftime(end_time, start_time);
        if (time_taken <= 0) time_taken = 1; // avoid div by zero

        // Accuracy
        int correct_chars = 0;
        int sentence_length = strlen(sentence);
        int input_length = strlen(user_input);

        for (int i = 0; i < sentence_length && i < input_length; i++) {
            if (sentence[i] == user_input[i]) {
                correct_chars++;
            }
        }

        double accuracy = ((double)correct_chars / sentence_length) * 100;

        // WPM
        double words = sentence_length / 5.0;
        double wpm = (words / time_taken) * 60.0;

        // Report
        printf("\n--- Typing Report ---\n");
        printf("You typed     : \"%s\"\n", user_input);
        printf("Time Taken    : %.2f seconds\n", time_taken);
        printf("Accuracy      : %.2f%%\n", accuracy);
        printf("Typing Speed  : %.2f WPM\n", wpm);
        printf("----------------------\n");

        if(!ask_again()) break;
    }

    return 0;
}
