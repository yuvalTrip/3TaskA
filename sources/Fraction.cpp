//
// Created by yuvaltrip on 4/15/23.
//

#include "Fraction.hpp"

Fraction::Fraction(int numer, int denom)
// Two-parameter constructor
{
    numerator = numer;
    denominator = denom;
}

// Empty constructor
Fraction::Fraction() {
    numerator=0;
    denominator=1;
};

// One-parameter constructor
//Fraction(int numer, int denom) : numerator(numer), denominator(denom) {}
Fraction doubleToFraction(double d) {
    int wholePart = static_cast<int>(d);
    Fraction fraction(wholePart);
    d -= wholePart;
    const int maxIterations = 30;
    for (int i = 0; i < maxIterations; i++) {
        d = 1 / d;
        int intPart = static_cast<int>(d);
        fraction = fraction + Fraction(intPart);
        d -= intPart;
        if (fabs(d) < 0.0001) {
            break;
        }
    }
    return fraction;
}
//
//// Operation declaration
//
//// Overloaded + operator
//Fraction operator+(const Fraction& other) const {
//    int num = numerator * other.denominator + other.numerator * denominator;
//    int den = denominator * other.denominator;
//    return Fraction(num, den);
//}
//
//// Overloaded - operator
//Fraction operator-(const Fraction& other) const {
//    int num = numerator * other.denominator - other.numerator * denominator;
//    int den = denominator * other.denominator;
//    return Fraction(num, den);
//}
//
//// Overloaded * operator
//Fraction operator*(const Fraction& other) const {
//    int num = numerator * other.numerator;
//    int den = denominator * other.denominator;
//    return Fraction(num, den);
//}
//
//// Overloaded / operator
//Fraction operator/(const Fraction& other) const {
//    if (other.numerator == 0) {
//        throw runtime_error("Cannot divide by zero!");
//    }
//    int num = numerator * other.denominator;
//    int den = denominator * other.numerator;
//    return Fraction(num, den);
//}
//
//// Overloaded == operator
//bool operator==(const Fraction& other) const {
//    return (numerator == other.numerator) && (denominator == other.denominator);
//}
//
//// Overloaded comparison operators
//bool operator>(const Fraction& other) const {
//    return (numerator * other.denominator > other.numerator * denominator);
//}
//
//bool operator<(const Fraction& other) const {
//    return (numerator * other.denominator < other.numerator * denominator);
//}
//
//bool operator>=(const Fraction& other) const {
//    return (numerator * other.denominator >= other.numerator * denominator);
//}
//
//bool operator<=(const Fraction& other) const {
//    return (numerator * other.denominator <= other.numerator * denominator);
//}
//
//// Overloaded pre-increment operator
//Fraction& operator++() {
//    numerator += denominator;
//    simplify();
//    return *this;
//}
//
//// Overloaded post-increment operator
//Fraction operator++(int) {
//    Fraction temp(*this);
//    ++(*this);
//    return temp;
//}
//
//// Overloaded pre-decrement operator
//Fraction& operator--() {
//    numerator -= denominator;
//    simplify();
//    return *this;
//}
//
//// Overloaded post-decrement operator
//Fraction operator--(int) {
//    Fraction temp(*this);
//    --(*this);
//    return temp;
//}
//
//// Overloaded << operator
//friend ostream& operator<<(ostream& os, const Fraction& frac)
//// Afriend function or class is allowed to access the private and protected data members of the class that it is a friend of.
//// This allows the operator<< function to access the private numerator and denominator members of the Fraction class,
//// which it needs to be able to output the fraction to a stream.
//{
//    os << frac.numerator << "/" << frac.denominator;
//    return os;
//}
////std::ostream& operator<<(std::ostream& out, const Fraction& f) {
////    out << f.num << "/" << f.den;
////    return out;



