#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Shape {
protected:
    double area;
public:
    virtual double calculateArea() = 0;
    virtual double calculateCost() = 0;
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) {
        side = s;
        area = calculateArea();
    }
    double calculateArea() override {
        return side * side;
    }
    double calculateCost() override {
        return 50 * area;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
        area = calculateArea();
    }
    double calculateArea() override {
        return length * width;
    }
    double calculateCost() override {
        return 50 * area;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;
public:
    Triangle(double b, double h) {
        base = b;
        height = h;
        area = calculateArea();
    }
    double calculateArea() override {
        return 0.5 * base * height;
    }
    double calculateCost() override {
        return 75 * area;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) {
        radius = r;
        area = calculateArea();
    }
    double calculateArea() override {
        return M_PI * radius * radius;
    }
    double calculateCost() override {
        return 100 * area;
    }
};

class CustomShape : public Shape {
private:
    Shape* shape1;
    Shape* shape2;
public:
    CustomShape(Shape* s1, Shape* s2) {
        shape1 = s1;
        shape2 = s2;
        area = calculateArea();
    }
    double calculateArea() override {
        return shape1->calculateArea() + shape2->calculateArea();
    }
    double calculateCost() override {
        return 50 * area;
    }
};

class Order {
private:
    vector<Shape*> shapes;
public:
    Order() {
        shapes.reserve(5);
    }
    void addShape(Shape* shape) {
        if (shapes.size() < 5) {
            shapes.push_back(shape);
        }
    }
    double calculateCost() {
        double cost = 0;
        for (Shape* shape : shapes) {
            cost += shape->calculateCost();
        }
        return cost;
    }
};

class OrderProcessingSystem {
private:
    vector<Order> orders;
public:
    void addOrder(Order order) {
        if (orders.size() < 6) {
            orders.push_back(order);
        }
    }
    double totalCost() {
        double cost = 0;
        for (Order order : orders) {
            cost += order.calculateCost();
        }
        return cost;
    }
};

int main() {
    OrderProcessingSystem system;
    
    Square* sq1 = new Square(5);
    Square* sq2 = new Square(10);
    Rectangle* rec1 = new Rectangle(4, 8);
    Triangle* tri1 = new Triangle(6, 10);
    Circle* cir1 = new Circle(3);
    Circle* cir2 = new Circle(5);
    CustomShape* cus1 = new CustomShape(sq1, rec1);
    CustomShape* cus2 = new CustomShape(tri1, cir1);
    
    
    Order order1;
    order1.addShape(sq1);
    order1.addShape(rec1);
    order1.addShape(cir1);
    system.addOrder(order1);
    std::cout << "Order 1 cost: " << order1.calculateCost() << std::endl;

    Order order2;
    order2.addShape(sq2);
    // order2.addShape(CustomShape(tri1, cir2));
    system.addOrder(order2);
    std::cout << "Order 2 cost: " << order2.calculateCost() << std::endl;

    Order order3;
    order3.addShape(cir1);
    order3.addShape(sq2);
    system.addOrder(order3);
    std::cout << "Order 3 cost: " << order3.calculateCost() << std::endl;

    std::cout << "Total cost: " << system.totalCost() << std::endl;

    return 0;
}
