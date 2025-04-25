#include "adjacencyMatrixTest.hpp"

adjacencyMatrixTest::adjacencyMatrixTest()
{

	AdjacencyMatrix M(2);

	mTestMatrix = M;

	for (int i = 0; i < 21; ++i)
	{

		mTestStatuses[i] = false;

	}

}
void adjacencyMatrixTest::runTest()
{

	std::cout << "The following matrix should print after enter is pressed \n\n";

	std::vector<std::vector<int>> M1{ {0, 0}, {0, 0} };

	for (int i = 0; i < 2; ++i)
	{

		for (int j = 0; j < 2; ++j)
		{

			std::cout << M1[i][j];

			if (j == 1)
			{

				std::cout << "\n";

			}

		}

	}

	std::cout << "\n";

	system("pause");

	system("cls");

	mTestMatrix.printAdjacencyMatrix();

	std::cout << "\n\nDid the correct item print?\n\n\t\t>y\t>n\n\n";

	char assessmentVariable;

	do
	{

		std::cin >> assessmentVariable;

		if (assessmentVariable != 'y' && assessmentVariable != 'n')
		{

			std::cout << "\n\nCharacter not recognized. Please enter a valid character\n\n";

			system("pause");

		}

	} while (assessmentVariable != 'y' && assessmentVariable != 'n');

	mTestStatuses[1] = (assessmentVariable == 'y');

	if (mTestMatrix.getVertexCount() != 2)
	{

		mTestStatuses[0] = false;

	}
	else
	{

		mTestStatuses[0] = true;

	}

	mTestStatuses[3] = true;

	std::vector<int> insertVector2d{ 1, 1 };

	mTestStatuses[2] = !(mTestMatrix.setColumnVector(insertVector2d, -1) || mTestMatrix.setColumnVector(insertVector2d, 3));

	mTestMatrix.setColumnVector(insertVector2d, 2);

	system("cls");

	assessmentVariable = '\0';

	std::cout << "The following matrix should print\n";

	std::vector<std::vector<int>> M2{ {0,0, 1}, {0, 0, 1}, {0, 0, 0} };

	for (int i = 0; i < 3; ++i)
	{

		for (int j = 0; j < 3; ++j)
		{

			std::cout << M2[i][j];

			if (j == 2)
			{

				std::cout << "\n";

			}

		}

	}


	std::cout << "\n\n";

	system("pause");

	mTestMatrix.printAdjacencyMatrix();

	std::cout << "\n\nDid the correct item print?\n\n\t\t>y\t>n\n\n";

	do
	{

		std::cin >> assessmentVariable;

		if (assessmentVariable != 'y' && assessmentVariable != 'n')
		{

			std::cout << "\n\nCharacter not recognized. Please enter a valid character\n\n";

			system("pause");

		}

	} while (assessmentVariable != 'y' && assessmentVariable != 'n');


	if (assessmentVariable == 'n')
	{

		mTestStatuses[3] = 0;

	}

	insertVector2d = { 1, 2, 3, 4 };

	mTestMatrix.setColumnVector(insertVector2d, 2);

	std::vector<std::vector<int>> M3{ {0,0,1,1}, {0,0,2,1}, {0,0,3,0}, {0,0,4,0} };

	system("cls");

	std::cout << "The following matrix will print \n\n";

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{

			std::cout << M3[i][j];

		}

		std::cout << "\n";

	}

	std::cout << "\n\n";

	system("pause");

	mTestMatrix.printAdjacencyMatrix();

	std::cout << "\n\nDid the correct item print?\n\n\t\t>y\t>n\n\n";

	do
	{

		std::cin >> assessmentVariable;

		if (assessmentVariable != 'y' && assessmentVariable != 'n')
		{

			std::cout << "\n\nCharacter not recognized. Please enter a valid character\n\n";

			system("pause");

		}

	} while (assessmentVariable != 'y' && assessmentVariable != 'n');

	if (assessmentVariable == 'n')
	{

		mTestStatuses[3] = false;

	}

	std::vector<std::vector<int>> M4{ {0, 1, 0, 1, 1}, {0, 2, 0, 2, 1}, {0, 0, 0, 3, 0}, {0, 0, 0, 4, 0}, {0, 0, 0, 0, 0,} };


	insertVector2d = { 1, 2 };

	mTestMatrix.setColumnVector(insertVector2d, 1);

	system("cls");

	std::cout << "The following matrix will print \n\n";

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{

			std::cout << M4[i][j];

		}

		std::cout << "\n";

	}

	std::cout << "\n\n";

	system("pause");

	mTestMatrix.printAdjacencyMatrix();

	std::cout << "\n\nDid the correct item print?\n\n\t\t>y\t>n\n\n";

	do
	{

		std::cin >> assessmentVariable;

		if (assessmentVariable != 'y' && assessmentVariable != 'n')
		{

			std::cout << "\n\nCharacter not recognized. Please enter a valid character\n\n";

			system("pause");

		}

	} while (assessmentVariable != 'y' && assessmentVariable != 'n');

	if (assessmentVariable == 'n')
	{

		mTestStatuses[3] = false;

	}

	insertVector2d = { 1, 2, 3, 4, 5 };

	std::vector<std::vector<int>> M5{ {0, 1, 0, 1, 0}, {0, 2, 0, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {1, 2, 3, 4, 5} };

	system("cls");

	std::cout << "The following matrix should print\n\n";

	system("pause");

	std::cout << "\n\n";

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{

			std::cout << M5[i][j];

		}

		std::cout << "\n";

	}

	mTestMatrix.setRowVector(insertVector2d, 2);

	system("pause");

	mTestMatrix.printAdjacencyMatrix();

	do
	{

		std::cin >> assessmentVariable;

		if (assessmentVariable != 'y' && assessmentVariable != 'n')
		{

			std::cout << "\n\nCharacter not recognized. Please enter a valid character\n\n";

			system("pause");

		}

	} while (assessmentVariable != 'y' && assessmentVariable != 'n');

	if (assessmentVariable == 'n')
	{

		mTestStatuses[3] = false;

	}

	mTestMatrix.setRowVector(insertVector2d, 4);

	mTestMatrix.printAdjacencyMatrix();

	std::cout << "\n\nDid the correct item print?\n\n\t\t>y\t>n\n\n";

	do
	{

		std::cin >> assessmentVariable;

		if (assessmentVariable != 'y' && assessmentVariable != 'n')
		{

			std::cout << "\n\nCharacter not recognized. Please enter a valid character\n\n";

			system("pause");

		}

	} while (assessmentVariable != 'y' && assessmentVariable != 'n');

	if (assessmentVariable == 'n')
	{

		mTestStatuses[4] = false;

	}


	/*
	*
	*	Final Test Status;
	*
	*/

	system("cls");

	for (int i = 0; i < 21; ++i)
	{

		std::cout << "Test status " << i;

		if (mTestStatuses[i])
		{

			std::cout << " true\n";

		}
		else
		{

			std::cout << " false\n";

		}
	}

	system("pause");



}
