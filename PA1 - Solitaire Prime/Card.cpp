#include <iostream>
#include "Card.h"
using namespace std;

// create a “blank” card
Card::Card()
{
	rank = 'z';
	suit = 'z';
}

// constructor to create a card, setting the rank and suit
Card::Card(char r, char s)
{
	rank = r;
	suit = s;
}

// set an existing blank card to a particular value
void Card::setCard(char r, char s)
{
	rank = r;
	suit = s;
}

// return the point value of the card.
int Card::getValue()
{
	// value of A is 1
	// T, J, Q, and K are all 10
	// else card value is 'rank - 48' since type casting 
	// a char into an int gives a different value
	int cardValue;
	if (rank == 'A') {
		cardValue = 1;
	}
	else if (rank == 'T' || rank == 'J' || rank == 'Q' || rank == 'K') {
		cardValue = 10;
	} 
	else {
		cardValue = int (rank) - 48;
	}
	return cardValue;
}

// display the card using 2 fields
void Card::showCard()
{
	// if rank is T display as 10 for legibility
	// else display rank and suit
	if (rank == 'T') {
		cout << 10 << suit << ", ";
	}
	else
	{
		cout << rank << suit << ", ";
	}
	
}
