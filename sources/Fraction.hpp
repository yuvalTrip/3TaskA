//
// Created by yuvaltrip on 4/15/23.
//

#ifndef INC_3TASKA_FRACTION_H
#define INC_3TASKA_FRACTION_H
#include <iostream>
#include <cmath>
#include <algorithm>
namespace ariel {
    class Fraction {
//private:

    public:
        int numerator;
        int denominator;

        Fraction(); //empty constructor
        Fraction(int numer, int denom);

        Fraction(double num);


        void simplify() {// For example : 4/8 -> 1/2
            if (numerator == 0) {
                denominator = 1;
            } else {
                int gcd = std::__gcd(numerator, denominator);
                numerator /= gcd;
                denominator /= gcd;

                if (denominator < 0) {
                    numerator *= -1;
                    denominator *= -1;
                }
            }
        }

//// OPERATOR +
// Overloaded + operator (Fraction + otherFraction)
        Fraction operator+(Fraction &other) {
            // Calculate the numerator and denominator of the resulting Fraction (Common ground)
            int num = numerator * other.denominator + other.numerator * denominator;
            int den = denominator * other.denominator;
            Fraction temp = Fraction(num, den);
            simplify();
            return temp;// Return Fraction
        }

        // Overloade + operator (Fraction + double)
        Fraction operator+(const double &d) //the 'const' make sure that the double parameter is treated as a constant and is not modified inside the function.
        {
//            double res = d + (static_cast<double>(numerator) / denominator);
//            return Fraction(res);// Return Fraction


//            int digits = std::to_string(d).length() - 1 - std::to_string(d).find('.');
//            int denominator = std::pow(10, digits);
//            int numerator = std::round(denominator * d);
//            Fraction f(numerator, denominator);
//            return (*this + f);
        }

        // Overloaded + operator (for double + Fraction)
        friend Fraction operator+(const double &d, const Fraction &f) {
            //the same as (Fraction + double) just now i access fo the frection 'f' I get
            double res = d + (static_cast<double>(f.numerator) / f.denominator);
            return Fraction(res);// Return Fraction
        }

//// OPERATOR -

        // Overloaded - operator (for Fraction - otherFraction)
        Fraction operator-(const Fraction &other) const {
            // Almost the same as + operator
            int num = numerator * other.denominator - other.numerator * denominator;
            int den = denominator * other.denominator;
            return Fraction(num, den);
        }

        // Overloaded - operator (Fraction - double)
        Fraction operator-(const double &d) {
            double res = (static_cast<double>(numerator) / denominator) - d;
            return Fraction(res);// Return Fraction
        }

        // Overloaded - operator (for double - Fraction)
        friend Fraction operator-(const double &d, const Fraction &f) {
            //the same as (Fraction - double) just now i access fo the frection 'f' I get
            double res = d - (static_cast<double>(f.numerator) / f.denominator);
            return Fraction(res);// Return Fraction
        }
//// OPERATOR *

        // Overloaded * operator (for Fraction * otherFraction)
        Fraction operator*(const Fraction &other) const {
            int num = numerator * other.numerator;// Numerators multiplication
            int den = denominator * other.denominator;// Denominators multiplication
            return Fraction(num, den);
        }

// Overloaded * operator (Fraction * double)
        Fraction operator*(const double &d) {
            double res = d * (static_cast<double>(numerator) / denominator);
            int num = std::round(res * 1000);
            int den = 1000;
            return Fraction(num, den);
        }

        // Overloaded * operator (for double * Fraction)
        friend Fraction operator*(const double &d, const Fraction &f) {
            double res = d * (static_cast<double>(f.numerator) / f.denominator);
            int num = std::round(res * 1000);
            int den = 1000;
            return Fraction(num, den);
        }

        //// OPERATOR /

        // Overloaded / operator (for Fraction / otherFraction)
        Fraction operator/(const Fraction &other) const {
            if (other.numerator == 0) {
                throw std::runtime_error("Cannot divide by zero!");
            }
            int num = numerator * other.denominator;
            int den = denominator * other.numerator;
            return Fraction(num, den);
        }

