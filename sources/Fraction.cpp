//
// Created by yuvaltrip on 4/21/23.
//

#include "Fraction.hpp"
#include <cmath> // for round()
#include <typeinfo>

using namespace ariel;
using namespace std;

// fraction constructor
Fraction::Fraction(int num, int den)
{
    if (den == 0)
    {
        throw invalid_argument("Error: Division by zero!");
    }
    if ((typeid(num)) != typeid(int) || (typeid(den)) != typeid(int))
    {
        throw invalid_argument("Error: Numbers must be integers!");
    }

    this->numerator = num;
    this->denominator = den;
    int BNum = gcd(numerator, denominator);
    numerator = numerator/BNum;
    denominator = denominator/BNum;
}


Fraction Fraction::operator+(const Fraction &other) const
{
    // using cross-multiplication
    int num = (this->numerator * other.denominator) + (other.numerator * this->denominator);
    int den = this->denominator * other.denominator;
    return Fraction(num, den).reduce();
}

Fraction Fraction::operator-(const Fraction &other) const
{
    int num = (this->numerator * other.denominator) - (other.numerator * this->denominator);
    int den = this->denominator * other.denominator;
    return Fraction(num, den).reduce();
}

Fraction Fraction::operator*(const Fraction &other) const
{
    // normal multiplication
    int num = this->numerator * other.numerator;
    int den = this->denominator * other.denominator;
    return Fraction(num, den).reduce();
}

Fraction Fraction::operator/(const Fraction &other) const
{
    // Division is cross multiplication
    int num = this->numerator * other.denominator;
    int den = this->denominator * other.numerator;
    if (den == 0)
    {
        throw invalid_argument("Error: Division by zero!");
    }
    return Fraction(num, den).reduce();
}

bool Fraction::operator==(const Fraction &other) const
{
    // compare numerator with numerator and denom with denom
    return (numerator == other.numerator) && (denominator == other.denominator);
}

bool Fraction::operator>(const Fraction &other) const
{
    // comparing numerator after cross-multiplication
    return (numerator * other.denominator) > (other.numerator * denominator);
}

bool Fraction::operator<(const Fraction &other) const
{
    // comparing numerator after cross-multiplication
    return (numerator * other.denominator) < (other.numerator * denominator);
}

bool Fraction::operator>=(const Fraction &other) const
{
    // comparing numerator after cross-multiplication or comparing equals
    return ((numerator * other.denominator) > (other.numerator * denominator)) || (numerator == other.numerator && denominator == other.denominator);
}

bool Fraction::operator<=(const Fraction &other) const
{
    // comparing numerator after cross-multiplication or comparing equals
    return ((numerator * other.denominator) < (other.numerator * denominator)) || (numerator == other.numerator && denominator == other.denominator);
}

Fraction &Fraction::operator++()
{
    // by adding the denominator to the numerator we are adding 1
    numerator += denominator;

    // return reference to the updates object so you can carry on working with it updated
    return *this;
}

Fraction Fraction::operator++(int)
{
    // Create a copy of the original object
    Fraction original = *this;

    // Increment the value of the object by one
    numerator += denominator;

    // Return the original object before increment may need to reduce original value
    return original;
}

Fraction &Fraction::operator--()
{
    // Decrement the value by 1
    numerator -= denominator;

    // return reference to the updates object so you can carry on working with it updated
    return *this;
}

Fraction Fraction::operator--(int)
{

    // Create a copy of the original object
    Fraction original = *this;

    // Decrement the value of the object by one
    numerator -= denominator;

    // Return the original object before increment may need to reduce original value
    return original;
}

Fraction Fraction::operator+(const float frac)
{
    // Turn float into fraction then used already implemented operator +
    Fraction fracF = floatToFraction(frac);
    return (*this) + fracF;
}

Fraction Fraction::operator-(const float frac)
{
    // Turn float into fraction then used already implemented operator -
    Fraction fracF = floatToFraction(frac);
    return (*this) - fracF;
}

Fraction Fraction::operator*(const float frac)
{
    // Turn float into fraction then used already implemented operator *
    Fraction fracF = floatToFraction(frac);
    return (*this) * fracF;
}

