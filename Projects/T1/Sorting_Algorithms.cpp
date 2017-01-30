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

void Sorting_Algorithms::mergeSort(int* v, int beg, int end)
{

	int i, j, k, middle;
	int* v_aux;

	if(beg == end)
		return;

	middle = (beg+end)/2;
	mergeSort(v, beg, middle);
	mergeSort(v, middle+1, end);

	i = beg;
	j = middle+1;
	k = 0;

	v_aux = new int[end-beg+1];
	//v_aux = (int *)malloc(sizeof(int)*(end-beg+1));

	while((i < middle+1) || (j < end+1))
	{

		if(i == middle+1)
		{

			v_aux[k] = v[j];
			j++;
			k++;

		}
		else
		{

			if(j == end+1)
			{

				v_aux[k] = v[i];
				i++;
				k++;

			}
			else
			{

				if(v[i] < v[j])
				{

					v_aux[k] = v[i];
					i++;
					k++;

				}
				else
				{

					v_aux[k] = v[j];
					j++;
					k++;

				}

			}

		}

	}

	for(i = beg; i <= end; i++)
		v[i] = v_aux[i-beg];

	delete[] v_aux;
	
}

/* void Sorting_Algorithms::merge(int* v, int beg, int middle, int end)
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

 	//for(int i = beg; i < k; i++)
 	//{

 	//cout<< 	v[i] << endl;

 	//}

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
 	
}*/

void Sorting_Algorithms::quickSort(int* v, int left, int right)
{

 	int pivo = left;
 	int i, ch, j;

 	for(i = left+1; i <= right; i++)
 	{

 		j = i;

 		if(v[j] < v[pivo])
 		{

 			ch = v[j];

 			while(j > pivo)
 			{

 				v[j] = v[j-1];
 				j--;

 			}
 			
 			v[j] = ch;
 			pivo++;

 		}

 	}

 	if((pivo-1) >= left)
 	{

 		quickSort(v, left, (pivo-1));

 	}

 	if((pivo+1) <= right)
 	{

 		quickSort(v, (pivo+1), right);

 	}

}

void Sorting_Algorithms::heapSort(int* v, int tam)
{

 	int size = tam;
 	int i = tam/2;
 	int father, son, t;

 	for(;;)
 	{

 		if(i > 0)
 		{

 			i--;
 			t = v[i];

 		}
 		else   
 		{

 			tam--;

 			if(tam == 0) 
 				return;

 			t = v[tam];
 			v[tam] = v[0];

 		}

 		father = i;
 		son = i*2+1;

 		while(son < tam)
 		{

 			if((son+1 < tam) && (v[son+1] > v[son]))
 				son++;

 			if(v[son] > t)
 			{

 				v[father] = v[son];
 				father = son;
 				son = father*2+1;

 			}
 			else
 			{

 				break;

 			}

 		}

 		v[father] = t;

 	}

}

