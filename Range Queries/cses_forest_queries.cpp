#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<char>> arr(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> prefix(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val = (arr[i][j] == '*');
            prefix[i][j] = val;

            if (i > 0)
                prefix[i][j] += prefix[i - 1][j];
            if (j > 0)
                prefix[i][j] += prefix[i][j - 1];
            if (i > 0 && j > 0)
                prefix[i][j] -= prefix[i - 1][j - 1];
        }
    }

    for (int i = 0; i < q; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = prefix[x2 - 1][y2 - 1];
        if (x1 > 1)
        {
            ans -= prefix[x1 - 2][y2 - 1];
        }
        if (y1 > 1)
        {
            ans -= prefix[x2 - 1][y1 - 2];
        }
        if (x1 > 1 && y1 > 1)
        {
            ans += prefix[x1 - 2][y1 - 2];
        }
        cout << ans << endl;
    }
}