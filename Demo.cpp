/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    Fraction a(5,3), b(14,21);
    float d= 0.25;
    Fraction c = a+d;
    cout<<c<<endl;

    //  Fraction c =a+b;
//    cout << "a: " << a << "b: " << b << endl;
//    std::cout << "a+b" << c << endl;
//    c=a-b;
//    cout << "a-b" << c << endl;
//    c=a/b;
//    cout << "a/b" << c<< endl;
//    c=a*b;
//    cout << "a*b" << c << endl;
//    cout << "2.3*b" << 2.3*b << endl;
//    cout << "a+2.421" << a+2.421 << endl;
//    c = (a+b) - (1);
//c++;
//    cout << (c) << endl;
//    --c;
//    c--;
//   cout << (c) << endl;
//
  // cout << "c >=b ? : " << (c >= b) << endl;
//    if (a > 1.1) cout << " a is bigger than 1.1" << endl;
//    else cout << " a is smaller than 1.1" << endl;

}