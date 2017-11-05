#include "Bullets.hpp"

Bullets::Bullets() : AEntities() {
	this->_x = 0;
	this->_y = 0;
	this->_type = '|';
}
Bullets::Bullets(int x, int y) : AEntities(x, y) {
	this->_x = x;
	this->_y = y;
	this->_type = '|';
}
Bullets::Bullets(Bullets const &rhs) : AEntities(rhs) {
	this->_x = rhs.getY();
	this->_y = rhs.getY();
	this->_type = rhs._type;
}

Bullets::~Bullets() {}

Bullets const & Bullets::operator=(Bullets const &rhs) {
	if (this != &rhs) {
		this->_x = rhs._x;
		this->_y = rhs._y;
		this->_type = rhs._type;
	}
	return *this;
}

void	Bullets::initArray() {
	for (int i = 0; i < B; ++i)
		bulletsArray[i] = NULL;
}

void	Bullets::createArray(int x, int y) {
	for (int i = 0; i < B; ++i)
	{
		if (bulletsArray[i] == NULL) {
			bulletsArray[i] = new Bullets(x, y);
			return;
		}
	}
}

void	Bullets::move(int x, int y) {
	x = -1;
	y = x;
	for (int i = 0; i < B; ++i)
	{
		if (bulletsArray[i])
		{
			bulletsArray[i]->setY(y);

			if (bulletsArray[i]->getY() == 0)
			{
				delete bulletsArray[i];
				bulletsArray[i] = NULL;
			}
		}
	}
}
