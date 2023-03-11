#include <string>
#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = nullptr;
};

LinkedList::~LinkedList()
{
    clear();
};

// Libera mem�ria 
void LinkedList::clear()
{
    NodeLL* pAnt, * pAnda = head;

    while (pAnda != nullptr)
    {
        pAnt = pAnda;  // Libera o n�
        pAnda = pAnda->getProx();
        pAnt->setProx(nullptr);
        delete pAnt;
        pAnt = nullptr;
    }
    head = nullptr;
}

bool LinkedList::isEmpty()
{
    if (getHead() == nullptr) return true;
    else return false;
};

bool LinkedList::isFull()
{
    NodeLL* aux = new NodeLL();

    if (aux == nullptr) return true;

    aux = nullptr;
    return false;
};

bool LinkedList::insertHead(int id)
{
    NodeLL* aux;
    if (!isFull())
    {
        aux = new NodeLL(id, nullptr, nullptr, 0);
        if (isEmpty())
        { // Lista est� vazia
            head = aux;
            head->setCount(1);
            head->setTail(head);
        }
        else
        { // Insere no come�o e atualiza o ponteiro
            aux->setProx(head);
            aux->setCount(head->getCount() + 1);
            aux->setTail(findTail());
            head->setCount(0);
            head->setTail(nullptr);
            head = aux;
        }
        return true;
    }
    else return false; // std::cout << "Overflow � Sem mem�ria";
};

bool LinkedList::insertTail(int id)
{
    NodeLL* aux, * pAnda;
    if (!isFull())
    {

        if (isEmpty())
        { // Lista est� vazia
            insertHead(id);
        }
        else
        { // Insere no final e atualiza o ponteiro
            aux = new NodeLL(id, nullptr, nullptr, 0);
            pAnda = head;  // Ponteiro que anda at� o final da lista 
            while (pAnda->getProx() != nullptr)
                pAnda = pAnda->getProx();
            pAnda->setProx(aux);
            head->setTail(aux);
            head->setCount(head->getCount() + 1);
        }
        return true;
    }
    else return false; // std::cout << "Overflow � Sem mem�ria";
};


NodeLL* LinkedList::search(int id) {
    NodeLL* pAnda;

    if (isEmpty())
    {
        return nullptr; // Lista vazia
    }
    else
    {
        pAnda = head;
        // procura a posi�o do elemento na lista
        while ((pAnda != nullptr) && (pAnda->getId() != id))
            pAnda = pAnda->getProx();
        return pAnda; // Retorna a refer�ncia para o elemento	encontrado
    }
}

bool LinkedList::remove(int id)
{
    NodeLL* pAnt = nullptr, * pAnda;
    if (isEmpty()) return false; // Lista vazia
    else {
        pAnda = head;
        // procura a posi�o do elemento na lista
        while ((pAnda != nullptr) && (pAnda->getId() != id))
        {
            pAnt = pAnda;
            pAnda = pAnda->getProx();
        }
        if (pAnda == nullptr) return false; // Se n�o encontrou o elemento
        // Se elemento encontrado remove da lista
        else
        {
            // se o elemento encontrado est� na cabe�a da lista
            if ((head == pAnda))
            {
                head->getProx()->setTail(head->getTail());
                head->getProx()->setCount(head->getCount() - 1);
                head = pAnda->getProx();
            }
            else
            { // remove elemento do meio/fim
                if (pAnda != findTail())
                {
                    pAnt->setProx(pAnda->getProx());
                    head->setCount(head->getCount() - 1);
                }
                else
                {
                    NodeLL* newTail = head;
                    while (newTail->getProx()->getProx() != nullptr)
                        newTail = newTail->getProx();
                    head->setTail(newTail);
                    pAnt->setProx(pAnda->getProx());
                    head->setCount(head->getCount() - 1);
                }
            }
            delete pAnda;
            pAnda = nullptr;
            return true;
        }
    }
}

void LinkedList::print()
{
    NodeLL* pAnda;
    std::cout << "L: [ ";
    pAnda = head;
    while (pAnda != nullptr)
    {
        std::cout << pAnda->getId() << " ";
        pAnda = pAnda->getProx();
    }
    std::cout << "]\n";
}

int LinkedList::contElemList()
{ 
    if (isEmpty())
        return -1;

    int count = 0;
    NodeLL* current = head;
    while (current->getProx() != nullptr)
    {
        count++;
        current = current->getProx();
    }
    current = nullptr;
    return count + 1;
}

NodeLL* LinkedList::findTail()
{
    if (isEmpty())
        return nullptr;

    NodeLL* current = head;
    while (current->getProx() != nullptr)
    {
        current = current->getProx();
    }
    return current;
}

bool LinkedList::insertGrowing(int elem)
{
    if (isFull())
    {
        return false;
    }

    if (isEmpty())
    {
        insertHead(elem);
    }
    else
    {
        int pos = findOrderingPos(elem);

        if (pos == -1 || pos == head->getCount())
            insertTail(elem);
        else if (pos == 0)
            insertHead(elem);
        else
        {
            NodeLL* newNode = new NodeLL(elem, nullptr, nullptr, 0);
            NodeLL* beforeNewNode = head;
            for (int i = 0; i < pos - 1; i++)
            {
                beforeNewNode = beforeNewNode->getProx();
            }
            newNode->setProx(beforeNewNode->getProx());
            beforeNewNode->setProx(newNode);
            head->setCount(head->getCount() + 1);
            beforeNewNode = nullptr;
        }
    }
    return true;
}

int LinkedList::findOrderingPos(int elem)
{
    NodeLL* current = head;
    for (int i = 0; i < head->getCount(); i++)
    {
        if (current->getId() > elem)
        {
            current = nullptr;
            return i;
        }
        current = current->getProx();
    }
    current = nullptr;
    return -1;
}


