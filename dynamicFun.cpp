/*********************************************************************
* Author : Wisam Thalij
* Date Greated:  10-25-2014
* Last Date Modified: 10-25-2014
* File Name : dynamicFun.cpp
*
* Overview:
* This program will create an array dynamically and askes the user to  
* input each element of the array and print out the largest and smallest 
* numbers from this array.
*
* Input:
* The input will be a user's entery for integer numbers.
*
* Output:
* The program will fins the smallest and largest of these values 
* and prints it out.
*********************************************************************/
# include <iostream>

using namespace std;

// A function prototype
int ifInteger(int input);

// A function prototype
int checks(int input);

int main()
{

	int *array;
	int arraySize;
	int largest;
	int smallest;

	cout << "You will be entering integer numbers and the program\n";
	cout << "will prints their largest and smallest numbers!" << endl;
	cout << "Please enter how many integers you want to enter :";
	cin >> arraySize;

    // checking if the user entered a valid integer
	arraySize = ifInteger(arraySize);

	// creating a new array
	array = new int[arraySize];

	// A for loop to get the user's entry for numbers
	for (int i=0 ; i < arraySize ; i++)
	{
		cout << "Please enter the " << (i+1) << " number: ";
		cin  >> array[i];
		array[i] = checks(array[i]);

	}

	// For loop to find the largest number in the array
	largest = array[0];
	
	for (int i=0 ; i < arraySize ; i++)
	{
		if (array[i] > largest)
		{
			largest = array[i];
		}
	}

	// For loop to find the smallest number in the array
	smallest = array[0];

	for (int i=0 ; i < arraySize ; i++)
	{
		if (array[i] < smallest)
		{
			smallest = array[i];
		}
	}
	// Printing out the result
	cout << "The smallest number entered is: " << smallest << endl;
	cout << "The largest number entered is : " << largest << endl;

	// Deleting the array
	delete [] array;

	return 0;
}
// A function checks user's validation for an integer for the array size
int ifInteger(int input)
{
	while ((cin.fail()) || ( input < 0 ))
	{
		cin.clear();
		cin.ignore();
		cout << "This is invalid entry! Please enter an integer : ";
		cin >> input;
	}
	return input;
}
// A function checks user's validation for an integer for the array elements
int checks(int input)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "This is invalid entry! Please enter an integer : ";
		cin >> input;
	}
	return input;
}