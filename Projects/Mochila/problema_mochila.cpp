////////////////////////////////////////////////////////////////////////////////////////////
         /////////   Alunos: Felipe da Cunha Andrade Nunes, 11328535    /////////
		/////////            Wellton Thyago de Souza, 11325715         /////////
////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <stdlib.h>

//#define DEBUG

using namespace std;

int main(int argc, char** argv)
{

	int **mat, **mat_in;
	int capacity = 0;
	int q_elem = 0;
	int temp = 0;
	vector<int> index;

	//leituras das variáveis...
	cin >> q_elem;
	cin >> capacity;

	// tabela de pesos e valores
	mat_in = (int**)calloc(q_elem, sizeof(int*));
	for(int i = 0; i < q_elem; i++)
		mat_in[i] = (int*)calloc(2, sizeof(int));
	
	//tabela de elementos por capacidade
	mat = (int**)calloc(q_elem+1, sizeof(int*));
	for(int i = 0; i < q_elem+1; i++)
		mat[i] = (int*)calloc(capacity+1, sizeof(int));

	//preenchimento da matriz de pesos e valores
	for(int i = 0; cin >> temp; i++)
	{
		if(i < q_elem)
			mat_in[i][0] = temp;
		else
			mat_in[i - q_elem][1] = temp;
	}

	//preenchendo a matriz de elementos e capacidade
	for(int i = 1; i <= q_elem; i++)
	{
		for(int j = 1; j <= capacity; j++)
		{
			if(mat_in[i-1][0] <= j)// se o elemento cabe na mochila
			{	
				if((mat_in[i-1][1] + mat[i-1][j-mat_in[i-1][0]]) > mat[i-1][j])//teste...
					mat[i][j] = (mat_in[i-1][1] + mat[i-1][j-mat_in[i-1][0]]);
				else
					mat[i][j] = mat[i-1][j];
			}
			else
			{
					mat[i][j] = mat[i-1][j];
			}
		}
	}

	//encontrando os indices que foram escolhidos
	temp = capacity;
	for(int i = q_elem; i > 0; i--)
	{	
		//cout << "i " << i << endl;
		if((mat[i][temp] != mat[i-1][temp]) ) //se houver mudança...
		{	
			index.push_back(i);
			temp -= mat_in[i-1][0];
		}
		else
		{

		}
	}

	//resposta final...
	cout << "valor = " << mat[q_elem][capacity] << endl;
	cout << "indices = " ;
	for(int i = index.size()-1; i >= 0 ; i--)
		cout << index[i] << " ";
	cout << endl;
	//responsta final...


	#ifdef DEBUG
	for(int i = 0; i < q_elem+1; i++)
		for(int j = 0; j < capacity+1; j++)
			cout << "mat[" << i << "]" << "[" << j << "] " << mat[i][j] << endl;
	#endif

	return 0;

}
