#include <iostream>
#include <fstream>

#include "hw3.hpp"

using std::cout;
using std::endl;


/*
    |0.01 error for the integration methods|

Max of abs(f''(x)) at [0, 200] -> M = 0.00216214
Max of abs(f''''(x)) at [0, 200] -> M_4 = 0.00000000864858

- Midpoint: (0.00216214 * 200^3) / (24 * n^2) = 0.01 -> n = 269
- Trapezoidal: (0.00216214 * 200^3) / (12 * n^2) = 0.01 -> n = 380
- 1/3 Simpson's: (200^5) / (2880 * n^4) * 0.00000000864858 = 0.01 -> n = 4

*/


// simple test function to check goodness of integrations
double function(double x) 
{
    return x * x;
}


int main()
{
    std::ofstream ofile ("output.txt");

    if (ofile.is_open())
    {
        ofile << "Midpoint integral:\tTrapezoidal integral:\tSimpson's 1/3 rule:" << endl;
        ofile << midpoint_integral(arc, 0.0, 200.0, 269) << ",\t\t\t";
        ofile << trapezoidal_integral(arc, 0.0, 200.0, 380) << ",\t\t\t\t";
        ofile << simpson_integral(arc, 0.0, 200.0, 4);
        ofile.close();
    }

    return 0;
}