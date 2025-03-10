#include <iostream>
#include <stddef.h>

class NonCopyable {
public:
    int val;
    NonCopyable() = default;
    NonCopyable(int x) {
        val = x;
    }
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator= (const NonCopyable&) = delete;
    // NonCopyable& operator= (const NonCopyable&) = default;
};

void test_nonCopyable() {
    NonCopyable inst = NonCopyable();
}

class NewDeleted {
public:
    void* operator new(size_t) = delete;
};

class DerivedNewDeleted : virtual public NewDeleted {
};

void test_newDeleted() {
    // DerivedNewDeleted inst = new DerivedNewDeleted();
}


int main() {
    // auto NewDeleted * inst : NewDeleted * = dynamic_cast
}
