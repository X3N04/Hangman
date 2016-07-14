// LetterBag.h
// Daniel Salazar
// 1/22/13
// Lab 1
// Implementation of ADT
//  using classes
//

#include<vector>
using namespace std;

#ifndef LetterBag_H
#define LetterBag_H

class LetterBag
{
public:
	LetterBag() ;  // no-parameter constructor for an empty LetterBag.
	LetterBag(const vector<char> & v);  // initialize using letters in v, omitting non letters
	bool operator==(const LetterBag & other) const;  // return true iff *this equals other
	bool operator!=(const LetterBag & other) const;  // return false iff *this equals other
	int getCurrentSize() const;  // return the current size of the LetterBag
	bool isEmpty() const;  // return true iff the LetterBag is empty
	LetterBag & add(char c); // add an occurrence of c to the LetterBag
	LetterBag & remove(char c); // remove one occurrence of c (if there is one).
	LetterBag & clear(); // remove all occurrences of all letters
	int getFrequency(char c) const; // count occurrences of c
	vector<char> toVector(); // return a vector with the letters in this object, in sorted order.
	int bag[26];
};

#endif

