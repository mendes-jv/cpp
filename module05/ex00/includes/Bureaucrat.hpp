#pragma once

#include <iostream>

class Bureaucrat {
 private:
  const std::string _name;
  int _grade;
 public:
  Bureaucrat();

  Bureaucrat(const std::string &name, int grade);

  Bureaucrat(const Bureaucrat &other);

  Bureaucrat &operator=(const Bureaucrat &other);

  ~Bureaucrat();

  Bureaucrat(const std::string &name, int grade) const;

  const std::string &getName() const;

  int &getGrade() const;

  void rankUp();

  void rankDown();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
