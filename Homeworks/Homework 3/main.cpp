#include <iostream>
#include <fstream>

#include "hw3.hpp"

using std::cout;
using std::endl;


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
        ofile << "Midpoint integral: " << midpoint_integral(arc, 0.0, 200.0, 269) << ",\t";
        ofile << "Trapezoidal integral: " <<trapezoidal_integral(arc, 0.0, 200.0, 380) << ",\t";
        ofile << "Simpson's 1/3 rule: " << simpson_integral(arc, 0.0, 200.0, 4);
        ofile.close();
    }

    return 0;
}