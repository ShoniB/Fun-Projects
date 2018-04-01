// Shondell Baijoo 

// Minesweeper - without functionality of uncovering all adjacent '0' squares 
// 3/15/2018


// 0 1 2 3 4 (mines adjacent), 5 = mine, 0 for uninitialized (0+1 everytime there is a neighboring mine)
// play board - 5 - flag, 0,1,2,3,4: uncovered adjacent, -1 - covered, not yet clicked space
// 4 way neighbors for adjacent mines

#include<iostream>
using namespace std; 

class Board { 
    public:
	char play[6][6]; // char
	int underlying[6][6];  
	int mines; 
	int moveCount; 
	bool lost; 
	Board(){
	    mines = 10;
	    moveCount = 0; 
	    lost = false; 
	    // initialize boards 
	    for(int i=0; i<6; i++)
	    {
		for(int j=0; j<6; j++)
		{
		    play[i][j] = 'x'; 
		    underlying[i][j] = 0; 
		}
	    }
	    setMines();  
	}

	void setMines() {
	    int count = 0;
	    while(count < 10) {
		int row = rand() % 6; 
		int col = rand() % 6; 
		if(underlying[row][col] == 0) {
		     underlying[row][col] = 5; // mine 
		     if(col < 5)  // right
			underlying[row][col+1]++;
		     if(col > 0) // left
			underlying[row][col-1]++;
		     if(row > 0) // up
			underlying[row-1][col]++; 
		     if(row < 5) // down
			underlying[row+1][col]++;  
		     count++;  
		} // endif
	    }//end while
	} 
	void clickBoard(int row, int col) {
	    if(underlying[row][col] == 5) // hit mine
		gameOver();
	    else { 
		play[row][col] =  (char)(underlying[row][col] + '0'); 
		moveCount++; 
	    } 
	}
	void setFlag(int row, int col) {
	    play[row][col] = 'f'; 
	}
	void removeFlag(int row, int col) {
	    if(play[row][col] == 'f')
		play[row][col] = 'x'; 
	    else
		cout << "Invalid move, no flag" << endl;	
	}
	void gameOver() { 
	    cout << "Game Over!" << endl;
	    lost = true; 
	}
	void win() {
	    if(moveCount == 26)	
		cout << "You've won!" << endl; 
	}
	void displayBoard()  {
	    for(int i=0; i<6; i++) {
		for(int j=0; j<6; j++) { 
		     cout << play[i][j] << " ";		
		}
		cout << endl; 
	    }	
	}
}; 

int main() {
    Board minesweeper; 
    while(minesweeper.moveCount < 26 && !minesweeper.lost) {
	minesweeper.displayBoard(); 
	int row, column; 
	cout << "Choose a row and column. Enter 8 to place flag" << endl;
	cin >> row; 
	if(row == 8) {
		cout << "You have chosen to place a flag. Choose a row and column." << endl; 
		cin >> row >> column;
		minesweeper.setFlag(row, column); 	
	}
	else {
	    cin >> column; 
	    minesweeper.clickBoard(row, column);  
	}
    }
    if(minesweeper.moveCount == 26) 
	minesweeper.win(); 
    return 0; 
} 
