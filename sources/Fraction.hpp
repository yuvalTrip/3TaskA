#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
using namespace std;
namespace ariel
{
    /* NOTES
     * The 'const' make sure that the parameters I sent are treated as a constant
     and it is not modified inside the function.
     * I used reference and did not create new objects inside the function (
     most of the time) because I want to make it more efficiency
     *
     * */

    class Fraction
    {
        int numerator;
        int denominator;

    public:
        Fraction(int num, int den);
        Fraction operator+(const Fraction &other) const;
        Fraction operator+(float float_num);

        Fraction operator-(const Fraction &other) const;
        Fraction operator-(float float_num);

        Fraction operator*(const Fraction &other) const;
        Fraction operator*(float float_num);

        Fraction operator/(const Fraction &other) const;
        Fraction operator/(float float_num);

        bool operator==(const Fraction &other) const;
        bool operator==(float float_num);

        bool operator>(const Fraction &other) const;
        bool operator>(float float_num);

        bool operator<(const Fraction &other) const;
        bool operator<(float float_num);

        bool operator>=(const Fraction &other) const;
        bool operator>=(float float_num);

        bool operator<=(const Fraction &other) const;
        bool operator<=(float float_num);

        Fraction &operator++();   // pre-increment
        Fraction operator++(int); // post-increment

        Fraction &operator--();   // pre-decrement
        Fraction operator--(int); // post-decrement

        void simplify() ;
        Fraction floatToFraction(float float_num);
        int gcd(int num1, int num2) const;

        friend ostream &operator<<(std::ostream &outs, const Fraction &frac);
        friend istream &operator>>(std::istream &ins, Fraction &frac);
    };

    Fraction operator+(float float_num, const Fraction &frac);
    Fraction operator-(float float_num, const Fraction &frac);
    Fraction operator*(float float_num, const Fraction &frac);
    Fraction operator/(float float_num, const Fraction &frac);
    bool operator>(float float_num, const Fraction &frac);
    bool operator<(float float_num, const Fraction &frac);
    bool operator==(float float_num, const Fraction &frac);
    bool operator>=(float float_num, const Fraction &frac);
    bool operator<=(float float_num, const Fraction &frac);

}

#endif // FRACTION_HPP
