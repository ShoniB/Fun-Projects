#ifndef BLACKJACK_H 
#define BLACKJACK_H

#include "deck.h"
#include "hand.h" 
using namespace std; 

/*
   Adds a card to the player or dealer's hand, checks if this is a winning or losing move. 
   Returns true if there is no winning or losing move and the game should continue, false if game should end. 
   Changes value of money if there is a loss/win for the player. 
   Input: Deck: deck of game, currentHand: hand of current player's move (can be player or dealer), money: player's money value, bet: player's bet value 
*/
bool hit(Deck& d, Hand& currentHand, int& money, int bet);

bool dealerShouldHit(Hand dealerHand);

void displayScores(int playerScore, int dealerScore); 

void stand(Deck& d, Hand& dealerHand, Hand& playerHand, int& money, int bet); 

#endif
