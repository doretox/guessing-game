#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_ATTEMPTS 3

int main () {
	printf("********************************\n");
	printf("* Welcome to the Guessing Game *\n");
	printf("********************************\n");	
	
	int hint;
	int win = 0;	
	int attempts = 1;
	int playAgain = 1;

	srand(time(0));
	int secretNumber = rand() % 100;

	int level;
	int totalAttempts;

		do {
		printf("Choose your difficult level: \n");
		printf("(1)Easy (2)Medium (3)Hard\n");
		printf(">");
		scanf("%d", &level);

		if(level == 1){
			totalAttempts = 20;
		} else if(level == 2) {
			totalAttempts = 15;
		} else {
			totalAttempts = 6;
		}

		while(1){
			printf("What is your %do. hint\n", attempts);
			printf("> ");
			scanf("%d", &hint);		

			if(hint < 0){
				printf("You can't enter a negative number!\n");
				continue;
			} else {
				printf("Your %do. hint was %d\n", attempts, hint);

				win = (hint == secretNumber);
				int bigger = (hint > secretNumber);

				if(win){
					printf("Congrats you guessed it right!\n");
					break;
				} else if(bigger){
					printf("Your hint was BIGGER than the secret number.\n");
				} else {
					printf("Your hint was LESS than the secret number.\n");
				}
			}
		attempts++;
		}
		printf("End of Game!\n");
		printf("You won with %d attempts.\n", attempts);

			printf("Do you want to play again? (1)Yes (0)No\n");
			printf(">");
			scanf("%d", &playAgain);
	} while(playAgain == 1);
    return 0;
}