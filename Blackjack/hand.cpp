#include "hand.h"

void Hand::addAces(){
    vector<int> scoreWithAce; 
    for(int i=0; i<score.size(); i++) 
    {
	scoreWithAce.push_back(score[i] + 1);
	if(score[i] + 10 <= 21)
	    scoreWithAce.push_back(score[i] + 10); 
    }	
    score = scoreWithAce; 
}

string Hand::checkForWin() {
    vector<int>::iterator i; 
    int countBust = 0; 
    for(i=score.begin(); i!=score.end(); i++) {
	if(*i == 21) {
	    return "Win"; // win 
	}
        else if(*i > 21) 
	    countBust++;  
    }
    if(score.size() == countBust) 
	return "Bust"; // BUST! 
    else 
	return "Continue"; 
}

void Hand::addCard(Card& c) {
    Card newCard = c; 
    handOfCards.push_back(newCard); 
    if(c.type == "Ace") { 
	addAces(); 
    }
    else {
	for(int i=0; i<score.size(); i++)
	    score[i]+=c.value; 
    }
} // add card

void Hand::showScores(){
    for(int i=0; i<score.size(); i++)
	cout << score[i] << " "; 
    cout << endl; 
}

void Hand::showHand(){
    for(int i=0; i<handOfCards.size(); i++) {
	cout << handOfCards[i].type << " of " << handOfCards[i].face << ", "; 
    }
    cout << endl; 
}

string Hand::getLastCardName() {
    int index = handOfCards.size() - 1; 
    string cardFaceAndType = handOfCards[index].type + " of " + handOfCards[index].face; 
    return cardFaceAndType; 
}

int Hand::getMinScore() {
    int minScore = INT_MAX; 
    for(int i=0; i<score.size(); i++) { 
	if(score[i] <= 21) 
	    minScore = std::min(minScore, score[i]); 
    }
    return minScore; 
}

int Hand::getBestScore() {
    int maxScore = INT_MIN; 
    for(int i=0; i<score.size(); i++) { 
	if(score[i] <= 21) 
	    maxScore = std::max(maxScore, score[i]); 
    }
    return maxScore; 
}

