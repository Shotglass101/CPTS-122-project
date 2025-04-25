#pragma once
#include "GamePlay.hpp" 

class Territory
{
public:
	Territory();
	Territory(string newName, string newRegion, int x, int y, string newOccupier, int newRep, int armie_amount);
	~Territory();

	//Getter Functions
	string getName();
	string getRegion();
	string getOccupier();
	int getRepNum();
	int getArmies();
	int getX();
	int getY();  

	//Setter Functions
	void setName(string newName);
	void setRegion(string newRegion);
	void setOccupier(string newOccupier);
	void setRepNum(int newRepNum);
	void setArmies(int amount);


private:
	string name;
	string region;
	int x;
	int y;
	string occupier; 
	int rep_num;
	int armies;
};
