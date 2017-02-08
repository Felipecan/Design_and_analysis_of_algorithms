#include "Linear_Sorting_Algorithm.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{

	Linear_Sorting_Algorithm lsa;
	int v_size = 0;
	int in;
	int* input;

	if(argc == 2)
	{

		if(atoi(argv[1]) >= 1 && atoi(argv[1]) <= 3)
		{

			cin >> v_size;
			input = new int[v_size];

			for(int i = 0; cin >> in; i++)
				input[i] = in;

			switch(atoi(argv[1]))
			{

				case 1:
					cout << "[1] Couting sort" << endl;
					lsa.countingSort(input, v_size);
					for(int i = 0; i < v_size; i++)
						cout << input[i] << endl;
					break;

				case 2:
					cout << "[2] Bucket sort" << endl;
					lsa.bucketSort(input, v_size);
					for(int i = 0; i < v_size; i++)
						cout << input[i] << endl;
					break;

				case 3:
					cout << "[3] Radix sort" << endl;
					lsa.radixSort(input, v_size);
					for(int i = 0; i < v_size; i++)
						cout << input[i] << endl;
					break;

				default:
					cout << "Alguma coisa errada nas estradas... rs" << endl;
					break;


			}

		}
		else
		{



		}

	}
	else
	{

		cout << "Argumentos de entrada invalido. ATENCAO AS OPCOES: " << endl;


	}

}