#ifndef DECK_H
#define DECK_H

#include <iostream> 
#include <limits.h>
#include <vector>
using namespace std; 

class Card { 
    public:
	Card(){
    	    face = ""; 
    	    value = -1;
    	    type = ""; 
	    isBlack = true; 
	}
 	Card(const Card& c) { // copy constructor
	    this->isBlack = c.isBlack; 
	    this->face = c.face; 
	    this->value = c.value; 
	    this->type = c.type; 	
	}
	Card& operator=(const Card &c) {
	    isBlack = c.isBlack; 
	    face = c.face; 
	    value = c.value; 
	    type = c.type; 
	    return *this; 
	}

	bool isBlack; 
	string face; 
	int value;
	string type; 
};

class Deck {
    public: 
	Deck();
	void shuffle();
	Card pullCard();
	void resetTopCard() { topCard = 0; } 
	int size() { return 52 - topCard; }
    private: 
	Card cards[52]; 
	int topCard; 
}; 



#endif

