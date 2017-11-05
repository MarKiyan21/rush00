#include "Enemies.hpp"

bool	Enemies::_flag = true;

Enemies::Enemies() : AEntities() {
	this->_x = rand() % W;
	this->_y = 0;
	this->_type = '*';
}
Enemies::Enemies(int x, int y, char type) : AEntities(x, y) {
	this->_x = rand() % W;
	this->_y = 0;
	this->_type = type;
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

void	Enemies::createEnemy() {
	char	type[2] = {'*', '^'};
	if (getFlag()) {
		initArray();
		setFlag();
	}
	for (int i = 0; i < 50; ++i)
	{
		if (enemiesArray[i] == NULL) {
			enemiesArray[i] = new Enemies(0, 0, type[rand() % 2]);
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

void	Enemies::bam(int index) {
	for (int i = 0; i < 50; ++i)
	{
		if (enemiesArray[i])
			if (i == index) {
				delete enemiesArray[i];
				enemiesArray[i] = new Enemies();
			}
	}
}

//bool	Enemies::collision(Player* &elem) {
//	return (_x == elem->getX() && _y == elem->getY());
//}