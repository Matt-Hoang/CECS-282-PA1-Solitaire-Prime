#ifndef DECK_H
#define DECK_H
#include "Card.h"

class Deck
{
public:
	Deck();				
	void refreshDeck(); 
	Card deal();		
	void shuffle();		
	void showDeck();	

private:
	Card deck[52];
	Card orderedDeck[52];
};

#endif