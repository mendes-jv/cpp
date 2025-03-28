#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
  int _numberValue;
  static const int _fractionalBits;
 public:
  Fixed();

  Fixed(const Fixed &other);

  Fixed(const int number);

  Fixed(const float number);

  bool operator>(const Fixed &other) const;

  bool operator<(const Fixed &other) const;

  bool operator>=(const Fixed &other) const;

  bool operator<=(const Fixed &other) const;

  bool operator==(const Fixed &other) const;

  bool operator!=(const Fixed &other) const;

  Fixed operator+(const Fixed &other) const;

  Fixed operator-(const Fixed &other) const;

  Fixed operator*(const Fixed &other) const;

  Fixed operator/(const Fixed &other) const;

  Fixed &operator++();

  Fixed operator++(int);

  Fixed &operator--();

  Fixed operator--(int);

  Fixed &operator=(const Fixed &other);

  ~Fixed();

  int getRawBits() const;

  void setRawBits(const int raw);

  float toFloat() const;

  int toInt() const;

  static Fixed &min(Fixed &a, Fixed &b);

  static const Fixed &min(const Fixed &a, const Fixed &b);

  static Fixed &max(Fixed &a, Fixed &b);

  static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif //FIXED_HPP
