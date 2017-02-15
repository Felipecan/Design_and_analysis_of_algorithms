#include "Heuristic.h"

Heuristic::Heuristic(){}

Heuristic::~Heuristic(){}

int Heuristic::partition(std::vector<int>* v, int left, int right)
{

	int pivot = v->at(right);
	int aux;
	int i = left;

	for(int j = left; j < right; ++j)
	{

		if(v->at(j) <= pivot)
		{

			aux = v->at(j);
			v->at(j) = v->at(i);
			v->at(i) = aux;
			i++;

		}

	}

	v->at(right) = v->at(i);
	v->at(i) = pivot;

	return i;

}

void Heuristic::quicksort(std::vector<int>* v, int left, int right)
{

	if(left < right)
	{	

		int p = partition(v, left, right);
		quicksort(v, left, p-1);
		quicksort(v, p+1, right);

	}

}

void Heuristic::maxHeapify(std::vector<int>* v, int heapSize, int index)
{

	int left = (index+1) * 2 - 1;
	int right = (index+1)*2;
	int largest = 0;

	if(left < heapSize && v->at(left) > v->at(index))
	{
		largest = left;
	}
	else
	{
		largest = index;
	}

	if(right < heapSize && v->at(right) > v->at(largest))
		largest = right;

	if(largest != index)
	{

		int aux = v->at(index);
		v->at(index) = v->at(largest);
		v->at(largest) = aux;

		maxHeapify(v, heapSize, largest);

	}

}

void Heuristic::heapsort(std::vector<int>* v, int size)
{

	int heapSize = size;

	for(int i = (heapSize-1)/2; i >=0; --i)
		maxHeapify(v, heapSize, i);

	for(int i = size-1; i > 0; --i)
	{

		int aux = v->at(i);
		v->at(i) = v->at(0);
		v->at(0) = aux;

		--heapSize;
		maxHeapify(v, heapSize, 0);

	}

}

void Heuristic::insertionSort(std::vector<int>* v, int size)
{

	for(int i = 1; i < size; ++i)
	{

		int j = i;

		while(j > 0)
		{

			if(v->at(j-1) > v->at(j))
			{

				v->at(j-1) ^= v->at(j);
				v->at(j) ^= v->at(j-1);
				v->at(j-1) ^= v->at(j);

				--j;

			}
			else
			{
				break;
			}

		}

	}

}

void Heuristic::introsort(std::vector<int>* v, int size)
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

void Heuristic::radixSort_num(std::vector<int>* v, int size)
{

	int j;
	int* v_aux = new int[size];

	for(int sft = 31; sft > -1; --sft)
	{

		j = 0;

		for(int i = 0; i < size; ++i)
		{

			bool mv = (v->at(i) << sft) >= 0;

			if(sft == 0 ? !mv : mv)
			{
				v->at(i-j) = v->at(i);
			}
			else
			{
				v_aux[j++] = v->at(i);
			}

		}

		for(int i = 0; i < j; i++)
		{
			v->at( (size-j)+i ) = v_aux[i];
		}

	}

	delete v_aux;

}




void Heuristic::analysis(std::vector<std::string>* v, int size)
{

	std::locale loc;

	if(size < 20)
		is_insert = true;

	for(int i = 0; i < size; i++)
	{

		

	}

}