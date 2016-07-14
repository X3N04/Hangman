// Hangman.cpp
// Daniel Salazar
// 1/25/12
// Implementation of LetterBag using Hangman wordgame
//

#include "Hangman.h"
#include "LetterBag.h"
#include<string>
#include<iostream>
#include<cctype>
#include<fstream>
#include<vector>
#include<ctime>

using namespace std;

Hangman::Hangman()
{
	// Open dictionary
	ifstream in;
	in.open("words.txt");
	if (!in)
	{
		cout << "fail";
		word = "fail";
	}
	else
	{
		// Get words and put in vector
		// then close dictionary
		vector <string> dict;
		dict.reserve(121289);
		string temp;
		while (in >> temp)
			dict.push_back(temp);
		in.close();

		// Randomly choose a word
		srand(time(NULL));
		int index = rand() % 121289;
		word = dict[index];
	}
	won = false;// Loop until player wins

	// Create two containers, one for correct
	// guesses and one for incorrect guesses
	LetterBag correctGuess;
	LetterBag wrongGuess;
}

void Hangman::printLetters()
{
	// Loop through each letter of the answer
	// checking if the user has already made a
	// correct guess that matches
	// if there is a match print that letter
	// else print a '-'
	char c = '-';
	for(unsigned int i = 0; i < word.length(); i++)
		cout << ((this->correctGuess.getFrequency(word[i]) > 0) ? word[i] : c);
	return;
}

void Hangman::guess()
{
	char guess; // container for user's guess
	bool isRight = false; // Correct/wrong flag

	// Prompt user for a guess
	cout << "\nGuess a letter(a-z): ";
	cin  >> guess;
	bool right = false;
	do
	{
		// Input validation
		if(this->wrongGuess.getFrequency(guess) > 0 || this->correctGuess.getFrequency(guess) > 0)
		{
			cout << endl << "You already picked that letter, choose again: ";
			cin  >> guess;
		}
		else
			right = true;
	}while(!right);

	// Loop through the answer until a match is found
	// if match: store into correct LetterBag
	for(unsigned int i = 0; i < word.length() && isRight != true; ++i)
	{
		if(word[i] == guess)
		{
			this->correctGuess.add(guess);
			cout << endl << "Correct!" << endl;
			isRight = true;
		}
	}

	// If the search completed and the flag was not switched
	// the guess was incorrect: store in wrong LetterBag
	if(isRight == false)
	{
		// Continues to next case in printGallows
		this->wrongGuess.add(guess);
		cout << endl << "Incorrect!" << endl;
	}
	return;
}

void Hangman::printGallows()
{
	// For every incorrect guess
	// one more stage of the gallows is revealed
	switch(this->wrongGuess.getCurrentSize())
	{
	case 0:cout << "\n\n\n\n\n\n";
		break;
	case 1:cout << "\n\n\n\n\n_______";
		break;
	case 2:cout << "\n |     \n |    \n |    \n |    \n_|_____";
		break;
	case 3:cout << " ,____\n |/  ;\n |   \n |   \n |   \n_|____";
		break;
	case 4:cout << " ,____\n |/  ;\n |   O\n |   \n |   \n_|____";
		break;
	case 5:cout << " ,____\n |/  ;\n |   O\n |   | \n |   \n_|____";
		break;
	case 6:cout << " ,____\n |/  ;\n |   O\n |  /|\\ \n |   \n_|____";
		break;
	case 7:cout << " ,____\n |/  ;\n |   O\n |  /|\\ \n |  / \\ \n_|____";
		break;
	}
	cout << endl;
	return;
}

void Hangman::winOrLoss()
{
	int count = 0;

	// counts number of correct guesses
	for(unsigned int i = 0; i < word.length(); ++i)
		if (this->correctGuess.getFrequency(word[i]) != 0)
			++count;

	// cross reference correct guesses to length of word
	// checks for win
	if(count == this->word.length())
	{
		cout << "You guessed the word right!" << endl;
		won = true;
	}

	// checks if MAX number of guesses has been reached
	// checks for loss
	if(this->wrongGuess.getCurrentSize() == 7)
	{
		cout << " ,____\n |/  ;\n |   O\n |  /|\\ \n |  / \\ \n_|____" << endl;
		cout << "HANGMAN! The word was " << this->word << "." << endl;
		won = true;
	}
	return;
}

void Hangman::printWrongLetters()
{
	// Prints out incorrect guesses in abc order
	cout << "Incorrect Guesses" << endl;
	int count = 0;
	vector<char> v = this->wrongGuess.toVector();
	for(int i = 0; i < this->wrongGuess.getCurrentSize(); ++i)
	{
		if(count == 4)
		{
			count = 0;
			cout << endl;
		}
		cout << v[i] << " ";
	}
	if(v.size() == 0)
		cout << "NONE!";
	cout << endl << endl;
	system("pause");
	return;
}

