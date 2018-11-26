#include <iostream>
#include <iomanip>
#include <sstream>
#include "rational.hpp"

// friend overloaded operators
std::ostream& operator<<(std::ostream& ostr, const Rational& q)
{
   ostr << float(q.num)/float(q.denom) << '\t';
   if (q.num % q.denom == 0) {
      int n = q.num / q.denom;
      ostr << std::setw(18) << n << '\t' << n;
   } else {
      std::stringstream ss;
      ss << q.num << '/' << q.denom;
      ostr << std::setw(18) << ss.str();
      ostr << '\t' << q.num/q.denom << ' ' << q.num%q.denom << '/' << q.denom;
   }
   return ostr;
}

Rational operator+(const Rational& p, const Rational& q)
{
   Rational z(p.num*q.denom + q.num*p.denom, p.denom*q.denom);
   z.reduce();
   return z;
}

Rational Rational::operator+=(const Rational& q)
{
   num = num*q.denom + q.num*denom;
   denom = denom*q.denom;
   reduce();
   return *this;
}

Rational Rational::add(Rational p, Rational q)
{
   Rational z(p.num*q.denom + q.num*p.denom, p.denom*q.denom);
   z.reduce();
   return z;
}

void Rational::assign(int n, int d)
{
   num = n;
   denom = d;
}

int Rational::numerator() const
{
   return num;
}

int Rational::denominator() const
{
   return denom;
}
