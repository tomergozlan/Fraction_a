
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

    public:

        void reduceForm();
        int gcd(int number1 , int number2);
        static Fraction convertFloatToFraction(float value);

        Fraction(int numerator=0,int denominator=1);
        Fraction(const Fraction& other);

        int getNumerator() const;
        int getDenominator() const;
        void setNumerator(int new_numerator);
        void setDenominator(int new_denominator);

        Fraction operator+(const Fraction& fraction) const;
        Fraction operator-(const Fraction& fraction) const;
        Fraction operator*(const Fraction& fraction) const;
        Fraction operator/(const Fraction& fraction) const;

        bool operator==(const Fraction& fraction) const;
        bool operator>(const Fraction& fraction) const;
        bool operator<(const Fraction& fraction) const;
        bool operator>=(const Fraction& fraction) const;
        bool operator<=(const Fraction& fraction) const;

        Fraction operator++();
        Fraction operator++(int);
        Fraction operator--();
        Fraction operator--(int);

        friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
        friend std::istream& operator>>(std::istream& in, Fraction& fraction);

        friend Fraction operator+(const Fraction& fraction,float float_num);
        friend Fraction operator+(float float_num, const Fraction& fraction);

        friend Fraction operator-(const Fraction& fraction,float float_num);
        friend Fraction operator-(float float_num,const Fraction& fraction);

        friend Fraction operator*(const Fraction& fraction,float float_num);
        friend Fraction operator*(float float_num,const Fraction& fraction);

        friend Fraction operator/(const Fraction& fraction,float float_num);
        friend Fraction operator/(float float_num,const Fraction& fraction);

        friend bool operator==(const Fraction& fraction,float float_num);
        friend bool operator==(float float_num,const Fraction& fraction);

        friend bool operator<(const Fraction& fraction,float float_num);
        friend bool operator<(float float_num,const Fraction& fraction);

        friend bool operator<=(const Fraction& fraction,float float_num);
        friend bool operator<=(float float_num,const Fraction& fraction);

        friend bool operator>(const Fraction& fraction,float float_num);
        friend bool operator>(float float_num,const Fraction& fraction);

        friend bool operator>=(const Fraction& fraction,float float_num);
        friend bool operator>=(float float_num,const Fraction& fraction);
    };
}

#endif //FRACTION_A_FRACTION_HPP
