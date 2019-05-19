#include "Vektorius2.h"
#include <vector>
#include <fstream>


int main()
{
	std::ofstream RZ("Rezultatai.txt");
	int cap = 0, sz = 1000;
	auto begin = std::chrono::high_resolution_clock::now();
	auto end = std::chrono::high_resolution_clock::now();
	for (int y = 0; y < 1; y++)
	{
		sz *= 10;
		RZ << "Dabar yra tiek irasu - " << sz << std::endl;
		begin = std::chrono::high_resolution_clock::now();
		std::vector<int> v1;
		for (int i = 1; i <= sz; ++i)
		{
			v1.push_back(i);
		}
		end = std::chrono::high_resolution_clock::now();
		RZ << "Irasant duomenis i std::vector prireike " << std::endl;
		RZ << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanosekundziu" << std::endl;
		v1.clear();
		begin = std::chrono::high_resolution_clock::now();
		Vector<int> v2;
		for (int i = 1; i <= sz; ++i)
		{
			v2.push_back(i);
		}
		end = std::chrono::high_resolution_clock::now();
		RZ << "Irasant duomenis i Vector prireike " << std::endl;
		RZ << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanosekundziu" << std::endl;
		v2.clear();
	}
	return 0;
}