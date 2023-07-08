#include <iostream>
#include <vector>

class StructPlay;

struct IntPlay{
    explicit IntPlay(int a) : val(a){};

    int val;
    StructPlay *next = nullptr;
};

struct StructPlay {
    explicit StructPlay(std::string a): val(a) {};

    std::string val;
    IntPlay *prev = nullptr;
};

int main() {
    auto *temp1 = new IntPlay(1);
    auto *temp2 = new StructPlay("hello");

    temp1->next = temp2;
    temp2->prev = temp1;

    /// lets see what happens:

    std::cout << "First element: " << temp1->val << " " << "Second element: " << temp2->val << std::endl;
    return 0;
}
