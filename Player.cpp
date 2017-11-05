#include "Player.hpp"

Player::Player() : AEntities() {
	this->_x = W/2;
	this->_y = H - 2;
	this->_type = '-';
	this->_cHP = 100;
	this->_mHP = 100;
	this->_points = 0;
}
Player::Player(int x, int y) : AEntities(x, y) {
	this->_x = W/2;
	this->_y = H - 2;
	this->_type = '-';
	this->_cHP = 100;
	this->_mHP = 100;
	this->_points = 0;
}
Player::Player(Player const &rhs) : AEntities(rhs) {
	this->_x = rhs.getY();
	this->_y = rhs.getY();
	this->_type = rhs._type;
	this->_cHP = rhs._cHP;
	this->_mHP = rhs._mHP;
	this->_points = rhs._points;
}

Player::~Player() {}

Player const & Player::operator=(Player const &rhs) {
	if (this != &rhs) {
		this->_x = rhs._x;
		this->_y = rhs._y;
		this->_live = rhs._live;
		this->_type = rhs._type;
	}
	return *this;
}

void	Player::move(int x, int y) {
	setX(x);
	setY(y);
	if (this->getX() >= W1)
		this->_x = W-2;
	if (this->getY() >= H1)
		this->_y = H-2;
	if ( this->getX() <= 1)
		this->_x = 1;
	if (this->getY() <= 1)
		this->_y = 1;
}

void	Player::setCHP(int number) {
	this->_cHP += number;
	if (this->_cHP >= this->_mHP)
		this->_cHP = this->_mHP;
}

int		Player::getCHP() const {
	return this->_cHP;
}