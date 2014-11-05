/********************************************************************
* Author : Wisam Thalij
* Date Greated:  10-25-2014
* Last Date Modified: 10-25-2014
* File Name : phrase.cpp
*
* Overview:
* This Program is a secret word game, the program will randomly select
* a random number of words from a specified string and askes the user
* to enter one letter at the time to guess the secret words
*
* Input: The user will enter a letter character one at the time 
*
* Output:
* The program will prints out a message to the user to tell if he guessed
* the "secret word" or not.
* And prints out a list of a valid letters to guess from.
* And prints out the missing letters in case he failed.
* Also prints out what the secret words was.
*********************************************************************/
# include <iostream>	// Header file needed to use cout and cin
# include <string>		// Header file for strings
# include <ctime>       // Header file needed to use time 
# include <cctype>      // Header file needed to use isalpha
# include <cstdlib>		// Header file for using rand and srand

using namespace std;

int randNum;
int StringLength;
int wrongGuess;

char play = 'y';
char playerGuess;

const int arraySize = 9;

string mainPhrase[] = {"the","quick","brown","fox","jumps","over","the","lazy","dog"};

string guessPhrase;
string hidden;
string missing;

char ifChar(char ch);


int main()
{

	while (play == 'y')
	{
		guessPhrase = "";		// Initializing the guess string to an empty string
								// for each new game

		cout << "This is a word guess game! You will have only 3 chances \n"
			<< "to guess wrong letters!" << endl;

		string validLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

		



		// This loop will generate a different random number for three times
		// each time will select the position from the main phrase and assign
		// it to the guess phrase
		for ( int i=0 ; i < 3; i++)
		{
			unsigned seed;       // A variable to store the seed value
			seed = time(NULL);		// Generating a different seed each run
			srand (seed);
			// Assign a new rand number to randNum
			// Append the string guessPhrase with the words from the array of words 
			randNum = rand() % (9 - i) + 1 ;
			guessPhrase.append(mainPhrase[randNum]);
			guessPhrase.append(" ");
		}


		StringLength = guessPhrase.length();			// Calculating the length of the secret Word 
		hidden.assign(StringLength , '#');		// creating a string containing "####" with the
												// same length as the secret word to mask the word 
		missing = guessPhrase;

		// A for loop to make spaces between the words in the hidden sentence
		for (int i=0; i < StringLength ; i++)
		{
			if (!isalpha(guessPhrase.at(i)))
			{
				hidden.at(i) = ' ' ;
			}
		}

		wrongGuess = 0;
		int guessLeft = StringLength - 3;

		while (wrongGuess < 3)
		{
			cout << "What has been guessed from the secret word so far is: \n";
			cout << hidden << endl;
			cout << "The list of valid letters is: " << validLetters << endl;
			cout << "You have " << guessLeft << " guesses left!" << endl;

			cout << "Please enter your guess : ";
			cin >> playerGuess;
			cin.clear();
			cin.ignore(50,'\n');
			
			// Check if the player entered a valid letter
			playerGuess = ifChar(playerGuess);
			
			// Changing the player entry to an upper case letter
			char upChar = toupper(playerGuess);


			int repeated = 0;				// A variable to store how many times the ch ocuur in the valid list 
			int numberOfAccurance = 0;		// Initializing a variable to store how many times 
											// The player guesses right

			// A while loop to check whether the player will enter the same letter twice!
			while (playerGuess)
			{
		
				// A for loop will go through the updated valid list to check whether the player
				// second guess entry is a letter that has been guessed before
				for (int j=0; j < validLetters.length(); j++)
				{
					if (upChar == validLetters.at(j))
					{
						repeated ++;   // increment by one if there is a match and exit the loop
						break;
					}

					// Here we are checking if the loop ended without finding a match and that 
					// means the entry has been guessed before so we will ask to get a valid entry
					if (j+1 == validLetters.length())
					{
						cout << "You already guessed this letter !! guess again:" << endl;
						cin >> playerGuess;
						cin.clear();
						cin.ignore(50,'\n');					
						ifChar(playerGuess);
						upChar = toupper(playerGuess);
					}
				}
				// Here we are checking if there is a match and repeated == 1 then leave the while loop
				if ( repeated == 1 )
				{
					break ;
				}
			}
			// a for loop to check if the player guessed letter match in the secret words
			for (int i=0; i < StringLength ; i++)
			{
				if (playerGuess == guessPhrase.at(i))
				{
					numberOfAccurance ++ ;
					hidden.at(i) = guessPhrase.at(i);
					missing.at(i) = '#';
				}

			}
			// a for loop to update the valid list of letters
			for (int j=0; j < validLetters.length(); j++)
			{
				if (upChar == validLetters.at(j))
				{
					validLetters.at(j) = '#';
					break;
				}
			}
			// This is in case the guess was right 
			if (numberOfAccurance > 0)
			{
				cout << "The letter you guessed was RIGHT!! ";
				cout << "and it occured " << numberOfAccurance << " time!" << endl;
				
				// Subtracting how many times the letter occurs in the secret word from the guessLeft 
				guessLeft = guessLeft - numberOfAccurance;

			}

			// If the letter is no match then print out a warning message!
			if (numberOfAccurance == 0)
			{
				cout << "Your guess is WRONG!!" << endl;
				wrongGuess ++ ;
			}
			// This part will print the missing letters in case the player guesses all right
			if (guessLeft == 0) 
			{
				cout << "You discovered the secrect words!" << endl;
				cout << "You had " << guessLeft << " Guesses left " << endl;
				break;
			}
			// This part will print the missing letters in case the player ran out of guesses
			if (wrongGuess == 3)
			{
				cout << "The secrest Words were : " << guessPhrase << endl;
				cout << "The missing letters/words were \"" << missing << "\"" << endl;
				break;
			}

		}
		cout << "Do you want to play again? (y/n): ";
		cin >> play;
		cin.clear();
		cin.ignore(50,'\n');
	}

	return 0;
}

/******************************************************************
*                          ifChar                       
*   
* Entry: ch a user's entry for a character.
*
* Exit: the function returns a valid character.
*
* Purpose : This function will take a user's entry for a character
*			and checks if its a valid letter then it will return it 
*			if not it will ask the user for a valid input and check
*			it again then return the valid entry.                        
******************************************************************/
char ifChar(char ch)
{
	while (ch)
	{
		if (isalpha(ch))    // When is a letter go to the next statement
		{
			break;
		}
		else			   // If 'not a letter' clear the entry and get a new one
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "Invalid Data Please enter again:" << endl;
			cin >> ch;
		}
	}
	return ch; 
}