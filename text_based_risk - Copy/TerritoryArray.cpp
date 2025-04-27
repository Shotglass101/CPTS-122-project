#include "TerritoryArray.hpp"
//Entire file made by: Jillian McBride
TerritoryArray::~TerritoryArray()
{
}

//This function prints out the masterList. Takes no inputs or outputs
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

//This function divides the territories evenly and randomly between player 1 and player 2
//Also takes no inputs or outputs
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

//This function prints the players territories that they currently own in the game
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

//This function checks to see if all of the territories have one occupier.
//It checks to see if all of the territories either all have "P1" as their occupier, or "P2"
//Takes no inputs or outputs
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

//This function adds more armies to a territory of the player's choosing. It takes a input of a integar 
//for the amount of armies wthe player is distributing, and a string with the player's name. 
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
		court << "List of enemy borders:" << endl; 
		 list_borders(i, player); 
		cout << "\n" << endl; 
	}
}

cout << "\n You have " << army_amount << " of armies" << endl; 

for (int i = 0; i < army_amount; i++)
{
	cout << "Where would you like to put your army? Please type the representative number for the terriotry" << endl;
	cin >> selection;  

	while (this->masterList[selection].getOccupier() != player)
	{
		cout << "You can't put an army there because you don't own that territory. Make another selection" << endl; 
		cin >> selection; 
	}

	for (int i = 0; i < 18; i++)
	{ 
		if (this->masterList[i].getRepNum() == selection) 
		{
			
			this->masterList[i].setArmies(this->masterList[i].getArmies() + 1); 
			

		}
	}


}
}

//This function chekcs to see if a player has gained a continent or not. It takes a input of the player's name, 
//and outputs the total number of armies they should have. If the player doesn't get a continent, then it just returns 0.
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

//This function was created to check and see if the territory that the user wants to attack from actually has a border with a enemy territory. 
//This way, we can better avoid a situation were a player chooses to attack from a territory, but there's no other territory that borders it to attack. 
bool TerritoryArray::has_enemies(int terrtiory, string opp_player)
{
	bool yes = false; 

	for (int i = 0; i < 18; i++)
	{
		if (check_borders(terrtiory, i) == true && this->masterList[i].getOccupier() == opp_player)
		{
			yes = true; 
			break; 
		}
	}

	return yes; 
}

//this function lists out all the borders that a territory has that isn't owned by the player inputed into the function. The territory is represented 
//by the number inputed into the function
void TerritoryArray::list_borders(int territory, string player)
{
	for (int i = 0; i < 18; i++)
	{
		if (check_borders(territory, i) == true && this->masterList[i].getOccupier() != player)
		{
			cout << this->masterList[i].getName() << endl; 
		}
	}
}

//This function returns the territory at the specific index that is inputed into the function
Territory& TerritoryArray::getIndex(int index)
{
	return this->masterList[index]; 
}
