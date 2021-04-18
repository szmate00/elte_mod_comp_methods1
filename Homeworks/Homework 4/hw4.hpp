#include <iostream>

// Newton method for first order differential equations
template<typename State, typename T, typename RHS>
auto solve_Newton(State y0, T t0, T t1, T h, RHS f)
{
    T t = t0;
    State y = y0;

    while (t < t1)
    {
        y = y + h * f(t, y);
        t = t + h;
    }
    return y;
}

// megj.: meg akartam csinálni a Runge-Kutta-Fehlberget is, de nem volt lelkierőm begépelni :((

// Runge-Kutta method
template<typename State, typename T, typename RHS>
auto solve_rk4(State y0, T t0, T t1, T h, RHS f)
{
    T t = t0;
    State y = y0;

    while (t < t1)
    {
        if (t + h > t1)
        {
             h = t1 - t;
        }

        State k1 = f(t, y);
        State k2 = f(t + h * (T)0.5, y + (h * (T)0.5) * k1);
        State k3 = f(t + h * (T)0.5, y + (h * (T)0.5) * k2);
        State k4 = f(t + h, y + h * k3);

        y = y + (k1 + k4 + (T)2 * (k2 + k3)) * (h / (T)6);
        t = t + h;
    }
    return y;
}