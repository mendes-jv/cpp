#ifndef CAT_HPP
# define CAT_HPP

# include <AAnimal.hpp>
# include <Brain.hpp>

class Cat : public AAnimal {
  Brain *_brain;
 public:
  Cat();

  Cat(const Cat &other);

  Cat &operator=(const Cat &other);

  virtual ~Cat();

  virtual void makeSound() const;

  std::string getIdea() const;

  void setIdea(const std::string &idea);
};

#endif //CAT_HPP
