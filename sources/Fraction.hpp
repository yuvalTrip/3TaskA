#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
using namespace std;
namespace ariel
{
    class Fraction
    {
        int numerator;
        int denominator;

    public:
        Fraction(int num, int den);
        // mathematical operation on two Fraction objects therefore they are const
        // I am sending a  reference and not a value is for efficiency not creating another object
        // and using const to make sure the other isn't modified inside the function
        Fraction operator+(const Fraction &other) const;
        Fraction operator+(float fNum);

        Fraction operator-(const Fraction &other) const;
        Fraction operator-(float fNum);

        Fraction operator*(const Fraction &other) const;
        Fraction operator*(float fNum);

        Fraction operator/(const Fraction &other) const;
        Fraction operator/(float fNum);


        bool operator==(const Fraction &other) const;
        bool operator==(float fNum);

        bool operator>(const Fraction &other) const;
        bool operator>(float fNum);

        bool operator<(const Fraction &other) const;
        bool operator<(float fNum);

        bool operator>=(const Fraction &other) const;
        bool operator>=(float fNum);

        bool operator<=(const Fraction &other) const;
        bool operator<=(float fNum);

        Fraction &operator++();   // pre-increment
        Fraction operator++(int); // post-increment

        Fraction &operator--();   // pre-decrement
        Fraction operator--(int); // post-decrement

        Fraction reduce() const;
        Fraction floatToFraction(float fNum);
        int gcd(int num1, int num2) const;

        friend ostream &operator<<(std::ostream &outs, const Fraction &frac);
        friend istream &operator>>(std::istream &ins, Fraction &frac);
    };

    Fraction operator+(float fNum, const Fraction &frac);
    Fraction operator-(float fNum, const Fraction &frac);
    Fraction operator*(float fNum, const Fraction &frac);
    Fraction operator/(float fNum, const Fraction &frac);
    bool operator==(float fNum, const Fraction &frac);
    bool operator>(float fNum, const Fraction &frac);
    bool operator>=(float fNum, const Fraction &frac);
    bool operator<(float fNum, const Fraction &frac);
    bool operator<=(float fNum, const Fraction &frac);

}

#endif // FRACTION_HPP
