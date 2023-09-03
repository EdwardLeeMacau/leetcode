#ifndef SUBRECTANGLE_H_
#define SUBRECTANGLE_H_

#include <unistd.h>
#include <vector>

class SubrectangleQueries 
{
public:
    SubrectangleQueries(std::vector<std::vector<int> >& );
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue);
    int getValue(int row, int col);

	std::vector<std::vector<int> > *rect;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */

#endif /* !SUBRECTANBLE_H_ */
