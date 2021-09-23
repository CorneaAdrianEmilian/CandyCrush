# CandyCrush
Algoritm ce simuleaza jocul "CandyCrush". Functia va cauta cea mai mare secventa  de culori din stanga vectorului, culorile fiind reprezentate de numere. Daca prin eliminarea 
grupului de "culori" se formeaza alta secventa aceasta va fi eliminata la randul ei urmand sa se testeze posibilitatea crearii altei secvente prin eliminarea celeilalte. Procesul
se repeta pana nu mai exista alte secvente create prin eliminarea altora. Ajuns in acest punct, algoritmul va cauta din nou cea mai mare grupare de "culori" aflata cel mai 
aproape de inceputul vectorului.
Exemplu:
5 1 3 3 2 2 2 2 3 1 1 5 6 4 4 4 4 4 7
5 1 3 3 3 1 1 5 6 4 4 4 4 7
5 1 1 1 5 6 4 4 4 4 7
5 5 6 4 4 4 4 7
5 5 6 7
