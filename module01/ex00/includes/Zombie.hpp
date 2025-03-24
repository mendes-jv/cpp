#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
    std::string _name;

    void announce() const;

    void denounce() const;

public:
    explicit Zombie(const std::string &name);

    ~Zombie();
};

Zombie *newZombie(const std::string &name);

void randomChump(const std::string &name);

#endif //ZOMBIE_HPP
