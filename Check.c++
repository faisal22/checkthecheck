#include "Check.h"
#include <iostream>
#include <string>
#include <cassert>
#include <vector>


using namespace std;
typedef vector<int> coordinates;

//------------
// check_read()
// reads in gameboard, while checking for empty board with all '..'
// which means that the loop finishes
//------------

bool check_read(std::istream& r, std::ostream& w){
	cout << "calling check_solve.." << endl;
	string temp_line;							// temp to store gameboard line
	bool valid_board = true; 					// check for entry of empty gameboard
	
	int w_king [2] = {-1 , -1};				// location of white king position
	int b_king [2] = {-1, -1} ;				// location of black king position
	vector< coordinates > w_queen;			// location of white queen position
	vector< coordinates > b_queen;			// location of black queen
	vector< coordinates > w_pawn;			// location of white pawn position
	vector< coordinates > b_pawn;			// location of black pawn position
	vector< coordinates > w_knight;			// location of white knight position
	vector< coordinates > b_knight;			// location of black knight position
	vector< coordinates > w_rook;			// location of white rook position
	vector< coordinates > b_rook;			// location of black rook position
 	vector< coordinates > w_bishop;			// location of white bishop position
	vector< coordinates > b_bishop;			// location of black bishop position


	vector< coordinates >* vec_positions [10] = { &b_rook , &b_knight, &b_bishop, &b_queen, &b_pawn, &w_pawn, &w_rook, &w_knight, &w_bishop, &w_queen };


	for(int i = 0; i < 8; i++){					// loop through game board lines
		r >> temp_line;							
		for(int k = 0; k < 8 ; k++){			// loop through pieces
			// check while reading, if piece at k is not a '.' , you're for sure not done with all boards
			
			if(valid_board && temp_line.at(k) != '.'){ valid_board = false; }
			vector <int> tmp;
			tmp.push_back(i); tmp.push_back(k);
			switch(temp_line.at(k)){


				case 'r':							// record position of black rook

					b_rook.push_back(tmp);
					break;

				case 'n':						// record position of black knight
					b_knight.push_back(tmp);
					break;

				case 'b':						// record position of black bishop
					b_bishop.push_back(tmp);
					break;

				case 'q':						// record position of black queen
					b_queen.push_back(tmp);
					break;

				case 'k':						// record position of black king
					// cout << "b_king[1]" << b_king[1] << endl;
					assert(b_king[0]==-1);
					assert(b_king[1]==-1);
					b_king[0] = i;
					b_king[1] = k;
					break;

				case 'p':						// record position of black pawn
					b_pawn.push_back(tmp);
					break;

				case 'Q':						// record position of white queen
					w_queen.push_back(tmp);
					break;

				case 'P':						// record position of white pawn
					w_pawn.push_back(tmp);
					break;
				case 'R':						// record position of white rook
					w_rook.push_back(tmp);
					break;
				case 'B':						// record position of white bishop
					w_bishop.push_back(tmp);
					break;
				case 'N':						// record position of white knight
					w_knight.push_back(tmp);
					break;
				case 'K': 						// record position of white king
					assert(w_king[0]==-1);
					assert(w_king[1]==-1);
					w_king[0] = i;
					w_king[1] = k;
					break;
			}	
			gameboard[i][k] = temp_line.at(k);
		}		
	}
	// assert(r == "\n");
	// temp_line = "";
	// r >> temp_line;
	// cout << "temp_line.size(): " << temp_line << endl;
	// assert(temp_line != "\n");
	// cout << "temp_line.size(): " << temp_line.size() << endl;

	if(!valid_board) {
		print_gameboard(); 
		// cout << "addr of vec_positions: " << (*(vec_positions[white_pawn])).size() << endl;
		check_solve(vec_positions, w_king , b_king); 
	}
	return !valid_board;
}


//------------
// check_solve()
//------------
void check_solve(vector <coordinates>* vec_positions [], int w_king [], int b_king[] ){
	check_valid_board();
	cout << "white king: (" << w_king[0] << "," << w_king[1] << ")" << endl;
	cout << "black king: (" << b_king[0] << "," << b_king[1] << ")" << endl;
	cout << "number of queens: " <<(*(vec_positions[white_queen])).size()  << endl;
	// cout << "addr of vec_positions: " << vec_positions << endl;

	cout << endl;
}

//------------
// check_valid_board()
//------------
void check_valid_board(vector <coordinates>* vec_positions []) {
	assert( (*(vec_positions[black_rook])).size() <= 2  );
	assert( (*(vec_positions[black_knight])).size() <= 2  );
	assert( (*(vec_positions[black_bishop])).size() <= 2  );
	assert( (*(vec_positions[black_queen])).size() <= 1  );
}

//------------
// print_gameboard()
// a simple function to print out gameboard
//------------
void print_gameboard(){
	cout << endl;
	for(int i = 0; i < 8; i++){
		for(int k = 0; k < 8 ; k++){
			cout << gameboard[i][k] << "";
		}		
		cout << endl;
	}
	cout << endl;

}
