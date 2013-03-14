#ifndef Check_h
#define Check_h


// Includes

#include <iostream>
#include <vector>	
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

static char gameboard [8][8];


bool check_read(std::istream&, std::ostream&);

void print_gameboard();

void check_solve(std::vector <std::vector <int> >* [], int [], int [] );

#endif // Check_h	