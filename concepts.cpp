/*
 * This example uses:
 *      Template specializations
 *      Concepts
 *      Constraints (requires)
 *      Fold expressions
 */
#include <iostream>
#include <utility>

template <int T>
struct FizzBuzz {
    static constexpr int value = T;
};

template<int T>
concept DivisibleByThree = (T % 3 == 0);

template<int T>
concept DivisibleByFive = (T % 5 == 0);

template <int T>
requires DivisibleByThree<T>
struct FizzBuzz<T> {
    static constexpr const char * value = "Fizz";
};

template <int T>
requires DivisibleByFive<T>
struct FizzBuzz<T> {
    static constexpr const char * value = "FizzBuzz";
};

template <int T>
requires DivisibleByThree<T> && DivisibleByFive<T>
struct FizzBuzz<T> {
    static constexpr const char * value = "FizzBuzz";
};


template<typename T, T... ints>
void print(std::integer_sequence<T, ints...> int_seq)
{
    ((std::cout << FizzBuzz<ints>::value << ' '), ...);
    std::cout << '\n';
}

int main() {
    print(std::make_integer_sequence<int, 100>());
    return 0;
};
