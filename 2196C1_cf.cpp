#include <bits/stdc++.h>
using namespace std;
#define pp pair<int, int>

void solve()
{
    int n;
    cin >> n;
    set<pp> vis;
    int i = 1;
    while (true)
    {
        cout << "?" << " " << i << endl;
        cout.flush();

        int s;
        cin >> s;
        vector<int> path(s);
        for (int j = 0; j < s; j++)
        {
            cin >> path[j];
        }

        for (int j = 1; j < s; j++)
        {
            vis.insert({path[j - 1], path[j]});
        }

        if ((s == 1 && path[0] == n)|| s==0)
        {
            break;
        }
        i++;
    }

    vector<pp> res(vis.begin(), vis.end());
    int m = res.size();

    cout << "! " << m << endl;
    for (int i = 0; i < m; i++)
    {
        cout << res[i].first << " " << res[i].second << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "new" << endl;
    }
    return 0;
}