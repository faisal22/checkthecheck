#ifndef Check_h
#define Check_h


// Includes

#include <iostream>
#include <vector>

static char gameboard [8][8];


bool check_read(std::istream&, std::ostream&);

void print_gameboard();

void check_solve(int [], int [] );

#endif // Check_h	