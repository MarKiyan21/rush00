#include "AEntities.hpp"

AEntities::AEntities() : _x(0), _y(0), _type('.') {}
AEntities::AEntities(int x, int y) : _x(x), _y(y), _type('.') {}
AEntities::AEntities(AEntities const &rhs) : _x(rhs._x), _y(rhs._y), _type(rhs._type) {}

AEntities const	& AEntities::operator=(AEntities const &rhs) {
	if (this != &rhs) {
		_x = rhs._x;
		_y = rhs._y;
		_type = rhs._type;
	}
	return *this;
}

AEntities::~AEntities() {}

int		AEntities::getX() const {
	return this->_x;
}

int		AEntities::getY() const {
	return this->_y;
}

void	AEntities::setX(int x) {
	this->_x += x;
}

void	AEntities::setY(int y) {
	this->_y += y;
}

//bool	AEntities::getLive() const {
//	this->_live;
//}
//
char *	AEntities::getType() {
	return &this->_type;
}

bool	AEntities::collision(AEntities &elem) {
	return (_x == elem.getX() && _y == elem.getY());
}