#include "GamePlay.hpp"
#include "TerritoryArray.hpp"
#include "Territory.hpp" 


//p1 is the attacker, p2 is the defender

//This function represents the dice in the game. In this function, the players get as many dice as their armies minus 1
//The attacking armies can have a maximum of 3 dice, and the defending dice can have a maximum of 2 dice
//The function compares the dice based on the highest rolls and determines how many armies are lost for both sides
//The armies are passed in by reference so that the armies passed in can be edited based on the dice roll

//Made by: Jillian McBride
void GamePlay::dice_throw(int& p1_armies, int& p2_armies)
{
	TerritoryArray board(18);   

int total_armies = 2;

char y_n = ' ';

bool win = false; 

int origin = 0;
int attack = 0; 

board.divideTerritories(); 

//board.print_players_territories(); 


while (win == false)
{
	//////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////Player 1's turn//////////////////////////////////////////
	cout << "Player 1's turn" << endl;

	total_armies += board.check_continent("P1");  

	cout << "Player 1 gets " << total_armies << " armies this turn" << endl; 
	
	
	board.add_more_armies(total_armies, "P1");

	cout << "Would you like to attack? Type y for yes type n for no" << endl;
	cin >> y_n;

	while(y_n == 'y')   
	{
		for (int i = 0; i < 18; i++)
		{
			if (board.getIndex(i).getOccupier() == "P1")
			{
				cout << "Representative Number: " << board.getIndex(i).getRepNum() << endl;
				cout << "Name: " << board.getIndex(i).getName() << endl;
				cout << "Region: " << board.getIndex(i).getRegion() << endl;
				cout << "Current Armies: " << board.getIndex(i).getArmies() << endl;
				cout << "\n" << endl;
			}
		}
		cout << "Where would you like to attack from? Please enter the terrritories representative number" << endl;

		cin >> origin;


		while (board.getIndex(origin).getOccupier() != "P1" || board.getIndex(origin).getArmies() < 2 || board.has_enemies(origin, "P2") == false )
		{
			if (board.getIndex(origin).getOccupier() != "P1")
			{
				cout << "You don't own that territory. Please enter a territory that you own: " << endl;
				cin >> origin;
			}
			if (board.getIndex(origin).getArmies() < 2)
			{
				cout << "You don't have enough armies in that territory to attack. Please select another territory" << endl;
				cin >> origin; 
			}
			if (board.has_enemies(origin, "P2") == false)
			{
				cout << "This territory doesn't border anything you can attack. Try again" << endl;
				cin >> origin;
			}
			
		}

		
		for (int i = 0; i < 18; i++)
		{
			if (board.getIndex(i).getOccupier() == "P2")
			{
				cout << "Representative Number: " << board.getIndex(i).getRepNum() << endl;
				cout << "Name: " << board.getIndex(i).getName() << endl;
				cout << "Region: " << board.getIndex(i).getRegion() << endl;
				cout << "Current Armies" << board.getIndex(i).getArmies() << endl;
				cout << "\n" << endl;
			}
		}
	
		cout << "Where would you like to attack to? Please enter the terrritories representative number" << endl;
		cin >> attack;

		
		bool world_of_coco_andies = board.check_borders(origin, attack);

		while (world_of_coco_andies == false)
		{
			if (world_of_coco_andies == false)
			{
				cout << "Please pick a territory that borders your own" << endl; 
				cin >> attack;
				
			} 
			world_of_coco_andies = board.check_borders(origin, attack); 
		}
		
		int attack_armies = board.getIndex(origin).getArmies();
		int defend_armies = board.getIndex(attack).getArmies();

		cout << "\n\n You want to attack from the " << board.getIndex(origin).getName() << " to " << board.getIndex(attack).getName() << endl;

		dice_throw(attack_armies, defend_armies);

		board.getIndex(origin).setArmies(attack_armies);
		board.getIndex(attack).setArmies(defend_armies);

		cout << "Current Attackers Armies: " << board.getIndex(origin).getArmies() << endl;
		cout << "Current Defender Armies: " << board.getIndex(attack).getArmies() << endl;

		if (board.getIndex(attack).getArmies() == 0)
		{
			cout << "\nYou got a new Territory!" << endl;
			board.getIndex(attack).setOccupier("P1");
			cout << board.getIndex(attack).getOccupier() << endl;
			board.getIndex(attack).setArmies(1);
			board.getIndex(origin).setArmies(board.getIndex(origin).getArmies() - 1);
		}
		     
		y_n = 'n'; 
	}

	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////Player 2/////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cout << "\n\n\nPlayer 2's turn: " << endl; 

	cout << "Player 2's turn" << endl;

	total_armies = 2; 

	total_armies += board.check_continent("P2");

	cout << "Player 2 gets " << total_armies << " armies this turn" << endl;

	board.add_more_armies(total_armies, "P2");

	cout << "Would you like to attack? Type y for yes type n for no" << endl;
	cin >> y_n;

	if (y_n == 'y')
	{

		for (int i = 0; i < 18; i++)
		{
			if (board.getIndex(i).getOccupier() == "P2")
			{
				cout << "Representative Number: " << board.getIndex(i).getRepNum() << endl;
				cout << "Name: " << board.getIndex(i).getName() << endl;
				cout << "Region: " << board.getIndex(i).getRegion() << endl;
				cout << "Current Armies" << board.getIndex(i).getArmies() << endl;
				cout << "\n" << endl;
			}
		}

		cout << "Where would you like to attack from? Please enter the terrritories representative number" << endl;

		cin >> origin;

		while (board.getIndex(origin).getOccupier() != "P2"|| board.getIndex(origin).getArmies() < 2 || board.has_enemies(origin, "P1") == false)
		{
			if (board.getIndex(origin).getOccupier() != "P2")
			{
				cout << "You don't own that territory. Please enter a territory that you own: " << endl;
				cin >> origin;
			}
			if (board.getIndex(origin).getArmies() < 2)
			{
				cout << "You don't have enough armies in that territory to attack. Please select another territory" << endl;
				cin >> origin;
			}
			if (board.has_enemies(origin, "P1") == false)  
			{
				cout << "This territory doesn't border anything you can attack." << endl;
				cin >> origin;
			}

		}

		

		for (int i = 0; i < 18; i++)
		{
			if (board.getIndex(i).getOccupier() == "P1")
			{
				cout << "Representative Number: " << board.getIndex(i).getRepNum() << endl;
				cout << "Name: " << board.getIndex(i).getName() << endl;
				cout << "Region: " << board.getIndex(i).getRegion() << endl;
				cout << "Current Armies" << board.getIndex(i).getArmies() << endl;
				cout << "\n" << endl;
			}
		}
		cout << "Where would you like to attack to? Please enter the terrritories representative number" << endl;
		cin >> attack;

		
		bool world_of_coco_andies = board.check_borders(origin, attack);
		
		while (world_of_coco_andies == false)
		{
			if (world_of_coco_andies == false)
			{
				cout << "Please pick a territory that borders your own" << endl;
				cin >> attack;

			}
			world_of_coco_andies = board.check_borders(origin, attack);
		}
		

		int attack_armies = board.getIndex(origin).getArmies();
		int defend_armies = board.getIndex(attack).getArmies();

		cout << "\n\n You want to attack from the " << board.getIndex(origin).getName() << " to " << board.getIndex(attack).getName() << endl;

		dice_throw(attack_armies, defend_armies);


		board.getIndex(origin).setArmies(attack_armies);
		board.getIndex(attack).setArmies(defend_armies);

		cout << "Current Attackers Armies: " << board.getIndex(origin).getArmies() << endl;
		cout << "Current Defender Armies: " << board.getIndex(attack).getArmies() << endl;

		if (board.getIndex(attack).getArmies() == 0)
		{
			cout << "\nYou got a new Territory!" << endl;
			board.getIndex(attack).setOccupier("P2");
			cout << board.getIndex(attack).getOccupier() << endl;
			board.getIndex(attack).setArmies(1);
			board.getIndex(origin).setArmies(board.getIndex(origin).getArmies() - 1);
		}
	}

	win = board.check_win();  
	   
}


}
