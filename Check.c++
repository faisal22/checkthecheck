#include "Check.h"
#include <iostream>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <stdio.h>
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
	check_valid_board(vec_positions);				// Check to make sure all pieces on the board are valid
	// cout << "\nwhite king: (" << w_king[0] << "," << w_king[1] << ")" << endl;
	// cout << "black king: (" << b_king[0] << "," << b_king[1] << ")" << endl;
	// cout << "number of queens: " <<(*(vec_positions[black_queen])).size()  << endl;

	check_queen(*(vec_positions[black_queen]) , w_king, b_king);	
	check_queen(*(vec_positions[white_queen]) , w_king, b_king);	


 	cout << endl;
}

//------------
// check_valid_board()
//------------
void check_valid_board(vector <coordinates>* vec_positions []) {
	cout << "calling check_valid_board()" << endl;

	// Check to see that the board is valid for black and white pieces
	assert( (*(vec_positions[black_rook])).size() <= 2  );	
	assert( (*(vec_positions[black_knight])).size() <= 2  );
	assert( (*(vec_positions[black_bishop])).size() <= 2  );
	assert( (*(vec_positions[black_queen])).size() <= 1  );
	assert( (*(vec_positions[black_pawn])).size() <= 8  );

	assert( (*(vec_positions[white_pawn])).size() <= 8);
	assert( (*(vec_positions[white_rook])).size() <= 2);	
	assert( (*(vec_positions[white_knight])).size() <= 2);	
	assert( (*(vec_positions[white_bishop])).size() <= 2);
	assert( (*(vec_positions[white_queen])).size() <= 2);

\
}
//------------
// check_queen_position
//------------
bool check_queen(vector <coordinates> queen_coords, int w_king[] , int b_king[] ){
	if(queen_coords.size()!=0){								// Check if there is a queen on the board
		assert(queen_cords.size == 1);						// Make sure there is only 1 queen
		cout << "calling check_queen().." << endl;

		int temp_i = queen_coords.at(0).at(0);
		int temp_j = queen_coords.at(0).at(1);
		int target_king [2] = { get_target_king(queen_coords, w_king, b_king)[0] , get_target_king(queen_coords, w_king, b_king)[1] };

		switch(check_piece_dir(queen_coords, w_king, b_king)){
			case 1:			
				// King is N of this queen
				cout << "king is N of queen" << endl;
				--temp_i;
 				while(gameboard[temp_i][temp_j] == '.' && temp_i != target_king[0] && temp_i > -2){
					--temp_i;					
				}
				break;
			case 2:			
				// King is NE of queen
				cout << "king is NE of queen" << endl;
				--temp_i;
				++temp_j;
 				while(gameboard[temp_i][temp_j] == '.' && temp_i != target_king[0] && temp_j != target_king[1] && temp_i > -1 && temp_j < 9){
					--temp_i;	
					++temp_j;				
				}
				break;

			case 3:			
				// King is E of queen
				cout << "king is E of queen" << endl;
				++temp_j;
				while(gameboard[temp_i][temp_j] == '.' && temp_j < 9){
					++temp_j;
				}
				break;

			case 4:			
				// King is SE of queen
				cout << "King is SE of queen" << endl;
				++temp_i;
				++temp_j;
				while(gameboard[temp_i][temp_j] == '.' && temp_j < 9 && temp_i < 9){
					++temp_j;
					++temp_i;
				}
				break;

			case 5:
				// King is S of queen
				cout << "king is S of queen" << endl;
				++temp_i;
 				while(gameboard[temp_i][temp_j] == '.' && temp_i != target_king[0] && temp_i < 9){
					temp_i++;					
				}
				break;

			case 6:			
				// King is SW of queen
				cout << "King is SW of queen" << endl;
				++temp_i;
				--temp_j;
				while(gameboard[temp_i][temp_j] == '.' && temp_j > -1 && temp_i < 9){
					++temp_i;
					--temp_j;
				}
				break;

			case 7:			
				// King is W of queen
				cout << "King is W of queen" << endl;
				--temp_j;
				while(gameboard[temp_i][temp_j] == '.' && temp_j > -1){
					--temp_j;
				}
				break;

			case 8:			
				// King is NW of queen
				cout << "King is NW of queen" << endl;
				--temp_i;
				--temp_j;
				while(gameboard[temp_i][temp_j] == '.' && temp_j < 9 && temp_i > -1){
					--temp_i;
					--temp_j;
				}
				break;
			default:
				cout << "Error. Invalid direction." << endl;
				exit(0);
				break;	
		}
		if(temp_i == target_king[0] && temp_j == target_king[1]){
			cout << "there was a check" << endl;
			// return false;
		}
		else{
			cout << "there is no check" << endl;
		}
	}
	return true;		
}
//------------
// get_target_king()
//------------
int* get_target_king(vector <coordinates> piece_coords, int w_king[] , int b_king[]){
	// cout << "calling get_target_king" << endl;
	int target_king[2] = {-1,-1};
	// Set target king according to piece color
	if(isupper(gameboard[piece_coords.at(0).at(0)][piece_coords.at(0).at(1)])){
		// cout << "checking white piece.." << endl;
		target_king[0] = b_king[0];
		target_king[1] = b_king[1]; }
	else if(islower(gameboard[piece_coords.at(0).at(0)][piece_coords.at(0).at(1)])){
		// cout << "checking black piece.." << endl;
		target_king[0] = w_king[0];
		target_king[1] = w_king[1]; }
	/*else{
		cout << "Error. Unknown piece detected." << endl;
		exit(0); }*/

	return target_king;
}

