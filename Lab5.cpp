/*
	Ben Richardson
	C++ Fall 2022
	Due: 10/28/22
	Lab 5 Number Guessing Game
	Description : Write a number - guessing game in which the computer selects a random
	number in the range of 0 to 100, and users get a maximum of 20 attempts to guess it.At
	the end of each game, users should be told whether they won or lost, and then be asked
	whether they want to play again.When the user quits, the program should output the
	total number of wins and losses. To make the game more interesting, the program
	should vary the wording of the messages that it outputs for winning, for losing, and for
	asking for another game.Create 10 different messages for each of these cases, and use
	random numbers to choose among them.This application should use at least one Do -
	While loop and at least one Switch statement. Write your C++ code using good style and
	documenting comments.You should use functions in your code as well.Your source
	code file should be called Lab5.cpp.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void WelcomeMessage(int& userInput);

//PreC: Program is compiled successfully
//PostC: Welcome message and Instructions

void attemptFunc(int& userInput, int& randomNumber); 

//PreC: Program is compiled succesfully
//PostC: 

void repeatFunc(char& repeat, int& userInput, int&randomNumber, int& wins, int& losses, int& gamestotal);

//PreC: The user has either won or lost the game
//PostC: Program gets character value to make a decision to either start a new game or stop the program

void mainFunc(char& repeat, int& userInput, int& randomNumber, int& wins, int& losses, int& gamestotal);

//PreC: Program is compiled succesfully
//PostC: Determines if user won or lost the game.

void scoreBoard(int& gamestotal, int& wins, int& losses);

//PreC: Variables totalGames, wins, and losses are initialized and passed to the function
//PostC: A scoreboard is printed that keeps track of total games played, wins, and losses

void endGame();

//PreC: The user wants to leave the game (Return value of NewGameMenu must be false)
//PostC: A parting message is printed to the screen.

void wrongMessage();

//PreC: Incorrect guess entered as to what the random number is
//PostC: An incorrect statement (out of 10) is showing up (Wrong guess)

void correctMessage();

//PreC: The user has entered the correct guess
//PostC: A correct statement (out of 10) is showing up (User won)

void failureMessage();
 
//PreC: Incorrect guess entered as to what the random number is
//PostC: An incorrect statement (out of 10) is showing up before asking a new game

int main()
{
	int randomNumber;
	int userInput;
	char repeat;
	int gamestotal = 0;
	int wins = 0;
	int losses = 0;

	++gamestotal; //Increasing number of games played
	scoreBoard(gamestotal, wins, losses); //Prints initial scoreboard.
	
	WelcomeMessage(userInput); //Showing welcome message and instructions

	attemptFunc( userInput, randomNumber); //User has 20 attempts
	mainFunc(repeat, userInput, randomNumber, wins, losses, gamestotal); //Prompts user for another game
	repeatFunc(repeat, userInput, randomNumber, wins, losses, gamestotal); //Depending on the users answer it repeats the function or quits the program
	
	endGame(); //Prints parting message
	scoreBoard(gamestotal, wins, losses); //Prints final score board.

	cout << "\n Thank you for playing, see you again soon...\n";

	return 1;
}

void attemptFunc(int& userInput, int& randomNumber)
{
	//Random number is generated
	srand(unsigned int(time(NULL))); //Seeds random number generator
	randomNumber = rand() % 100 +1; //Generates random numbers between 0 and 100.
	
	for (int i = 1; i < 20; ++i) //User has 20 attempts to guess
	{
		if (randomNumber != userInput) //If user isn't able to guess it continues until they reach 0 attempts
		{
			wrongMessage(); //wrong guess returns a failure message. 
			cout << " ";
			cin >> userInput;
			cout << endl;
		}	
	}
}

void repeatFunc(char& repeat, int& userInput, int& randomNumber, int& wins, int& losses, int& gamestotal)
{

	while (repeat == 89 || repeat == 121) // I fuser types Y or y they will generate another random number and play again 
	{
		++gamestotal;
		int randomNumber = rand() % 100 + 1;

		cout << " Enter a number between 0 and 100: " << endl << " ";
		cin >> userInput;

		attemptFunc(userInput, randomNumber);
		mainFunc(repeat, userInput, randomNumber, wins, losses, gamestotal);
		repeatFunc(repeat, userInput, randomNumber, wins, losses, gamestotal);
	} 
}

void mainFunc(char& repeat, int& userInput, int& randomNumber, int& wins, int& losses,int& gamestotal) // Prints message depending if user guesses number or not
{
		if (randomNumber != userInput) // If user does not guess the number correctly they will add a loss to the socreboard and have a message outputted to the screen
		{
			++losses;
			cout << "*******************************************************************\n\n";
			failureMessage(); //Prints failure message
			cout << "\n The random number is: " << randomNumber << "\n\n" << " Do you want to have another try?" << endl << " Y or N: ";
			cin >> repeat;
			cout << "\n*******************************************************************\n";
		
		} 
		else if (randomNumber == userInput) // If user does guess the number correctly they will add a win to the socreboard and have a message outputted to the screen
		{
			++wins;
			cout << "*******************************************************************\n";
			correctMessage(); //Prints success message
			cout << "\n Would you like to play again? \n" << " Y or N: ";
			cin >> repeat;
			cout << "\n*******************************************************************\n";

		}
}

void scoreBoard(int& gamestotal, int& wins, int& losses)
{
	cout << "\n-------------------------------------------------------------------\n";
	cout << " This is the score so far: \n";
	cout << " Number of games played: " << gamestotal << endl;
	cout << " Number of games won: " << wins << endl;
	cout << " Number of games lost: " << losses << endl;
	cout << "-------------------------------------------------------------------\n";
}	

void endGame()
{
	cout << " Thank you for participating in this game.\n";
	cout << " Here are your final stats: ";
}

void wrongMessage()
{
	int failureMessage = 0;

	srand(unsigned int(time(NULL)));
	failureMessage = rand() % 10 + 1; 

	switch (failureMessage)
	{
	case 1 : cout << " Unlucky, try again: ";
		break;

	case 2: cout << " Wrong answer: "; 
		break; 

	case 3: cout << " This isn't that hard, try again: ";
		break;

	case 4 : cout << " Almost there: ";
		break; 

	case 5 : cout << " Give it another go: ";
		break; 

	case 6 : cout << " Not quite the answer: ";
		break; 

	case 7 : cout << " Bad luck, try again: ";
		break; 

	case 8 : cout << " You are bad at this: ";
		break; 

	case 9 : cout << " Very disappointing: ";
		break; 

	case 10 : cout << " Perdedor (Loser): ";
		break; 

	default: cout << " Other error: ";
	}
}

void correctMessage()
{
	int correctGuessMess = 0; 

	srand(unsigned int(time(NULL)));
	correctGuessMess = rand() % 10 + 1;

	switch (correctGuessMess)
	{
	case 1 :cout << "\n !!!!!!!!\n";
			cout << " Jackpot. ";
			cout << "\n !!!!!!!!\n";
		break;

	case 2 : cout << "\n !!!!!!!!!!!\n";
		     cout << " Lucky guess. "; 
			 cout << "\n !!!!!!!!!!!\n";
		break; 

	case 3 : cout << "\n !!!!!!!!\n"; 
			 cout << " Perfect. ";
			 cout << "\n !!!!!!!!\n";
		break; 

	case 4 : cout << "\n !!!!!!!!\n"; 
			 cout << " You won. ";
			 cout << "\n !!!!!!!!\n";
		break;

	case 5 : cout << "\n !!!!!!!!!!!\n"; 
			 cout << " You did it. ";
			 cout << "\n !!!!!!!!!!!\n";
		break;

	case 6 : cout << "\n !!!!!!!!!!!!!!!!\n"; 
			 cout << " Congratulations. ";
			 cout << "\n !!!!!!!!!!!!!!!!\n";
		break;

	case 7 : cout << "\n !!!!!!!!!!!!!!!!!!!!!!!!!!!\n";	
			 cout << " Woooooooooooow, incredible. ";
			 cout << "\n !!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
		break;

	case 8 : cout << "\n !!!!!!!!!!!!!!!!!!!!!!!!\n"; 
			 cout << " You're the best at this.";
			 cout << "\n !!!!!!!!!!!!!!!!!!!!!!!!\n";
		break;

	case 9 : cout << "\n !!!!!!!!!!!!!!!\n"; 
			 cout << " That's the one. ";
			 cout << "\n !!!!!!!!!!!!!!!\n";
		break; 

	case 10 : cout << "\n !!!!!!!!!!\n"; 
			  cout << " Great job. ";
			  cout << "\n !!!!!!!!!!\n";
		break;

	default: cout << " Error ";
	}

}

void failureMessage()
{
	int failureEndMess = 0;

	srand(unsigned int(time(NULL)));
	failureEndMess = rand() % 10 + 1;

	switch (failureEndMess)
	{
	case 1: cout << " You have used your 20 attempts. ";
		break;

	case 2: cout << " You lost, not having a good day huh?  ";
		break;

	case 3: cout << " Not good enough. ";
		break;

	case 4: cout << " You should try again later. ";
		break;

	case 5: cout << " You're a very unlucky person. ";
		break;

	case 6: cout << " Didn't go your way huh? ";
		break;

	case 7: cout << " You were very close. ";
		break;

	case 8: cout << " Don't give up just yet.";
		break;

	case 9: cout << " I hope you enjoyed the game. ";
		break;

	case 10: cout << " Give it another shot. ";
		break;

	default: cout << " Error ";
	}

}

void WelcomeMessage(int& userInput)
{
		cout << " Welcome to the number guessing game, you have a total of 20 attempts to guess a number between 1 and 100. Good luck" << endl;
		cout << " Enter a number between 0 and 100: " << " ";
		cin >> userInput;
}