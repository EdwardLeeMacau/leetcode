#ifndef RANDPOINT_H_
#define RANDPOINT_H_

#include <vector>

class Solution {
public:
    Solution(double radius, double x_center, double y_center);
    std::vector<double> randPoint();
private:
    double _r, _x_center, _y_center;
};

#endif /* !SOLUTION_H_ */
