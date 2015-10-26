#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Rational {
public:
    Rational(): numerator(0), denominator(1) {}
    Rational(int n): numerator(n), denominator(1) {}
    Rational(int n, int d) {
        if (d == 0) {
            throw std::invalid_argument("Input invalid!!! Denominator is zero");
        }

        if (n == 0) {
            numerator = 0;
            denominator = 1;
        }
        else {
            int unsigned_n = transPos(n);
            int unsigned_d = transPos(d);
            int unsigned_gcd = gcd(unsigned_n, unsigned_d);
            if ((d < 0 && n > 0) || (d > 0 && n < 0)) {
                numerator = -(unsigned_n/unsigned_gcd);
                denominator = (unsigned_d/unsigned_gcd);
            }
            else {
                numerator = unsigned_n/unsigned_gcd;
                denominator = unsigned_d/unsigned_gcd;
            }
        }
    }

    int num() const {
        return numerator;
    }

    int denom() const {
        return denominator;
    }

    Rational reciprocal() {
        int n = denom();
        int d = num();
        return Rational(n, d);
    }

    Rational& operator+=(const Rational& right);

    Rational& operator-=(const Rational& right);

    Rational& operator*=(const Rational& right);

    Rational& operator/=(const Rational& right);

    Rational& operator++();

    Rational operator++(int);

    Rational& operator--();

    Rational operator--(int);

    Rational operator-();

    operator float();

    operator double();

    friend std::ostream& operator <<(std::ostream& os, const Rational& obj) {
        if (obj.denom() == 1) {
            return os << obj.num();
        }
        else {
            return os << obj.num() << "/" << obj.denom();
        }
    };


    /*Here, we assume that a>0, b>0*/
    static int gcd(int a, int b) {
        while (a != b) {
            if (a > b)
                a = a - b;
            else
                b = b - a;
        }
        return a;
    }

    static int transPos(int a) {
        return (a > 0) ? (a):(-a);
    }

private:
    int numerator;
    int denominator;
};



inline Rational operator+(const Rational& left, const Rational& right) {
    int n = left.num()*right.denom() + left.denom()*right.num();
    int d = left.denom()*right.denom();
    return Rational(n, d);
}

inline Rational operator-(const Rational& left, const Rational& right) {
    int n = left.num()*right.denom() - left.denom()*right.num();
    int d = left.denom()*right.denom();
    return Rational(n, d);
}

inline Rational operator*(const Rational& left, const Rational& right) {
    int n = left.num()*right.num();
    int d = left.denom()*right.denom();
    return Rational(n, d);
}

inline Rational operator/(const Rational& left, const Rational& right) {
    int n = left.num()*right.denom();
    int d = left.denom()*right.num();
    return Rational(n, d);
}

inline bool operator==(const Rational& left, const Rational& right){ return (left.num() == right.num()) && (left.denom() == right.denom()); }
inline bool operator!=(const Rational& left, const Rational& right){return !operator==(left,right);}
inline bool operator< (const Rational& left, const Rational& right){ return left.num()*right.denom() < left.denom()*right.num(); }
inline bool operator> (const Rational& left, const Rational& right){return  operator< (right, left);}
inline bool operator<=(const Rational& left, const Rational& right){return !operator> (left, right);}
inline bool operator>=(const Rational& left, const Rational& right){return !operator< (left, right);}
