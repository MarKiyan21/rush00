#include "Enemies.hpp"

Enemies::Enemies() : AEntities() {
	this->_x = rand() % W;
	this->_y = 0;
	this->_type = '*';
}
Enemies::Enemies(int x, int y) : AEntities(x, y) {
	this->_x = rand() % W;
	this->_y = 0;
	this->_type = '*';
}
Enemies::Enemies(Enemies const &rhs) : AEntities(rhs) {
	this->_x = rhs.getY();
	this->_y = rhs.getY();
	this->_type = rhs._type;
}

Enemies::~Enemies() {}

Enemies const & Enemies::operator=(Enemies const &rhs) {
	if (this != &rhs) {
		this->_x = rhs._x;
		this->_y = rhs._y;
		this->_type = rhs._type;
	}
	return *this;
}

void	Enemies::move(int x, int y) {
	setX(x);
	setY(y);
//	if (this->getX() >= W1)
//		this->_x = W-2;
//	if (this->getY() >= H1)
//		this->_y = H-2;
//	if ( this->getX() <= 1)
//		this->_x = 1;
//	if (this->getY() <= 1)
//		this->_y = 1;
}