#include <iostream>


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

void foo(int&& a) {
    std::cout << a << "\n";
    a = 10;
}

template<typename R>
void func(R&& a) {
    std::cout << a << "\n";
}


int main() {
    int a = 1, b = 2, c = 3, d = 4;
    foo(5);
    func(b);

    printer_left(a, b, c, d);
    print_right(a, b, c, d);
}
