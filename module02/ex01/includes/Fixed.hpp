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

  Fixed &operator=(const Fixed &other);

  ~Fixed();

  int getRawBits() const;

  void setRawBits(const int raw);

  float toFloat() const;

  int toInt() const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif //FIXED_HPP
