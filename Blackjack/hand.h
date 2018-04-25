#ifndef HAND_H
#define HAND_H

#include "deck.h" 
#include<string> 
#include<vector> 
using namespace std; 

class Hand {
    public: 
	Hand(string s) {
	    score.push_back(0);  
	    numAce = 0; 
	    id = s; 
	}
        vector<Card> handOfCards; 
        vector<int> score; 
        int numAce; 
	string id; 
	string getID() { return id; } 
	void addAces();
	void showScores(); 
	void showHand(); 
	string getLastCardName(); 
	string checkForWin();
	void addCard(Card& c); 
	int getMinScore();
	int getBestScore();
};

#endif
