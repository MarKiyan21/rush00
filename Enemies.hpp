#ifndef ENEMIES_HPP
# define ENEMIES_HPP

# include "AEntities.hpp"
# include "Player.hpp"

class Enemies : public AEntities {

public:
	Enemies(void);
	Enemies(int x, int y, char type);
	Enemies(Enemies const &);

	~Enemies(void);

	Enemies const	&operator=(Enemies const &rhs);
	void	move(int x, int y);
	Enemies	*enemiesArray[50];
	void	initArray();
	void	createEnemy();
//	bool	collision(Player*&);
	void	bam(int);
	bool	getFlag();
	void	setFlag();

private:
	static bool	_flag;

};

#endif