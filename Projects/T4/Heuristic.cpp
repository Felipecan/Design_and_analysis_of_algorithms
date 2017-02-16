#include "Heuristic.h"

Heuristic::Heuristic()
{

	is_insert = false;
	is_string = false;
	entropy = false;
	count_enable = false;
	max = false;

}

Heuristic::~Heuristic(){}

long Heuristic::partition(std::vector<long>* v, long left, long right)
{

	long pivot = v->at(right);
	long aux;
	long i = left;

	for(long j = left; j < right; ++j)
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

void Heuristic::quicksort(std::vector<long>* v, long left, long right)
{

	if(left < right)
	{	

		long p = partition(v, left, right);
		quicksort(v, left, p-1);
		quicksort(v, p+1, right);

	}

}

void Heuristic::maxHeapify(std::vector<long>* v, int heapSize, long index)
{

	long left = (index+1) * 2 - 1;
	long right = (index+1)*2;
	long largest = 0;

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

		long aux = v->at(index);
		v->at(index) = v->at(largest);
		v->at(largest) = aux;

		maxHeapify(v, heapSize, largest);

	}

}

void Heuristic::heapsort(std::vector<long>* v, int size)
{

	int heapSize = size;

	for(int i = (heapSize-1)/2; i >=0; --i)
		maxHeapify(v, heapSize, i);

	for(int i = size-1; i > 0; --i)
	{

		long aux = v->at(i);
		v->at(i) = v->at(0);
		v->at(0) = aux;

		--heapSize;
		maxHeapify(v, heapSize, 0);

	}

}

void Heuristic::insertionSort(std::vector<long>* v, int size)
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

void Heuristic::introsort(std::vector<long>* v, int size)
{

	long part_size = partition(v, 0, size-1);

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

void Heuristic::radixSort_num(std::vector<long>* v, int size)
{

	int j;
	long* v_aux = new long[size];

	for(long sft = 31; sft > -1; --sft)
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

void Heuristic::countingSort(std::vector<long>* v, int size)
{

	int z = 0;
	int min = *min_element(v->begin(), v->end());
	int max = *max_element(v->begin(), v->end());
	int len = max - min + 1;

	int* v_aux = (int*)calloc(len, sizeof(int));

	for(int i = 0; i < size; i++)
		v_aux[ v->at(i) - min ]++;

	for(int i = min; i <= max; i++)
	{

		while(v_aux[i-min]-- > 0)
		{

			v->at(z) = i;
			++z;

		}

	}

	delete v_aux;

}


void Heuristic::analysis(std::vector<std::string>* v, int size)
{

	//std::locale loc;
	int sort = 0;
	int aux;
	//int 
	v_internal.reserve(size);

	for(int i = 0; i < size; i++)
	{

		v_internal.push_back(atol(v->at(i).c_str()));

		if(i == size-1)
			break;

		if(atol(v->at(i).c_str()) <= atol(v->at(i+1).c_str()))
		{
			sort++;
		}

		//if(v->at(i).find_first_of() == v->at(i).end())

	}

	if(size <= 20)
		is_insert = true;

	if(((float)sort/size)*100 > 85)//colocar alguma coisa aqui pra definir o quão ordneado é
		entropy = true;

	//chavae máxima
	long elem_max = *max_element(v_internal.begin(), v_internal.end());
	if(elem_max < 10000)
		max = true;


	std::set<long> set_aux_diff(v_internal.begin(), v_internal.end());
    aux = set_aux_diff.size();
    if(((float)aux/size)*100 <= 50) //mais de 50% da variáveis repetidas
    	count_enable = true;

    

}

void Heuristic::heuristic(std::vector<std::string>* v, int size)
{

	analysis(v, size);

	/*if(is_string)
	{
		//radiz string
		return;
	}*/

	if(is_insert)
	{	
		std::cout << "insertion sort" << std::endl;
		insertionSort(&v_internal, size);
		for(int i = 0; i < size; i++)
			std::cout << v_internal[i] << std::endl;
		return;
	}

	if(count_enable && max)
	{
		std::cout << "counting sort" << std::endl;
		countingSort(&v_internal, size);
		for(int i = 0; i < size; i++)
			std::cout << v_internal[i] << std::endl;
	}
	else
	{

		if(entropy)
		{
			std::cout << "introsort" << std::endl;
			introsort(&v_internal, size);
			for(int i = 0; i < size; i++)
				std::cout << v_internal[i] << std::endl;
		}
		else
		{
			std::cout << "radix sort num" << std::endl;
			radixSort_num(&v_internal, size);
			for(int i = 0; i < size; i++)
				std::cout << v_internal[i] << std::endl;
		}

	}

}