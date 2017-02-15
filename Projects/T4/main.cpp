#include "Heuristic.h"

int main()
{

	Heuristic h;
	int size;
	int aux;
	std::vector<int> input_v;

	std::cin >> size;
	input_v.reserve(size);

	while(std::cin >> aux)
		input_v.push_back(aux);

	std::string s = "asçkldjfçlskjdfçklsjadfçlkjsaf";
	std::locale loc;

	std::cout << s << std::endl;

	if(std::isalpha(s[0], loc))
		std::cout << "true" << std::endl;

	if(!std::isalpha(s[0], loc))
		std::cout << "false" << std::endl;

	//h.radixSort_num(&input_v, size);
	//for(int i = 0; i < size; i++)
	//	std::cout << input_v[i] << std::endl;

}