//------------
// check_piece_dir()
//------------
int check_piece_dir(vector <coordinates> piece_coords, int w_king[] , int b_king[] ){
	if(piece_coords.size() != 0){
		int target_king [2] = {-1 , -1};							// Which king to check?


		// TO_DO: ADD TRY CATCH FOR EXCEPTION.


 		target_king[0] = get_target_king(piece_coords, w_king, b_king)[0];
 		target_king[1] = get_target_king(piece_coords, w_king, b_king)[1];

 		// cout << "piece: (" << piece_coords.at(0).at(0) << "," << piece_coords.at(0).at(1) << ")" << endl;
 		// cout << "target king: (" << target_king[0] << "," << target_king[1] << ")" << endl;

 		// TO_DO: Encapsulate this logic into one function which would check the direction of a piece given the coordinates. Such function would return a number 1 - 8 which represent a compass direction starting from North (N, NE, E, SE, S, SW, W, NW) in which the king resides

 		//Logic to determine the relative position fo the piece with the king on the board
 		if(piece_coords.at(0).at(0) > target_king[0]){
 			// cout << "The king is above the piece on the board" << endl;
 			if(piece_coords.at(0).at(1) > target_king[1]){
 				// cout << "The king is to the left of the piece" << endl;
 				// . . . K
 				// . . .
 				// . .
 				// Q
 				return NORTHWEST;

 			}
 			else if (piece_coords.at(0).at(1) < target_king[1]){
 				// cout << "The king is to the right of the piece" << endl;
 				// . . . K
 				// . . .
 				// . .
 				// Q
 				return NORTHEAST;
 			}
 			else{
 				// cout << "The king is vertical to the piece" << endl;
 				// K
 				// .
 				// .
 				// Q
 				return NORTH;
 			}
 		}
 		else if(piece_coords.at(0).at(0) < target_king[0]){
 			   // cout << "The king is lower than the piece on the board" << endl;
 			if(piece_coords.at(0).at(1) > target_king[1]){
 				// cout << "The king is to the left of the piece" << endl;
 				// . . . Q
 				// . . .
 				// . .
 				// K
 				return SOUTHWEST;
 			}
 			else if (piece_coords.at(0).at(1) < target_king[1]){
 				// cout << "The king is to the right of the piece" << endl;
  				// Q
 				// . . 
 				// . . .
 				// . . . K
 				return SOUTHEAST;
 			}
 			else{
 				// cout << "The king is vertical to the piece" << endl;
 				// Q
 				// .
 				// .
 				// K
 				return SOUTH;
 			}
 		}
 		else{
 			// cout << "The king is horizontal to the piece on the board" << endl;
  			if(piece_coords.at(0).at(1) > target_king[1]){
 				// cout << "The king is to the left of the piece" << endl;
 				// K . . . Q
 				return WEST;
 				 
 			}
 			else if (piece_coords.at(0).at(1) < target_king[1]){
 				// cout << "The king is to the right of the piece" << endl;
  				// Q . . . K
  				return EAST;
 			}
 		}

	}
	return false;
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
