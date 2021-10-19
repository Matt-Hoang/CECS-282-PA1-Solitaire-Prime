// Name: Matthew Hoang
// Class: CECS 282 - 04
// Project Name: Prog 1 - Solitaire Prime
// Due Date: 9/13/21 
// I certify that this program is my own original work. I did not copy any part of this program from 
// any other source. I further certify that I typed each and every line of code in this program

#include <iostream>
#include <string>
#include "Deck.h"
#include "Card.h"
using namespace std;

// sieve of eratosthenes
// checks if numbered inputed is prime, returns true or false
bool isPrime(int inputNum) {
    int n = 340; // highest possible value of all cards combined
    int maxPrime = 18; // floor of square root of n 
    bool numbers[340];

    // makes all values in numbers true 
    for (int i = 0; i < n; i++) {
        numbers[i] = true;
    }

    numbers[1] = false; // makes 1 not a prime

    // while i is less than sqrt of n, 
    // turns all non prime numbers to false
    int i = 2;
    while (i < maxPrime) {
        if (numbers[i] == true) {
            for (int j = i * i; j < n; j += i) {
                numbers[j] = false;
            }
        }
        i++;
    }

    // checks if prime based on calculated array
    // if number is prime return true, else return false
    if (numbers[inputNum]) {
        return true;
    }
    else {
        return false;
    }
}

int main() 
{   
    cout << "Welcome to Solitaire Prime!\n";
    int menuSelection = 0;
    Deck deck; // initializes the deck
    while (menuSelection != 5) {
        // displays menu and asks for input
        cout << "1) New Deck\n"
            << "2) Display Deck\n"
            << "3) Shuffle Deck\n"
            << "4) Play Solitaire Prime\n"
            << "5) Exit\n"
            << "Selection: ";
        cin >> menuSelection;
        cout << "\n";

        if (menuSelection == 1) {
            // creates unshuffled deck (S, H, D, C - A, 2, 3, ... T, J, Q, K)
            deck.refreshDeck();
        }
        else if (menuSelection == 2) {
            // display deck in gird of 13 columns and 4 row
            deck.showDeck();
        }
        else if (menuSelection == 3) {
            // randomly shuffle deck
            deck.shuffle();
            cout << "Deck has been shuffled\n\n";
        }
        else if (menuSelection == 4) {
            // play solitaire prime
            cout << "=== Playing Solitaire Prime ===\n";
            int numberOfDecks = 0;
            int currentPlayDeckTotal = 0;
            string currentPlayDeck;

            // ensures 52 cards in deck only played once
            for (int i = 0; i < 52; i++) {
                Card currentCard = deck.deal();
                currentCard.showCard(); 
                currentPlayDeckTotal += currentCard.getValue();

                // if current play deck total is true (prime),
                // prints the total, increments number of decks,
                // and resets current deck total and current play deck
                // then if last card is prime you win else you lose
                if (isPrime(currentPlayDeckTotal) == true) {
                    cout << "Prime: " << currentPlayDeckTotal << "\n";
                    numberOfDecks += 1;
                    currentPlayDeckTotal = 0;
                    currentPlayDeck = "";
                    if (i == 51) {
                        cout << "Winner in " << numberOfDecks << " piles!\n\n";
                    }
                }
                else if (i == 51) {
                    cout << "Loser\n\n";
                }
            }
        }
    }
    cout << "Thank you for playing! Exiting game.";
    return 0;
}