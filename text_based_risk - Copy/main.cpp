/*************************************************************************************************************************************************************************
* 
* 
* 
* 
*************************************************************************************************************************************************************************/
#include "adjacencyMatrix.hpp"
#include "adjacencyMatrixTest.hpp"
#include "TerritoryArray.hpp"
#include "territory.hpp" 
#include "GamePLay.hpp" 

int main(void) 
{
	std::srand(std::time(0));

	int optionSelector = 0;

do
{
	system("cls");

	std::cout << "Select what you want to do here\n\n\t>1. test \n\n\t>2. Play\n\n\t\t>";

	std::cin >> optionSelector;

}while (!(optionSelector == 1 || optionSelector == 2));

system("cls");

switch (optionSelector)
{
	
case 2:
{
	system("pause");

	GamePlay cheese;

	cheese.risk();

	//TerritoryArray test(18);

	break;
}
case 1:
{
	adjacencyMatrixTest matrixTest;

	matrixTest.runTest();

	break;
}
default:
	break;
}


	
	

	

	
	return 0;

}
