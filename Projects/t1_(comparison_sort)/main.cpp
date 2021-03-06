#include "Sorting_Algorithms.h"

#include <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{

	int size = 0;
	int count = 0;
	int in = 0;
	int option = 0;
	int* input;
	Sorting_Algorithms sorting;


	if(argc == 2)
	{

		option = atoi(argv[1]);
		if(option >= 1 && option <= 5)
		{

			cin >> size;

			input = new int[size];

			while(cin >> in)
			{

				input[count] = in;
				count++;

			}

			switch(option)
			{

				case 1:
					cout << "[1] Selection sort\n" << endl;
					sorting.selectionSort(input, size);
					break;

				case 2:
					cout << "[2] Insertion sort\n" << endl;
					sorting.insertionSort(input, size);
					break;

				case 3:
					cout << "[3] Merge sort\n" << endl;
					sorting.mergeSort(input, 0, (size-1));
					for(int i = 0; i < size; i++)
				 		cout << input[i] << endl;
					break;

				case 4:
					cout << "[4] Quicksort\n" << endl;
					sorting.quickSort(input, 0, (size-1));
					for(int i = 0; i < size; i++)
				 		cout << input[i] << endl;
					break;

				case 5:
					cout << "[5] Heapsort\n" << endl;
					sorting.heapSort(input, (size));
					for(int i = 0; i < size; i++)
				 		cout << input[i] << endl;
					break;

				default:
					cout << "Alguma informacao foi inserida incorretamente, execute o programa novamente" << endl;
					break;

			}

		}
		else
		{

			cout << "Opcao invalida, insira um numero de 1 a 5" << endl;
			cout << "[1] Selection sort" << endl;
			cout << "[2] Insertion sort" << endl;
			cout << "[3] Merge sort" << endl;
			cout << "[4] Quicksort" << endl;
			cout << "[5] Heapsort" << endl;

		}

	}
	else
	{

		cout << "Quantidade argumentos invailda, insira somente um numero de 1 a 5" << endl;
		cout << "[1] Selection sort" << endl;
		cout << "[2] Insertion sort" << endl;
		cout << "[3] Merge sort" << endl;
		cout << "[4] Quicksort" << endl;
		cout << "[5] Heapsort" << endl;

	}


}