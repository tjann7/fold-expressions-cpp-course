#include <iostream>


int sum(int x) {
    return x;
}

int sum(int x, int y) {
    return x + y;
}

int sum(int x, int y, int z) {
    return x + y + z;
}

/**
 * Folding can be used along with other function overridings
 */

template<typename... Args>
int sum(Args... args)
{
    return (args + ...);
}

int sum() {
    return 0;
}

/**
 * Unary Right Fold / Unary Left Fold
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

/**
 * Binary Left Fold / Binary Right Fold
 */

template<class... Args>
int subtract_left_fold(Args... args) {
    return (10 - ... - args);
}

template<class... Args>
int subtract_right_fold(Args... args) {
    return (args - ... - 10);
}

/**
 * Printer example + Reverse Printer
 */

template<typename... Args>
void printer_left(Args&&... args) {
    (std::cout << ... << args) << '\n';
}

template<typename Last>
void print_right(Last&& last) {
    std::cout << last;
}

template<typename First, typename... Rest>
void print_right(First&& first, Rest&&... rest) {
    print_right(rest...);
    std::cout << first;
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

    int a = 1, b = 2, c = 3, d = 4;

    printer_left(a, b, c, d);
    print_right(a, b, c, d);
}
