#include <iostream>


// class bool {
    
// };

class C {
public:
private:
    int val{0};
    // int val = 0; - OK
    // int val(0) - Error
};


void if_cond() {
    std::cout << "IF_COND\n";
    if (int x = std::rand()) {
        std::cout << (x > 0) << " " << x;
    } else {
        std::cout << (x > 0) << " " << x;
    }
    std::cout <<"IF_INIT_AND_EXPR\n";
    /**
    if (int x = std::rand(); x = (x > 0)) {
        std::cout << "X is Positive!\n";
    } else {
        std::cout << "X is Non-Positive!\n";
    }
    */
}

void auto_with_tuple() {
    std::tuple<int, int&> f();
    // const auto [x, y] = f();
    // x = const int, y = int&

    std::tuple<const int, int> f1();
    // const auto [x, y] = f1();
}

void int_inits() {
    int x = (1, 2, 3, 4, 5);
    std::cout << "*********************\n"
        << "Int Initializations:\n";
    std::cout << x << "\n";
    int y(0);
    std::cout << y << "\n";
    std::cout << "\n*********************\n";
}

int main() {
    if_cond();
    int_inits();

    return 0;
}