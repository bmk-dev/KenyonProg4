/**********************************************************************
* Program Name:   KenyonProgram4
* Author:        Brandon Kenyon
* Date:           4/5/2021
* Course/Section: CSC 110
* Program Description:
*	This program will calculate the elapsed time in minutes between a given starting and ending time, expressed as integers on a 24-hour scale.
**********************************************************************/
/**********************************************************************
*
* Pseudocode:
*    Initial Algorithm
*    -------
*       Prompt user for beginning and ending time (24 hour timescale, no colon)
*       Calculate elapsed time between the beginning and ending times
*		Output elapsed time to the user, in minutes, on a 24 hour timescale
*
*	 Functions
*	 -------
*		- int main: The main program function
*		- int calcTime: calculates the elapsed time, in minutes on a 24 hour scale, between the startTime and endTime values provided by the user
*		- bool isGreaterThan: Used for error checking the user's inputs, returns true if the starting time is greater than the ending time (not possible).
*
*	 Data Requirements
*	 -------
*		Inputs:
*		 - (int) startTime: the start time entered by the user
*		 - (int) endTime: the end time entered by the user
*		 - (char) choice: the response from the user determining whether to re-execute the program ('Y' or 'N')
*
*		Outputs:
*		- (int) display: The calculated number of elapsed minutes to display on screen
*
*		Formulas:
*		- minutes = hours  60
*
*    Refined Algorithm
*    -------
*	do:
*		Clear screen
*		Prompt user for data
*			Request start time
*			 Store to integer 'startTime'
*			 Clear screen
*			Request end time
*			 Store to integer 'endTime'
*			 Clear screen
*		Check that the start time comes before the end time using function isGreaterThan, 
*		 if yes:
*			Calculate time using function calcTime(startTime, endTime)
*			Output the elapsed time in minutes to the user
*		 if no:
*			Output error reminding user that the time must be in a 24 hour format, and not include colons.
*
*	do while: user's choice (variable choice) to calculate another time = yes
*	Pause output
*
*
**********************************************************************/

/************************** Compiler Directives **********************/

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//Checks to ensure that the start value is less than the end value before executing calculations
bool startIsGreater(int startValue, int endValue);
//Calculates the elapsed time between the given start and ending times
int calcTime(int startValue, int endValue);


/*********************** Global Data Declarations ********************/

//None in this program.

int main()
{
	//Local variables

	//Whether or not to re-run the program
	char choice;

	//The starting time, input by the user
	int startTime;
	//The ending time, input by the user
	int endTime;


	/*************** Begin main Function Executables *****************/

	

	//Enclose code in do while loop, so that the program can be executed multiple times from the same instance
	do
	{
		//Clear screen
		system("cls");
		//Request start time
		cout << "Please enter the start time. (24-hr scale, no colon)" << endl;
		//Store to int 'startTime'
		cin >> startTime;
		//Clear screen
		system("cls");
		//Request end time
		cout << "Please enter the end time. (24-hr scale, no colon)" << endl;
		//Store to int 'endTime'
		cin >> endTime;

		//Call startIsGreater function to verify that the start time does in fact come before the end time
		if (startIsGreater(startTime, endTime))
		{
			//If the start time is greater, output error informing user the inputs are incorrect.
			cout << "Please ensure the start time is less than the end time!";
		}
		else
		{
			//Call the calcTime function to return the elapsed time, in minutes, between starting and ending times. Store to local variable display
			int display = calcTime(startTime, endTime);
			//Output the elapsed time to the user
			cout << "The elapsed time (in minutes) is: " + display << endl;

			//Ask if the user would like to run again
			cout << "Would you like to run the program again?" << endl;
			//Input character to char 'choice'
			cin >> choice;
			

		}
		//Loop as long as the user opts to, allowing the program to be executed multiple times.
	} while (choice == 'Y' || choice == 'y');
	
	//Pause system to view output
	system("pause");
	//Indicate to OS successful termination of program
	return 0;
}   //End main

/* ** Function description **
* Name: startIsGreater
* Author: Brandon Kenyon
* Date written: 4/3/2021
* Description: This function returns true or false based on whether or not the starting time given by the user comes before
(is less than) the ending time given by the user.
*
* Pseudocode:
*	IF starting value > ending value
*		return true
*	ELSE
*		return false
*/
bool startIsGreater(int startValue, int endValue)
{
	//If the start time is less than the end time
	if (startValue > endValue)
	{
		//return true
		return true;
	}
	//If the start time is more than the end time
	else
	{
		//return false
		return false;
	}
}

/* ** Function description **
* Name: printB
* Author: Brandon Kenyon
* Date written: 4/3/2021
* Description: This function calculates the elapsed time, in minutes, between a starting and ending time given in a 24 hour scale
with no colon.
*
* Pseudocode:
*	Define 'minutes', set to 0
*	Define 'hours', set to 0
*	Define 'difference',
*	  set to (ending time - starting time)
*	Start for loop: Set i to difference in military time, execute while i > 100, subtract 100 each execution
*	   Execute:
*		 Subtract 100 from difference
*		 Add 1 hour to 'hours' count
*	Calculate total number of minutes from hours: minutes = (hours * 60)
*	IF there are any minutes remaining (less than an hour left)
*		Add 30 minutes to total value 'minutes'
*		Set difference equal to 0
*	return total minutes
*/
int calcTime(int startValue, int endValue) 
{
	//The elapsed time, in minutes
	int minutes = 0;
	//The calculated total number of hours, used in calculations
	int hours = 0;
	//The difference between the starting and ending value, used in calculations
	int difference = endValue - startValue;
	//For loop: Set i to time difference in military time; Execute while i > 100; subtract 100 each execution.
	for (int i = difference; i > 100; i -= 100)
	{
		//Subtract 100 from the original value, for calculations later
		difference -= 100;
		//Add an hour
		hours++;
	}
	//Using the number of hours, multiply by 60 to determine the number of minutes.
	minutes = hours * 60;
	//If there are any minutes left over (i.e. the user entered a half-hour time, such as 330)
	if (difference > 0)
	{
		//Add 30 minutes to the total
		minutes = minutes + 30;
		//Set the remaining time to 0. Calculation is complete
		difference = 0;
	}

	//return the calculated number of minutes elapsed.
	return minutes;
}