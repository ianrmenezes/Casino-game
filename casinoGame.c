#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void showRules();
void playRound();

int main() {
    showRules();
    
    printf("\n\n");
    
    playRound();
    
    return 0;
}

void showRules() {
    printf("----------------------------------------------------------------------------\n");
    printf("                                  RULES\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("  1. Choose any number between 1 to 10\n");
    printf("  2. If you win, you will get 10 times the money you bet\n");
    printf("  3. If you bet on the wrong number, you will lose your betting amount\n");
    printf("-----------------------------------------------------------------------------\n");
}

void playRound() {
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);
    
    printf("\n\n");
    
    int balance;
    printf("Enter the amount of money to deposit for the game: $");
    scanf("%d", &balance);
    
    printf("\n\n");
    
    printf("Your current balance is $%d\n\n", balance);
    
    srand(time(NULL));  // Seed the random number generator
    
    while (balance > 0) {
        int bet;
        printf("%s, Enter the money to bet: $", name);
        scanf("%d", &bet);
        
        while (bet > balance) {
            printf("Money exceeds current balance. Enter again: $");
            scanf("%d", &bet);
        }
        
        printf("\n\n");
        
        int guess;
        printf("Guess a number from 1 to 10: ");
        scanf("%d", &guess);
        
        while (guess < 1 || guess > 10) {
            printf("Number exceeds the valid range. Enter again: ");
            scanf("%d", &guess);
        }
        
        printf("\n\n");
        
        int computerChoice = rand() % 10 + 1;
        
        if (guess == computerChoice) {
            int winnings = bet * 10;
            balance += winnings;
            printf("You have won $%d\n\n", winnings);
            printf("Your new balance is $%d\n\n", balance);
        } else {
            balance -= bet;
            printf("You have lost $%d\n\n", bet);
            printf("The correct number was: %d\n\n", computerChoice);
            printf("Your new balance is $%d\n\n", balance);
        }
        
        if (balance == 0) {
            printf("You have $0 left. You have no more money to play.\n");
            printf("Have a nice day!\n");
            break;
        }
        
        int decision;
        printf("Do you want to continue playing?\n");
        printf("Press 1 for YES\n");
        printf("Press 2 for NO\n\n");
        printf("Your choice: ");
        scanf("%d", &decision);
        
        if (decision == 2) {
            printf("Have a good day!\n");
            break;
        }
        
        printf("\n\n");
    }
}
