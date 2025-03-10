#include <iostream>




class Grandparent {
public:
    int grandparent_data;
};
   
class Parent1 : virtual public Grandparent {
public:
    int parent1_data;
};
   
class Parent2 : virtual public Grandparent {
public:
    int parent2_data;
};
   
class Child : public Parent1, public Parent2 {
    int child_data;
};
   
int main() {
    Child child;
    child.grandparent_data = 0;
    Parent1 p1;
    p1.grandparent_data = 3;
}
