#include <iostream>
#include <cstdlib>
#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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

  std::cout << blue << "\nCreating WrongAnimal object" << reset << std::endl;
  WrongAnimal *wrongAnimal = new WrongAnimal();
  std::cout << red << "WrongAnimal type: " << wrongAnimal->getType() << reset << std::endl;
  wrongAnimal->makeSound();
  delete wrongAnimal;

  std::cout << blue << "\nCreating WrongAnimal object with WrongCat type" << reset << std::endl;
  WrongCat *wrongCat = new WrongCat();
  wrongAnimal = wrongCat;
  std::cout << red << "WrongAnimal type: " << wrongAnimal->getType() << reset << std::endl;
  wrongAnimal->makeSound();
  std::cout << red << "WrongCat type: " << wrongCat->getType() << reset << std::endl;
  wrongCat->makeSound();
  delete wrongCat;

  return EXIT_SUCCESS;
}
