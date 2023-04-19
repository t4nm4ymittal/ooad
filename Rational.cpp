#include "Rational.h"
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
void Rational::reduce() {
int gcd = __gcd(numerator, denominator);

numerator /= gcd;
denominator /= gcd;
}

Rational::Rational(int num=1, int denom=2) : numerator(num), denominator(denom) {
reduce();
}

Rational Rational::operator+(const Rational &other) const {
int num = numerator * other.denominator + denominator * other.numerator;
int denom = denominator * other.denominator;
return Rational(num, denom);
}

Rational Rational::operator-(const Rational &other) const {
int num = numerator * other.denominator - denominator * other.numerator;
int denom = denominator * other.denominator;
return Rational(num, denom);
}

Rational Rational::operator*(const Rational &other) const {
int num = numerator * other.numerator;
int denom = denominator * other.denominator;
return Rational(num, denom);
}

Rational Rational::operator/(const Rational &other) const {
int num = numerator * other.denominator;
int denom = denominator * other.numerator;

return Rational(num, denom);
}

std::string Rational::toRationalString() const {
return std::to_string(numerator) + "/" + std::to_string(denominator);
}
