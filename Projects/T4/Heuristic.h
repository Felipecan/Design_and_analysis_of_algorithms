#ifndef T4_H
#define T4_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <locale>
#include <vector>
#include <string>
#include <algorithm>


class Heuristic
{

	private:
		bool is_insert;
		bool is_string;
		bool entropy;

	public:
		Heuristic();
		~Heuristic();
		
					 		//introsort
		int partition(std::vector<int>* v, int left, int right);
		void quicksort(std::vector<int>* v, int left, int right);
		void maxHeapify(std::vector<int>* v, int heapSize, int index);
		void heapsort(std::vector<int>* v, int heapSize);
		void introsort(std::vector<int>* v, int size);

				//insertion sort p/ intro e sozinho
		void insertionSort(std::vector<int>* v, int size);

					          //radixs
		void  radixSort_num(std::vector<int>* v, int size);

							 //counting
		void countingSort(std::vector<int>* v, int size);

						//rotinas auxiliares
		void analysis(std::vector<std::string>* v, int size);

							//heuristica
		void heuristic(std::vector<std::string>* v, int size);


};

#endif