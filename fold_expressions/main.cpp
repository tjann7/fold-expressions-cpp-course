#include <iostream>

/**
 * A C++17 feature
 * 
 * 1) Unary Left Fold Expression
 */

template<typename... Args>
auto all(Args... args) { return (... + args); }

bool bool_left = all(true, true, true, false);
int b = all(1, 2, 3, 4);
// within all(), the unary left fold expands as
//  return ((true && true) && true) && false;
// b is false

template<typename... Args>
auto all_right(Args... args) { return (args + ...); }

bool bool_right = all_right(true, true, true, false);
int b_right = all_right(1, 2, 3, 4);
// within all(), the unary left fold expands as
//  return ((true && true) && true) && false;
// b is false




/**
 * Why do we need it?
 */


int sum(int x) {
    return x;
}

int sum(int x, int y) {
    return x + y;
}

int sum(int x, int y, int z) {
    return x + y + z;
}


template<typename... Args>
int sum(Args... args)
{
    return (args + ...);
}

int sum() {
    return 0;
}

/**
 * Types of Fold Expressions
 * 
 */

class my_int {
public:
    my_int(int value) {
        this->value = value;
    }
    int value;
};

int operator+ (my_int v1, my_int v2) {
    std::cout << "Iteration... left=" << v1.value << " right=" << v2.value << "\n";
    if (v1.value > 5) {
        std::cout << "\nMax value already exceeded - " << v1.value << "\n";
        return v1.value;
    }
    v1.value += v2.value;
    return v1.value;
}

template<typename... Args>
int sum_left_fold(Args... args)
{
    return (... + args);
}

template<typename... Args>
int sum_right_fold(Args... args)
{
    return (args + ...);
}

template<typename... Args>
auto check(Args&&... args) {
    std::cout << ... << args;
}

int main() {
    my_int v1(1), v2(2), v3(3), v4(4), v5(5);
    std::cout << "Left Folding...\n";
    std::cout << sum_left_fold(v1, v2, v3, v4, v5) << "\n";
    std::cout << "Right Folding...\n";
    std::cout << sum_right_fold(v1, v2, v3, v4, v5) << "\n";
}
