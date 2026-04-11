#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;

    srand(time(0)); // generate random seed
    number = rand() % 100 + 1; // random number (1–100)

    printf("Guess the number (1 to 100):\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > number)
            printf("Too High!\n");
        else if (guess < number)
            printf("Too Low!\n");
        else
            printf("Correct! You guessed in %d attempts 🎉\n", attempts);

    } while (guess != number);

    return 0;
}
