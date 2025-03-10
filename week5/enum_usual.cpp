#include <iostream>

enum Day { // Compiler does not see this is different type
    // Unscoped Enumeration
    Sunday,
    Monday,
    Tuesday
};

enum Month { // Compiler does not see this is different type
    // Unscoped Enumeration
    January,
    February,
    Match
};

enum class CorrectDay { // Compiler does not see this is different type
    // Scoped Enumeration
    Sunday,
    Monday,
    Tuesday
};

enum class CorrectMonth { // Compiler does not see this is different type
    // Scoped Enumeration
    January,
    February,
    Match
};

void test_compareEnums() {
    Day day = Monday;
    Month month = February;
    // day == month  incorrect enum comparison
    CorrectDay correctDay = CorrectDay::Monday;
    CorrectMonth correctMonth = CorrectMonth::February;
    // correctDay == correctMonth   no operators match this comparison
}


int main() {
    test_compareEnums();
}