
// Created by tomergozlan on 4/24/23./

# include "sources/Fraction.hpp"
#include "doctest.h"

using namespace ariel;
using namespace std;

TEST_CASE("Test Case number 1 : Initialize a fraction with a zero denominator"){
    CHECK_THROWS(Fraction(1, 0));
}
TEST_CASE("Test Case number 1 : Initialize a fraction with a zero denominator"){
    Fraction fraction1(1, 2);
    Fraction fraction2;
    Fraction fraction3(0,1);
    CHECK_THROWS((fraction2 = fraction1 / Fraction(0, 1));
}
