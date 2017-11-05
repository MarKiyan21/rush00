#include "Enemies.hpp"

bool	Enemies::_flag = true;

Enemies::Enemies() : AEntities() {
	char	tab[2] = {'*', '^'};
	this->_x = rand() % W;
	this->_y = 0;
	this->_type = tab[rand() % 2];
}
Enemies::Enemies(int x, int y) : AEntities(x, y) {
	char	tab[2] = {'*', '^'};
	this->_x = rand() % W;
	this->_y = 0;
	this->_type = tab[rand() % 2];
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

bool	Enemies::getFlag() {
	return Enemies::_flag;
}

void	Enemies::setFlag() {
	if (Enemies::_flag)
		Enemies::_flag = false;
	else
		Enemies::_flag = true;
}

void	Enemies::initArray() {
	for (int i = 0; i < 50; ++i)
		enemiesArray[i] = NULL;
}

void	Enemies::createArray() {
	if (getFlag()) {
		initArray();
		setFlag();
	}
	for (int i = 0; i < 50; ++i)
	{
		if (enemiesArray[i] == NULL) {
			enemiesArray[i] = new Enemies();
			return;
		}
	}
}

void	Enemies::move(int x, int y) {
	for (int i = 0; i < 50; ++i)
	{
		if (enemiesArray[i])
		{
			enemiesArray[i]->setY(y);
			enemiesArray[i]->setX(x);
			if (enemiesArray[i]->getY() == H)
			{
				delete enemiesArray[i];
				enemiesArray[i] = new Enemies();
			}
		}
	}
}