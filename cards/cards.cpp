#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;
    while (n != 0)
    {
        deque<int> cards, discard;
        for (int i = 0; i < n; i++)
        {
            cards.push_back(i);
        }
        cout << "Discarded cards: ";
        cout << cards.front()+1;
        cards.pop_front();
        cards.push_back(cards[0]);
        cards.pop_front();
        n--;
        while (n > 1)
        {
            cout << ", " << cards.front()+1;
            cards.pop_front();
            cards.push_back(cards[0]);
            cards.pop_front();
            n--;
        }
        cout<<"\n";
        cout<<"Remaining card: "<< cards.front()+1;
        cin>>n;
        cout<<"\n";
    }
    return 0;
