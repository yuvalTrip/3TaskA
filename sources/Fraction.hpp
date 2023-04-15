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
            throw runtime_error("Cannot divide by zero!");
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

    bool operator>=(const Fraction& other) const {
        return (numerator * other.denominator >= other.numerator * denominator);
    }

    bool operator<=(const Fraction& other) const {
        return (numerator * other.denominator <= other.numerator * denominator);
    }

// Overloaded pre-increment operator
    Fraction& operator++() {
        numerator += denominator;
        //simplify();
        return *this;
    }

// Overloaded post-increment operator
    Fraction operator++(int) {
        Fraction temp(*this);
        ++(*this);
        return temp;
    }

// Overloaded pre-decrement operator
    Fraction& operator--() {
        numerator -= denominator;
        //simplify();
        return *this;
    }

// Overloaded post-decrement operator
    Fraction operator--(int) {
        Fraction temp(*this);
        --(*this);
        return temp;
    }

// Overloaded << operator
//friend ostream& operator<<(ostream& os, const Fraction& frac) {
//    os << frac.numerator << "/" << frac.denominator;
//    return os;
//}



};

std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    out << f.numerator << "/" << f.denominator;
    return out;
}


#endif //INC_3TASKA_FRACTION_H
