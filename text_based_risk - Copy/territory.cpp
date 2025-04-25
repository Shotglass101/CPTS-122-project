#include "Territory.hpp"



Territory::Territory()
{
	name = "";
	region = "";
	occupier = "";
	rep_num = 0;
	armies = 0;
}

Territory::Territory(string newName, string newRegion, int Newx, int Newy, string newOccupier, int newRep, int armie_amount)
{
	name = newName;
	region = newRegion;
	occupier = newOccupier;
	x = Newx;
	y = Newy; 
	rep_num = newRep;
	armies = armie_amount;
}

Territory::~Territory()
{
}

string Territory::getName()
{
	return this->name;
}

string Territory::getRegion()
{
	return this->region;
}

string Territory::getOccupier()
{
	return this->occupier;
}

int Territory::getRepNum()
{
	return this->rep_num;
}

int Territory::getArmies()
{
	return this->armies;
}

int Territory::getX()
{
	return this->x; 
}

int Territory::getY()
{
	return this->y; 
}

void Territory::setName(string newName)
{
	this->name = newName;
}

void Territory::setRegion(string newRegion)
{
	this->region = newRegion;
}

void Territory::setOccupier(string newOccupier)
{
	this->occupier = newOccupier;
}

void Territory::setRepNum(int newRepNum)
{
	this->rep_num = newRepNum;
}

void Territory::setArmies(int amount)
{
	this->armies = amount;
}
