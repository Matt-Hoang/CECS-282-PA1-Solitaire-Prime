#ifndef CARD_H
#define CARD_H

class Card 
{
public:
	Card();						
	Card(char, char);			
	void setCard(char, char);	
	int getValue();				
	void showCard();			

private:
	char rank;
	char suit;
};

#endif
