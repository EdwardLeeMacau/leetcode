#include "subrectangle.h"

#include <iostream>

using namespace std;

SubrectangleQueries::SubrectangleQueries(vector<vector<int> >& rectangle): rect(&rectangle)
{

}

void SubrectangleQueries::updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
{
	int row, col;

	for (row = row1; row <= row2; ++row) {
		for (col = col1; col <= col2; ++col) {
			(*rect)[row][col] = newValue;
		}
	}
}

int SubrectangleQueries::getValue(int row, int col)
{
	return (*rect)[row][col];
}
