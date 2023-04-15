//
// Created by yuvaltrip on 4/15/23.
//

#ifndef INC_3TASKA_FRACTION_H
#define INC_3TASKA_FRACTION_H
#include <iostream>
#include <cmath>

class Fraction {
//private:

public:
    int numerator;
    int denominator;
    Fraction(); //empty constructor
    Fraction(int numer, int denom);
    Fraction(double num);

    void simplify() {
        if (numerator == 0) {
            denominator = 1;
        }
        else {
            int gcd = std::__gcd(numerator, denominator);
            numerator /= gcd;
            denominator /= gcd;

            if (denominator < 0) {
                numerator *= -1;
                denominator *= -1;
            }
        }
    }

// Overloaded + operator
    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }
// Overloade operator that can handle the addition of a Fraction object and a double.
    Fraction operator+(const double& d) const {
        double res = d + (static_cast<double>(numerator) / denominator);
        return Fraction(res);
    }


    // Overloaded - operator
    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

// Overloaded * operator
    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    // Overloaded * operator (for double * Fraction)
    friend Fraction operator*(const double& d, const Fraction& f) {
        double res = d * (static_cast<double>(f.numerator) / f.denominator);
        int num = std::round(res * 1000);
        int den = 1000;
        return Fraction(num, den);
    }

    // Overloaded / operator
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw std::runtime_error("Cannot divide by zero!");
        }
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den);
    }

// Overloaded == operator
    bool operator==(const Fraction& other) const {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }

// Overloaded comparison operators
    bool operator>(const Fraction& other) const {
        return (numerator * other.denominator > other.numerator * denominator);
    }

    bool operator<(const Fraction& other) const {
        return (numerator * other.denominator < other.numerator * denominator);
    }

// Overloaded comparison and equalization operators

    bool operator>=(const Fraction& other) const {
        return (numerator * other.denominator >= other.numerator * denominator);
    }

    bool operator<=(const Fraction& other) const {
        return (numerator * other.denominator <= other.numerator * denominator);
    }

// Overloaded pre-increment operator
    Fraction& operator++() {
        numerator += denominator;
        simplify();
        return *this;
    }

// Overloaded post-increment operator
    Fraction operator++(int) {
        Fraction temp(*this);
        ++(*this);
        simplify();// simplify to this
        // simplify to temp already done in constructor
        return temp;
    }

// Overloaded pre-decrement operator
    Fraction& operator--() {
        numerator -= denominator;
        simplify();
        return *this;
    }

// Overloaded post-decrement operator
    Fraction operator--(int) {
        Fraction temp(*this);
        --(*this);
        simplify();// simplify to 'this'
        // simplify to temp already done in constructor
        return temp;
    }

// Overloaded << operator
//friend ostream& operator<<(ostream& os, const Fraction& frac) {
//    os << frac.numerator << "/" << frac.denominator;
//    return os;
//}



};

inline std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    out << f.numerator << "/" << f.denominator;
    return out;
}


#endif //INC_3TASKA_FRACTION_H
