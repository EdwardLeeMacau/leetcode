#include "randPoint.h"

#include <math.h>

Solution::Solution(double radius, double x_center, double y_center): 
    _r(radius), _x_center(x_center), _y_center(y_center)
{

}

/**
 * @brief Template of the solution
 * @score (runtime / memory) (00.00% / 00.00%)
 * @time-complexity O(N). N stands for something
 * @space-complexity O(M). M stands for something
 */
std::vector<double> Solution::randPoint()
{
    std::vector<double> point(2, 0);
    double theta;
    
    theta = rand() / RAND_MAX * 2 * M_PI;
    point[0] = cos(theta) * _r + _x_center;
    point[1] = sin(theta) * _r + _y_center;

    return point;
}
