#include<iostream>
#include<string>
#include "LetterBag.h"
#include "Hangman.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	cout << "Searching for a random word..." << endl;
	Hangman newGame;
	system("cls");
	srand (time(NULL));
	while(!newGame.won)
	{
		newGame.printGallows();
		cout << endl;
		newGame.printLetters();
		cout << endl;
		newGame.guess();
		system("pause");
		system("cls");
		newGame.printWrongLetters();
		system("cls");
		newGame.winOrLoss();
	}

	system("pause");
	return 0;
}