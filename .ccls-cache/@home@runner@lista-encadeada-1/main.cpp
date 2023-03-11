#include <iostream>
#include "LinkedList.h"

void insertTail(LinkedList* ll)
{
	int e;
	std::cout << "\nElemento a Inserir: ";
	std::cin >> e;
	if (ll->insertTail(e)) std::cout << "Sucesso!\n";
	else std::cout << "Falha na inserção!\n";
}

void insertHead(LinkedList* ll)
{
	int e;
	std::cout << "\nElemento a Inserir: ";
	std::cin >> e;
	if (ll->insertHead(e)) std::cout << "Sucesso!\n";
	else std::cout << "Falha na inserção!\n";
}

void remove(LinkedList* ll)
{
	int e;
	std::cout << "\nElemento a Remover: ";
	std::cin >> e;
	if (ll->remove(e)) std::cout << "Sucesso!\n";
	else std::cout << "Falha na remoção!\n";
}


void search(LinkedList* ll)
{
	int e;
	std::cout << "\nElemento a procurar: ";
	std::cin >> e;
	if (ll->search(e) != nullptr) std::cout << "Elemento " << e << " Encontrado!\n";
	else std::cout << "Elemento " << e << " não encontrado!\n";
}

void copiaLista(LinkedList* original, LinkedList* copia)
{
	NodeLL* currentOriginal = original->getHead();
	NodeLL* currentCopia = copia->getHead();
	while (currentOriginal != nullptr)
	{
		currentOriginal->setId(currentCopia->getId());
		currentOriginal = currentOriginal->getProx();
		currentCopia = currentCopia->getProx();
	}	
	currentOriginal = nullptr;
	currentCopia = nullptr;
}

void Exercicio9(LinkedList* ll)
{
	if (ll->isEmpty())
	{
		std::cout << "Lista Vazia\n";
	}
	else
	{
		NodeLL* current = ll->getHead();
		LinkedList* auxll = new LinkedList();
		std::cout << "\nAbaixo,o teste relacionados ao exe 9:";
		std::cout << "\nnumeros a serem inseridos na lista: ";
		ll->print();
		for (int i = 0; i < ll->getHead()->getCount(); i++)
		{
			auxll->insertGrowing(current->getId());
			current = current->getProx();
		}
		copiaLista(ll, auxll); 

		std::cout << "\nlista apos insercao com insertGrowing\n";
		ll->print();
		std::cout << "\nNumero de Elementos: " << ll->getHead()->getCount() << "\nUltimo elemento:" << ll->getHead()->getTail()->getId() << "\n";
		delete auxll;
		auxll = nullptr;
		current = nullptr;
	}
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
			<< "[7] Saida exercicio 2\n"
			<< "[8] Saida exercicio 3\n"
			<< "[9] Saida exercicio 4\n"
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

		case 7:
			if (ll->isEmpty() || ll->contElemList() == -1)
				std::cout << "Lista Vazia";
			else
				std::cout << "\ntamanho = " << ll->contElemList() << "\n";

			break;
		case 8:
			if (ll->findTail() == nullptr || ll->getHead() == nullptr)
				std::cout << "Lista Vazia";
			else
			{
				std::cout << "\nLeitura feita a partir do head: \ntamanho = "
					<< ll->getHead()->getCount() << "\nId do tail = " << ll->findTail()->getId() << "\n";
			}
			break;

		case 9:
			Exercicio9(ll);
			break;
		}

		std::cout << '\n';
	} while (option != 0);
	delete ll;
	ll = nullptr;
	system("pause");
	return 0;

}
