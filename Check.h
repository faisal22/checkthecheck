#ifndef Check_h
#define Check_h


// Includes

#include <iostream>
#include <vector>	
typedef std::vector <int> coordinates;
// { &b_rook , &b_knight, &b_bishop, &b_queen, &b_pawn, &w_pawn, &w_rook, &w_knight, &w_bishop, &w_queen };

static int black_rook = 0;
static int black_knight = 1;
static int black_bishop = 2;
static int black_queen = 3;
static int black_pawn = 4;
static int white_pawn = 5;
static int white_rook = 6;
static int white_knight = 7;
static int white_bishop = 8;
static int white_queen = 9;
static int white_king = 10;
static int black_king = 11;

static int NORTH = 1;
static int NORTHEAST = 2;
static int EAST = 3;
static int SOUTHEAST = 4;
static int SOUTH = 5;
static int SOUTHWEST = 6;
static int WEST = 7;
static int NORTHWEST = 8;
static char gameboard [8][8];

static std::vector <int> black_king_coords;
static std::vector <int> white_king_coords;


bool check_read(std::istream&, std::ostream&);

void print_gameboard();

void check_solve(std::vector <coordinates>* []);

void check_valid_board(std::vector <coordinates >* []) ;

int check_piece_dir(std::vector <int>);

bool check_queen(std::vector <coordinates>);

int* get_target_king(std::vector <int>);

#endif // Check_h	