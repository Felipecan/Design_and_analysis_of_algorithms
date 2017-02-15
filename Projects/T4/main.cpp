#include "Heuristic.h"

int main()
{

	Heuristic h;
	int size;
	//std::string aux;
	int aux;
	//std::vector<std::string> input_v;
	std::vector<int> input_v;

	std::cin >> size;
	input_v.reserve(size);

	while(std::cin >> aux)
		input_v.push_back(aux);

	//h.analysis(&input_v, size);
	/*std::string s = "asçkldjfçlskjdfçklsjadfçlkjsaf";
	std::locale loc;

	std::cout << s << std::endl;

	if(std::isalpha(s[0], loc))
		std::cout << "true" << std::endl;

	if(!std::isalpha(s[0], loc))
		std::cout << "false" << std::endl;*/

	h.countingSort(&input_v, size);
	for(int i = 0; i < size; i++)
		std::cout << input_v[i] << std::endl;

}