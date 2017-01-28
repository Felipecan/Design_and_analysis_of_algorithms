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

 void Sorting_Algorithms::insertionSort(int* v, int size)
 {

 	for(int i = 1; i < size; i++)
 	{

 		int k = v[i];
 		int j = i-1;

 		while((j >= 0) && (v[j] > k))
 		{

 			v[j+1] = v[j];
 			j--;

 		}

 		v[j+1] = k;

 	}

 	for(int i = 0; i < size; i++)
		cout << v[i] << endl;

 }

 void Sorting_Algorithms::merge(int* v, int beg, int middle, int end)
 {

 	int i, j, k;
 	int* v_aux;

 	i = beg;
 	j = middle+1;
 	k = beg;
 	v_aux = v;

 	while((i <= middle) && (j <= end))
 	{

 		if(v_aux[i] < v_aux[j])
 		{

 			v[k] = v_aux[i];
 			i++;

 		}
 		else
 		{

 			v[k] = v_aux[j];
 			j++;

 		}

 		k++;

 	}

 	while(i <= middle)
 	{

 		v[k] = v_aux[i];
 		i++;
 		k++;

 	}

 	while(j <= end)
 	{

 		v[k] = v_aux[j];
 		j++;
 		k++;

 	}

 	for(int i = beg; i < k; i++)
 	{

 		v[i] = v_aux[i];

 	}

 	for(int i = beg; i < k; i++)
 	{

 	cout<< 	v[i] << endl;

 	}

 }

 void Sorting_Algorithms::mergeSort(int* v, int beg, int end)
 {

 	if(beg < end)
 	{

 		int middle = (beg + end) / 2;
 		//cout << "m " << middle << endl;

 		mergeSort(v, beg, middle);
 		mergeSort(v, middle+1, end);
 		merge(v, beg, middle, end);

 	}
 	
 }

