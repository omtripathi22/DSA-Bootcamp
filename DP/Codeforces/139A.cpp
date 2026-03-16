#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> days(7);
    int add = 0;
    for (int i = 0; i < 7; i++)
    {
        cin >> days[i];
        // add+=days[i];
    }

    while (n > 0)
    {
        for (int i = 0; i < 7; i++)
        {
            n -= days[i];
            if (n <= 0)
            {
                cout << i + 1;
                return 0;
            }
        }
    }
}