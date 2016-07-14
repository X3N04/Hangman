// Hangman.h
// Daniel Salazar
// 1/25/12
// Implementation of LetterBag using Hangman wordgame
//

#include<string>
#include<iostream>
#include "LetterBag.h"
using namespace std;

#ifndef Hangman_H
#define Hangman_H

class Hangman
{
public:
	// Constructor that creates a string 
	// to be the container for the answer,
	// creates two LetterBags, one to store
	// user guesses that match the word,
	// and one that stores incorrect guesses
	Hangman();

	// Prints out the dashes and letters of the word
	void printLetters();

	// Prints out what the user has guessed so far
	// if user has no guesses: prints out '-' for
	// every letter in the word.
	// if correct guess: add guess to correct LetterBag
	// if incorrect guess: add guess to wrong LetterBag
	void guess();

	// Prints out the hangman image
	// For every mistake the user makes
	// One more part of the gallows is added
	// Max Seven guesses
	void printGallows();

	// Determines if the user has won or lost
	// at the end of each round
	void winOrLoss();
	
	// Prints out a table of the letters already used
	void printWrongLetters();

	int randWordNum;
	string word;
	LetterBag correctGuess;
	LetterBag wrongGuess;
	bool won;
};

#endif

