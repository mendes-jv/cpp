#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {
  std::string ideas[100];
 public:
  Brain();

  Brain(const Brain &other);

  Brain &operator=(const Brain &other);

  ~Brain();

  std::string getIdea() const;

  void setIdea(const std::string &idea);
};

#endif //BRAIN_HPP
