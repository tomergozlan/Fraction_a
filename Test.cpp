/**
 * Test case file for the exercise
 *
 * @author Tomer Gozlan
 * @since 2023-04
 */

# include "sources/Fraction.hpp"
#include "doctest.h"
#include <limits>
#include <sstream>

using namespace ariel;
using namespace std;

TEST_CASE("Test Case number 1: Initialize a fraction with a zero denominator"){
    CHECK_THROWS(Fraction(1, 0));
}
TEST_CASE("Test Case number 2: Divide fraction by zero"){
    Fraction fraction1(1, 2);
    Fraction fraction2(0,1);
    Fraction fraction3;
    CHECK_THROWS(fraction3 = fraction1 / fraction2);
}
TEST_CASE("Test Case number 3: Constructor throws exception for maximum and minimum values") {
    int max = std::numeric_limits<int>::max();
    int min = std::numeric_limits<int>::min();
    CHECK_THROWS(Fraction(max+1,1));
    CHECK_THROWS(Fraction(1,min-1));
}
TEST_CASE("Test Case number 4: Constructor reduces fraction to lowest form") {
    Fraction f1(4, 8);
    Fraction f2(-3, 9);
    Fraction f3(-6, -12);
    CHECK(f1.getNumerator() == 1);
    CHECK(f1.getDenominator() == 2);
    CHECK(f2.getNumerator() == -1);
    CHECK(f2.getDenominator() == 3);
    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 2);
}
TEST_CASE("Test Case number 5: Setters reduces fraction to lowest form") {
    Fraction f1(7, 8);
    f1.setNumerator(-2);
    CHECK(f1.getNumerator() == -1);
    CHECK(f1.getDenominator() == 4);
    f1.setDenominator(36);
    f1.setNumerator(12);
}
TEST_CASE("Test Case number 6: Check 3 digit float number") {
    float float_num = 0.28543;
    Fraction f1 = ariel::Fraction::convertFloatToFraction(float_num);
    CHECK(f1 .getNumerator() == 57);
    CHECK(f1.getDenominator() == 200);
}
TEST_CASE("Test Case number 7: Addition Fraction to Fraction & Fraction to Float & Float to Fraction") {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    float float_num = 0.28543;
    Fraction result1 = f1 + f2;
    CHECK(result1.getNumerator() == 5);
    CHECK(result1.getDenominator() == 4);
    Fraction result2 = f1 + float_num;
    CHECK(result2.getNumerator() == 157);
    CHECK(result2.getDenominator() == 200);
    Fraction result3 = float_num + f2;
    CHECK(result3.getNumerator() == 207);
    CHECK(result3.getDenominator() == 200);
}
TEST_CASE("Test Case number 8: Subtraction Fraction to Fraction & Fraction to Float & Float to Fraction") {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    float float_num = 0.28543;
    Fraction result1 = f1 - f2;
    CHECK(result1.getNumerator() == -1);
    CHECK(result1.getDenominator() == 4);
    Fraction result2 = f1 - float_num;
    CHECK(result2.getNumerator() == 43);
    CHECK(result2.getDenominator() == 200);
    Fraction result3 = float_num - f2;
    CHECK(result3.getNumerator() == -93);
    CHECK(result3.getDenominator() == 200);
}
TEST_CASE("Test Case number 9: Division Fraction to Fraction & Fraction to Float & Float to Fraction") {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    float float_num = 0.28543;
    Fraction result1 = f1 / f2;
    CHECK(result1.getNumerator() == 2);
    CHECK(result1.getDenominator() == 3);
    Fraction result2 = f1 / float_num;
    CHECK(result2.getNumerator() == 100);
    CHECK(result2.getDenominator() == 57);
    Fraction result3 = float_num / f2;
    CHECK(result3.getNumerator() == 19);
    CHECK(result3.getDenominator() == 50);
}
TEST_CASE("Test Case number 10: Multiplication Fraction to Fraction & Fraction to Float & Float to Fraction") {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    float float_num = 0.28543;
    Fraction result1 = f1 * f2;
    CHECK(result1.getNumerator() == 3);
    CHECK(result1.getDenominator() == 8);
    Fraction result2 = f1 * float_num;
    CHECK(result2.getNumerator() == 57);
    CHECK(result2.getDenominator() == 400);
    Fraction result3 = float_num * f2;
    CHECK(result3.getNumerator() == 171);
    CHECK(result3.getDenominator() == 800);
}
TEST_CASE("Test Case number 11: Comparison operators Fraction to Fraction & Fraction to Float & Float to Fraction ") {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    float float_num1 = 0.5;
    float float_num2 = 0.75;
    CHECK(f1 == float_num1);
    CHECK(float_num1 == f1);
    CHECK_FALSE(f1 == f2);
    CHECK(f1 < f2);
    CHECK_FALSE(f2 < f1);
    CHECK(f1 < float_num2);
    CHECK_FALSE(float_num2 < f1);
    CHECK(f1 <= f2);
    CHECK(f1 <= float_num2);
    CHECK(float_num1 <= f1);
    CHECK(f1 <= f1);
    CHECK(f2 > f1);
    CHECK_FALSE(f1 > f2);
    CHECK(float_num2 > f1);
    CHECK_FALSE(f1 > float_num2);
    CHECK(f2 >= f1);
    CHECK(float_num2 >= f1);
    CHECK(f1 >= float_num1);
    CHECK(f1 >= f1);
}
TEST_CASE("Test Case number 12: Increment and decrement operators") {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction result1 = ++f1;
    CHECK(result1.getNumerator() == 3);
    CHECK(result1.getDenominator() == 2);
    CHECK(f1.getNumerator() == 3);
    CHECK(f1.getDenominator() == 2);
    Fraction result2 = f2++;
    CHECK(result2.getNumerator() == 3);
    CHECK(result2.getDenominator() == 4);
    CHECK(f2.getNumerator() == 7);
    CHECK(f2.getDenominator() == 4);
    Fraction result3 = --f1;
    CHECK(result3.getNumerator() == 1);
    CHECK(result3.getDenominator() == 2);
    CHECK(f1.getNumerator() == 1);
    CHECK(f1.getDenominator() == 2);
    Fraction result4 = f2--;
    CHECK(result4.getNumerator() == 7);
    CHECK(result4.getDenominator() == 4);
    CHECK(f2.getNumerator() == 3);
    CHECK(f2.getDenominator() == 4);
}
TEST_CASE("Test Case number 13: Output and input stream operators") {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    std::stringstream out1;
    std::stringstream out2;
    out1 << f1;
    CHECK(out1.str() == "1/2");
    out2 << f2;
    CHECK(out2.str() == "3/4");
    std::stringstream out3("5/6");
    Fraction f3;
    out3 >> f3;
    CHECK(f3.getNumerator() == 5);
    CHECK(f3.getDenominator() == 6);
}
TEST_CASE("Test Case number 15: Initialize a fraction with default values"){
    Fraction fraction;
    CHECK(fraction.getNumerator()==0);
    CHECK(fraction.getDenominator()==1);
}