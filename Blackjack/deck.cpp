#include "deck.h" 
#include <time.h> 
Deck::Deck() {
	    // create deck of cards
	    // So....4 cards for all values - 13 (values and face)
	    // two colors
    topCard = 0; 
    int val = 1; 
    for(int i=0; i<52; i+=4) {
//		if(i%4 == 0) {
        cards[i].face = "Hearts"; 
	cards[i].isBlack = false; // if not black, it's red 
	cards[i].value = val; 
//		}
//		else if(i%4 == 1) { 
	cards[i+1].face = "Spades"; 
	cards[i+1].value = val; 
	cards[i+1].isBlack = true; 	
//		}
//		else if(i%4 == 2){
	cards[i+2].face = "Clubs"; 
	cards[i+2].value = val; 
	cards[i+2].isBlack = true; 
//		}
//		else if(i%4 == 3) { 
	cards[i+3].face = "Diamonds";
	cards[i+3].value = val; 
	cards[i+3].isBlack = false; 		
//		} 
//	    }
	string cardType = ""; 
	if(i == 0) 
	    cardType = "Ace"; 
	else if(i >= 4 && i< 8)
	    cardType = to_string(2);
	else if(i>=8 && i <  12) 
	    cardType = to_string(3); 
	else if(i >= 12 && i < 16) 
	    cardType = to_string(4); 
	else if(i >= 16 && i < 20) 
   	    cardType = to_string(5); 
	else if(i >= 20 && i < 24) 
	    cardType = to_string(6); 
	else if(i >= 24 && i < 28) 
	    cardType = to_string(7); 
	else if(i>=28 && i < 32) 
	    cardType = to_string(8); 
	else if(i>=32 && i < 36) 
	    cardType = to_string(9); 
	else if(i>=36 && i < 40) 
	    cardType = to_string(10); 
	else if(i == 40) 
	    cardType = "Jack"; 
	else if(i == 44) 
	    cardType = "Queen"; 
	else if(i == 48) 
	    cardType = "King"; 
  	for(int j=0; j<4; j++) 
	    cards[i + j].type = cardType;
	if(val < 10) 
	   val++; 
     }//end for 
} // end Deck()

void Deck::shuffle() 
{ // in place shuffle 
    srand(time(NULL)); 
    topCard = 0; 
    for(int i=0; i<52; i++) {
	int shuffledIndex = rand() % (51 - i + 1) + i; 
	std::swap(cards[i], cards[shuffledIndex]); 
    }
}

Card Deck::pullCard() { 
    if(topCard >= 52) {	
	Card empty; 
	return empty; 
    }  
    Card current(cards[topCard]);
    topCard++; 
    return current; 
}

