////
//// Created by yuvaltrip on 4/15/23.
////
//
//#include "Fraction.hpp"
//using namespace ariel;
//#include <cmath> // for round()
//#include <typeinfo>
//ariel::Fraction::Fraction(int numer, int denom)
//// Two-parameter constructor
//{
//    numerator = numer;
//    denominator = denom;
//    if (denominator == 0)
//    {
//        throw std::runtime_error("Denominator can not be zero!");
//    }
//    simplify();
//}
//
//// Helper function to calculate the greatest common divisor (GCD) of two integers
//int Fraction::gcd(int num1, int num2) const
//{
//    // Euclidean algorithm for finding the GCD
//    if (num2 == 0)
//    {
//        return num1;
//    }
//    else
//    {
//        return gcd(num2, num1 % num2);
//    }
//}
//// Empty constructor
//ariel::Fraction::Fraction() {
//    numerator=0;
//    denominator=1;
//};
//
//// One-parameter constructor
//ariel::Fraction::Fraction (double d)
//{// constructor get double number and convert it to Fraction
////    cout << "d :::::::::::::::::::"<<d<<endl;
////    // First, extract the whole part of the double and create a Fraction object from it
////    int wholePart = static_cast<int>(d);
////    cout << "wholePart:::::::::::::::: "<<wholePart<<endl;
////    numerator = wholePart;
////    cout << "numerator :::::::::::::::::::"<<numerator<<endl;
////    denominator = 1;
////    // Subtract the whole part from the double to get the fractional part
////    d = d-wholePart;
////    cout << "d :::::::::::::::::::"<<d<<endl;
////
////    // Use continued fractions to approximate the fractional part of the double as a Fraction object
////    const int maxIterations = 30;
////    for (int i = 0; i < maxIterations; i++) {
////        d = 1 / d;// invert d to get the reciprocal
////        int intPart = static_cast<int>(d);// extract the integer part of the reciprocal
////        numerator = numerator * intPart + denominator;
////        denominator = numerator - denominator * intPart;
////        if (std::abs(denominator) > 1000)
////        {
////            break;
////        }
////        d -= intPart;// subtract the integer part from the reciprocal
////        if (fabs(d) < 0.0001)
////        {// check if the remainder is small enough
////            break;// if it is, exit the loop
////        }
////    }
////    cout << "numerator after:::::::::::::::::::"<<numerator<<endl;
////    cout << "denominator after:::::::::::::::::::"<<denominator<<endl;
////    simplify();
////        int digAfterPoint=howManyNumAfterPoint(d);
////        int numerator=digAfterPoint*d;
////        cout<<"digAfterPoint"<<digAfterPoint<<endl;
////        int denominator=digAfterPoint;
////        Fraction(numerator,denominator);
////        simplify();
//
//    }
//
// Fraction Fraction::reduce() const
//{
//    int gcdVal = gcd(numerator, denominator); // Find the greatest common divisor (GCD) of the numerator and denominator
//    int num = numerator / gcdVal;             // Divide numerator by GCD to get the reduced numerator
//    int den = denominator / gcdVal;           // Divide denominator by GCD to get the reduced denominator
//    return Fraction(num, den);                // Return the reduced fraction as a new Fraction object
//}
//
//
//Fraction Fraction::floatToFraction(const float frac)
//{
//    int intF = static_cast<int>(frac * 1000 + 0.5);
//
//    int den = 1000;
//
//    return Fraction(intF, den).reduce();
//}
//
//
//
//
//
//
//
//
//
//
