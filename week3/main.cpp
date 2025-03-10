#include <iostream>

class C {
public:
    int a;
    C(int i) { a = i; }
    operator bool() { return a == 0; }
};

class B;

// class A {
// public:
// /*
// Declaration and Definition
// distinction between the two in C++ language
// */
//     int val;
//     const int x;
//     A(int b) {
//         val = b;
//         // x(3);
//     }
//     A (B& b) {
//         val = b.val;
//         x = x(3);
//     }
// };

// class B {
// public:
//     int val;
//     A operator()(A a) { return A(val); }
// };

// int main() {
//     C c(1);
//     bool b = c;
    
// }