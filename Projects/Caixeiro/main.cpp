#include <iostream>
#include <cstdlib>

//#define DEBUG

using namespace std;

int main(int argc, char** argv)
{

	//auxiliares
	unsigned int i = 0;
	unsigned int index = 0;
	unsigned int seq = 0;
	unsigned int temp = 4294967295; //maior tamanho que um unsigned int pode receber

	unsigned int read, size;
	unsigned int cost = 0;
	bool* city_control;
	unsigned int* circuit;
	unsigned int **matrix_adj;
	

	//tamanho e alocação da matriz de adjacências...
	cin >> size;

	matrix_adj = (unsigned int**)calloc(size, sizeof(unsigned int*));
	for(unsigned int i = 0; i < size; i++)
		matrix_adj[i] = (unsigned int*)calloc(size, sizeof(unsigned int));

	//preenchendo a matriz de adjacências...
	for(unsigned int i = 0; i < size; i++)
	{
		for(unsigned int j = 0; j < size; j++)
		{	
			cin >> read;
			matrix_adj[i][j] = read;
		}
	}

	//Array para identificar as cidades visatas e o circuito que ira percorrer no fim de tudo...
	city_control = (bool*)calloc(size, sizeof(bool));
	circuit = (unsigned int*)calloc(size, sizeof(unsigned int));

	//a cidade 0 (1) recebe true como visitada, pois é origem e 1 no circuito pois é a cidade 1...
	city_control[index] = true;
	circuit[seq] = 1;

	//percorre até o size-1, porque a última cidade não precisa ser analisada, ela vai voltar para o inicio
	while(seq < size-1)
	{	

		//percorrendo as cidades a qual deve ir...
		for(int j = 0; j < size; j++)
		{	
			//se o valor não for zero, pois ele aponta para ele mesmo e tiver um caminho menor...
			if((matrix_adj[i][j] != 0) && (temp > matrix_adj[i][j]))
			{
				temp = matrix_adj[i][j];
				index = j;

				if(city_control[index])//caso a cidade já tenha cido visitada, começa novamente...
				{					   //e zera o valor que foi encontrado, pois ele não entra...
					matrix_adj[i][j] = 0;
					j = -1;
					temp = 4294967295;
				}
			}
		}
		
		//atualização do indices 
		circuit[++seq] = index+1;
		city_control[index] = true;
		i = index;
		cost += temp;
		temp = 4294967295;
		
	}

	//calculando o custo final, do último para o cidade de origem (1)...
	cost += matrix_adj[index][0];

	
	//impressão dos valores finais
	cout << "Valor: " << cost << endl;
	cout << "Circuito: ";
	for(unsigned int i = 0; i < size; i++)
		cout << circuit[i] << " - ";
	cout << "1" << endl;

	#ifdef DEBUG
	cout << "MATRIZ" << endl;
	for(unsigned int i = 0; i < size; i++)
	{
		for(unsigned int j = 0; j < size; j++)
		{	
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	#endif

	//limpando...
	free(city_control);
	free(circuit);
	free(matrix_adj);

	return 0;

}