#include "game.h"

void sequenceDestroyer(std::vector<int>& culori)
{
	if(culori.size()>0)
	{
		int culoare = 0;
		//folosim 4 iteratori pentru a parcurge vectorul. 2 iteratori sunt folositi pentru a pastra secventa curenta
		//  "first" si "last". in cazul in care dimensiunea secventei curente este mai mare ca cea mai mare dimensiune "theBiggest"
		// se actualizeaza ceilalti 2 iteratori care tin secventa cu cea mai mare dimensiune "firstErase" "lastErase"
		std::vector<int>::iterator first = culori.begin();
		std::vector<int>::iterator last;
		std::vector<int>::iterator firstErase = culori.begin();
		std::vector<int>::iterator lastErase;
		//primul index testat
		culoare = *first;
		//variabila care opreste stergerea elementelor in cazul in care nu mai sunt secvente la final
		bool repeat = false;
		//dimensiunea secventei curente
		int d_secventa = 1;
		//dimensiunea celei mai mari secvente pana in prezent
		int theBiggest = 1;
		
		for (std::vector<int>::iterator it = culori.begin() + 1; it != culori.end(); it++)
		{
			//if care testeaza daca sunt identice 2 indexe. doar daca se intra in else se seteaza "last"
			//daca "it" reprezinta ultimul element avem nevoie de un alt if daca indecsii sunt identici
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
		//conditie ca secventa sa fie de minim 3 elemente
		if (theBiggest >= 3)
		{
			//doar in cazul in care secventa cea mai mare gasita are in stanga si in dreapta ei minim un element se poate produce
			// un "aftereffect" care ar putea lipi indecsii astfel in cat sa formeze o secventa. ex: 3 555 33
			//daca secventa nu are un element fie in stanga fie dreapta nu se poate forma o alta secventa. ex: 555 33 sau 33 555

			if (lastErase != culori.end() - 1 && firstErase != culori.begin())
			{
				afterEffect = true;
				//index care salveaza elementul din stanga secventei inainte de stergere
				afterIndex = firstErase - 1;
			}
		}
		//in cazul in care secventa se afla la finalul vectorului daca apelam erase de "firstErase" si "lastErase" ultimul
		//  element al secventei ramane nesters
		if (theBiggest >= 3) {
			if (lastErase == culori.end() - 1 && *lastErase == *(lastErase - 1)) {
				//culori.erase(firstErase, lastErase);
				culori.erase(firstErase, culori.end());
				repeat = true;
			}
			else
				culori.erase(firstErase, lastErase);
			repeat = true;
		}

		//doar in cazul in care s-a eliminat o secventa printam ca a ramas
		if (repeat)
		{
			for (auto it = culori.begin(); it != culori.end(); it++)
			{
				std::cout << (*it) << ' ';
			}
			std::cout << std::endl;
		}
		//folosim 2 bucle while pentru ca nu stim care "aftereffecte" se produc dupa eliminarea secventei
		//se pot forma de la 0 in sus iar daca avem 2 trebuie executat de 2 ori codul
		//ex: 1 3 3  5 5 5  3 1 1/  1  3 3 3  1 1/ 1 1 1 / 
		while (afterEffect)
		{

			d_secventa = 1;
			bool eraseAfter = false;
			//variabila pentru testat indecsii
			int temp = 0;
			//setam iteratorii folositi la erase pe cei doi indecsi care erau in stanga si dreapta secventei sterse
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
				//in cazul unui "aftereffect" trebuie testat si in stanga si in dreapta indexului salvat "afterIndex"
				//testam in dreapta cu conditia sa nu fi terminat deja de testat "conditie1"
				if (temp == *lastErase && !conditie1)
				{
					++d_secventa;
				}
				else
				{
					conditie1 = true;
				}
				//incrementam doar daca nu s a terminat deja testarea in dreapta si daca nu am atins ultimul element
				if (culori.end() - 1 != lastErase && !conditie1)
					lastErase++;
				//testam in stanga cu conditia sa nu fi terminat deja de testat "conditie2" si sa nu fi ajuns cu indexul"afterIndex" la primul element
				if (afterIndex != culori.begin() && !conditie2) {
					if (*afterIndex == *(afterIndex - 1)) {
						afterIndex = afterIndex - 1;
						d_secventa++;
					}
					else
						conditie2 = true;
				}//daca nu mai avem indecsii in stanga s-a terminat testarea iar daca nu mai avem duplicate iar s-a terminat testarea (in stanga)
				else
					conditie2 = true;
				//daca avem o secventa de minim 3 putem sterge iar
				if (d_secventa >= 3)
					eraseAfter = true;
				// daca ambele testari(dreapta-stanga) s-au terminat iesim din bucla secundara
				if (conditie1 && conditie2) {
					afterEffect = false;
				}


			}
			firstErase = afterIndex;
			//aceeasi regula de mai sus cu "afterEffect-ul"- daca avem indecsi in stanga si dreapta
			if (lastErase != culori.end() - 1 && firstErase != culori.begin() && eraseAfter)
			{
				//asa setam bucla principala pe true si se reia procesul pana nu mai exista "afterEffect"
				afterEffect = true;
				afterIndex = afterIndex - 1;
			}
			if (eraseAfter)
			{


				if (lastErase == culori.end() - 1 && *lastErase == *(lastErase - 1)) {
					//culori.erase(firstErase, lastErase);
					culori.erase(firstErase, culori.end());
				}
				else
					culori.erase(firstErase, lastErase);
			}

			//printam doar daca am sters o secventa
			if (eraseAfter) {
				for (auto it = culori.begin(); it != culori.end(); it++)
				{
					std::cout << (*it) << ' ';
				}
				std::cout << std::endl;
			}
			

		}
		//functia va mai rula o data ca sa testeze daca mai poate elimina alte secvente principale
		//in cazul in care nu exista nici o secventa de minim 3 repeat va fi false
		if (!afterEffect && repeat)
			sequenceDestroyer(culori);
		if (!repeat) {
			std::cout << "Numar de bile ramase:" << culori.size() << std::endl;
		}
	}
	
}
