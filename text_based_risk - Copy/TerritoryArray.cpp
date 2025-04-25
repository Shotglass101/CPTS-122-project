#include "TerritoryArray.hpp"

TerritoryArray::~TerritoryArray()
{
}

void TerritoryArray::print()
{
	for (int i = 0; i < 18; i++)
	{
		cout << "Name:" << this->masterList[i].getName() << endl;
		cout << "Region: " << this->masterList[i].getRegion() << endl;
		cout << "Rep Number: " << this->masterList[i].getRepNum() << endl;
		cout << "Player: " << this->masterList[i].getOccupier() << endl; 
		cout << "\n" << endl;
	}
}

void TerritoryArray::divideTerritories()
{
	int territory_amount = 0;
	int territory_num = 0;

	while (territory_amount < 9)
	{
		territory_num = rand() % 18;


		while (this->masterList[territory_num].getOccupier() != " ")
		{
			territory_num = rand() % 18;
		}

		this->masterList[territory_num].setOccupier("P1");
		this->masterList[territory_num].setArmies(1);
		territory_amount++;
	}

	for (int i = 0; i < 18; i++)
	{
		if (this->masterList[i].getOccupier() == " ")
		{
			this->masterList[i].setOccupier("P2");
			this->masterList[i].setArmies(1);
		}
	}
}

void TerritoryArray::print_players_territories()
{
	cout << "Player 1's territories: " << endl;
	for (int i = 0; i < 18; i++)
	{
		if (this->masterList[i].getOccupier() == "P1")
		{
			cout << "Name: " << this->masterList[i].getName() << endl;
			cout << "Region: " << this->masterList[i].getRegion() << endl;
			cout << "Rep Number: " << this->masterList[i].getRepNum() << endl;
			cout << "Army Count: " << this->masterList[i].getArmies() << endl;
			cout << "\n" << endl;
		}
	}

	cout << "\n\n" << endl;
	cout << "Player 2's territories: " << endl;

	for (int i = 0; i < 18; i++)
	{
		if (this->masterList[i].getOccupier() == "P2")
		{
			cout << "Name: " << this->masterList[i].getName() << endl;
			cout << "Region: " << this->masterList[i].getRegion() << endl;
			cout << "Rep Number: " << this->masterList[i].getRepNum() << endl;
			cout << "Army Count: " << this->masterList[i].getArmies() << endl;
			cout << "\n" << endl;
		}
	}
}

bool TerritoryArray::check_win()
{
	int p1_territory_count = 0;
	int p2_territory_count = 0;

	bool win = false; 

	for (int i = 0; i < 18; i++)
	{
		
		if (this->masterList[i].getOccupier() == "P1")
		{
			p1_territory_count++; 
			
		}
		else if (this->masterList[i].getOccupier() == "P2")
		{
			p2_territory_count++; 
			
		}
	}

	if (p1_territory_count == 18)
	{
		cout << "Player 1 wins!" << endl;
		win = true;
	}
	else if (p2_territory_count == 18)
	{
		cout << "Player 2 wins!" << endl;
		win = true;
	}

	return win;   


}

void TerritoryArray::add_more_armies(int army_amount, string player) 
{

	int selection = 0; 
	for (int i = 0; i < 18; i++)
	{
		if (this->masterList[i].getOccupier() == player) 
		{
			cout << "Representative Number: " << this->masterList[i].getRepNum() << endl; 
			cout << "Name: " << this->masterList[i].getName() << endl;
			cout << "Region: " << this->masterList[i].getRegion() << endl;
			cout << "Current Number of Armies: " << this->masterList[i].getArmies() << endl;
			cout << "\n" << endl; 
		}
	}

	cout << "\n You have " << army_amount << " of armies" << endl; 

	for (int i = 0; i < army_amount; i++)
	{
		cout << "Where would you like to put your army? Please type the representative number for the terriotry" << endl;
		cin >> selection;  


		for (int i = 0; i < 18; i++)
		{ 
			if (this->masterList[i].getRepNum() == selection) 
			{
				
				this->masterList[i].setArmies(this->masterList[i].getArmies() + 1); 
				

			}
		}


	}
}

int TerritoryArray::check_continent(string player)
{
	int northside = 0; 
	int southside = 0;
	int greek_row = 0;
	int hillside = 0;
	int farmland = 0; 

	int total = 0; 

	for (int i = 0; i < 18; i++)
	{
		if (this->masterList->getOccupier() == player && this->masterList->getRegion() == "Northside")
		{
			northside++;
		}
		else if (this->masterList->getOccupier() == player && this->masterList->getRegion() == "Southside")
		{
			southside++;
		}
		else if (this->masterList->getOccupier() == player && this->masterList->getRegion() == "Hillside")
		{
			hillside++;  
		}
		else if (this->masterList->getOccupier() == player && this->masterList->getRegion() == "Greek Row") 
		{
			greek_row++; 
		}
		else if (this->masterList->getOccupier() == player && this->masterList->getRegion() == "Farmland")
		{
			farmland++; 
		}
	}

	if (northside == 5)
	{
		total += 4;
	}
	if (southside == 5)
	{
		total += 4; 
	}
	if (hillside == 3)
	{
		total += 3; 
	}
	if (greek_row == 2)
	{
		total += 2;
	}
	if (farmland == 2)
	{
		total += 2; 
	}

	return total; 


}

Territory& TerritoryArray::getIndex(int index)
{
	return this->masterList[index]; 
}
