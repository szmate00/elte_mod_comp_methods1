#include <iostream>

// func: Function to find the root of
// func_dot: Derivative of the function
// x0: Initial guess
// tolerance: Stopping when the result is within tolerance
// epsilon: f'(x) is considered as 0 if < epsilon
template<typename F, typename F_dot, typename T>
T Newton(F func, F_dot func_dot, T x0, double tolerance, double epsilon)
{
    double x1 = x0 - func(x0) / func_dot(x0);
    int conv = 1;
    while (abs(x0-x1) > epsilon)
    {
        x0 = x1;
        x1 = x0 - func(x0) / func_dot(x0);

        // if f'(x1) is too small we break the loop to avoid division by zero
        if (func_dot(x1) < epsilon)
        {
            conv = 0;
            break;
        }
    }

    if (conv = 1){ return x1; }

    else 
    {
        std::cout << "Error, derivative zero!\n";
        return 0;
    }
}

int main()
{
    double x0 = 10.0;
    double tolerance = 0.005;
    double epsilon = 0.0000000000001;

    std::cout << Newton([](double x){return x*x - 612.0;}, [](double x){return 2.0*x;}, x0, tolerance, epsilon);

    return 0;
}