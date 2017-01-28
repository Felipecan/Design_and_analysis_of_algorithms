#include "Sorting_Algorithms.h"

using namespace std;

Sorting_Algorithms::Sorting_Algorithms()
{

	size = 0;

}

Sorting_Algorithms::~Sorting_Algorithms(){}

void Sorting_Algorithms::selectionSort(int* v, int size)
{

	int min, aux;

	for(int i = 0; i < (size-1); i++)
	{

		min = i;

		for(int j = (i+1); j < size; j++)
		{

			if(v[j] < v[min])
			{

				min = j;

			}

		}

		if(i != min)
		{

			aux = v[i];
			v[i] = v[min];
			v[min] = aux;

		}

	}

	for(int i = 0; i < size; i++)
		cout << v[i] << endl;

}

 void Sorting_Algorithms::insertionSort(int* v, int size){}

 void Sorting_Algorithms::merge(int* , int, int, int){}

 void Sorting_Algorithms::mergeSort(int* v, int beg, int end){}

