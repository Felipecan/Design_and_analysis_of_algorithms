#include "Sorting_Algorithms.h"

using namespace std;

Sorting_Algorithms::Sorting_Algorithms()
{

	size = 0;

}

Sorting_Algorithms::~Sorting_Algorithms(){}

void Sorting_Algorithms::selectionSort(int* v, int size)
{

	int min, aux;

	for(int i = 0; i < (size-1); i++) //laço externo, controlando os índices do vetor
	{

		min = i; //define o min como o primeiro, em seguida o segundo... e assim vai

		for(int j = (i+1); j < size; j++) //laço interno, comparando os valores...
		{

			if(v[j] < v[min]) // se o elemento do laço interno for menor que o min estabelecido, atribuir nova posição minima
			{

				min = j;

			}

		}

		if(i != min) //verifica se a posição i teve algum menor, se sim, fazer a troca
		{

			aux = v[i];
			v[i] = v[min];
			v[min] = aux;

		}

	}

}

void Sorting_Algorithms::insertionSort(int* v, int size)
{

	for(int i = 1; i < size; i++)
 	{

 		int k = v[i];
 		int j = i-1;

 		while((j >= 0) && (v[j] > k)) // enquanto o não estiver percorrido todo vetor ao contrário
 		{							  // E enquanto o valor na posição j for maior que o o valor na posição i

 			v[j+1] = v[j]; //a próxima posição recebe a anterior... joga o vetor pra "frente"
 			j--;

 		}

 		v[j+1] = k; //como o j voltou a um valor baixo, ele adiciona mais um e inseri o k v[...]

 	}

}

void Sorting_Algorithms::mergeSort(int* v, int beg, int end)
{

	int i, j, k, middle;
	int* v_aux;

	if(beg == end)
		return;

	middle = (beg+end)/2; ///meio do vetor
	mergeSort(v, beg, middle); //smalleramada recursiva que divide os vetores ao meio (a partir do inicio)
	mergeSort(v, middle+1, end); //smalleramada recursiva que divide os vetores ao meio (a partir do meio)

	i = beg;
	j = middle+1;
	k = 0;

	v_aux = new int[end-beg+1];

	while((i < middle+1) || (j < end+1)) //enquanto o indicie incial for menor que o meio
	{									 //ou enquanto o indice do meio for menor que o fim

		if(i == middle+1) // se i(beg) passou da metade
		{

			v_aux[k] = v[j]; //vetor temporário pega o v[j]
			j++;
			k++;

		}
		else
		{

			if(j == end+1) //caso j passo da segunda metade
			{

				v_aux[k] = v[i]; //vetor temporario pega o v[i]
				i++;
				k++;

			}
			else
			{

				if(v[i] < v[j])
				{

					v_aux[k] = v[i];
					i++;
					k++;

				}
				else
				{

					v_aux[k] = v[j];
					j++;
					k++;

				}

			}

		}

	}

	for(i = beg; i <= end; i++) // copia para o vetor original no final
		v[i] = v_aux[i-beg];

	delete[] v_aux;

}

void Sorting_Algorithms::quickSort(int* v, int left, int right)
{

 	int pivo = left; //incia o pivo como o indice mais a esqueda, o início
 	int i, smaller, j;

 	for(i = left+1; i <= right; i++) // o for percorre o vetor até o indice mais a direita
 	{

 		j = i;

 		if(v[j] < v[pivo]) //se a posição atual v[j] for menor que a do pivo
 		{

 			smaller = v[j]; //sendo menor, a variável recebe o valor de v[j]

 			while(j > pivo) //desloca os valores a partir do indice j para esquerda
 			{

 				v[j] = v[j-1];
 				j--;

 			}
 			
 			v[j] = smaller; //a posĩção j, atribui o menor valor encontrado
 			pivo++; //desloca o pivo

 		}

 	}

 	if((pivo-1) >= left) //verificando se o pivo é maior que o final, então finaliza, se passar
 	{

 		quickSort(v, left, (pivo-1));

 	}

 	if((pivo+1) <= right)//verifica se é menor, se for, ainda está dentro dos limeites, então continua
 	{

 		quickSort(v, (pivo+1), right);

 	}

}

void Sorting_Algorithms::heapSort(int* v, int num_elements)
{

 	int size = num_elements;
 	int i = num_elements/2;
 	int father, son, t;

 	for(;;)
 	{

 		if(i > 0)
 		{

 			i--;
 			t = v[i];

 		}
 		else   
 		{

 			num_elements--;

 			if(num_elements == 0) 
 				return;

 			t = v[num_elements];
 			v[num_elements] = v[0];

 		}

 		father = i;
 		son = i*2+1;

 		while(son < num_elements)
 		{

 			if((son+1 < num_elements) && (v[son+1] > v[son]))
 				son++;

 			if(v[son] > t)
 			{

 				v[father] = v[son];
 				father = son;
 				son = father*2+1;

 			}
 			else
 			{

 				break;

 			}

 		}

 		v[father] = t;

 	}

}

void Sorting_Algorithms::copy(int* d, int* o, int size)
{

	for(int i = 0; i < size; i++)
		d[i] = o[i];

}

