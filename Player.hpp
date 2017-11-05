#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "AEntities.hpp"

class Player : public AEntities {

public:
	Player(void);
	Player(int x, int y);
	Player(Player const &);

	~Player(void);

	Player const	&operator=(Player const &rhs);
	void	move(int x, int y);
	int		getCHP(void) const;
	void	setCHP(int);

private:
	int		_cHP;
	int		_mHP;
	int		_points;
};

#endif