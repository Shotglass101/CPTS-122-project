#include "adjacencyMatrix.hpp"
/*
*/

#pragma once

#include "Territory.hpp"

class TerritoryArray : public AdjacencyMatrix
{
public:
	
	TerritoryArray(int vertexCount) : AdjacencyMatrix(vertexCount)
	{
		std::ifstream input;

		int repNum = 0;
		string occupier = " ";
		string name = " ";
		string region = " ";
		string xStr = "";
		string yStr = ""; 

		int x = 0;
		int y = 0; 
		int armies = 0;

		string line = " ";
		string temp = " ";

		std::vector<int> V;

		input.open("MasterList.csv");


		if (!input)
		{
			cout << "File Can't open" << endl;
		}
		else
		{
			int rowNumber = 0;

			while (std::getline(input, temp, ','))
			{
				repNum = atoi(temp.c_str());

				std::getline(input, name, ',');

				std::getline(input, region, ','); 

				std::getline(input, xStr, ',');

				

				
				std::getline(input, yStr, ',');



				x = atoi(xStr.c_str());
				y = atoi(yStr.c_str());

				//cout << x << endl;
				//cout << y << endl;
				//cout << "\n" << endl;
				Territory newTerritory(name, region,x,y,occupier, repNum, armies); 

				masterList[repNum] = newTerritory;

				for (int i = 0; i < this->getVertexCount() - 1; i++)
				{
					std::getline(input, temp, ',');
					
					//cout << temp; 
					V.push_back(atoi(temp.c_str()));  
					this->setAtCoordinates(repNum, i, atoi(temp.c_str()));
					
					
				}

				std::getline(input, temp);
				
				
				this->setAtCoordinates(repNum, 17, atoi(temp.c_str()));
				
			}
	
		}
	}
	~TerritoryArray();
	void print();
	void divideTerritories();
	void print_players_territories();
	bool check_win();
	void add_more_armies(int army_amount, string player);  
	int check_continent(string player); 

        bool has_enemies(int terrtiory, string opp_player); 
 
 

	Territory& getIndex(int index); 


private:
	Territory masterList[18];
};

