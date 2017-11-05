#include "Bullets.hpp"

bool	Bullets::_flag = true;

Bullets::Bullets() : AEntities() {
	this->_x = 0;
	this->_y = 0;
	this->_type = '.';
}
Bullets::Bullets(int x, int y) : AEntities(x, y) {
	this->_x = x;
	this->_y = y;
	this->_type = '.';
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

bool	Bullets::getFlag() {
	return Bullets::_flag;
}

void	Bullets::setFlag() {
	if (Bullets::_flag)
		Bullets::_flag = false;
	else
		Bullets::_flag = true;
}

void	Bullets::initArray() {
	for (int i = 0; i < 50; ++i)
		bulletsArray[i] = NULL;
}

void	Bullets::createArray(int x, int y) {
	if (getFlag()) {
		initArray();
		setFlag();
	}
	for (int i = 0; i < 50; ++i)
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
	for (int i = 0; i < 50; ++i)
	{
		if (bulletsArray[i])
		{
			bulletsArray[i]->setY(y);
			if (bulletsArray[i]->getY() == 5)
//			{
				delete bulletsArray[i];
//				bulletsArray[i] = new Bullets(x, y);
//			}
		}
	}
}