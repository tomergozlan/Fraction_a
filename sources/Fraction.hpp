
/// Created by tomergozlan on 4/15/23.


#ifndef FRACTION_A_FRACTION_HPP
#define FRACTION_A_FRACTION_HPP

#include <iostream>

using namespace std;
namespace ariel{

    class Fraction{

    private:

     int numerator;
     int denominator;
     void reduceForm();
     int gcd(int number1 , int number2);

    public:

        Fraction(int numerator=0,int denominator=1);
        Fraction(const Fraction& other);
        int getNumerator();
        int getDenominator();
        void setNumerator(int new_numerator);
        void setDenominator(int new_denominator);
        Fraction operator+(Fraction& fraction);
        Fraction operator-(Fraction& fraction);
        Fraction operator*(Fraction& fraction);
        Fraction operator/(Fraction& fraction);
        bool operator==(Fraction& fraction);
        bool operator>(Fraction& fraction) ;
        bool operator<( Fraction& fraction) ;
        bool operator>=(Fraction& fraction) ;
        bool operator<=(Fraction& fraction) ;
        Fraction operator++();
        Fraction operator++(int);
        Fraction operator--();
        Fraction operator--(int);
        friend std::ostream& operator<<(std::ostream& out, Fraction& fraction);
        friend std::istream& operator>>(std::istream& in, Fraction& fraction);
    };
}

#endif //FRACTION_A_FRACTION_HPP