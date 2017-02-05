#include "Sorting_Algorithms.h"

#include <stdlib.h>
#include <algorithm>
#include <time.h>

using namespace std;


int main(int argc, char** argv)
{

	int size = 0;
	int count = 0;
	int in = 0;
	int* input;
	int* input_aux;
	Sorting_Algorithms sorting;

	clock_t c_t;
	double dif;


	cin >> size;			
	input = new int[size];
	input_aux = new int[size];

	while(cin >> in)
	{

		input[count] = in;
		input_aux[count] = in;
		count++;

	}


			
	//ordenação
	cout << "===================================================" << endl;
	cout << "[1] Selection sort\n" << endl;
	c_t = clock();
	sorting.selectionSort(input, size);
	c_t = clock() - c_t;
	dif = ((double)c_t)/CLOCKS_PER_SEC;
	cout << "Time " << dif << " s\n" << endl;
	//for(int i = 0; i < size; i++)
	//	cout << input[i] << endl;

	cout << "\n\n\n===================================================" << endl;	
	cout << "[2] Insertion sort\n" << endl;
	sorting.copy(input, input_aux, size);
	c_t = clock();
	sorting.insertionSort(input, size);
	c_t = clock() - c_t;
	dif = ((double)c_t)/CLOCKS_PER_SEC;
	cout << "Time " << dif << " s\n" << endl;
	//for(int i = 0; i < size; i++)
	//	cout << input[i] << endl;

	cout << "\n\n\n===================================================" << endl;
	cout << "[3] Merge sort\n" << endl;
	sorting.copy(input, input_aux, size);
	c_t = clock();
	sorting.mergeSort(input, 0, (size-1));
	c_t = clock() - c_t;
	dif = ((double)c_t)/CLOCKS_PER_SEC;
	cout << "Time " << dif << " s\n" << endl;
	//for(int i = 0; i < size; i++)
	//	cout << input[i] << endl;

	cout << "\n\n\n===================================================" << endl;
	cout << "[4] Quicksort\n" << endl;
	sorting.copy(input, input_aux, size);
	c_t = clock();
	sorting.quickSort(input, 0, (size-1));
	c_t = clock() - c_t;
	dif = ((double)c_t)/CLOCKS_PER_SEC;
	cout << "Time " << dif << " s\n" << endl;
	//for(int i = 0; i < size; i++)
	//	cout << input[i] << endl;

	cout << "\n\n\n===================================================" << endl;
	cout << "[5] Heapsort\n" << endl;
	sorting.copy(input, input_aux, size);
	c_t = clock();
	sorting.heapSort(input, (size));
	c_t = clock() - c_t;
	dif = ((double)c_t)/CLOCKS_PER_SEC;
	cout << "Time " << dif << " s\n" << endl;
	//for(int i = 0; i < size; i++)
	//	cout << input[i] << endl;

	cout << "\n\n\n===================================================" << endl;
	cout << "[5] Sort C++\n" << endl;
	sorting.copy(input, input_aux, size);
	c_t = clock();
	sort(input, input+size);
	c_t = clock() - c_t;
	dif = ((double)c_t)/CLOCKS_PER_SEC;
	cout << "Time " << dif << " s\n" << endl;
	//for(int i = 0; i < size; i++)
	//	cout << input[i] << endl;



}
