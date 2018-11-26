#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
      friend std::ostream& operator<<(std::ostream&, const Rational&);
      friend Rational operator+(const Rational&, const Rational&);
   public:
      Rational() : num(0), denom(1) { reduce(); }
      Rational(int n, int d) : num(n), denom(d) { reduce(); }
      Rational operator+=(const Rational&);
      Rational add(Rational, Rational);
      void assign(int, int);
      int numerator() const;
      int denominator() const;
   private:
      int num, denom;
      int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b); }
      void reduce() { int g = gcd(num, denom); num /= g; denom /= g; }
};

#endif
