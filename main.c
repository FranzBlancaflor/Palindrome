#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pal.h"
#include "Useful.h"

void start_game()
{
	int number_of_digits = 'i';
	int positionOfCursor = 0;
	int numberOfGoes = 0;

	printf("Please Enter Size of List:");//Ask user input
	while (scanf("%d", &number_of_digits) != 1)//If the User Input is not a number
	{
		char m = my_get_char();
		printf("You have Entered ");
		putchar(m);
		printf(". This is not an integer");

		while (my_get_char() != '\n');
		printf("\nPlease Enter Size Of List:");//Ask again
	}

    //Producing Random Numbers
	srand(time(0));
	positionOfCursor = rand() % number_of_digits;

	//Allocates memory the random numbers
    int* pNumbers = (int*)malloc(sizeof(int)*number_of_digits);
	int r;
	srand(time(0));

	for (r = 0; r < number_of_digits; r++)
		*(pNumbers + r) = rand() % 10;

    printf("Start location is 0x%p\n", pNumbers);
	printf("Address of the pointer is %p\n", pNumbers);
	printf("Position of the cursor is %d\n", positionOfCursor);

	int size = (sizeof(int)*number_of_digits) / sizeof(*(pNumbers + 0));

	//Check if is Palindrome
	boolean p = is_palindrome(pNumbers, size);
	printf("Is it a Palindrome: %s", (p) ? "Yes" : "No");

	char commands;
	while (p == 0)
	{
		displayState(pNumbers, positionOfCursor, number_of_digits);

		commands = get_command();

		processCommand(pNumbers, size, &positionOfCursor, commands);

		p = is_palindrome(pNumbers, size);

		numberOfGoes += 1;
	}

	printf("\nPalindrome Successful \n");
    printf("Overall Number Of Goes: %d\n", numberOfGoes);
	free(pNumbers);
}

int main()
{
	start_game();
	return 0;
}
