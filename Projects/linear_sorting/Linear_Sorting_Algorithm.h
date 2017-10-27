#ifndef T3_H
#define T3_H

#include <vector>

using namespace std;

class Linear_Sorting_Algorithm
{

	public:
		Linear_Sorting_Algorithm();
		~Linear_Sorting_Algorithm();
		void countingSort(int* v, int v_size);
		void bucketSort(int* v, int v_size);
		void radixSort(int* v, int v_size);

};

#endif