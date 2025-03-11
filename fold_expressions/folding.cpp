#include <iostream>


/**
 * Folding and Fold Expressions
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

template<class... Args>
int subtract_left_fold(Args... args) {
    return (10 - ... - args);
}

template<class... Args>
int subtract_right_fold(Args... args) {
    return (args - ... - 10);
}

int main() {
    my_int v1(1), v2(2), v3(3), v4(4), v5(5);
    std::cout << "Left Folding...\n";
    std::cout << sum_left_fold(v1, v2, v3, v4, v5) << "\n";
    std::cout << "Right Folding...\n";
    std::cout << sum_right_fold(v1, v2, v3, v4, v5) << "\n";

    // Binary Subtracting
    std::cout << "Left Folding...\n";
    std::cout << "Left Folding... " << subtract_left_fold(1, 2, 3, 4, 5);
    std::cout << subtract_left_fold(1, 2, 3, 4, 5) << "\n";
    std::cout << "Right Folding...\n";
    std::cout << subtract_right_fold(1, 2, 3, 4, 5) << "\n";
}
