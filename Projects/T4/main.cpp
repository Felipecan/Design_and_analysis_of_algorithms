#include "Heuristic.h"

int main()
{

	Heuristic h;
	int size;
	//std::string aux;
	long aux;
	//std::vector<std::string> input_v;
	std::vector<long> input_v;

	std::cin >> size;
	input_v.reserve(size);

	while(std::cin >> aux)
		input_v.push_back(aux);

	//h.heuristic(&input_v, size);
	h.radixSort_num(&input_v, size);
	for(int i = 0; i < size; i++)
		std::cout << input_v[i] << std::endl;



	//h.analysis(&input_v, size);
	/*std::string s = "asçkldjfçlskjdfçklsjadfçlkjsaf";
	
	auto pos = std::string::npos

	while((pos = to_search.find))
*/
	//h.introsort(&input_v, size);
	//h.heapsort(&input_v, size);
	//h.insertionSort(&input_v, size);
	//h.quicksort(&input_v, 0, size-1);
	//h.radixSort_num(&input_v, size);
	//h.countingSort(&input_v, size);
	//for(int i = 0; i < size; i++)
	//	std::cout << input_v[i] << std::endl;

	return 0;

}