#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d ", &n);
    for (int i = 0; i < n; i++)
    {
        string msg, new_msg,test;
        getline(cin, msg);
        bool code = true;
        for (auto x : msg)
        {
            if (x == ' ')
            {
                code = true;
            }
            else if (x == '\n')
            {
                continue;
            }
            else if (code)
            {
                new_msg.push_back(x);
                code = false;
            }

            else
            {
                continue;
            }
        }
        cout << new_msg << endl;
    }

    return 0;
}
