#include <ostream>
#include <istream>
#include <math.h> 

// defining vector struct with two elements
template<typename T>
struct Vector2d
{
    T x, y;

    Vector2d<T>& operator+=( Vector2d const& vec)
    {
        x += vec.x;
        y += vec.y;
        return *this;
    }
};

// defining addition operation
template<typename T>
Vector2d<T> operator+( Vector2d<T> const& a, Vector2d<T> const& b)
{
    return Vector2d<T>{ a.x + b.x, a.y + b.y};
}

// defining subtraction operation
template<typename T>
Vector2d<T> operator-( Vector2d<T> const& a, Vector2d<T> const& b)
{
    return Vector2d<T>{ a.x - b.x, a.y - b.y};
}

// multiplication with scalar value
template<typename T>
Vector2d<T> scalar_mult( Vector2d<T> const& a, double const& b)
{
    return Vector2d<T>{ b * a.x, b * a.y};
}

// dot product
template<typename T>
T dot( Vector2d<T> const& a, Vector2d<T> const& b)
{
    return a.x * b.x + a.y * b.y;
}

// length
template<typename T>
T length( Vector2d<T> const& a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

// length
template<typename T>
T sqlength( Vector2d<T> const& a)
{
    return a.x * a.x + a.y * a.y;
}

// normalization
template<typename T>
Vector2d<T> normalize( Vector2d<T> const& a)
{
    return Vector2d<T>{a.x / length(a), a.y / length(a)};
}

// writing out
template<typename T>
std::ostream& operator<<( std::ostream& out, Vector2d<T>& vec )
{
    out << "(" << vec.x << ", " << vec.y << ")";
    return out;
}

// reading in
template<typename T>
std::istream& operator>>( std::istream& in, Vector2d<T>& vec )
{
    in >> vec.x;
    in >> vec.y;
    return in;
}