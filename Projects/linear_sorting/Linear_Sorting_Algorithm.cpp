#include "Linear_Sorting_Algorithm.h"

#include <stdlib.h>
#include <algorithm>

using namespace std;

Linear_Sorting_Algorithm::Linear_Sorting_Algorithm()
{}

Linear_Sorting_Algorithm::~Linear_Sorting_Algorithm(){}

void Linear_Sorting_Algorithm::countingSort(int* v, int v_size)
{

	int z = 0;
	int min = *min_element(v, v+v_size);
	int max = *max_element(v, v+v_size);
	int len = max - min + 1;

	int* v_aux = (int*)calloc(len, sizeof(int));

	for(int i = 0; i < v_size; i++)
		v_aux[ v[i] - min ]++;

	for(int i = min; i <= max; i++)
	{

		while(v_aux[i-min]-- > 0)
		{

			v[z] = i;
			++z;

		}

	}

	delete v_aux;

}

void Linear_Sorting_Algorithm::bucketSort(int* v, int v_size)
{

	int k = 0;
	int bucketlen;
	int min_v = v[0];
	int max_v = v[0];
	vector<int>* bucket;

	for(int i = 1; i < v_size; i++)
	{

		if(v[i] > max_v)
			max_v = v[i];
		
		if(v[i] < min_v)
			min_v = v[i];

	}

	bucketlen = max_v - min_v + 1;
	bucket = new vector<int>[bucketlen];

	for(int i = 0; i < bucketlen; i++)
		bucket[i] = vector<int>();

	for(int i =0; i < v_size; i++)
		bucket[v[i] - min_v].push_back(v[i]);

	for(int i = 0; i < bucketlen; i++)
	{

		int bucket_size = bucket[i].size();

		if(bucket_size > 0)
		{

			for(int j = 0; j < bucket_size; j++)
			{

				v[k] = bucket[i][j];
				k++;

			}

		}

	}

}

void Linear_Sorting_Algorithm::radixSort(int* v, int v_size)
{

	int j;
	int* v_aux = new int[v_size];

	for(int sft = 31; sft > -1; --sft)
	{

		j = 0;

		for(int i = 0; i < v_size; ++i)
		{

			bool mv = (v[i] << sft) >= 0;

			if(sft == 0 ? !mv : mv)
			{
				v[i-j] = v[i];
			}
			else
			{
				v_aux[j++] = v[i];
			}

		}

		for(int i = 0; i < j; i++)
		{

			v[ (v_size-j)+i ] = v_aux[i];

		}

	}

	delete v_aux;

}

