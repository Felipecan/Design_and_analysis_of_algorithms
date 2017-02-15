#ifndef T4_H
#define T4_H

class Heuristic
{

	private:

	public:
		Heuristic();
		~Heuristic();
		
						//introsort
		int partition(int* v, int left, int right);
		void quicksort(int* v, int left, int right);
		void maxHeapify(int* v, int heapSize, int index);
		void heapsort(int* v, int heapSize);
		void introsort(int* v, int size);

		//insertion sort p/ intro e sozinho
		void insertionSort(int* v, int size);

		//radixs 

		//rotinas auxiliares


};

#endif