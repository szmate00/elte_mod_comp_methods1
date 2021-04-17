#include <iostream>
#include <fstream>
#include <math.h> 

#include "hw4.hpp"
 

double func(double t, double y)
{
    return 1 + y * y;
}


int main()
{
    double y0 = 0.0;
    double t0 = 0.0;
    double t1 = 1.0;
    double h = 0.002;


    double anal = tan(t1);
    double y_Newton = solve_Newton(y0, t0, t1, h, func);
    double y_rk4 = solve_rk4(y0, t0, t1, h, func);

    std::ofstream ofile ("output.txt");

    if (ofile.is_open())
    {
        ofile << "Analitic solution\tNewton method\tRunge-Kutta" << std::endl;
        ofile << anal << "\t\t\t\t" << y_Newton << "\t\t\t" << y_rk4;

        ofile.close();
    }


    return 0;
}