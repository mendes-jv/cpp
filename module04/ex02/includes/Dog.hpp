#ifndef DOG_HPP
# define DOG_HPP

# include <AAnimal.hpp>
# include <Brain.hpp>

class Dog : public AAnimal {
  Brain *_brain;
 public:
  Dog();

  Dog(const Dog &other);

  Dog &operator=(const Dog &other);

  virtual ~Dog();

  virtual void makeSound() const;

  std::string getIdea() const;

  void setIdea(const std::string &idea);
};

#endif //DOG_HPP
