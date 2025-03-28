#include <iostream>
#include <cstdlib>
#include <Fixed.hpp>

int main() {
  Fixed a;
  Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;

  std::cout << b << std::endl;

  std::cout << Fixed::max( a, b ) << std::endl;


  std::cout << "\nMY TESTS:\n" << std::endl;

  std::cout << "=== Constructors and Assignment ===\n";
  std::cout << "Default constructor: Fixed a; a = " << a << std::endl;
  Fixed c(-5);
  std::cout << "Int constructor: Fixed b(10); b = " << b << std::endl;
  std::cout << "Int constructor: Fixed c(-5); c = " << c << std::endl;
  Fixed d(42.42f);
  Fixed e(-13.37f);
  std::cout << "Float constructor: Fixed d(42.42f); d = " << d << std::endl;
  std::cout << "Float constructor: Fixed e(-13.37f); e = " << e << std::endl;
  Fixed f(b);
  std::cout << "Copy constructor: Fixed f(b); f = " << f << std::endl;
  Fixed g;
  g = e;
  std::cout << "Assignment operator: g = e; g = " << g << std::endl;

  std::cout << "\n=== Arithmetic Operators ===\n";
  Fixed x(2.5f);
  Fixed y(1.5f);
  Fixed z1 = x + y;
  std::cout << x << " + " << y << " = " << z1 << std::endl;
  Fixed z2 = x - y;
  std::cout << x << " - " << y << " = " << z2 << std::endl;
  Fixed z3 = x * y;
  std::cout << x << " * " << y << " = " << z3 << std::endl;
  Fixed z4 = x / y;
  std::cout << x << " / " << y << " = " << z4 << std::endl;
  // Additional arithmetic tests
  Fixed m(10);
  Fixed n(0.5f);
  Fixed z5 = m / n;
  std::cout << m << " / " << n << " = " << z5 << std::endl;
  Fixed p(100);
  Fixed q(0.01f);
  Fixed z6 = p * q;
  std::cout << p << " * " << q << " = " << z6 << std::endl;

  std::cout << "\n=== Comparison Operators ===\n";
  std::cout << std::boolalpha;  // print bool as true/false
  Fixed X(2);
  Fixed Y(3);
  std::cout << X << " > " << Y << " ? " << (X > Y) << std::endl;
  std::cout << X << " < " << Y << " ? " << (X < Y) << std::endl;
  std::cout << X << " >= " << Y << " ? " << (X >= Y) << std::endl;
  std::cout << X << " <= " << Y << " ? " << (X <= Y) << std::endl;
  std::cout << X << " == " << Y << " ? " << (X == Y) << std::endl;
  std::cout << X << " != " << Y << " ? " << (X != Y) << std::endl;
  Fixed Y2(2);
  std::cout << X << " >= " << Y2 << " ? " << (X >= Y2) << std::endl;
  std::cout << X << " <= " << Y2 << " ? " << (X <= Y2) << std::endl;
  std::cout << X << " == " << Y2 << " ? " << (X == Y2) << std::endl;
  std::cout << X << " != " << Y2 << " ? " << (X != Y2) << std::endl;

  std::cout << "\n=== Increment/Decrement Operators ===\n";
  Fixed i(0);
  std::cout << "i = " << i << std::endl;
  std::cout << "i++ = " << i++ << std::endl;
  std::cout << "after i++, i = " << i << std::endl;
  std::cout << "++i = " << ++i << std::endl;
  std::cout << "after ++i, i = " << i << std::endl;
  std::cout << "i-- = " << i-- << std::endl;
  std::cout << "after i--, i = " << i << std::endl;
  std::cout << "--i = " << --i << std::endl;
  std::cout << "after --i, i = " << i << std::endl;
  Fixed j(2);
  std::cout << "j = " << j << std::endl;
  std::cout << "++j = " << ++j << std::endl;
  std::cout << "--j = " << --j << std::endl;

  std::cout << "\n=== min() / max() ===\n";
  Fixed u(10);
  Fixed v(20.5f);
  Fixed w(20.5f);
  std::cout << "min(" << u << ", " << v << ") = " << Fixed::min(u, v) << std::endl;
  std::cout << "max(" << u << ", " << v << ") = " << Fixed::max(u, v) << std::endl;
  std::cout << "min(" << v << ", " << w << ") = " << Fixed::min(v, w)
			<< " (both are equal)" << std::endl;
  const Fixed cu(u);
  const Fixed cv(v);
  std::cout << "min(const " << cu << ", const " << cv << ") = " << Fixed::min(cu, cv) << std::endl;
  std::cout << "max(const " << cu << ", const " << cv << ") = " << Fixed::max(cu, cv) << std::endl;

  std::cout << "\n=== Conversion toInt / toFloat ===\n";
  Fixed t1(5.5f);
  Fixed t2(-5.5f);
  std::cout << t1 << " as integer = " << t1.toInt() << std::endl;
  std::cout << t1 << " as float = " << t1.toFloat() << std::endl;
  std::cout << t2 << " as integer = " << t2.toInt() << std::endl;
  std::cout << t2 << " as float = " << t2.toFloat() << std::endl;
  Fixed t3(42);
  Fixed t4(42.125f);
  std::cout << t3 << " as float = " << t3.toFloat() << std::endl;
  std::cout << t4 << " as int = " << t4.toInt() << std::endl;

  std::cout << "\n=== getRawBits / setRawBits ===\n";
  Fixed r;
  std::cout << "r = " << r << ", raw bits = " << r.getRawBits() << std::endl;
  r.setRawBits(256);  // 256 corresponds to 1.0 in fixed-point (8 fractional bits)
  std::cout << "after setRawBits(256): r = " << r << ", raw bits = " << r.getRawBits() << std::endl;
  r.setRawBits(-256); // -256 corresponds to -1.0
  std::cout << "after setRawBits(-256): r = " << r << ", raw bits = " << r.getRawBits() << std::endl;

  return EXIT_SUCCESS;
}
