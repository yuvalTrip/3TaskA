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
Fraction::Fraction (double d)
{// constructor get double number and convert it to Fraction

    int wholePart = static_cast<int>(d);
    numerator = wholePart;
    denominator = 1;
    d -= wholePart;
    const int maxIterations = 30;
    for (int i = 0; i < maxIterations; i++) {
        d = 1 / d;
        int intPart = static_cast<int>(d);
        numerator = numerator * intPart + denominator;
        denominator = numerator - denominator * intPart;
        if (std::abs(denominator) > 1000) {
            break;
        }
        d -= intPart;
        if (fabs(d) < 0.0001) {
            break;
        }
    }


//    // First, extract the whole part of the double and create a Fraction object from it
//    int wholePart = static_cast<int>(d);
//    Fraction fraction(wholePart);
//
//    // Subtract the whole part from the double to get the fractional part
//    d -= wholePart;
//
//    // Use continued fractions to approximate the fractional part of the double as a Fraction object
//    const int maxIterations = 30;
//    for (int i = 0; i < maxIterations; i++) {
//        d = 1 / d; // invert d to get the reciprocal
//        int intPart = static_cast<int>(d); // extract the integer part of the reciprocal
//        fraction = fraction + Fraction(intPart); // add the integer part to the fraction
//        d -= intPart; // subtract the integer part from the reciprocal
//        if (fabs(d) < 0.0001) { // check if the remainder is small enough
//            break; // if it is, exit the loop
//        }
//    }
//
//    // Return the Fraction object that approximates the original double
//    return fraction;
}


