#include "game.h"

void sequenceDestroyer()
{
	std::vector <int> culori;
	int dimensiune = 0;
	std::cout << "Introduceti numarul de bile:\n";
	std::cin >> dimensiune;
	std::cout << "Introduceti culorile:\n";
	int culoare = 0;
	for (int i = 0; i < dimensiune; i++) {
		std::cin >> culoare;
		culori.push_back(culoare);
	}
	std::vector<int>::iterator first = culori.begin();
	culoare = *first;
	std::vector<int>::iterator last;
	std::vector<int>::iterator firstErase = culori.begin();
	std::vector<int>::iterator lastErase;

	int d_secventa = 1;
	int theBiggest = 1;
	int index = 0;
	for (std::vector<int>::iterator it= culori.begin()+1;it!=culori.end();it++)
	{
		if (culoare == *it) {
			
			++d_secventa;
			if(it==culori.end()-1)
			{
				last = it;
				if (theBiggest < d_secventa)
				{
					lastErase = it;
					firstErase = first;
				}
			}
		}
		else 
		{
			last = it;
			culoare = *it;
			if (theBiggest < d_secventa) 
			{
				theBiggest = d_secventa;
				lastErase = it;
				firstErase = first;
			}
			first = it;
			d_secventa = 1;
		}
	}
	if (lastErase == culori.end() - 1&&*lastErase==*(lastErase-1)) {
		culori.erase(firstErase, lastErase);
		culori.erase(culori.end()-1,culori.end());
	}else
		culori.erase(firstErase, lastErase);
	for (auto it = culori.begin(); it !=culori.end(); it++)
	{
		std::cout << (*it) << ' ';
	}
}
