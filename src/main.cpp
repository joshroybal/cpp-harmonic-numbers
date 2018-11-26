#include <iostream>
#include "rational.hpp"

int main()
{
   Rational s;
   for (int i = 1; i <= 19; i++) {
      Rational x(1, i);
      s += x;
      std::cout << s << std::endl;
   }
   return 0;
}
