#include <iostream>

class Coordinates_2D {
public:
    Coordinates_2D() : x(0), y(0) {}

    Coordinates_2D(int x, int y) : x(x), y(y) {}

    Coordinates_2D operator+(const Coordinates_2D other) const {
        return {x + other.x, y + other.y};
    }

    Coordinates_2D operator-(const Coordinates_2D other) const {
        return {x + other.x, y + other.y};
    }

    Coordinates_2D operator*(const Coordinates_2D other) const {
        return {x * other.x, y * other.y};
    }

    bool operator==(const Coordinates_2D& other) const {
        return (x == other.x && y == other.y);
    }


    void printValues() {
        std::cout << x << " " << y << std::endl;
    }

private:
    int x;
    int y;
};

int main() {
    Coordinates_2D a(1, 2);
    Coordinates_2D b(1, 2);

    a.printValues(); // Output: 1 2
    b.printValues(); // Output: 1 2

    Coordinates_2D c = a + b;
    c.printValues(); // Output: 2 4

    a.printValues(); // Output: 1 2
    b.printValues(); // Output: 1 2


    if (a == b) {
        std::cout << "a and b are equal" << std::endl;
    } else {
        std::cout << "a and b are not equal" << std::endl;
    }

    return 0;
}

