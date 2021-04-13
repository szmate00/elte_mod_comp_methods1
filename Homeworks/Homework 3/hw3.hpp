#include <iostream>
#include <cmath> 

using std::cosh;


// parameters
const int F = 900;           // N
const double q = 1.8;        // N/m
const int a = 200;           // m
const int height = 35;           // m


// Hyperbolic function describing the shape of the cable
double func(double x)
{
    return F / q * (cosh(q / F * x) - cosh( (q * a) / (2 * F)) + height);
}

// 2nd order Richardson
template <typename T> 
T D(T x, double h){ return (func(x + h) - func(x - h)) / (2 * h); }

// 4th order Richardson
template <typename T> 
T S(T x, double h) { return (4 * D(x, h) - D(x, 2 * h)) / 3; }

// 6th order Richardson
template <typename T> 
T Richardson_6th(T x)
{   
    double h = 1;

    return (16 * S(x, h) - S(x, 2 * h)) / 15;
}

// Arc (sqrt(1 + f'(x)^2))
double arc(double x)
{ 
    double f_diff = Richardson_6th(x);

    return sqrt(1 + (f_diff * f_diff));
}


// Midpoint/rectangle integration
template <typename T> 
T midpoint_integral(T (*f)(T x), double a, double b, int n)
{
    T integral;

    double step = (b - a) / n;

    for (int i = 0; i < n; ++i)
    {
        integral += f(a + (i + 0.5) * step);
    }

    return step * integral;
}


// Trapezoidal integration
template <typename T>
T trapezoidal_integral(T (*f)(T x), double a, double b, int n)
{
    double step = (b - a) / n;

    T integral = (f(a) + f(b)) / 2;

    for (int i = 0; i < n; ++i)
    {
        integral += f(a + i * step);
    }

    return step * integral;
}


// Simpson's 1/3 rule
template <typename T>
T simpson_integral(T (*f)(T x), double a, double b, int n)
{   
    T odd_sum = 0;
    T even_sum = 0;

    double step = (b - a) / n;
    double lim = n / 2;

    T integral = (f(a) + f(b));

    for(int i = 1; i <= lim; i++)
    {
      odd_sum += f(a + (2 * i - 1) * step);
    }

    odd_sum *= 4;


    for(int i = 1; i < lim; i++)
    {
      even_sum += f(a + (2 * i) * step);
    }

    even_sum *= 2;


    integral += odd_sum + even_sum;
    integral *= step / 3;

    return integral;
}



