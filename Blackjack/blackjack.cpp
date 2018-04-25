// Implementation of blackjack functions 

#include "blackjack.h" 

bool hit(Deck& d, Hand& currentHand, int& money, int bet) {
   Card c = d.pullCard(); 
   currentHand.addCard(c);  
   if(currentHand.getID() == "Player") {
        cout << "Your card: " << currentHand.getLastCardName() << endl;
	cout << "Your Score(s): "; 
	currentHand.showScores();  
   }
   string result = currentHand.checkForWin(); 
   if(result == "Win") {
        if(currentHand.getID() == "Player") {
	    money += (bet*2);  
	    cout << "Blackjack!\n";  
	    cout << "Money: " << money << endl; 
	    return false; 
	}
	return true; // If dealer gets blackjack, return true because the game still continues
   }
   if(result == "Bust") {
	if(currentHand.getID() == "Player") { 
	    cout << "That's a bust! You lose!\n";
	    cout << "Money: " << money<<endl; 	
	}
	else {
	    money+=(bet*2);
	    cout << "The dealer busted! You win!\n";
	    cout << "Money: " << money<<endl; 
	}
	return false; 
   } 
   else
	return true; 
}

bool dealerShouldHit(Hand dealerHand) {
     if(dealerHand.getMinScore() < 17) 
	    return true; 
     return false; 
}

void displayScores(int playerScore, int dealerScore) {
    cout << "Your Score: " << playerScore << endl;
    cout << "Dealer Score: " << dealerScore << endl; 
} 

void stand(Deck& d, Hand& dealerHand, Hand& playerHand, int& money, int bet){
     while(dealerShouldHit(dealerHand)) {
	if(!hit(d, dealerHand, money, bet)) 
	    return; // if dealer busts, player wins (dealt with in hit) 
     }
     // check player score against dealer score 
     int playerScore = playerHand.getBestScore();
     int dealerScore = dealerHand.getBestScore(); 
     cout << "Dealer's Hand: " <<endl; 
     dealerHand.showHand(); 
     cout << "Your Hand: " << endl; 
     playerHand.showHand(); 
     if(playerScore > dealerScore) {
	money += (bet*2); 
	displayScores(playerScore, dealerScore); 
	cout << "You Win!\n"; 
	cout << "Money: " << money << endl; 
    } 
    else if (playerScore == dealerScore) {
	money+=bet;  
	displayScores(playerScore, dealerScore); 
	cout << "Draw!\n"; 
	cout << "Money: " << money << endl; 
    } 
    else { // lose
	displayScores(playerScore, dealerScore); 
	cout << "You lost!\n"; 
	cout << "Money: " << money << endl; 
    }
} 
