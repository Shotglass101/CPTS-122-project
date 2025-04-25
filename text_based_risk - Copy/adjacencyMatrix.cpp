#include "adjacencyMatrix.hpp"
/******************************************************************************************************************************************************************
*																																								  *
*	This file contains the member funcions for an adjacency matrix base class, constructed from a two by two array of integers. We make no assumption that the	  *
*	graph is undirected. If the graph is undirected, it is advisable to use a different class, as this class requires instantiation of both triangles of the	  *
*	adjacency matrix, which takes twice the time as instantiating only the upper or lower triangles.															  *
*																																								  *
*******************************************************************************************************************************************************************/

/*
*
*
*
*/
AdjacencyMatrix::AdjacencyMatrix()
{

	std::vector<std::vector<int>> M{ {0} };

	mAdjacencyMatrix = M;

	mVertexCount = 1;

}

/*******************************************************************************************************************************************************************
*
*	Constructor: This function takes the expected number of verticies of the graph represented by the adjacancy matrix and initializes a two dimensional array,
*				 where each row and column of the adjacancy matrix represents the verticies of the graph and the numbers in each cell of the two dimensional
*				 array are the number of edges connecting from the column vertex to the row vertex.
*
********************************************************************************************************************************************************************/
AdjacencyMatrix::AdjacencyMatrix(int vertexCount)
{

	mVertexCount = vertexCount;

	std::vector<int>insertionVector;

	if (vertexCount != 0)
	{

		for (int i = 0; i < mVertexCount; ++i)
		{

			insertionVector.push_back(0);

		}

		for (int i = 0; i < mVertexCount; ++i)
		{

			mAdjacencyMatrix.push_back(insertionVector);

		}

	}
}

