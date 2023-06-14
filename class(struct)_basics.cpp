#include <iostream>
#include <vector>

struct coordinates {
    int x;
    int y;

    // Default constructor
    coordinates() {
        x = 0;
        y = 0;
    }

    // Constructor with parameters
    coordinates(int a, int b) {
        x = a;
        y = b;
    }

    void get_coord() {
        std::cout << x << " " << y << std::endl;
    }

    static void sayHello() {
        std::cout << "I'm a static method in coordinates" << std::endl;
    }
};

int main() {
    std::cout << "Not using constructor" << std::endl;
    coordinates a{};
    a.x = 10;
    a.y = 11;
    a.get_coord();

    std::cout << "Using constructor" << std::endl;
    coordinates b{};
    b.get_coord();

    std::cout << "Using constructor override" << std::endl;
    coordinates c{1, 2};
    c.get_coord(); // Corrected function call for object c

    coordinates::sayHello();

    std::cout << "Using const constructor" << std::endl;
    coordinates d{};
    d.get_coord(); // Corrected function call for object c

    return 0;
}


  
