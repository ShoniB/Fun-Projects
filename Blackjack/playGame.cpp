#include "deck.h"
#include "hand.h" 
#include "blackjack.h" 
#include <iostream>
using namespace std; 

int main() 
{
    bool carryOn = true; 
    cout << "How much money do you have?\n"; 
    int money = 0; 
    cin >> money; 
    while(cin.fail() || money <= 0) {
	cout << "Invalid value. Enter a new amount:\n"; 
	cin.clear(); 
	cin.ignore(9999, '\n'); 
	cin >> money; 
    }
    Deck d; 
    d.shuffle(); 
    while(carryOn) {
   	cout << endl << "How much would you like to bet?\n"; 
	int bet = 0;
	cin >> bet; 
	while(cin.fail() || bet > money || bet < 0) {
	    cout << "Invalid value. Enter a new amount:\n"; 
	    cin.clear(); 
	    cin.ignore(9999, '\n'); 
	    cin >> bet; 
	}
	if(bet == 0) { 
	    cout << "Goodbye, please play again!" << endl; 
	    carryOn = false;  	
	}
	else { 
	    money = money-bet; 
	    Hand playerHand("Player"); 
	    Hand dealerHand("Dealer"); 
	    Card pCard, dCard; 
	    if(d.size() > 0) { 
	        pCard = d.pullCard(); 
	        cout<< "Your Card: " << pCard.type << " of " << pCard.face << endl; 	
	    }	
	    playerHand.addCard(pCard); 
	    if(d.size() > 0) { 
	        dCard = d.pullCard(); 
	        cout << "Dealer's Card: " << dCard.type << " of " << dCard.face << endl;  	
	    }
	    dealerHand.addCard(dCard); 
	    cout << endl << "Dealer's Score(s): "; 
	    dealerHand.showScores();
	    cout << endl << "Your Score(s): "; 
	    playerHand.showScores(); 
	    cout << endl;  
	    bool game = true; 
	    while(d.size() > 0 && game) {
	        cout << "Hit or Stand? (Input 'h' for a hit, 's' for a stand)\n"; 
	        string playerMove = "";
	        cin >> playerMove; 
	        while(playerMove != "h" && playerMove != "s")
	        {
	     	    cout << "Incorrect input. Input 'h' for a hit or 's' for a stand.\n"; 
		    cin >> playerMove; 
		} 
		if(playerMove == "s") { 
		    game = false; 
		    stand(d, dealerHand, playerHand, money, bet); 
		}
		else if(playerMove == "h") {
		    if(!hit(d, playerHand, money, bet)) 
			game = false; 
		}
	   } // end whlie
	   if(money == 0)
	   {
	       carryOn = false; 
	       cout << "you broke" <<endl; 
	   }
	}// end game on bet value
    } // end Carryon
    
    return 0; 
}