/*
*
*
*
*/
bool AdjacencyMatrix::setColumnVector(std::vector<int> insertionVector, int columnNumber)
{

	if (columnNumber < 0)
	{

		return false;

	}
	else
	{

		if (columnNumber > insertionVector.size())
		{

			return false;

		}
		else if (insertionVector.size() > mVertexCount)
		{

			std::vector<int> empty_vector;

			for (int i = 0; i < mVertexCount; ++i)
			{

				for (int j = mVertexCount; j < insertionVector.size(); ++j)
				{

					mAdjacencyMatrix[i].push_back(0);

				}

			}

			for (int i = 0; i < insertionVector.size(); ++i)
			{

				empty_vector.push_back(0);

			}

			for (int i = mVertexCount; i < insertionVector.size(); ++i)
			{

				mAdjacencyMatrix.push_back(empty_vector);

			}

			for (int i = 0; i < mVertexCount; ++i)
			{

				for (int j = mVertexCount - 1; j >= columnNumber; --j)
				{

					mAdjacencyMatrix[i][j + 1] = mAdjacencyMatrix[i][j];

				}

			}

			mVertexCount = insertionVector.size();

			for (int i = 0; i < mVertexCount; ++i)
			{

				mAdjacencyMatrix[i][columnNumber] = insertionVector[i];

			}

			return true;

		}
		else if (insertionVector.size() < mVertexCount)
		{

			std::vector<int> empty_vector;

			for (int i = 0; i < mVertexCount; ++i)
			{

				empty_vector.push_back(0);

			}

			mAdjacencyMatrix.push_back(empty_vector);

			++mVertexCount;

			for (int i = 0; i < mVertexCount; ++i)
			{

				mAdjacencyMatrix[i].push_back(0);

			}

			for (int i = 0; i < mVertexCount; ++i)
			{

				for (int j = mVertexCount - 1; j >= columnNumber; --j)
				{

					mAdjacencyMatrix[i][j] = mAdjacencyMatrix[i][j - 1];

				}

				if (i < insertionVector.size())
				{

					mAdjacencyMatrix[i][columnNumber] = insertionVector[i];
				}
			}

			return true;

		}
		else
		{

			std::vector<int> emptyVector;


			for (int i = 0; i < mVertexCount; ++i)
			{

				emptyVector.push_back(0);

			}

			mAdjacencyMatrix.push_back(emptyVector);

			++mVertexCount;

			for (int i = 0; i < mVertexCount; ++i)
			{

				mAdjacencyMatrix[i].push_back(0);

				for (int j = mVertexCount - 1; j >= columnNumber; --j)
				{

					mAdjacencyMatrix[i][j] = mAdjacencyMatrix[i][j - 1];

				}

				if (i < insertionVector.size())
				{

					mAdjacencyMatrix[i][columnNumber] = insertionVector[i];

				}


			}

			return true;

		}

	}



}
/**/
bool AdjacencyMatrix::setRowVector(std::vector<int> insertionVector, int rowNumber)
{
	//
	//	Under Matrix
	//
	if (rowNumber < 0)
	{

		return false;

	}
	else
	{

		if (insertionVector.size() > mVertexCount)
		{

			std::vector<int> emptyVector;

			for (int i = 0; i < insertionVector.size(); ++i)
			{

				emptyVector.push_back(0);

			}

			for (int i = 0; i < mVertexCount; ++i)
			{

				for (int j = mVertexCount; j < insertionVector.size(); ++j)
				{

					mAdjacencyMatrix[i].push_back(0);

				}

			}

			for (int i = mVertexCount; i < insertionVector.size(); ++i)
			{

				mAdjacencyMatrix.push_back(emptyVector);

			}
			for (int i = rowNumber; i < insertionVector.size() - 1; ++i)
			{

				for (int j = 0; j < mVertexCount; ++j)
				{

					mAdjacencyMatrix[i + 1][j] = mAdjacencyMatrix[i][j];

				}

			}
			for (int i = 0; i < insertionVector.size(); ++i)
			{

				mAdjacencyMatrix[rowNumber][i] = insertionVector[i];

			}

			mVertexCount = insertionVector.size();

			return true;

		}
		else
		{

			if (rowNumber >= mVertexCount)
			{
				//
				//	Under repair
				//

				std::vector<int> emptyVector;

				for (int i = 0; i < mVertexCount; ++i)
				{

					emptyVector.push_back(0);

				}
				for (int i = rowNumber; i < insertionVector.size() - 1; ++i)
				{

					for (int j = 0; j < mVertexCount; ++j)
					{

						mAdjacencyMatrix[i + 1][j] = mAdjacencyMatrix[i][j];

					}

				}

				mAdjacencyMatrix.push_back(emptyVector);

				for (int i = 0; i < insertionVector.size(); ++i)
				{

					mAdjacencyMatrix[rowNumber][i] = insertionVector[i];

				}
			}
			else
			{

				for (int i = 0; i < insertionVector.size(); ++i)
				{

					mAdjacencyMatrix[rowNumber][i] = insertionVector[i];

				}
				for (int i = insertionVector.size(); i < mVertexCount; ++i)
				{

					mAdjacencyMatrix[rowNumber][i] = 0;

				}

				return true;

			}
		}
	}

}
/**/
void AdjacencyMatrix::printAdjacencyMatrix(void) const
{
	//
	//	Under Construction
	//
	system("cls");

	for (int i = 0; i < mVertexCount; ++i)
	{

		for (int j = 0; j < mVertexCount; ++j)
		{

			std::cout << mAdjacencyMatrix[i][j];

			if (j + 1 == mVertexCount)
			{

				std::cout << "\n";

			}
		}

	}

	system("pause");

	system("cls");

}
/**********************************************************************************************************************************
*
***********************************************************************************************************************************
*
*
**********************************************************************************************************************************/
bool AdjacencyMatrix::setAtCoordinates(int rowCoordinate, int columnCoordinate, int newValue)
{

	//
	//	Under construction(?)
	//

	if (!((rowCoordinate < mVertexCount && columnCoordinate < mVertexCount) && (rowCoordinate >= 0 && columnCoordinate >= 0)))
	{

		return false;

	}
	else
	{

		mAdjacencyMatrix[rowCoordinate][columnCoordinate] = newValue;

		return true;

	}

}
/**********************************************************************************************************************************
*
***********************************************************************************************************************************
*
*
**********************************************************************************************************************************/
int AdjacencyMatrix::getAtCoordinates(int const& rowCoordinate, int const& columnCoordinate) const
{
	//
	//	Under Construction
	//
	if ((rowCoordinate >= mVertexCount || columnCoordinate >= mVertexCount) || (rowCoordinate < 0 || columnCoordinate < 0))
	{

		return 0;

	}
	else
	{

		return mAdjacencyMatrix[rowCoordinate][columnCoordinate];

	}

}
/**********************************************************************************************************************************
*
***********************************************************************************************************************************
*
*
**********************************************************************************************************************************/
bool AdjacencyMatrix::addDirectedNode(std::vector<int> newAdjacencies)
{
	//
	//	Under construction
	//
	if (newAdjacencies.size() > mVertexCount + 1)
	{

		return false;

	}
	else
	{

		for (int i = 0; i < mVertexCount; ++i)
		{

			mAdjacencyMatrix[i].push_back(0);
		}

		mAdjacencyMatrix.push_back(newAdjacencies);


		mVertexCount + 1;

		if (newAdjacencies.size() < mVertexCount)
		{

			for (int i = 0; i < newAdjacencies.size(); ++i)
			{

				mAdjacencyMatrix[mVertexCount][i] = newAdjacencies.at(i);

			}
			for (int i = newAdjacencies.size(); i < mVertexCount; ++i)
			{


				mAdjacencyMatrix[mVertexCount][i] = 0;

			}

		}
		else
		{

			for (int i = 0; i < mVertexCount; ++i)
			{

				mAdjacencyMatrix[mVertexCount][i] = newAdjacencies.at(i);

			}

		}


		return true;

	}

}
/**********************************************************************************************************************************
*
***********************************************************************************************************************************
*
*
**********************************************************************************************************************************/
bool AdjacencyMatrix::addEdge(int vertex1, int vertex2)
{
	//
	//	Under construction
	//
	if (vertex1 > mVertexCount || vertex2 > mVertexCount || vertex1 < 0 || vertex2 < mVertexCount)
	{

		return false;

	}
	else
	{

		mAdjacencyMatrix[vertex1][vertex2]++;

		return true;

	}

}
/**********************************************************************************************************************************
*
***********************************************************************************************************************************
*
*
**********************************************************************************************************************************/
bool AdjacencyMatrix::addUndirectedNode(std::vector<int> newAdjacencies)
{
	//
	//	Under construction
	//
	if (newAdjacencies.size() > mVertexCount + 1)
	{

		return false;

	}
	else
	{

		for (int i = 0; i < mVertexCount; ++i)
		{

			mAdjacencyMatrix[i].push_back(0);
		}

		mAdjacencyMatrix.push_back(newAdjacencies);


		mVertexCount + 1;

		if (newAdjacencies.size() < mVertexCount)
		{

			for (int i = 0; i < newAdjacencies.size(); ++i)
			{

				mAdjacencyMatrix[mVertexCount][i] = newAdjacencies.at(i);

				mAdjacencyMatrix[i][mVertexCount] = newAdjacencies.at(i);

			}
			for (int i = newAdjacencies.size(); i < mVertexCount; ++i)
			{


				mAdjacencyMatrix[mVertexCount][i] = 0;

			}

		}
		else
		{

			for (int i = 0; i < mVertexCount; ++i)
			{

				mAdjacencyMatrix[mVertexCount][i] = newAdjacencies.at(i);

				mAdjacencyMatrix[i][mVertexCount] = newAdjacencies.at(i);

			}

		}

		for (int i = 0; i < mVertexCount; ++i)
		{

			for (int j = i; j < mVertexCount; ++j)
			{

				mAdjacencyMatrix[j][i] = mAdjacencyMatrix[i][j];

			}

		}

		return true;

	}


}

bool AdjacencyMatrix::check_borders(int attack, int defend)
{
	bool cheese = false; 

	if (this->mAdjacencyMatrix[attack][defend] == 1)
	{
		cheese = true; 
	}
	return cheese; 
}

/**********************************************************************************************************************************
*
***********************************************************************************************************************************
*
*
**********************************************************************************************************************************/
bool AdjacencyMatrix::removeEdge(int vertex1, int vertex2)
{
	//
	//	Under construction
	//
	if (vertex1 > mVertexCount || vertex2 > mVertexCount || vertex1 < 0 || vertex2 < mVertexCount)
	{

		return false;

	}
	else
	{

		mAdjacencyMatrix[vertex1][vertex2]--;

		return true;

	}

}

/*
*
*
*
*/
int AdjacencyMatrix::getVertexCount(void) const
{
	//
	//	Under construction
	//
	return mVertexCount;

}
