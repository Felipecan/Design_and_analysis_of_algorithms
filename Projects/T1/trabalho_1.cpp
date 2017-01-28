#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> 
#include <stdlib.h>

using namespace std;

void selectionSort(vector<int> v);
void insertionSort(vector<int> v);
void merge(vector<int>* v, int begin, int middle, int end);
void mergeSort(vector<int>* v, int begin, int end);

int main(int argc, char** argv)
{
	
	int size;
	int in;
	int option = 0;
	vector<int> input;



	cin >> size;

	while(cin >> in)
	{
	
		input.push_back(in);
		//cout << in << endl;

	}

	//selectionSort(input);
	//insertionSort(input);
	mergeSort(&input, *input.begin(), *input.end());

	/*cout << "Digite o numero associado a qual algoritmo de ordenacao deseja utilizar: " << endl;
	cout << "[1] Selection sort" << endl;
	cout << "[2] Insertion sort" << endl;
	cout << "[3] Merge sort" << endl;
	cout << "[4] Quicksort" << endl;
	cout << "[5] Heapsort" << endl;
	
	cin >> option;

	switch(option)
	{

		case 1:
			//selectionSort(input);
			break;

		case 2:
			//insertionSort(input);
			break;

		case 3:
			//
			break;

		case 4:
			//
			break;

		case 5:
			//
			break;

		default:
			cout << "Alguma informacao foi inserida incorretamente, execute o programa novamente" << endl;
			break;

	}*/

	return 0;

}


//SELECTION SORT
void selectionSort(vector<int> v)
{

	vector<int>::iterator it;

	for(it = v.begin(); it != v.end(); ++it)
	{

		iter_swap(it, min_element(it, v.end()));

	}

	for(int i = 0; i < v.size(); i++)
		cout << v[i] << endl;

}

/*void selectionSort(vector<int> v)
{

	int size, min, aux;

	size = v.size();

	for(int i = 0; i < (size - 1); i++)
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

}*/

//INSERTION SORT
void insertionSort(vector<int> v)
{

	int size = v.size();

	for(int i = 1; i < size; i++)
	{

		int k = v[i];
		int j = i - 1;

		while((j >= 0) && (v[j] > k))
		{

			v[j + 1] = v[j];
			j--;

		}

		v[j + 1] = k;

	}

	for(int i = 0; i < v.size(); i++)
		cout << v[i] << endl;

}

//MERGE SORT
void merge(vector<int>* v, int begin, int middle, int end)
{

	int i, j, k;
	vector<int>* v_aux;

	i = begin;
	j = middle + 1;
	k = begin;
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

	for(int x = begin; x < k; x++)
		v[x] = v_aux[x];

	for(int x = 0; x < v->size(); x++)
		cout << v->at(x) << endl;


}

void mergeSort(vector<int>* v, int begin, int end)
{
	
	if(begin < end)
	{

		int middle = (begin + end) / 2;

		mergeSort(v, begin, middle);
		mergeSort(v, (middle + 1), end);
		merge(v, begin, middle, end);

	}

}