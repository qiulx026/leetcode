// ConsoleApplication7.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

class Board {							//For each game, there is only one Board object. 
public: 
	void show();						//To show the board
	int  judge();						//judge whether game is over, return 1 when there is a winner, return 0 when draw, return -1 when the game is not over
	bool validmove(int i);				//check the step player(or computer) want to place is valid or not
	void move(char ch,int i);			//after check that the step is valid, the board could do the step.
	void initiate();
private:								//stand for the board
	vector <char> myboard; 
};

class player {                               //a class for player
public:
	char getmark(){                          //get player's mark
		return 'o';
	}
	int pick(){                              //get a step the player want to move			
		cout << "Player  enter a number:  "; 
		cin >> move_index;
		return move_index;
	}
private:
	int move_index;
};

class computer {							//a class for computer
public:
	char getmark(){							//get player's mark
		return 'x';
	}
	int pick(){								//get a random step from 1 to 9
		move_index = rand() % 9 +1;
		return move_index;
	}
private:
	int move_index;
};



int main()
{
	Board board;
	board.initiate();
	board.show();
	player you;											//player
	computer com;										//computer
	int stopat=0;										//a mark that stands for who goes the last one step when game is stop(to judge who is winner)
	int move_step;										//move step number
	char mark;											//player or computer's mark('o' or 'x')
	char who_first=0;									// stands for who is first, 'y' for computer, others for player
	cout << "Computer first? y/n\n"; 
	cin >> who_first;
	if(who_first=='y'){                               //if computer is first, then computer goes a step before the while loop
		mark=com.getmark();
		move_step=com.pick();
		while(board.validmove(move_step)==false){
			move_step=com.pick();
		}
		board.move(mark,move_step);	
	}
	while(board.judge()==-1){                           // while loop, end when there is winner or no step to go
		board.show();
		mark=you.getmark();								//player goes first
		move_step=you.pick();
		while(board.validmove(move_step)==false){       //while loop to get a valid move step
			cout<<"invalid number"<<endl;
			move_step=you.pick();
		}
		board.move(mark,move_step);
		if(board.judge()!=-1)  {stopat=1;break;}			//judge after player goes
		else {
			mark=com.getmark();								//computer goes 
			move_step=com.pick();
			while(board.validmove(move_step)==false){       //while loop to get a valid move step
				move_step=com.pick();
			}
			board.move(mark,move_step);		
		}
	}
	board.show();
	if(board.judge()==0) cout<<"you and computer get a draw"<<endl;
	if(board.judge()==1&&stopat==1) cout<<"congratulation! you win!"<<endl;
	if(board.judge()==1&&stopat==0) cout<<"sorry, computer win."<<endl;
	return 0;
}

int Board::judge()                //check every row,colon and diagonal， if there is winner, return 1;if every step is full, return 0;else return -1.
{
	if (myboard[0] == myboard[1] && myboard[1] == myboard[2])

		return 1;
	else if (myboard[3] == myboard[4] && myboard[4] == myboard[5])

		return 1;
	else if (myboard[6] == myboard[7] && myboard[7] == myboard[8])

		return 1;
	else if (myboard[0] == myboard[3] && myboard[3] == myboard[6])

		return 1;
	else if (myboard[1] == myboard[4] && myboard[4] == myboard[7])

		return 1;
	else if (myboard[2] == myboard[5] && myboard[5] == myboard[8])

		return 1;
	else if (myboard[0] == myboard[4] && myboard[4] == myboard[8])

		return 1;
	else if (myboard[2] == myboard[4] && myboard[4] == myboard[6])

		return 1;
	else if (myboard[0] != '1' && myboard[1] != '2' && myboard[2] != '3' 
		&& myboard[3] != '4' && myboard[4] != '5' && myboard[5] != '6' 
		&& myboard[6] != '7' && myboard[7] != '8' && myboard[8] != '9')
		return 0;
	else
		return -1;
}


void Board::show(){
	system("cls");
	cout << "Lianxiao Qiu's Game";

	cout << "\nYou (o)  -  Computer (x)\n"<< endl;

	cout << "\t*\t*\t" << endl;
	cout << "   " << myboard[0] << "\t*   " << myboard[1] << "\t*   " << myboard[2] << endl;

	cout << "\t*\t*\t" << endl;
	cout << "* * * * * * * * * * * * *" << endl;
	cout << "\t*\t*\t" << endl;

	cout << "   " << myboard[3] << "\t*   " << myboard[4] << "\t*   " << myboard[5] << endl;

	cout << "\t*\t*\t" << endl;
	cout << "* * * * * * * * * * * * *" << endl;
	cout << "\t*\t*\t" << endl;

	cout << "   " << myboard[6] << "\t*   " << myboard[7] << "\t*   " << myboard[8] << endl;

	cout << "\t*\t*\t" << endl;
}


bool Board::validmove(int i){
	char ch=(char)i+48;
	if(ch==myboard[i-1]) return true;  					//if myboard[index] hasn't been changed, it is valid  
	else return false;
}
void Board::initiate(){                    //initiate the borad vector<char> myboard
	for(int i=0;i<9;i++){
		myboard.push_back(i+49);
	}
}
void Board::move(char ch,int i){						//change myboard[index] to mark(player's or computer's)
	myboard[i-1]=ch;
}