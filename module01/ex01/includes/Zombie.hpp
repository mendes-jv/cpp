#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
    std::string _name;

    void denounce() const;

public:
    void announce() const;

    Zombie();

    explicit Zombie(const std::string &name);

    ~Zombie();

    void setName(const std::string &name);
};

Zombie *newZombie(const std::string &name);

Zombie *zombieHorde(int size, const std::string &name);

void randomChump(const std::string &name);

#endif //ZOMBIE_HPP
