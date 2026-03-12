#include <bits/stdc++.h>
using namespace std;

int find(int num, vector<int> &par, vector<int> &size)
{
    int curr_par = par[num];
    return par[num] = (curr_par == num) ? num : find(curr_par, par, size);
}

void Union(int x, int y, vector<int> &par, vector<int> &size, vector<vector<int>> &temp)
{
    int a = find(x, par, size);
    int b = find(y, par, size);

    if (a == b)
    {
        temp.push_back(vector<int>{ x, y});
        return;
    }

    if (size[a] > size[b])
    {
        par[b] = a;
        size[a] += size[b];
    }
    else
    {
        par[a] = b;
        size[b] += size[a];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> par(n + 1), size(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }

    vector<vector<int>> temp;
    for (int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v, par, size, temp);
    }

    if (temp.size() == 0)
    {
        cout << 0;
        return 0;
    }

    cout << temp.size() << endl;
    set<int>comp;

    for (int i = 1; i <= n; i++)
    {
        comp.insert(find(i, par, size));
    }

    vector<int>arr(comp.begin(),comp.end());
    int j=0;
    for(int i=1;i<arr.size();i++){
        cout << temp[j][0] <<" "<< temp[j][1] <<" "<< arr[0] <<" "<< arr[i] << endl;
        j++;
    }
}