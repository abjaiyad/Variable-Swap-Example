#include <stdio.h>
#include <stdlib.h>
#include <windows.h>  // For Sleep function and system("cls")

// Function to display the Digital Clock
void startDigitalClock() {
    int hour = 0, minute = 0, second = 0;

    printf("\n\t----------------------------------------");
    printf("\n\t|          DIGITAL CLOCK UI           |");
    printf("\n\t----------------------------------------\n");
    printf("\nEnter current time in the format HH MM SS: ");
    scanf("%d %d %d", &hour, &minute, &second);

    // Validate the input time
    if (hour > 23 || minute > 59 || second > 59) {
        printf("\nInvalid time format! Please restart the clock.\n");
        return;
    }

    // Loop to keep the clock running
    while (1) {
        // Clear the screen for a refreshing display
        system("cls");

        // Display a nice UI for the clock
        printf("\n\t----------------------------------------");
        printf("\n\t|          DIGITAL CLOCK UI           |");
        printf("\n\t----------------------------------------");
        printf("\n\n\t\t\t%02d : %02d : %02d", hour, minute, second);
        printf("\n\n\t----------------------------------------");
        printf("\n\t|   Press Ctrl+C to Exit the Clock    |");
        printf("\n\t----------------------------------------");

        // Wait for 1 second
        Sleep(1000);

        // Increment the time
        second++;

        // Handle time overflow
        if (second == 60) {
            second = 0;
            minute++;
        }
        if (minute == 60) {
            minute = 0;
            hour++;
        }
        if (hour == 24) {
            hour = 0;
        }
    }
}

// Function to display the main menu
void displayMenu() {
    int choice;

    do {
        // Clear the screen
        system("cls");

        // Display the menu
        printf("\n\t----------------------------------------");
        printf("\n\t|          DIGITAL CLOCK MENU          |");
        printf("\n\t----------------------------------------");
        printf("\n\t1. Start Digital Clock");
        printf("\n\t2. About");
        printf("\n\t3. Exit");
        printf("\n\t----------------------------------------");
        printf("\nEnter your choice (1-3): ");
        scanf("%d", &choice);

        // Handle menu choices
        switch (choice) {
            case 1:
                startDigitalClock();  // Start the digital clock
                break;
            case 2:
                // About the program
                printf("\n\t----------------------------------------");
                printf("\n\t|        ABOUT THE DIGITAL CLOCK       |");
                printf("\n\t----------------------------------------");
                printf("\n\tThis program is a simple Digital Clock");
                printf("\n\tcreated using the C programming language.");
                printf("\n\tIt demonstrates basic programming concepts.");
                printf("\n\t----------------------------------------");
                printf("\n\tPress any key to return to the menu...");
                getchar(); getchar();  // Wait for user input
                break;
            case 3:
                // Exit the program
                printf("\nExiting the program. Goodbye!\n");
                break;
            default:
                // Handle invalid input
                printf("\nInvalid choice! Please try again.");
                Sleep(2000);  // Wait for 2 seconds before re-displaying the menu
        }
    } while (choice != 3);  // Loop until the user chooses to exit
}

int main() {
    // Start the program with the menu
    displayMenu();
    return 0;
}
