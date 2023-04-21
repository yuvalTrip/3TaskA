////
//// Created by yuvaltrip on 4/15/23.
////
//#ifndef INC_3TASKA_FRACTION_H
//#define INC_3TASKA_FRACTION_H
//#include <cmath>
//#include <algorithm>
//#include <iostream>
//using namespace std;
//namespace ariel
//{
//    class Fraction
//    {
//        int numerator;
//        int denominator;
//
//    public:
//        Fraction(int num, int den);
////         OPERATOR +
//// Overloaded + operator (Fraction + otherFraction)
//        Fraction operator+(const Fraction &other) const;
//        // Overloade + operator (Fraction + double)
////        Fraction operator+(const double &d)
//        Fraction operator+(float fNum);
//        // Overloaded + operator (for double + Fraction)
////        friend Fraction operator+(const double &d, const Fraction &f) {
//            //the same as (Fraction + double) just now i access fo the frection 'f' I get
//        Fraction operator+(float fNum, const Fraction &frac);
//
//
//        // Fraction operator+(float f) const;
//        Fraction operator-(const Fraction &other) const;
//        // Fraction operator-(float f) const;
//        Fraction operator*(const Fraction &other) const;
//        // Fraction operator*(float f) const;
//        Fraction operator/(const Fraction &other) const;
//        // Fraction operator/(float f) const;
//
//        // bool functions
//        bool operator==(const Fraction &other) const;
//        bool operator>(const Fraction &other) const;
//        bool operator<(const Fraction &other) const;
//        bool operator>=(const Fraction &other) const;
//        bool operator<=(const Fraction &other) const;
//
//        Fraction &operator++();   // pre-increment
//        Fraction operator++(int); // post-increment
//        Fraction &operator--();   // pre-decrement
//        Fraction operator--(int); // post-decrement
//
//        // float operators
//        Fraction operator-(float fNum);
//        Fraction operator*(float fNum);
//        Fraction operator/(float fNum);
//
//        // float bool operators
//        bool operator==(float fNum);
//        bool operator>(float fNum);
//        bool operator<(float fNum);
//        bool operator>=(float fNum);
//        bool operator<=(float fNum);
//
//        // Helper functions
//        Fraction reduce() const;
//        Fraction floatToFraction(float fNum);
//        int gcd(int num1, int num2) const;
//
//        friend std::ostream &operator<<(std::ostream &outs, const Fraction &frac);
//        friend std::istream &operator>>(std::istream &ins, Fraction &frac);
//    };
//
//    Fraction operator-(float fNum, const Fraction &frac);
//    Fraction operator*(float fNum, const Fraction &frac);
//    Fraction operator/(float fNum, const Fraction &frac);
//    bool operator==(float fNum, const Fraction &frac);
//    bool operator>(float fNum, const Fraction &frac);
//    bool operator>=(float fNum, const Fraction &frac);
//    bool operator<(float fNum, const Fraction &frac);
//    bool operator<=(float fNum, const Fraction &frac);
//
//}
//
//#endif // INC_3TASKA_FRACTION_H
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
//
//
//
//
//
//
//
//
//
////const int double_denom = 1000;
////using namespace std;
////namespace ariel {
////    class Fraction {
//////private:
////
////    public:
////        int numerator;
////        int denominator;
////
////        Fraction(); //empty constructor
////        Fraction(int numer, int denom);
////
////        Fraction( double num);
////        Fraction floatToFraction(const float frac);
////        Fraction reduce() const;
////        int gcd(int num1, int num2) const;
////
////// assist funcs
////        float roundPoint3(float num) const;
////        void lowestFrac(int &nom, int &denom); // reduce fraction - https://www.tutorialspoint.com/reduce-the-fraction-to-its-lowest-form-in-cplusplus
////
////
////        Fraction(float num) : denominator(double_denom)
////        {
////            float rounded = roundPoint3(num); // make sure it's 3 point decimal
////            numerator = int(rounded * double_denom);
////            lowestFrac(numerator, denominator);
////        }
////
////        void simplify() {// For example : 4/8 -> 1/2
////            if (numerator == 0) {
////                denominator = 1;
////            } else {
////                int gcd = std::__gcd(numerator, denominator);
////                numerator /= gcd;
////                denominator /= gcd;
////
////                if (denominator < 0) {
////                    numerator *= -1;
////                    denominator *= -1;
////                }
////            }
////        }
//////        unsigned long howManyNumAfterPoint(double d)
//////        {
//////            unsigned long totalDigits = std::numeric_limits<double>::digits10 + 1; // add 1 for the decimal point
//////            unsigned long digitsAfterPoint = totalDigits - std::to_string(static_cast<int>(d)).length() - 1; // subtract the length of the integer part and the decimal point
//////            //std::cout << "Number of digits after the decimal point: " << digitsAfterPoint << std::endl;
//////            return digitsAfterPoint;
//////        }
//////// OPERATOR <<
////
////
//////        Fraction float_to_fraction(double x, double tolerance=1e-6) {
//////            vector<ll> v;
//////            ll a = (ll) x;
//////            double f = x - a;
//////            while (abs(f) > tolerance) {
//////                v.push_back(a);
//////                a = (ll) (1.0/f);
//////                f = 1.0/f - a;
//////            }
//////            ll num = 1, den = v.back();
//////            for (int i = (int) v.size()-2; i >= 0; --i) {
//////                ll tmp = den;
//////                den = num + den * v[i];
//////                num = tmp;
//////            }
//////            num += a * den;
//////            return Fraction(num, den);
//////        }
////
//////// OPERATOR +
////// Overloaded + operator (Fraction + otherFraction)
////        Fraction operator+(Fraction &other) {
////            // Calculate the numerator and denominator of the resulting Fraction (Common ground)
////            int num = numerator * other.denominator + other.numerator * denominator;
////            int den = denominator * other.denominator;
////            Fraction temp = Fraction(num, den);
////            simplify();
////            return temp;// Return Fraction
////        }
////
////        // Overloade + operator (Fraction + double)
////        Fraction operator+(const double &d) //the 'const' make sure that the double parameter is treated as a constant and is not modified inside the function.
////        {
////            double res = d + (static_cast<double>(numerator) / denominator);
////            return Fraction(res);// Return Fraction
////
////
////
//////            int digits = std::to_string(d).length() - 1 - std::to_string(d).find('.');
//////            int denominator = std::pow(10, digits);
//////            int numerator = std::round(denominator * d);
//////            Fraction f(numerator, denominator);
//////            return (*this + f);
////        }
////
////        // Overloaded + operator (for double + Fraction)
////        friend Fraction operator+(const double &d, const Fraction &f) {
////            //the same as (Fraction + double) just now i access fo the frection 'f' I get
////            double res = d + (static_cast<double>(f.numerator) / f.denominator);
////            return Fraction(res);// Return Fraction
////        }
////
//////// OPERATOR -
////
////        // Overloaded - operator (for Fraction - otherFraction)
////        Fraction operator-(const Fraction &other) const {
////            // Almost the same as + operator
////            int num = numerator * other.denominator - other.numerator * denominator;
////            int den = denominator * other.denominator;
////            return Fraction(num, den);
////        }
////
////        // Overloaded - operator (Fraction - double)
////        Fraction operator-(const double &d) {
////            double res = (static_cast<double>(numerator) / denominator) - d;
////            return Fraction(res);// Return Fraction
////        }
////
////        // Overloaded - operator (for double - Fraction)
////        friend Fraction operator-(const double &d, const Fraction &f) {
////            //the same as (Fraction - double) just now i access fo the frection 'f' I get
////            double res = d - (static_cast<double>(f.numerator) / f.denominator);
////            return Fraction(res);// Return Fraction
////        }
//////// OPERATOR *
////
////        // Overloaded * operator (for Fraction * otherFraction)
////        Fraction operator*(const Fraction &other) const {
////            int num = numerator * other.numerator;// Numerators multiplication
////            int den = denominator * other.denominator;// Denominators multiplication
////            return Fraction(num, den);
////        }
////
////// Overloaded * operator (Fraction * double)
////        Fraction operator*(const double &d) {
////            double res = d * (static_cast<double>(numerator) / denominator);
////            int num = std::round(res * 1000);
////            int den = 1000;
////            return Fraction(num, den);
////        }
////
////        // Overloaded * operator (for double * Fraction)
////        friend Fraction operator*(const double &d, const Fraction &f) {
////            double res = d * (static_cast<double>(f.numerator) / f.denominator);
////            int num = std::round(res * 1000);
////            int den = 1000;
////            return Fraction(num, den);
////        }
////
////        //// OPERATOR /
////
////        // Overloaded / operator (for Fraction / otherFraction)
////        Fraction operator/(const Fraction &other) const {
////            if (other.numerator == 0) {
////                throw std::runtime_error("Cannot divide by zero!");
////            }
////            int num = numerator * other.denominator;
////            int den = denominator * other.numerator;
////            return Fraction(num, den);
////        }
////
//////         Overloaded / operator (Fraction / double)
////        Fraction operator/(const double &d) {
////            // Turn float into fraction then used already implemented operator /
////    Fraction fracF = floatToFraction(d);
////    return (*this) / fracF;
//////
//////            if (d == 0) {
//////                throw std::runtime_error("Cannot divide by zero!");
//////            }
//////            cout<< "numa: "<<numerator<<endl;
//////            cout<< "deno: "<<denominator<<endl;
//////            cout<< "d: "<<d<<endl;
//////
//////            long double res = (static_cast<long double>(numerator)/static_cast<long double>( denominator)) / static_cast<long double>(d);
//////            cout<< "res: "<<res<<endl;
//////            Fraction temp=Fraction(res);
////////            cout<< "temp: "<<temp<<endl;
//////
//////            return temp;
//////        if (d == 0) {
//////            throw std::runtime_error("Cannot divide by zero!");
//////        }
//////        Fraction x=float_to_fraction(d);
//////        Fraction original= Fraction (numerator,denominator);
//////        return (original/x);
//////            //float_to_fraction
////////
//////            double res = (static_cast<double>(numerator) / d) / denominator;
//////            int num = std::round(res * 1000);
//////            int den = 1000;
//////            return Fraction(num, den);
////        }
////
////        // Overloaded * operator (for double / Fraction)
////        friend Fraction operator/(const double &d, const Fraction &f) {
////            return Fraction(d) / f;
////        }
////
////        //// OPERATOR ==
////
////// Overloaded == operator (for Fraction == otherFraction)
////        bool operator==(const Fraction &other) const {
////            return (numerator == other.numerator) && (denominator == other.denominator);
////        }
////
//////    Overloaded == operator (Fraction == double)
////        bool operator==(const double &d) {
////            return std::abs(static_cast<double>(numerator) / denominator - d) < 1e-6;
////        }
////
//////    Overloaded == operator (double == Fraction)
////        friend bool operator==(const double &d, const Fraction &f) {
////            return f == d;
////        }
////        //// OPERATOR >
////
////        // Overloaded > operator (for Fraction > otherFraction)
////        bool operator>(const Fraction &other) const {
////            double thisVal = static_cast<double>(numerator) / denominator;
////            double otherVal = static_cast<double>(other.numerator) / other.denominator;
////            return thisVal > otherVal;
////        }
////
////        // Overloaded  > operator (Fraction > double)
////        bool operator>(const double &d) const {
////            double res = (static_cast<double>(numerator) / denominator);
////            return res > d;
////        }
////
//////        // Overloaded  > operator (double > Fraction)
//////        friend Fraction operator>(const double &d, const Fraction &f) {
//////            return d > static_cast<double>(f.numerator) / f.denominator;
//////        }
////
//////        bool friend Fraction ariel::operator>(const float fNum, const Fraction &frac)
//////        {
//////            Fraction Fraction1 = floatToFraction(fNum);
//////            return Fraction1 > frac;
//////        }
////
////        bool friend Fraction operator>(const double &d, const Fraction &f) {
////            Fraction doubleToFrec= Fraction(d);
////            Fraction frec=Fraction(f.numerator,f.denominator);
////            return (doubleToFrec > frec);
////        }
////        //// OPERATOR <
////// Exactly the same as > !
////        // Overloaded < operator (for Fraction < otherFraction)
////        bool operator<(const Fraction &other) const {
////            double thisVal = static_cast<double>(numerator) / denominator;
////            double otherVal = static_cast<double>(other.numerator) / other.denominator;
////            return thisVal < otherVal;
////        }
////
////        // Overloaded  < operator (Fraction > double)
////        bool operator<(const double &d) const {
////            double res = (static_cast<double>(numerator) / denominator);
////            return res > d;
////        }
////
////        // Overloaded  < operator (double < Fraction)
////        bool friend Fraction operator<(const double &d, const Fraction &f) {
////            Fraction doubleToFrec= Fraction(d);
////            Fraction frec=Fraction(f.numerator,f.denominator);
////            return (doubleToFrec < frec);
////        }
////        //// OPERATOR >=
////
////// Overloaded comparison and equalization operators
////
////        // Overloaded >= operator (for Fraction >= otherFraction)
////        bool operator>=(const Fraction &other) const {
////            double thisVal = static_cast<double>(numerator) / denominator;
////            double otherVal = static_cast<double>(other.numerator) / other.denominator;
////            return (thisVal >= otherVal);
////        }
////
////        // Overloaded  >= operator (Fraction >= double)
////        bool operator>=(const double &d) const {
////            double res = (static_cast<double>(numerator) / denominator);
////            return res >= d;
////        }
////
////        // Overloaded  >= operator (double >= Fraction)
////        friend Fraction operator>=(const double &d, const Fraction &f) {
////            return d >= static_cast<double>(f.numerator) / f.denominator;
////        }
////
////        //// OPERATOR <=
////// Exactly the same as >= !
////
////        // Overloaded <= operator (for Fraction <= otherFraction)
////        bool operator<=(const Fraction &other) const {
////            double thisVal = static_cast<double>(numerator) / denominator;
////            double otherVal = static_cast<double>(other.numerator) / other.denominator;
////            return (thisVal <= otherVal);
////        }
////
////        // Overloaded  <= operator (Fraction <= double)
////        bool operator<=(const double &d) const {
////            double res = (static_cast<double>(numerator) / denominator);
////            return res <= d;
////        }
////
////        // Overloaded  <= operator (double <= Fraction)
////        friend Fraction operator<=(const double &d, const Fraction &f) {
////            return d <= static_cast<double>(f.numerator) / f.denominator;
////        }
////
////        //// OPERATOR ++
////        // Overloaded pre-increment operator
////        Fraction &operator++() {
////            numerator += denominator;
////            simplify();
////            return *this;
////        }
////
////// Overloaded post-increment operator
////        Fraction operator++(int) {
////            Fraction temp(*this);
////            ++(*this);
////            simplify();// simplify to this
////            // simplify to temp already done in constructor
////            return temp;
////        }
////        //// OPERATOR --
////
////// Overloaded pre-decrement operator
////        Fraction &operator--() {
////            numerator -= denominator;
////            simplify();
////            return *this;
////        }
////
////// Overloaded post-decrement operator
////        Fraction operator--(int) {
////            Fraction temp(*this);
////            --(*this);
////            simplify();// simplify to 'this'
////            // simplify to temp already done in constructor
////            return temp;
////        }
////
////// Overloaded << operator
//////friend ostream& operator<<(ostream& os, const Fraction& frac) {
//////    os << frac.numerator << "/" << frac.denominator;
//////    return os;
//////}
////
////
////
////    };
////    inline std::ostream &operator<<(std::ostream &out, const Fraction &f) {
////        out << f.numerator << "/" << f.denominator;
////        return out;
////    }
////
////}
////
////#endif //INC_3TASKA_FRACTION_H
