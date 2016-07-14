// LetterBagSource.cpp
// Daniel Salazar
// 1/24/12
//

#include "LetterBag.h"
#include<vector>
#include<cctype>

LetterBag::LetterBag()
{
	// no-parameter constructor for an empty LetterBag.
	for(int i = 0; i < 26; ++i) bag[i] = 0;
}

LetterBag::LetterBag(const vector<char> & v)
{
	for (int i = 0; i < 26; ++i) bag[i] = 0;
	// initialize using letters in v, omitting non letters
	for(unsigned int i = 0; i < v.size(); ++i)
		if (isalpha(v[i]))
			++bag[int(v[i]) - 97];
}

bool LetterBag::operator==(const LetterBag & other) const
{
	// return true iff *this equals other
	bool isEqual = true;
	for(int i = 0; i < 26 && isEqual; ++i)
		if (this->bag[i] != other.bag[i])
			isEqual = false;
	return isEqual;
}

bool LetterBag::operator!=(const LetterBag & other) const
{
	// return false iff *this equals other
	return (this->bag == other.bag? true: false);
}

int LetterBag::getCurrentSize() const
{
	// return the current size of the LetterBag
	int count = 0;
	for(int i = 0; i < 26; ++i)
		if (this->bag[i] != 0)
			++count;
	return count;
}

bool LetterBag::isEmpty() const
{
	// return true iff the LetterBag is empty
	return (getCurrentSize() == 0);
}

LetterBag & LetterBag::add(char c)
{
	// add an occurrence of c to the LetterBag
	++bag[(int(c) - 97)];
	return *this;
}
LetterBag & LetterBag::remove(char c)
{
	// remove one occurrence of c (if there is one).
	--bag[(int(c) - 97)];
	return *this;
}
LetterBag & LetterBag::clear()
{
	// remove all occurrences of all letters
	for(int i = 0; i < 26; i++)
		this->bag[i] = 0;
	return *this;
}

int LetterBag::getFrequency(char c) const
{
	// count occurrences of c
	return bag[(int(c) - 97)];
}

vector<char> LetterBag::toVector(void)
{
	// return a vector with the letters in this object, in sorted order.
	vector<char> vectorBag;
	for(int i = 0; i < 26; i++)
		if (this->bag[i] != 0)
			for (int j = 0; j < this->bag[i]; j++)
				vectorBag.push_back(char(i + 97));
	return vectorBag;
}