        // Overloaded / operator (Fraction / double)
        Fraction operator/(const double &d) {
            if (d == 0) {
                throw std::runtime_error("Cannot divide by zero!");
            }
            double res = (static_cast<double>(numerator) / denominator) / d;
            int num = std::round(res * 1000);
            int den = 1000;
            return Fraction(num, den);
        }

        // Overloaded * operator (for double / Fraction)
        friend Fraction operator/(const double &d, const Fraction &f) {
            return Fraction(d) / f;
        }

        //// OPERATOR ==

// Overloaded == operator (for Fraction == otherFraction)
        bool operator==(const Fraction &other) const {
            return (numerator == other.numerator) && (denominator == other.denominator);
        }

//    Overloaded == operator (Fraction == double)
        bool operator==(const double &d) {
            return std::abs(static_cast<double>(numerator) / denominator - d) < 1e-6;
        }

//    Overloaded == operator (double == Fraction)
        friend bool operator==(const double &d, const Fraction &f) {
            return f == d;
        }
        //// OPERATOR >

        // Overloaded > operator (for Fraction > otherFraction)
        bool operator>(const Fraction &other) const {
            double thisVal = static_cast<double>(numerator) / denominator;
            double otherVal = static_cast<double>(other.numerator) / other.denominator;
            return thisVal > otherVal;
        }

        // Overloaded  > operator (Fraction > double)
        bool operator>(const double &d) const {
            double res = (static_cast<double>(numerator) / denominator);
            return res > d;
        }

        // Overloaded  > operator (double > Fraction)
        friend Fraction operator>(const double &d, const Fraction &f) {
            return d > static_cast<double>(f.numerator) / f.denominator;
        }

        //// OPERATOR <
// Exactly the same as > !
        // Overloaded < operator (for Fraction < otherFraction)
        bool operator<(const Fraction &other) const {
            double thisVal = static_cast<double>(numerator) / denominator;
            double otherVal = static_cast<double>(other.numerator) / other.denominator;
            return thisVal < otherVal;
        }

        // Overloaded  < operator (Fraction > double)
        bool operator<(const double &d) const {
            double res = (static_cast<double>(numerator) / denominator);
            return res > d;
        }

        // Overloaded  < operator (double < Fraction)
        friend Fraction operator<(const double &d, const Fraction &f) {
            return d < static_cast<double>(f.numerator) / f.denominator;
        }
        //// OPERATOR >=

// Overloaded comparison and equalization operators

        // Overloaded >= operator (for Fraction >= otherFraction)
        bool operator>=(const Fraction &other) const {
            double thisVal = static_cast<double>(numerator) / denominator;
            double otherVal = static_cast<double>(other.numerator) / other.denominator;
            return (thisVal >= otherVal);
        }

        // Overloaded  >= operator (Fraction >= double)
        bool operator>=(const double &d) const {
            double res = (static_cast<double>(numerator) / denominator);
            return res >= d;
        }

        // Overloaded  >= operator (double >= Fraction)
        friend Fraction operator>=(const double &d, const Fraction &f) {
            return d >= static_cast<double>(f.numerator) / f.denominator;
        }

        //// OPERATOR <=
// Exactly the same as >= !

        // Overloaded <= operator (for Fraction <= otherFraction)
        bool operator<=(const Fraction &other) const {
            double thisVal = static_cast<double>(numerator) / denominator;
            double otherVal = static_cast<double>(other.numerator) / other.denominator;
            return (thisVal <= otherVal);
        }

        // Overloaded  <= operator (Fraction <= double)
        bool operator<=(const double &d) const {
            double res = (static_cast<double>(numerator) / denominator);
            return res <= d;
        }

        // Overloaded  <= operator (double <= Fraction)
        friend Fraction operator<=(const double &d, const Fraction &f) {
            return d <= static_cast<double>(f.numerator) / f.denominator;
        }

        //// OPERATOR ++
        // Overloaded pre-increment operator
        Fraction &operator++() {
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
        //// OPERATOR --

// Overloaded pre-decrement operator
        Fraction &operator--() {
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

//// OPERATOR <<

    inline std::ostream &operator<<(std::ostream &out, const Fraction &f) {
        out << f.numerator << "/" << f.denominator;
        return out;
    }
}

#endif //INC_3TASKA_FRACTION_H
