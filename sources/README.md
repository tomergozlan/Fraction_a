<div dir="rtl" lang="en">

# Constructor:

Fraction(int numerator, int denominator): constructs a Fraction object with the given numerator and denominator. It reduces the fraction to its simplest form and throws an exception if the denominator is zero or if the numerator or denominator is out of range.
Public Methods:

* int getNumerator() const: returns the numerator of the fraction.
* int getDenominator() const: returns the denominator of the fraction.
* void setNumerator(int new_numerator): sets the numerator of the fraction to the new value and reduces the fraction to its simplest form.
* void setDenominator(int new_denominator): sets the denominator of the fraction to the new value and reduces the fraction to its simplest form. Throws an exception if the new denominator is zero.
* Fraction operator+(const Fraction& fraction) const: returns the sum of the current fraction and the input fraction.
* Fraction operator-(const Fraction& fraction) const: returns the difference between the current fraction and the input fraction.
* Fraction operator*(const Fraction& fraction) const: returns the product of the current fraction and the input fraction.
* Fraction operator/(const Fraction& fraction) const: returns the quotient of the current fraction and the input fraction.
* Fraction& operator=(const Fraction& other): assigns the value of the input fraction to the current fraction.
* Fraction& operator=(Fraction&& other) noexcept: assigns the value of the input fraction to the current fraction using move semantics.
* bool operator==(const Fraction& fraction) const: returns true if the current fraction is equal to the input fraction.
* bool operator>(const Fraction& fraction) const: returns true if the current fraction is greater than the input fraction.
* bool operator<(const Fraction& fraction) const: returns true if the current fraction is less than the input fraction.
* 
# Private Methods:

* int gcd(int number1, int number2): returns the greatest common divisor of two integers.
* void reduceForm(): reduces the fraction to its simplest form.
* Fraction convertFloatToFraction(float value): converts a floating point number to a fraction. Throws an exception if the float value is out of range.

</div>
