#include <stdio.h>
#pragma warning(disable : 4996)
int lowestNum;
int highestNum;
int sumOfNums;
int amountOfNums;
int main(int a) {
	if (a == 1)
	{
		// first loop
		printf("Enter a negative number or letter to get results.\n");
	}
	else if (a == 2) {
		// not first loop
		lowestNum = 0;
		highestNum = 0;
		sumOfNums = 0;
		amountOfNums = 0;
		printf("\n\033[31mWould you like to run the program again? (Q to exit) : ");
		char exit = getch();
		printf("\n");
		if (exit == 'q' || exit == 'Q') {
			return 0;
		}
	}
	enterNum();
	printf("\033[32mThe smallest number is: %d\n", lowestNum);
	printf("The highest number is: %d\n", highestNum);
	printf("The sum of all numbers is: %d\n", sumOfNums);
	float average = (float)sumOfNums / (float)amountOfNums;
	printf("The average value is: %.2f", average);
	main(2);
}

int enterNum() {
	int newNum;
	printf("\033[36mGive number: ");
	scanf("%d", &newNum);
	// Go through scanf buffer in case a letter is inputted
	fseek(stdin, 0, SEEK_END);
	// see if input was below 0, larger than largest and lower than lowest
	if (newNum < 0) {
		// stop loop if number was below 0 (letters always return below 0)
		return;
	}
	if (lowestNum == 0) {
		lowestNum = newNum;
	}
	else if (newNum < lowestNum) {
		lowestNum = newNum;
	}
	if (highestNum == 0) {
		highestNum = newNum;
	}
	else if (newNum > highestNum) {
		highestNum = newNum;
	}
	// add input to total and add one to amount of inputs (usefull for determining the average later)
	sumOfNums += newNum;
	amountOfNums += 1;
	// loop
	enterNum();
}