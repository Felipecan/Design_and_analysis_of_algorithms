#include "Heuristic.h"

int main()
{

	Heuristic h;
	int size;
	std::string aux;

	std::vector<std::string> input_v;


	std::cin >> size;
	input_v.reserve(size);

	while(std::cin >> aux)
		input_v.push_back(aux);

	h.heuristic(&input_v, size);

	return 0;

}