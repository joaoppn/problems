#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, b, h, w, p, a;
    int min;

    while (cin >> n >> b >> h >> w)
    {
        
        min = INT_MAX;

        for (int i = 0; i < h; i++)
        {
            cin >> p;
            bool fits = false;

            for (int j = 0; j < w; j++)
            {
                cin >> a;
                if (a >= n)
                {
                    fits = true;
                    
                }
            }

            if (fits)
            {
                int custo = n * p;
                
                if (custo <= b && custo < min)
                {
                    min = custo;
                    
                }
            }
        }

        if (min == INT_MAX)
        {
            cout << "stay home\n";
        }
        else
        {
            cout << min << "\n";
        }
    }

    return 0;
}
