#include "rational.h"

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

Rational& Rational::operator+=(const Rational& right) {
    int n = this->numerator*right.denom() + this->denominator*right.num();
    int d = this->denominator*right.denom();
    Rational temp = Rational(n, d);
    this->numerator = temp.num();
    this->denominator = temp.denom();
    return *this;
}

Rational& Rational::operator-=(const Rational& right) {
    int n = this->numerator*right.denom() - this->denominator*right.num();
    int d = this->denominator*right.denom();
    Rational temp = Rational(n, d);
    this->numerator = temp.num();
    this->denominator = temp.denom();
    return *this;
}

Rational& Rational::operator*=(const Rational& right) {
    int n = this->numerator*right.num();
    int d = this->denominator*right.denom();
    Rational temp = Rational(n, d);
    this->numerator = temp.num();
    this->denominator = temp.denom();
    return *this;
}

Rational& Rational::operator/=(const Rational& right) {
    int n = this->numerator*right.denom();
    int d = this->denominator*right.num();
    Rational temp = Rational(n, d);
    this->numerator = temp.num();
    this->denominator = temp.denom();
    return *this;
}

Rational& Rational::operator++() {
    *this += Rational(1, 1);
    return *this;
}

Rational Rational::operator++(int) {
    Rational temp(*this);
    ++(*this);
    return temp;
}

Rational& Rational::operator--() {
    *this -= Rational(1, 1);
    return *this;
}

Rational Rational::operator--(int) {
    Rational temp(*this);
    --(*this);
    return temp;
}

Rational Rational::operator-() {
    return Rational(-(this->num()), this->denom());
}

Rational::operator float() {
    return float(this->num())/this->denom();
}

Rational::operator double() {
    return double(this->num())/this->denom();
}


//int main() {
//    Rational x(2, 3);
//    cout << x.num() << " " << x.denom() << endl;
//    return 0;
//}
