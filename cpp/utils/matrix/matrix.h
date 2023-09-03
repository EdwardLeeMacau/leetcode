#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>

template <class T>
class Matrix 
{
public:

    Matrix()
    {

    }
    Matrix(T val, int numRows, int numCols)
    {

    }
    ~Matrix()
    {

    }

    T& operator() (int row, int col)
    {

    }
    const T& operator() (int row, int col) const
    {

    }

    void resize(int numRows, int numCols)
    {

    }
    int width() const 
    {

    }
    int height() const
    {

    }

private:

    std::vector<std::vector<T>> grid;
};

#endif /* !MATRIX_H_ */
