#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <vector>


using namespace std;

class NoList {
    public:
        int index;
        NoList* next;
        NoList* prev;

public:
    NoList();
    NoList(int a);
};

class LinkedList {
    public:
        NoList* head;
        NoList* tail;
        int color;

public:
    LinkedList();

    void insertH(int x);

};
class Grafo{
    public:
        int V;
        vector<LinkedList*> lists;
        vector<int> visited;

public:
    Grafo();
    Grafo(int a);
    ~Grafo();

    void add_a(int a, int b);
    bool dfs(int a, int r);
};

#endif
