#include <iostream>
#include "vector2.hpp"

int main()
{
    Vector2d<double> vec1{}, vec2{};

    // reading in two vectors from terminal
    std::cout << "Enter vector 1:\n";
    std::cin >> vec1;
    std::cout << "Enter vector 2:\n";
    std::cin >> vec2;

    std::cout << "---------------------------------\n";

    // addition of two vectors
    Vector2d<double> sum = operator+(vec1, vec2);
    std::cout << "vector1 + vector2 = " << sum << "\n";

    std::cout << "---------------------------------\n";

    // subtraction of two vectors
    Vector2d<double> sub = operator-(vec1, vec2);
    std::cout << "vector1 - vector2 = " << sub << "\n"; 

    std::cout << "---------------------------------\n";

    // multiplying the two vectors with a scalar
    double scalar;
    std::cout << "Enter a scalar:\n";
    std::cin >> scalar;

    Vector2d<double> scalar_mult1 = scalar_mult(vec1, scalar);
    Vector2d<double> scalar_mult2 = scalar_mult(vec2, scalar);
    std::cout << "scalar * vector1 = " << scalar_mult1 << "\n";
    std::cout << "scalar * vector2 = " << scalar_mult2 << "\n";

    std::cout << "---------------------------------\n";

    // dot product
    double dot_prod = dot(vec1, vec2);
    std::cout << "dot product of vector1 and vector2 = " << dot_prod << "\n";

    std::cout << "---------------------------------\n";

    // length
    double length1 = length(vec1);
    double length2 = length(vec2);
    std::cout << "length of vector1 = " << length1 << "\n";
    std::cout << "length of vector2 = " << length2 << "\n";

    std::cout << "---------------------------------\n";

    // squared lenth
    double sqlength1 = sqlength(vec1);
    double sqlength2 = sqlength(vec2);
    std::cout << "squared length of vector1 = " << sqlength1 << "\n";
    std::cout << "squared length of vector2 = " << sqlength2 << "\n";

    std::cout << "---------------------------------\n";

    // normalized vectors
    Vector2d<double> norm1 = normalize(vec1);
    Vector2d<double> norm2 = normalize(vec2);
    std::cout << "vector1 normalized = " << norm1 << "\n";
    std::cout << "vector2 normalized = " << norm2 << "\n";





    return 0;
}