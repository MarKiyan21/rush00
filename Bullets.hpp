#ifndef BULLETS_HPP
# define BULLETS_HPP

# include "AEntities.hpp"

class	Bullets : public AEntities {

public:
	Bullets(void);
	Bullets(int x, int y);
	Bullets(Bullets const &);

	~Bullets(void);

	Bullets const	&operator=(Bullets const &rhs);
	void	move(int, int);
	Bullets	*bulletsArray[B];
	void	initArray();
	void	createArray(int, int);

};

#endif