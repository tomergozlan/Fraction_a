//
// Created by tomergozlan on 4/15/23.
//

#include "Fraction.hpp"
#include <stdexcept>
#include <cmath>
#include <limits>
#include <iomanip>

namespace ariel {
    Fraction::Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("Error: the denominator of fraction can't be zero.");
        }
        if (numerator == std::numeric_limits<int>::min() || numerator == std::numeric_limits<int>::max() ||
            denominator == std::numeric_limits<int>::min() || denominator == std::numeric_limits<int>::max()) {
            throw std::out_of_range("Numerator or denominator value is out of range.");
        }
        if (numerator < 0 && denominator < 0 || numerator > 0 && denominator < 0) {
            denominator *= -1;
            numerator *= -1;
        }
        this->denominator = denominator;
        this->numerator = numerator;
        reduceForm();
    }

    Fraction::Fraction(const Fraction &other) {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }

    int Fraction::gcd(int number1, int number2) {
        return (number2 == 0) ? number1 : gcd(number2, number1 % number2);
    }

    void Fraction::reduceForm() {
        int gcd = this->gcd(::abs(this->numerator), this->denominator);
        if (gcd > 1) {
            this->numerator /= gcd;
            this->denominator /= gcd;
        }
    }

    Fraction Fraction::convertFloatToFraction(float value) {
        if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min()) {
            throw out_of_range("ERROR: out of range float number.");
        }
        int numerator =(value * 1000);
        int denominator = 1000;
        Fraction fraction(numerator, denominator);
        return fraction;
    }

    int Fraction::getNumerator() const {
        return this->numerator;
    }

    int Fraction::getDenominator() const {
        return this->denominator;
    }

    void Fraction::setNumerator(int new_numerator) {
        this->numerator = new_numerator;
        if (numerator < 0 && denominator < 0 || numerator > 0 && denominator < 0) {
            denominator *= -1;
            numerator *= -1;
        }
        this->reduceForm();
    }

    void Fraction::setDenominator(int new_denominator) {
        if (new_denominator == 0) {
            throw invalid_argument("Error: the denominator of fraction can't be zero.");
        }
        this->denominator = new_denominator;
        if (numerator < 0 && denominator < 0 || numerator > 0 && denominator < 0) {
            denominator *= -1;
            numerator *= -1;
        }
        this->reduceForm();
    }

    Fraction Fraction::operator+(const Fraction &fraction) const {
        Fraction resultFraction;

        if (this->denominator == fraction.getDenominator()) {
            resultFraction.setNumerator(this->numerator + fraction.getNumerator());
            resultFraction.setDenominator(this->denominator);
        } else {
            resultFraction.setNumerator(
                    (this->numerator * fraction.getDenominator()) + (fraction.getNumerator() * this->denominator));
            resultFraction.setDenominator(this->denominator * fraction.getDenominator());
        }
        resultFraction.reduceForm();
        return resultFraction;
    }

    Fraction Fraction::operator-(const Fraction &fraction) const {
        Fraction resultFraction;
        if (this->denominator == fraction.getDenominator()) {
            resultFraction.setNumerator(this->numerator - fraction.getNumerator());
            resultFraction.setDenominator(this->denominator);
        } else {
            resultFraction.setNumerator((this->numerator * fraction.getDenominator()) - (fraction.getNumerator() * this->denominator));
            resultFraction.setDenominator(this->denominator * fraction.getDenominator());
        }
        resultFraction.reduceForm();
        return resultFraction;
    }

    Fraction Fraction::operator*(const Fraction &fraction) const {
        Fraction resultFraction;

        resultFraction.setNumerator(this->numerator * fraction.getNumerator());
        resultFraction.setDenominator(this->denominator * fraction.getDenominator());

        resultFraction.reduceForm();
        return resultFraction;
    }

    Fraction Fraction::operator/(const Fraction &fraction) const {
        Fraction resultFraction;

        resultFraction.setDenominator(this->denominator * fraction.getNumerator());
        resultFraction.setNumerator(this->numerator * fraction.getDenominator());

        resultFraction.reduceForm();
        return resultFraction;
    }

    bool Fraction::operator==(const Fraction &fraction) const {
        return (this->numerator * fraction.getDenominator()) == (this->denominator * fraction.getNumerator());
    }

    bool Fraction::operator>(const Fraction &fraction) const {
        return (this->numerator * fraction.getDenominator()) > (this->denominator * fraction.getNumerator());
    }

    bool Fraction::operator<(const Fraction &fraction) const {
        return (this->numerator * fraction.getDenominator()) < (this->denominator * fraction.getNumerator());
    }

    bool Fraction::operator>=(const Fraction &fraction) const {
        return (this->numerator * fraction.getDenominator()) >= (this->denominator * fraction.getNumerator());
    }

    bool Fraction::operator<=(const Fraction &fraction) const {
        return (this->numerator * fraction.getDenominator()) <= (this->denominator * fraction.getNumerator());
    }

    Fraction& Fraction::operator++() {
        this->numerator += this->denominator;
        this->reduceForm();
        return *this;
    }

    Fraction Fraction::operator++(int) {
        Fraction temp= (*this);
        ++(*this);
        return temp;
    }

    Fraction Fraction::operator--() {
        this->numerator -= this->denominator;
        this->reduceForm();
        return *this;
    }

    Fraction Fraction::operator--(int) {
        Fraction temp = (*this);
        this->numerator -= this->denominator;
        temp.reduceForm();
        return temp;
    }

    std::ostream &operator<<(std::ostream &out, const Fraction &fraction) {
        out << fraction.getNumerator() << "/" << fraction.getDenominator();
        return out;
    }

    std::istream &operator>>(std::istream &in, Fraction &fraction) {
        int numerator, denominator;
        char slash;

        if (in >> numerator >> slash >> denominator && slash == '/') {
            fraction.setNumerator(numerator);
            fraction.setDenominator(denominator);
        } else {
            throw invalid_argument("ERROR: invalid input format.");
        }
        return in;
    }

    Fraction operator+(const float float_num, const Fraction &fraction) {
        const Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        Fraction resultFraction;

        resultFraction.setNumerator(float_frac.getNumerator() * fraction.getDenominator() +
                                    fraction.getNumerator() * float_frac.getDenominator());
        resultFraction.setDenominator(float_frac.getDenominator() * fraction.getDenominator());
        resultFraction.reduceForm();

        return resultFraction;
    }

    Fraction operator+(const Fraction &fraction, const float float_num) {
        const Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        Fraction resultFraction;

        resultFraction.setNumerator(float_frac.getNumerator() * fraction.getDenominator() +
                                    fraction.getNumerator() * float_frac.getDenominator());
        resultFraction.setDenominator(float_frac.getDenominator() * fraction.getDenominator());
        resultFraction.reduceForm();

        return resultFraction;
    }

    Fraction operator-(const float float_num, const Fraction &fraction) {
        const Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        Fraction resultFraction;
        if (float_frac.getDenominator() == fraction.getDenominator()) {
            resultFraction.setNumerator(float_frac.getNumerator() - fraction.getNumerator());
            resultFraction.setDenominator(float_frac.getDenominator());
        } else {
            resultFraction.setNumerator((float_frac.getNumerator() * fraction.getDenominator()) -
                                        (fraction.getNumerator() * float_frac.getDenominator()));
            resultFraction.setDenominator(float_frac.getDenominator() * fraction.getDenominator());
        }
        resultFraction.reduceForm();
        return resultFraction;
    }

    Fraction operator-(const Fraction &fraction, const float float_num) {
        const Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        Fraction resultFraction;
        if (float_frac.getDenominator() == fraction.getDenominator()) {
            resultFraction.setNumerator( fraction.getNumerator()-float_frac.getNumerator());
            resultFraction.setDenominator(fraction.getDenominator());
        } else {
            resultFraction.setNumerator((fraction.getNumerator() * float_frac.getDenominator()) -(fraction.getDenominator() * float_frac.getNumerator()));
            resultFraction.setDenominator(float_frac.getDenominator() * fraction.getDenominator());
        }
        resultFraction.reduceForm();
        return resultFraction;
    }

    Fraction operator*(const Fraction &fraction, const float float_num) {
        const Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        Fraction resultFraction;

        resultFraction.setNumerator(float_frac.getNumerator() * fraction.getNumerator());
        resultFraction.setDenominator(float_frac.getDenominator() * fraction.getDenominator());

        resultFraction.reduceForm();
        return resultFraction;
    }

    Fraction operator*(const float float_num, const Fraction &fraction) {
        const Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        Fraction resultFraction;

        resultFraction.setNumerator(float_frac.getNumerator() * fraction.getNumerator());
        resultFraction.setDenominator(float_frac.getDenominator() * fraction.getDenominator());

        resultFraction.reduceForm();
        return resultFraction;
    }

    Fraction operator/(const Fraction &fraction, float float_num) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        Fraction resultFraction;

        resultFraction.setDenominator(float_frac.getDenominator() * fraction.getNumerator());
        resultFraction.setNumerator(float_frac.getNumerator() * fraction.getDenominator());

        resultFraction.reduceForm();
        return resultFraction;
    }

    Fraction operator/(float float_num, const Fraction &fraction) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        Fraction resultFraction;

        resultFraction.setDenominator(float_frac.getDenominator() * fraction.getNumerator());
        resultFraction.setNumerator(float_frac.getNumerator() * fraction.getDenominator());

        resultFraction.reduceForm();
        return resultFraction;
    }

    bool operator==(const Fraction &fraction, float float_num) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        return (float_frac.getNumerator() * fraction.getDenominator()) ==
               (float_frac.getDenominator() * fraction.getNumerator());
    }

    bool operator==(float float_num, const Fraction &fraction) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        return (float_frac.getNumerator() * fraction.getDenominator()) ==
               (float_frac.getDenominator() * fraction.getNumerator());
    }

    bool operator<(const Fraction &fraction, float float_num) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        return (float_frac.getDenominator() * fraction.getNumerator() <
                (float_frac.getNumerator() * fraction.getDenominator()));
    }

    bool operator<(float float_num, const Fraction &fraction) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        return (float_frac.getNumerator() * fraction.getDenominator()) <
               (float_frac.getDenominator() * fraction.getNumerator());
    }

    bool operator<=(const Fraction &fraction, float float_num) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        return (float_frac.getDenominator() * fraction.getNumerator() <=
                (float_frac.getNumerator() * fraction.getDenominator()));
    }

    bool operator<=(float float_num, const Fraction &fraction) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        return (float_frac.getNumerator() * fraction.getDenominator()) <=
               (float_frac.getDenominator() * fraction.getNumerator());
    }

    bool operator>(const Fraction &fraction, float float_num) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        return (float_frac.getDenominator() * fraction.getNumerator() >
                (float_frac.getNumerator() * fraction.getDenominator()));
    }

    bool operator>(float float_num, const Fraction &fraction) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        return (float_frac.getNumerator() * fraction.getDenominator()) >
               (float_frac.getDenominator() * fraction.getNumerator());
    }

    bool operator>=(const Fraction &fraction, float float_num) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        return (float_frac.getDenominator() * fraction.getNumerator() >=
                (float_frac.getNumerator() * fraction.getDenominator()));
    }

    bool operator>=(float float_num, const Fraction &fraction) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        return (float_frac.getNumerator() * fraction.getDenominator()) >=
               (float_frac.getDenominator() * fraction.getNumerator());
    }
}
