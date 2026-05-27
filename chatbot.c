#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

// Convert text to lowercase
void toLowerCase(char text[]) {

    for(int i = 0; text[i]; i++) {
        text[i] = tolower(text[i]);
    }
}

int main() {

    char userInput[100];
    char userName[50];

    // Random generator
    srand(time(0));

    // Greeting replies
    char greetings[3][100] = {
        "Hello! Nice to meet you.",
        "Hi there! How are you doing?",
        "Hey! What can I help you with?"
    };

    // Study replies
    char studyReplies[3][100] = {
        "Consistency is more important than motivation.",
        "Small daily progress creates big success.",
        "Focus on learning step by step."
    };

    // Joke replies
    char jokes[3][150] = {
        "Why do programmers prefer dark mode? Because light attracts bugs.",
        "Why was the computer cold? Because it left its Windows open.",
        "Why do Java developers wear glasses? Because they cannot C."
    };

    printf("=====================================\n");
    printf("         AI CHATBOT CREATED BY TUSHAR TALEKAR\n");
    printf("=====================================\n");

    // Ask user name
    printf("Enter your name: ");
    fgets(userName, sizeof(userName), stdin);

    userName[strcspn(userName, "\n")] = 0;

    printf("\nBot: Welcome %s!\n", userName);
    printf("Bot: Type 'help' to see available commands.\n");

    while(1) {

        printf("\nYou: ");

        fgets(userInput, sizeof(userInput), stdin);

        // Remove newline
        userInput[strcspn(userInput, "\n")] = 0;

        // Convert to lowercase
        toLowerCase(userInput);

        // Greetings
        if(strstr(userInput, "hello") ||
           strstr(userInput, "hi") ||
           strstr(userInput, "hey")) {

            int randomIndex = rand() % 3;

            printf("Bot: %s\n", greetings[randomIndex]);
        }

        // Study
        else if(strstr(userInput, "study")) {

            int randomIndex = rand() % 3;

            printf("Bot: %s\n", studyReplies[randomIndex]);
        }

        // Joke
        else if(strstr(userInput, "joke")) {

            int randomIndex = rand() % 3;

            printf("Bot: %s\n", jokes[randomIndex]);
        }

        // Exam
        else if(strstr(userInput, "exam")) {

            printf("Bot: Revision and practice are the keys to exam success.\n");
        }

        // Coding
        else if(strstr(userInput, "coding") ||
                strstr(userInput, "programming")) {

            printf("Bot: Programming improves problem-solving skills.\n");
        }

        // Name
        else if(strstr(userInput, "your name")) {

            printf("Bot: I am an AI chatbot written in C language.\n");
        }

        // Time
        else if(strstr(userInput, "time") ||
                strstr(userInput, "date")) {

            time_t currentTime;
            time(&currentTime);

            printf("Bot: Current date and time is:\n");
            printf("%s", ctime(&currentTime));
        }

        // Help command
        else if(strstr(userInput, "help")) {

            printf("\n========== AVAILABLE COMMANDS ==========\n");

            printf("hello / hi / hey\n");
            printf("study\n");
            printf("joke\n");
            printf("exam\n");
            printf("coding\n");
            printf("time\n");
            printf("date\n");
            printf("your name\n");
            printf("bye\n");

            printf("========================================\n");
        }

        // Exit
        else if(strstr(userInput, "bye") ||
                strstr(userInput, "exit")) {

            printf("Bot: Goodbye %s! Have a great day.\n", userName);
            break;
        }

        // Unknown input
        else {

            printf("Bot: Interesting... tell me more.\n");
        }
    }

    return 0;
}