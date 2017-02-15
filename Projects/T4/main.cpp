#include "Heuristic.h"

#include <iostream>

int main()
{

	Heuristic h;
	int size;
	int aux;
	int* input_v;

	std::cin >> size;
	input_v = new int[size];

	for(int i = 0; std::cin >> aux; i++)
		input_v[i] = aux;

	h.introsort(input_v, size);
	for(int i = 0; i < size; i++)
		std::cout << input_v[i] << std::endl;

}