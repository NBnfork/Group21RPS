/*********************************************************************
** Program name: validInt.cpp
** Author: 
** Date: 
** Description: 
*********************************************************************/

#include "validInt.hpp"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;
using std::stoi;

int validInt(string strIn, int min, int max)
{
	bool loopEnder;
	int asciiVal;
	int validatedInt;

	do {
		// resets loopEnder to true, so it will flip to false if not all conditions are met
		loopEnder = true;
		// for input starting w/ '-', which ascii val is 45
		if (int(strIn[0]) == 45)
		{	
			// not allowing for inputs in the billions (which is where the max int is)
			// works fine for limiting our inputs, as we will not be in this range
			if (strIn.length() > 10)
			{
				loopEnder = false;
				cout << "This input validation does not allow for integers less than -999,999,999" << endl;
				cout << "Your string should be less than 11 characters if beginning with a negative sign." << endl;
			}
			else
			{
				for(int i = 1; i < strIn.length(); i++)
				{
					// assigns ascii value to each char to test if it's a number
					asciiVal = int(strIn[i]);
					// numbers are ascii 48-57
					if(asciiVal < 48 || asciiVal > 57)
					{
						// if the value is not in this range, the loopEnder will be flipped to false
						loopEnder = false;
						cout << "This input validation does not allow for non-integer characters" << endl;
					}
				}
			}
		}
		// for all others
		else
		{

			if (strIn.length() > 9)
			{
				loopEnder = false;
				cout << "This input validation does not allow for integers greater than 999,999,999" << endl;
				cout << "Your string should be less than 10 characters if not beginning with a negative sign." << endl;
			}
			else
			{
				for(int i = 0; i < strIn.length(); i++)
				{
					// assigns ascii value to each char to test if it's a number
					asciiVal = int(strIn[i]);
					// numbers are ascii 48-57
					if(asciiVal < 48 || asciiVal > 57)
					{
						// if the value is not in this range, the loopEnder will be flipped to false
						loopEnder = false;				
					}
				}
				if (loopEnder == false)
				{
					cout << "This input validation does not allow for non-integer characters" << endl;
				}
			}
		}
		// if we check all of the chars in the string & get at least 1 non-digit
		if (loopEnder == false)
		{
			// we must loop again with a newly assigned startMenuStr
			cout << "String entered cannot be converted to integer. Please try again." << endl;
			getline(cin, strIn);
		}
		// if all of the chars return digits
		else
		{
			// use stoi to create a validatedInt value
			validatedInt = stoi(strIn);
			// if we check that it's within menu range
			if (validatedInt < min || validatedInt > max)
			{
				// if it's not, we must loop again with a newly assigned startMenuStr
				loopEnder = false;
				cout << validatedInt << " is not an option per the specified range. Please try again." << endl;
				getline(cin, strIn);
			}
			// if it is, we break out of the do while loop with our validatedInt value
			else
			{
				break;
			}
		}

	} while(loopEnder == false);

	return validatedInt;
}