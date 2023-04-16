//
// Created by tomergozlan on 4/15/23.
//

#include "Fraction.hpp"
#include <stdexcept>
#include <cmath>
#include <limits>

namespace ariel {
    Fraction::Fraction(int numerator, int denominator) {
        if(denominator==0){
            throw invalid_argument("Error: the denominator of fraction can't be zero.");
        }
        if (numerator == std::numeric_limits<int>::min() || numerator == std::numeric_limits<int>::max() ||
            denominator == std::numeric_limits<int>::min() || denominator == std::numeric_limits<int>::max()) {
            throw std::out_of_range("Numerator or denominator value is out of range.");
        }
        this->denominator=denominator;
        this->numerator=numerator;
        reduceForm();
    }
    Fraction::Fraction(const Fraction& other) {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }

    int Fraction::gcd(int number1, int number2) {
        return (number2 == 0) ? number1: gcd(number2,number1 % number2);
        }

    void Fraction::reduceForm() {
        int gcd = this->gcd(this->numerator,this->denominator);
        if(gcd > 1) {
            this->numerator /= gcd;
            this->denominator /= gcd;
        }
    }
    int Fraction::getNumerator() {
        return this->numerator;
    }

    int Fraction::getDenominator() {
        return this->denominator;
    }

    void Fraction::setNumerator(int new_numerator) {
        this->numerator = new_numerator;
    }

    void Fraction::setDenominator(int new_denominator) {
        if(new_denominator==0){
            throw invalid_argument("Error: the denominator of fraction can't be zero.");
        }
        this->denominator = new_denominator;
    }

    Fraction Fraction::operator+(Fraction& fraction) {
        Fraction resultFraction;

        if (this->denominator == fraction.getDenominator()) {
            resultFraction.setNumerator(this->numerator + fraction.getNumerator());
            resultFraction.setDenominator(this->denominator);
        } else {
            resultFraction.setNumerator((this->numerator * fraction.getDenominator()) + (fraction.getNumerator() * this->denominator));
            resultFraction.setDenominator(this->denominator * fraction.getDenominator());
        }
        resultFraction.reduceForm();
        return resultFraction;
    }
    Fraction Fraction::operator-(Fraction& fraction) {
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
    Fraction Fraction::operator*(Fraction& fraction) {
        Fraction resultFraction;

        resultFraction.setNumerator(this->numerator * fraction.getNumerator());
        resultFraction.setDenominator(this->denominator * fraction.getDenominator());

        resultFraction.reduceForm();
        return resultFraction;
    }
    Fraction Fraction::operator/(Fraction& fraction) {
        Fraction resultFraction;

        resultFraction.setDenominator(this->denominator * fraction.getNumerator());
        resultFraction.setNumerator(this->numerator * fraction.getDenominator());

        resultFraction.reduceForm();
        return resultFraction;
    }
    bool Fraction::operator==(Fraction& fraction){
        return (this->numerator * fraction.getDenominator()) == (this->denominator * fraction.getNumerator());
    }
    bool Fraction::operator>(Fraction& fraction) {
        return (this->numerator * fraction.getDenominator()) > (this->denominator * fraction.getNumerator());
    }
    bool Fraction::operator<(Fraction& fraction) {
        return (this->numerator * fraction.getDenominator()) < (this->denominator * fraction.getNumerator());
    }
    bool Fraction::operator>=(Fraction& fraction) {
        return (this->numerator * fraction.getDenominator()) >= (this->denominator * fraction.getNumerator());
    }
    bool Fraction::operator<=(Fraction& fraction) {
        return (this->numerator * fraction.getDenominator()) <= (this->denominator * fraction.getNumerator());
    }

    Fraction Fraction::operator++() {
        this->numerator += this->denominator;
        this->reduceForm();
        return *this;
    }
    Fraction Fraction::operator++(int) {
        Fraction temp(*this);
        this->numerator += this->denominator;
        temp.reduceForm();
        return temp;
    }
    Fraction Fraction::operator--() {
        this->numerator -= this->denominator;
        this->reduceForm();
        return *this;
    }

    Fraction Fraction::operator--(int) {
        Fraction temp(*this);
        this->numerator -= this->denominator;
        temp.reduceForm();
        return temp;
    }

    std::ostream& operator<<(std::ostream& out, Fraction& fraction) {
        out << fraction.getNumerator() << "/" << fraction.getDenominator();
        return out;
    }
    std::istream& operator>>(std::istream& in, Fraction& fraction) {
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
}