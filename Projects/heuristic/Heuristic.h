#ifndef T4_H
#define T4_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>


class Heuristic
{

	private:
		bool is_insert;
		bool is_string;
		bool entropy;
		bool count_enable;
		std::vector<long> v_internal;

	public:
		Heuristic();
		~Heuristic();
		
					 		//introsort
		long partition(std::vector<long>* v, long left, long right);
		void quicksort(std::vector<long>* v, long left, long right);
		void maxHeapify(std::vector<long>* v, int heapSize, long index);
		void heapsort(std::vector<long>* v, int heapSize);
		void introsort(std::vector<long>* v, int size);

				//insertion sort p/ intro e sozinho
		void insertionSort(std::vector<long>* v, int size);

					          //radixs
		void radixSort_num(std::vector<long>* v, int size);
		void radixSort_str(std::vector<std::string>* v, int size);

							 //counting
		void countingSort(std::vector<long>* v, int size);
		void countSort_str(std::vector<std::string>* v, int size, size_t loop_i);

						//rotinas auxiliares
		void analysis(std::vector<std::string>* v, int size);
		size_t max_eleme(std::vector<std::string>* v, int size);

							//heuristica
		void heuristic(std::vector<std::string>* v, int size);


};

#endif