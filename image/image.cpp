    #include <bits/stdc++.h>

    using namespace std;

    int main(int argc, char const *argv[])
    {
        int n, m, n_, m_;
        cin >> n >> m;
        while (n != 0 & m != 0)
        {
            vector<string> matriz;  
            for (int i = 0; i < n; i++)
            {
                string a;
                cin >> a;
                matriz.push_back(a);
            }

            cin >> n_ >> m_;
            int scale_n = n_ / n;
            int scale_m = m_ / m;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < scale_n; j++)
                {
                    for (auto x : matriz[i])
                    {
                        for (int k = 0; k < scale_m; k++)
                        {
                            cout<<x;
                        }
                    }
                    cout<<"\n";
                }
            }

            cin >> n >> m;
        }

        return 0;
    }