Fraction Fraction::operator/(const float frac)
{
    // Turn float into fraction then used already implemented operator /
    Fraction fracF = floatToFraction(frac);
    return (*this) / fracF;
}

bool Fraction::operator==(const float frac)
{
    // Turn float into fraction then used already implemented operator ==
    Fraction fracF = floatToFraction(frac);
    return (*this) == fracF;
}

bool Fraction::operator>(const float frac)
{
    // Turn float into fraction then used already implemented operator >
    Fraction fracF = floatToFraction(frac);
    return (*this) > fracF;
}

bool Fraction::operator<(const float frac)
{
    // Turn float into fraction then used already implemented operator <
    Fraction fracF = floatToFraction(frac);
    return (*this) < fracF;
}

bool Fraction::operator>=(const float frac)
{
    // Turn float into fraction then used already implemented operator >=
    Fraction fracF = floatToFraction(frac);
    return (*this) >= fracF;
}

bool Fraction::operator<=(const float frac)
{
    // Turn float into fraction then used already implemented operator <=
    Fraction fracF = floatToFraction(frac);
    return (*this) <= fracF;
}

ostream &ariel::operator<<(std::ostream &outs, const Fraction &f)
{
    outs << f.numerator << "/" << f.denominator;
    return outs;
}

istream &ariel::operator>>(std::istream &ins, Fraction &f)
{
    int num, den;
    ins >> num >> den;
    f.numerator = num;
    f.denominator = den;
    return ins;
}

// Helper function to reduce a fraction to its simplest form
Fraction Fraction::reduce() const
{
    int gcdVal = gcd(numerator, denominator); // Find the greatest common divisor (GCD) of the numerator and denominator
    int num = numerator / gcdVal;             // Divide numerator by GCD to get the reduced numerator
    int den = denominator / gcdVal;           // Divide denominator by GCD to get the reduced denominator
    return Fraction(num, den);                // Return the reduced fraction as a new Fraction object
}

Fraction Fraction::floatToFraction(const float frac)
{
    int intF = static_cast<int>(frac * 1000 + 0.5);

    int den = 1000;

    return Fraction(intF, den).reduce();
}

Fraction floatToFraction(const float frac)
{
    int intF = static_cast<int>(frac * 1000 + 0.5);

    int den = 1000;

    return Fraction(intF, den).reduce();
}

// Helper function to calculate the greatest common divisor (GCD) of two integers
int Fraction::gcd(int num1, int num2) const
{
    // Euclidean algorithm for finding the GCD
    if (num2 == 0)
    {
        return num1;
    }
    else
    {
        return gcd(num2, num1 % num2);
    }
}

Fraction ariel::operator+(const float fNum, const Fraction &frac)
{
    Fraction Fraction1 = floatToFraction(fNum);
    return Fraction1 + frac;
}

Fraction ariel::operator-(const float fNum, const Fraction &frac)
{
    Fraction Fraction1 = floatToFraction(fNum);
    return Fraction1 - frac;
}

Fraction ariel::operator*(const float fNum, const Fraction &frac)
{
    Fraction Fraction1 = floatToFraction(fNum);
    return Fraction1 * frac;
}

Fraction ariel::operator/(const float fNum, const Fraction &frac)
{
    Fraction Fraction1 = floatToFraction(fNum);
    return Fraction1 / frac;
}

bool ariel::operator==(const float fNum, const Fraction &frac)
{
    Fraction Fraction1 = floatToFraction(fNum);
    return Fraction1 == frac;
}

bool ariel::operator>(const float fNum, const Fraction &frac)
{
    Fraction Fraction1 = floatToFraction(fNum);
    return Fraction1 > frac;
}

bool ariel::operator<(const float fNum, const Fraction &frac)
{
    Fraction Fraction1 = floatToFraction(fNum);
    return Fraction1 < frac;
}

bool ariel::operator>=(const float fNum, const Fraction &frac)
{
    Fraction Fraction1 = floatToFraction(fNum);
    return Fraction1 >= frac;
}

bool ariel::operator<=(const float fNum, const Fraction &frac)
{
    Fraction Fraction1 = floatToFraction(fNum);
    return Fraction1 <= frac;
}