#ifndef ENEMIES_HPP
# define ENEMIES_HPP

# include "AEntities.hpp"

class Enemies : public AEntities {

public:
	Enemies(void);
	Enemies(int x, int y);
	Enemies(Enemies const &);

	~Enemies(void);

	Enemies const	&operator=(Enemies const &rhs);
	void	move(int x, int y);
//	Enemies*	newEnemies();

private:

};

#endif