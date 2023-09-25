#include <iostream>
#include <vector>
#include "grafo.h"
using namespace std;

// nó

NoList::NoList()
{
    index = 0;
    next = NULL;
    prev = NULL;
}
NoList::NoList(int a)
{
    index = a;
    next = NULL;
    prev = NULL;
};

// LinkedList

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
    color = 0;
};

void LinkedList::insertH(int x)
{
    NoList *no = new NoList(x);
    if (head == NULL)
    {
        head = no;
    }
    else
    {
        head->prev = no;
        no->next = head;
        head = no;
    }
};



Grafo::Grafo()
{
    V = 0;
};
Grafo::Grafo(int a)
{
    V = a;
    for (int i = 0; i < V; i++)
    {
        lists.push_back(new LinkedList());
        visited.push_back(0);
    }
    
};
Grafo::~Grafo()
{
    for (int i = 0; i < V; i++)
    {
        free(lists[i]);
    }
}

void Grafo::add_a(int a, int b)
{
    lists[a]->insertH(b);
    lists[b]->insertH(a);
}

bool Grafo::dfs(int a, int color){
    lists[a]->color = color;
    NoList *aux = lists[a]->head; //variavel auxiliar para adentrar os adj de cada vertice
    while (aux != nullptr) //enquanto tiver adj vai acessando todos
    {
        if(lists[aux->index]->color == 0){ //se o vertice n tem cor designada 
            if(color == 1){
                return dfs(aux->index, 2); //chama a função recursiva com a cor alternativa
            }
            else{
                return dfs(aux->index, 1); //chama a função recursiva com a cor alternativa
            }
           
        }
        if(lists[aux->index]->color == color){ //se o vertice adj ja tem a mesma cor do vertice atual, retorna falso
            return false;
        }
        aux = aux->next;
    }
    return true; //se rodar tudo certo ate o final retorna true
    
    }; 

