//
// Created by yuvaltrip on 4/15/23.
//

#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"
//#include "sources/Fraction.cpp"

using namespace std;
using namespace ariel;
TEST_CASE("The initialization of Fraction")
{
    // Regular initialization
    CHECK_NOTHROW(Fraction a(5,3));
    CHECK_NOTHROW(Fraction b(14,21));
    CHECK_NOTHROW(Fraction a(5,3));

    // Wrong initialization
    CHECK_THROWS(Fraction (5,0));// No need in a before (5.0) because it is not create an object because of the exeption
    // Initialization of 0
    CHECK_THROWS(Fraction (0,0));//wrong
    CHECK_NOTHROW(Fraction a(0,1)); // ok

}

TEST_CASE(" Division operation by 0 ")
{
    Fraction a(5,3);
    Fraction b(0,1);
    // Test division by zero
    CHECK_THROWS(a/0); // wrong
    //CHECK_NOTHROW(b/a); // ok
}

TEST_CASE(" Division ")
{
    Fraction a(5,3), b(14,21);

    // Test fraction division
    CHECK((a/b) == Fraction(5,2));
    CHECK((b/a) == Fraction(2,5));

    // Test division by float
    CHECK((a/2.421) == Fraction(5000,7263));
    CHECK((2.421/a) == Fraction(7263,5000));
}

TEST_CASE(" Addition") {
    Fraction a(5,3), b(14,21);

    // Test fraction addition
    CHECK((a+b) == Fraction(7,3));
    CHECK((b+a) == Fraction(7,3));

    // Test addition with zero
    Fraction c=Fraction(0,1);
    CHECK(a+c == a);
    CHECK((Fraction(0,1)+a) == a);

    // Test addition with float
    CHECK((a+2.421) == Fraction(2421, 1000));
    CHECK((2.421+a) == Fraction(2421, 1000));
}

TEST_CASE("Subtraction of Fractions") {
    Fraction a(5,3), b(14,21);

//    // Test Fraction subtraction
    CHECK((a-b) == 1);
//    CHECK((b-a) == -1);

//    // Test subtraction with zero
//    CHECK((a-Fraction(0,1)) == a);
//    CHECK((Fraction(0,1)-a) == Fraction(-5,3));
//
//    // Test subtraction with float
//    CHECK((a-2.421) == Fraction(-2263, 3000));
//    CHECK((2.421-a) == Fraction(2263, 3000));
}

TEST_CASE("Multiplication of Fractions") {
    Fraction a(5,3), b(14,21);

    // Test multiplication
    CHECK((a*b) == Fraction(70,63));
    CHECK((b*a) == Fraction(70,63));

    // Test multiplication with zero
    CHECK((a*Fraction(0,1)) == Fraction(0,1)); //0
    CHECK((Fraction(0,1)*a) == Fraction(0,1)); //0

    // Test multiplication with float
    CHECK((a*2.421) == Fraction(807,200));
    CHECK((2.421*a) == Fraction(807,200));
}

TEST_CASE("Comparison of Fractions") {
    Fraction a(5,3), b(14,21), c(-5,3), d(-14,21), e(10,6);
    CHECK(a > c);
    CHECK(d < b);
    CHECK(a >= e);
    CHECK(b <= e);
}

TEST_CASE("Equality of Fractions") {
    Fraction a(5, 3), b(14, 21), c(15, 9);

    // Test equality
    CHECK((a == Fraction(5, 3)));
    CHECK((a == c));
    CHECK_FALSE((a == b));
}

TEST_CASE("Increment and Decrement Operators") {
    Fraction a(5, 3), b(14, 21);
    Fraction c = a + b - 1;

    // Prefix increment
    ++a;
    CHECK(a == Fraction(8, 3));

// Postfix increment
    Fraction result_postfix = b++;
    CHECK(result_postfix == Fraction(14, 21));
    CHECK(b == Fraction(35, 21));

// Prefix decrement
    --c;
    CHECK(c == Fraction(4, 3));

// Postfix decrement
    Fraction result_postfix_ = a--;
    CHECK(result_postfix_ == Fraction(8, 3));
    CHECK(a == Fraction(5, 3));
}

