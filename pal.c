#include <stdio.h>
#include "Useful.h"

void displayState(int* pListOfNumbers,  int  positionOfCursor, int number_of_digits)
//Pointing at item, Position of the cursor, The number of digits in list
{
	char c[] = "Game State:\t <";
    int i;
	int l = strlen(c) + 2;//Length to calculate the spaces to traverse

	printf(" \n %s",c);//Prints title

	for (i = 0; i < number_of_digits; i++)
        printf("%2d" , pListOfNumbers[i]);//Prints List of Numbers

	printf(" > \t Cursor at %d \n", positionOfCursor);//Prints Position of Cursor

	for (i = 0; i < l; i++)//Prints Spaces for length
		printf(" ");

	for (i = -1; i < positionOfCursor; i++)//Prints Spaces when traversing to position of cursor
		printf("  ");

	printf(" ^\n");
}

void moveCursorRight(int* pPosOfCursor, int max)
//Position of Cursor, Max number of digits
{
	if (*(pPosOfCursor) < (max - 1))//If the cursor is less than the last digit
		*pPosOfCursor += 1;

	else
		printf("ERROR CAN'T MOVE RIGHT");
}

void moveCursorLeft(int* pPosOfCursor)
{
	if (*(pPosOfCursor) > 0)//If the cursor is more than 0
		*pPosOfCursor -= 1;

	else
		printf("ERROR CAN'T MOVE LEFT");
}

void incrementDigitInListAtPos(int* pListOfNumbers, int positionOfCursor)
//Points at item, Position of cursor
{
	if(*(pListOfNumbers + positionOfCursor) < 9)//If the value is less than 9(the highest number allowed in the list)
	*(pListOfNumbers + positionOfCursor) = *(pListOfNumbers + positionOfCursor) + 1;
}

void decrementDigitInListAtPos(int* pListOfNumbers, int positionOfCursor)
{
	if (*(pListOfNumbers + positionOfCursor) > 0)//If the value is more than 0(the lowest number allowed in the list)
		*(pListOfNumbers + positionOfCursor) = *(pListOfNumbers + positionOfCursor) - 1;

	else
		printf("ERROR CAN'T SUBTRACT");
}

boolean is_palindrome(int* plist_of_numbers, int size)
//Pointing at item, Size of the list
{
	int s;
	int f;
	boolean palindrome = True;

	if (size % 2 == 0)//If the size is even
	{

		for (s = 0, f = (size - 1); s < size / 2 && f > ((size/2) - 1); s++, f--)//Traversing Biodirectionally from start point to finish point
		{

			if (*(plist_of_numbers + s) == *(plist_of_numbers + f))//If the first = last
			{
				continue;//Continue iterating
			}

			else
				palindrome = False;//Not a Palindrome
		}
	}

	else//If the size is odd
	{

		for (s = 0, f = (size - 1); s < size / 2 && f > size / 2; s++, f--)//Traversing Biodirectionally from start point to finish point, until middle element is reach
		{

			if (*(plist_of_numbers + s) == *(plist_of_numbers + f))//If the first = last
			{
				continue;//Continue Iterating
			}

			else
				palindrome = False;//Not Palindrome
		}
	}

	return palindrome;
}

char get_command()
{
	char  validCharacters[] = { 'a', 'd', 'w', 'x' };//Characters
	char z;
	int n = 0;

	do
	{
		if (n == 0)
		{
			printf(" \n \t a: Move Cursor Left \n \t d: Move Cursor Right \n \t w: Increment Number \n \t x: Decrement Number \n");
			printf(" \t Please Enter Command: \t");

			z = my_get_char();//

			if (z == '\n')
				z = my_get_char();//User Input

			if (z == validCharacters[0])
				n = 1;

			else if (z == validCharacters[1])
				n = 1;

			else if (z == validCharacters[2])
				n = 1;

			else if (z == validCharacters[3])
				n = 1;
		}

		else

			break;

	} while (n == 0);

	return z;
}

void processCommand(int* pList, int size, int* pPositionOfCursor, char command)
//Pointing at item, Size of list, Pointing at Cursor, Commands
{
	int n = 0;

		switch (command)
		{

		case 'a':
			moveCursorLeft(pPositionOfCursor);
			break;

		case 'd':
			moveCursorRight(pPositionOfCursor, size);
			break;

		case 'w':
			incrementDigitInListAtPos(pList, *pPositionOfCursor);
			break;

		case 'x':
			decrementDigitInListAtPos(pList, *pPositionOfCursor);
			break;

		}
}



