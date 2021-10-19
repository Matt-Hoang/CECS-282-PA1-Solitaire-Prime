#include <iostream>
#include "Deck.h"
using namespace std;

// constructor which creates a deck of 52 cards. Ace of Spades on top, followed by the rest of the spades in order, followed by Hearts, Diamonds and Clubs.
Deck::Deck()
{ 
	char rank[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
	char suit[] = {'S', 'H', 'D', 'C'};

	int i = 0;
	for (int j = 0; j < 4; j++) {
		for (int k = 0; k < 13; k++) {
			deck[i].setCard(rank[k], suit[j]);
			i++;
		}
	}

	for (int i = 0; i < 52; i++) {
		orderedDeck[i] = deck[i];
	}
}

// reset the deck so it looks like a new deck.
void Deck::refreshDeck()
{	
	// reasigns values from orderedDeck into main deck
	for (int i = 0; i < 52; i++) {
		deck[i] = orderedDeck[i];
	}
}

// deal a card from the top of the deck.
Card Deck::deal() 
{	
	// top card is at index 0
	Card topCard = deck[0];

	// shifts entire deck by 1 to get next top card
	for (int i = 1; i < 52; i++) {
		deck[i-1] = deck[i];
	}
	deck[sizeof(deck) / sizeof(deck[0]) - 1] = topCard;
	return topCard;
}

// shuffle the cards in the deck. 
void Deck::shuffle()	
{
	srand(time(NULL)); // seed rand

	// gets a random index to swap with every card in deck 52 times 
	for (int i = 0; i < sizeof(deck) / sizeof(deck[0]); i++) {
		int randIndex = rand() % 52;
		Card tempShiftCard = deck[i];
		deck[i] = deck[randIndex];
		deck[randIndex] = tempShiftCard;
	}
}

// show all the cards in the deck: 13 columns and 4 rows.
void Deck::showDeck()
{
	// displays cards, if 13 cards are printed then new line
	for (int i = 0; i < 52; i++) {
		deck[i].showCard();
		if (i % 13 == 12) {
			cout << "\n";
		}
	}
	cout << endl;
}