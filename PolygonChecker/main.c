#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>


#include "main.h"															// Header file for main Library
#include "triangleSolver.h"													// Header file for triangleSolver Library
#include "rectangleSolver.h"												// Header file for rectangleSolver Library
#include "../PolygonChecker/RectangleUserInput.h"			// linking header file for RectangleUserInput
#include "../PolygonChecker/Rectangle.h"					// linking header file for Rectangle

#define SIZE 20						// this constant signifies SIZE
#define ZERO 0            // this constant signifies ZERO
#define ONE 1             // this constant signifies ONE


int side = 0;

int main() {
	int arrayOfX[SIZE];						// this int array will store all values of x inputted by user
	int arrayOfY[SIZE];						// this int array will store all values of y inputted by user
	bool validInput;						// this variable will store result of validation of user input for rectangle
	bool isARectangle;						// this variable will tell us if the points given by the user form a rectangle or not

	bool continueProgram = true;

	int askFurtherInput = -1;

	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:

			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
      
      //use this function after checking triangle validity!!
			double* n = FindAnglesInTriangleAndPrint((double)triangleSidesPtr[0], (double)triangleSidesPtr[1], (double)triangleSidesPtr[2]);
      
			printf_s("%s\n", result);
			break;


		case 2:

			printf("Enter 0 for first Approach, 1 for Second Approach: \n");        // this asks user which approach they want
			scanf("%d", &askFurtherInput);                                          // this takes the user input and stores in the variable askFurtherInput

			if (askFurtherInput == ZERO) {                                          // if user inputted value is equal to the value stored in constant ZERO, then this if block gets executed

				validInput = FourPoints(arrayOfX, arrayOfY);					// FourPoints function is called and two integer arrays are passed as arguments, the returned bool value is stored in validInput variable

				if (validInput) {											// if the user input is valid this if block gets executed

					isARectangle = PointsToRectangle(arrayOfX, arrayOfY);			// calling PointsToRectangle function and two integer arrays are passed as arguments
				}

			}
			else if (askFurtherInput == ONE) {                       // if user inputted value is equal to the value stored in constant ONE, then this if block gets executed                                

				// Function for rectangle
			printf_s("Rectangle selected.\n");
			RectangleSolver();
      

			}
      
      break;											// to break out of switch
      
		case 0:
			continueProgram = false;
			break;

		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");

	printf("2. Rectangle\n");				// option 2 for Rectangle

	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");				// asks the user to enter number relevant to Menu
	scanf_s("%1o", &shapeChoice);			// saving that input in variable named shapeChoice

	return shapeChoice;						// returning variable
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}