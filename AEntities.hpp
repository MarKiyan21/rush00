#ifndef ENTITIES_HPP
# define ENTITIES_HPP

# include <iostream>
# include <ncurses.h>
# include <unistd.h>

# define H 50
# define W 150
# define H1 H-1
# define W1 W-1

class	AEntities {

public:
	AEntities(void);
	AEntities(int x, int y);
	AEntities(AEntities const &);

	virtual ~AEntities(void);

	AEntities const	&operator=(AEntities const &rhs);
	virtual void	move(int x, int y) = 0;
	bool			collision(AEntities*&);
	int				getX(void) const;
	int				getY(void) const;
	void			setX(int x);
	void			setY(int y);
	char *			getType(void);
//	bool			getLive(void) const;

protected:
	int		_x;
	int		_y;
	bool	_live;
	char	_type;
};

#endif