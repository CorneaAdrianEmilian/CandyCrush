#include "game.h"

void sequenceDestroyer(std::vector<int>& culori)
{
	if(culori.size()>0)
	{
		int culoare = 0;
		std::vector<int>::iterator first = culori.begin();

		culoare = *first;
		std::vector<int>::iterator last;
		std::vector<int>::iterator firstErase = culori.begin();
		std::vector<int>::iterator lastErase;
		bool repeat = false;
		int d_secventa = 1;
		int theBiggest = 1;
		int index = 0;
		for (std::vector<int>::iterator it = culori.begin() + 1; it != culori.end(); it++)
		{
			if (culoare == *it) {

				++d_secventa;
				if (it == culori.end() - 1)
				{
					last = it;
					if (theBiggest < d_secventa)
					{
						lastErase = it;
						firstErase = first;
						theBiggest = d_secventa;
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
		std::vector<int>::iterator afterIndex;
		bool afterEffect = false;
		if (theBiggest >= 3)
		{
			if (lastErase != culori.end() - 1 && firstErase != culori.begin())
			{
				afterEffect = true;
				afterIndex = firstErase - 1;
			}
		}

		if (theBiggest >= 3) {
			if (lastErase == culori.end() - 1 && *lastErase == *(lastErase - 1)) {
				culori.erase(firstErase, lastErase);
				culori.erase(culori.end() - 1, culori.end());
			}
			else
				culori.erase(firstErase, lastErase);
			repeat = true;
		}

		if (repeat)
		{
			for (auto it = culori.begin(); it != culori.end(); it++)
			{
				std::cout << (*it) << ' ';
			}
			std::cout << std::endl;
		}

		while (afterEffect)
		{
			d_secventa = 1;
			bool eraseAfter = false;
			int temp = 0;
			firstErase = afterIndex;
			lastErase = afterIndex + 1;
			if (afterEffect)
			{
				temp = *afterIndex;
			}
			bool conditie1 = false;
			bool conditie2 = false;
			while (afterEffect)
			{
				if (temp == *lastErase && !conditie1)
				{
					++d_secventa;
				}
				else
				{
					conditie1 = true;
				}
				if (culori.end() - 1 != lastErase && !conditie1)
					lastErase++;
				if (afterIndex != culori.begin() && !conditie2) {
					if (*afterIndex == *(afterIndex - 1)) {
						afterIndex = afterIndex - 1;
						d_secventa++;
					}
					else
						conditie2 = true;
				}
				else
					conditie2 = true;
				if (d_secventa >= 3)
					eraseAfter = true;
				if (conditie1 && conditie2) {
					afterEffect = false;
				}


			}
			firstErase = afterIndex;
			if (lastErase != culori.end() - 1 && firstErase != culori.begin() && eraseAfter)
			{
				afterEffect = true;
				afterIndex = afterIndex - 1;
			}
			if (eraseAfter)
			{


				if (lastErase == culori.end() - 1 && *lastErase == *(lastErase - 1)) {
					culori.erase(firstErase, lastErase);
					culori.erase(culori.end() - 1, culori.end());
				}
				else
					culori.erase(firstErase, lastErase);
			}


			if (eraseAfter) {
				for (auto it = culori.begin(); it != culori.end(); it++)
				{
					std::cout << (*it) << ' ';
				}
				std::cout << std::endl;
			}
			bool repeat = false;

		}
		if (!afterEffect && repeat)
			sequenceDestroyer(culori);
	}
	
}
