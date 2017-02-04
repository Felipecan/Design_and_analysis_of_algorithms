#include "Sorting_Algorithms.h"

#include <stdlib.h>
#include <dirent.h>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void searchDirFiles(const char* d, vector<string>* f);

int main(int argc, char** argv)
{

	int size = 0;
	int count = 0;
	int in = 0;
	int* input;
	int* input_aux;
	Sorting_Algorithms sorting;
	vector<string> files;
	ifstream f_in;
	ofstream f_out;


	if(argc > 1)
	{

		searchDirFiles(argv[1], &files);

		for(int i = 0; i < files.size(); i++)
		{

			f_in.open(files[i].c_str());
			if(f_in.is_open())
			{

				f_in >> size;
				
				input = new int[size];
				input_aux = new int[size];

				while(f_in >> in)
				{

					input[count] = in;
					input_aux[count] = in;
					count++;

				}

				//criar nome do arquivo de saida
				//abrir aquivivo escrever algo no incio e começa as ordençaões

				//ordenação

				cout << "[1] Selection sort\n" << endl;
				//tempo inicio
				sorting.selectionSort(input, size);
				//tempo fim
				for(int i = 0; i < size; i++)
	 				cout << input[i] << endl;

				cout << "[2] Insertion sort\n" << endl;
				sorting.copy(input, input_aux, size);
				//tempo inicio
				sorting.insertionSort(input, size);
				//tempo fim
				for(int i = 0; i < size; i++)
	 				cout << input[i] << endl;

				cout << "[3] Merge sort\n" << endl;
				sorting.copy(input, input_aux, size);
				//tempo inicio
				sorting.mergeSort(input, 0, (size-1));
				//tempo fim
				for(int i = 0; i < size; i++)
	 				cout << input[i] << endl;

				cout << "[4] Quicksort\n" << endl;
				sorting.copy(input, input_aux, size);
				//tempo inicio
				sorting.quickSort(input, 0, (size-1));
				//tempo fim
				for(int i = 0; i < size; i++)
					cout << input[i] << endl;

				cout << "[5] Heapsort\n" << endl;
				sorting.copy(input, input_aux, size);
				//tempo inicio
				sorting.heapSort(input, (size));
				//tempo fim
				for(int i = 0; i < size; i++)
					cout << input[i] << endl;

			}
			else
			{

				cout << "arquivo" << endl;

			}

		}

	}
	else
	{

		cout << "Argumento" << endl;

	}
	

}

void searchDirFiles(const char* d, vector<string>* f)
{

	DIR* dir = NULL;
	struct dirent* drnt; 

	dir = opendir(d);
	if(dir)
	{

		while(drnt = readdir(dir))
		{

			int p = 0;
			string s_aux = (string)drnt->d_name;
			p = s_aux.find("~");

			if(s_aux == "." || s_aux == ".." || s_aux[p] == '~'){cout << "if " << s_aux << endl;}
            else
            {
cout << s_aux << endl;
                f->push_back((string)drnt->d_name);

            }

		}

	}
	else
	{

		cout << "Diretorio nao encontrado, nao foi possivel abrir" << endl;
		exit(1);

	}

	closedir(dir);

}