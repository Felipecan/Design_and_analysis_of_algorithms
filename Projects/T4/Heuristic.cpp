#include "Heuristic.h"

#include <cmath>

Heuristic::Heuristic(){}

Heuristic::~Heuristic(){}

int Heuristic::partition(int* v, int left, int right)
{

	int pivot = v[right];
	int aux;
	int i = left;

	for(int j = left; j < right; ++j)
	{

		if(v[j] <= pivot)
		{

			aux = v[j];
			v[j] = v[i];
			v[i] = aux;
			i++;

		}

	}

	v[right] = v[i];
	v[i] = pivot;

	return i;

}

void Heuristic::quicksort(int* v, int left, int right)
{

	if(left < right)
	{	

		int p = partition(v, left, right);
		quicksort(v, left, p-1);
		quicksort(v, p+1, right);

	}

}

void Heuristic::maxHeapify(int* v, int heapSize, int index)
{

	int left = (index+1) * 2 - 1;
	int right = (index+1)*2;
	int largest = 0;

	if(left < heapSize && v[left] > v[index])
	{
		largest = left;
	}
	else
	{
		largest = index;
	}

	if(right < heapSize && v[right] > v[largest])
		largest = right;

	if(largest != index)
	{

		int aux = v[index];
		v[index] = v[largest];
		v[largest] = aux;

		maxHeapify(v, heapSize, largest);

	}

}

void Heuristic::heapsort(int* v, int size)
{

	int heapSize = size;

	for(int i = (heapSize-1)/2; i >=0; --i)
		maxHeapify(v, heapSize, i);

	for(int i = size-1; i > 0; --i)
	{

		int aux = v[i];
		v[i] = v[0];
		v[0] = aux;

		--heapSize;
		maxHeapify(v, heapSize, 0);

	}

}

void Heuristic::insertionSort(int* v, int size)
{

	for(int i = 1; i < size; ++i)
	{

		int j = i;

		while(j > 0)
		{

			if(v[j-1] > v[j])
			{

				v[j-1] ^= v[j];
				v[j] ^= v[j-1];
				v[j-1] ^= v[j];

				--j;

			}
			else
			{
				break;
			}

		}

	}

}

void Heuristic::introsort(int* v, int size)
{

	int part_size = partition(v, 0, size-1);

	if(part_size < 16)
	{
		insertionSort(v, size);
	}
	else if(part_size > (2*log(size)))
	{
		heapsort(v, size);
	}
	else
	{
		quicksort(v, 0, size-1);
	}

}