#include <iostream>
#include "LinkedList.h"

void insertTail(LinkedList *ll){
	int e;
   	std::cout <<"\nElemento a Inserir: ";
   	std::cin >> e;
   	if (ll->insertTail(e)) std::cout << "Sucesso!\n";
   	else std::cout << "Falha na inserção!\n";
}

void insertHead(LinkedList *ll){
	int e;
   	std::cout <<"\nElemento a Inserir: ";
   	std::cin >> e;
   	if (ll->insertHead(e)) std::cout << "Sucesso!\n";
   	else std::cout << "Falha na inserção!\n";
}

void remove(LinkedList *ll){
	int e;
   	std::cout <<"\nElemento a Remover: ";
   	std::cin >> e;
   	if (ll->remove(e)) std::cout << "Sucesso!\n";
   	else std::cout << "Falha na remoção!\n";	
}


void search(LinkedList *ll){
	int e;
   	std::cout <<"\nElemento a procurar: ";
   	std::cin >> e;
   	if (ll->search(e) != nullptr) std::cout << "Elemento " << e << " Encontrado!\n";
   	else std::cout << "Elemento " << e << " não encontrado!\n";	
}


int main() {
	
	LinkedList* ll = new LinkedList();

	const int SIZE = 9;
	int ids[SIZE] = { 5, 4, 3, 1, 2, 6, 7, 9, 8 };

	for (int i = 0; i < SIZE; ++i)
		ll->insertTail(ids[i]);

	int option = 0;
	do
	{
		std::cout << "*** Linked List ***\n"
			<< "[1] Insert tail\n"
			<< "[2] Insert head\n"
			<< "[3] Remove\n"
			<< "[4] Search\n"
			<< "[5] Print\n"
			<< "[6] Clear\n"
			<< "[0] Exit\n"
			<< "Option: ";
		std::cin >> option;
		std::cout << '\n';

		switch (option)
		{
		case 1: insertTail(ll);  break;
		case 2: insertHead(ll); break;
		case 3: remove(ll); break;
		case 4: search(ll); break;
		case 5: ll->print(); break;
		case 6: ll->clear(); break;
		}

		std::cout << '\n';
	} while (option != 0);

 	ll = nullptr;	
	system("pause");
	return 0;

}
