#ifndef T1_H
#define T1_H

#include <iostream>

class Sorting_Algorithms
{

	private:
		int size;
		int* input;

	public:
		Sorting_Algorithms();
		~Sorting_Algorithms();
		void selectionSort(int* v, int size);
		void insertionSort(int* v, int size);
		void merge(int*, int, int, int);
		void mergeSort(int* v, int beg, int end);
		void quickSort(int* v, int left, int right);
		void heapSort(int* v, int tam);


};

#endif