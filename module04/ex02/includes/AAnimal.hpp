#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal {
 protected:
  std::string _type;
 public:
  AAnimal();

  AAnimal(const AAnimal &other);

  AAnimal &operator=(const AAnimal &other);

  virtual ~AAnimal();

  std::string getType() const;

  virtual void makeSound() const = 0;
};

#endif //AANIMAL_HPP
