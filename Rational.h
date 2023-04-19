#pragma once
#include <string>

class Rational {
int numerator, denominator;
void reduce(); // helper function to reduce fraction to lowest terms
public:
Rational(int, int ); // default constructor with default values
Rational operator+(const Rational &) const; // addition operator
Rational operator-(const Rational &) const; // subtraction operator
Rational operator*(const Rational &) const; // multiplication operator
Rational operator/(const Rational &) const; // division operator
std::string toRationalString() const; // returns string representation of fraction
};
