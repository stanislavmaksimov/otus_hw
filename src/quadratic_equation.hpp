#include <limits>
#include <math.h>
#include <stdexcept>
#include <vector>
#include <type_traits>

template <typename T, std::enable_if_t<std::is_floating_point<T>::value, bool> = true>
std::vector<T> solve(T a, T b, T c)
{
    constexpr const T epsilon = std::numeric_limits<T>::epsilon();
    constexpr const T rate_2 { 2 };
    constexpr const T rate_4 { 4 };

    if (abs(a) < epsilon) { // A = 0
        throw std::invalid_argument("'a' can't be zero");
    }
    
    const auto discriminant = b*b - rate_4*a*c;
    if (discriminant > epsilon) { // D > 0
        return {
            (-b + sqrt(discriminant)) / (rate_2*a),
            (-b - sqrt(discriminant)) / (rate_2*a)
        };
    } else if (abs(discriminant) < epsilon) { // D = 0
        return { -b/(rate_2*a) };
    }
    return {};
}

template <typename T, typename TT = typename std::enable_if<!std::is_floating_point<T>::value>::type>
std::vector<T> solve(T a, T b, T c)
{
    throw std::invalid_argument("non floating point type");
}
