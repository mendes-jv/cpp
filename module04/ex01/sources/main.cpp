#include <iostream>
#include <cstdlib>
#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>

int main() {
  std::string green = "\033[1;32m";
  std::string red = "\033[1;31m";
  std::string blue = "\033[1;34m";
  std::string reset = "\033[0m";

  std::cout << green << "\t//MY MAIN TESTS//\n\n" << reset
			<< blue << "Creating Animal object" << reset
			<< std::endl;
  Animal *animal = new Animal();
  std::cout << red << "Animal type: " << animal->getType() << reset << std::endl;
  animal->makeSound();
  delete animal;

  std::cout << blue << "\nCreating Animal object with Cat type" << reset << std::endl;
  animal = new Cat();
  std::cout << red << "Animal type: " << animal->getType() << reset << std::endl;
  animal->makeSound();
  delete animal;

  std::cout << blue << "\nCreating Animal object with Dog type" << reset << std::endl;
  animal = new Dog();
  std::cout << red << "Animal type: " << animal->getType() << reset << std::endl;
  animal->makeSound();
  delete animal;

  std::cout << blue << "\nCreating Animal array" << reset << std::endl;
  Animal *animals[4];
  for (int i = 0; i < 2; ++i) {
	animals[i] = new Dog();
	std::cout << red << "Animal type: " << animals[i]->getType() << reset << std::endl;
	animals[i]->makeSound();
  }
  for (int i = 2; i < 4; ++i) {
	animals[i] = new Cat();
	std::cout << red << "Animal type: " << animals[i]->getType() << reset << std::endl;
	animals[i]->makeSound();
  }
  for (int i = 0; i < 4; ++i) {
	delete animals[i];
  }
  std::cout << blue << "\nCheck deep copy" << reset << std::endl;
  Dog dog1;
  dog1.setIdea("42");
  Dog dog2(dog1);
  dog2.setIdea("42++");
  std::cout << red << "Dog1 idea: " << dog1.getIdea() << reset << std::endl;
  std::cout << red << "Dog2 idea: " << dog2.getIdea() << reset << std::endl;
  dog2.setIdea("Woof");
  std::cout << red << "Dog1 idea: " << dog1.getIdea() << reset << std::endl;
  std::cout << red << "Dog2 idea: " << dog2.getIdea() << reset << std::endl;
  std::cout << red << "Dog1 type: " << dog1.getType() << reset << std::endl;
  std::cout << red << "Dog2 type: " << dog2.getType() << reset << std::endl;

  std::cout << blue << "\nCheck assignment operator" << reset << std::endl;
  Dog dog3;
  dog3 = dog1;
  std::cout << red << "Dog3 type: " << dog3.getType() << reset << std::endl;

  std::cout << blue << "\nCheck memory leak" << reset << std::endl;
  Dog *dog4 = new Dog();
  std::cout << red << "Dog4 type: " << dog4->getType() << reset << std::endl;

  std::cout << blue << "\nCheck memory leak" << reset << std::endl;
  Cat *cat1 = new Cat();
  Cat *cat2 = new Cat();
  std::cout << red << "Cat1 type: " << cat1->getType() << reset << std::endl;
  std::cout << red << "Cat2 type: " << cat2->getType() << reset << std::endl;
  std::cout << blue << "\nCheck memory leak" << reset << std::endl;
  Dog basicDog;
  {
	Dog tmpDog = basicDog;
  }
  Cat basicCat;
  {
	Cat tmpCat = basicCat;
  }

  std::cout << blue << "\nDestructors" << reset << std::endl;
  delete dog4;
  delete cat1;
  delete cat2;
  return EXIT_SUCCESS;
}
