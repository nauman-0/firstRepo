#include <iostream>
#include <string>

using namespace std;

class Shape {
public:
    virtual int area() = 0;
};

class Circle : public Shape {
private:
    int radius;

public:
    Circle(int userRadius) {
        radius = userRadius;
    }

    int area() {
        return 3 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    int length;
    int width;

public:
    Rectangle(int userLength, int userWidth) {
        length = userLength;
        width = userWidth;
    }

    int area() {
        return length * width;
    }
};

int main() {
    Circle myCircle(10);
    Rectangle myRectangle(10, 5);

    cout << "Circle area is: " << myCircle.area() << endl;
    cout << "Rectangle area is: " << myRectangle.area() << endl;

    return 0;
}