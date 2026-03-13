#include <bits/stdc++.h>
using namespace std;

string calculatePath(vector<vector<pair<int, int>>> &parent, int row, int col)
{
    string path = "";
    while (parent[row][col] != make_pair(-1, -1))
    {
        auto p = parent[row][col];
        int pr = p.first;
        int pc = p.second;

        if (pr == row - 1 && pc == col)
            path.push_back('D');
        else if (pr == row + 1 && pc == col)
            path.push_back('U');
        else if (pr == row && pc == col - 1)
            path.push_back('R');
        else if (pr == row && pc == col + 1)
            path.push_back('L');

        row = pr;
        col = pc;
    }

    reverse(path.begin(), path.end());
    return path;
}

string reachDestination(vector<vector<char>> &adj, vector<vector<int>> &timeStamp,
                        int row, int col, int &m, int &n)
{
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<bool>> vis(m, vector<bool>(n, 0));
    queue<pair<int, int>> q;
    vector<vector<pair<int, int>>> parent(m, vector<pair<int, int>>(n, {-2, -2}));

    q.push({row, col});
    vis[row][col] = 1;
    parent[row][col] = {-1, -1};

    int currTime = 1;
    string ans = "";
    bool flag = false;

    while (!q.empty())
    {
        int size = q.size();
        for (int k = 0; k < size; k++)
        {
            auto p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;

            for (int d = 0; d < 4; d++)
            {
                int newRow = i + dir[d][0];
                int newCol = j + dir[d][1];

                if (newRow < 0 || newCol < 0 || newRow >= m || newCol >= n)
                {
                    ans = calculatePath(parent, i, j);
                    flag = true;
                    break;
                }

                if (adj[newRow][newCol] != '#' && !vis[newRow][newCol] &&
                    (timeStamp[newRow][newCol] == -1 ||
                     timeStamp[newRow][newCol] > currTime))
                {
                    q.push({newRow, newCol});
                    vis[newRow][newCol] = 1;
                    parent[newRow][newCol] = {i, j};
                }
            }
            if (flag)
                break;
        }
        if (flag)
            break;

        currTime++;
    }
    return ans;
}

vector<vector<int>> calculateMonstersTime(vector<vector<char>> &adj, int &m, int &n)
{
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> monsters;
    vector<vector<bool>> vis(m, vector<bool>(n, 0));
    vector<vector<int>> timeStamp(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == 'M')
            {
                monsters.push({i, j});
                timeStamp[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }

    int time = 1;
    while (!monsters.empty())
    {
        int size = monsters.size();
        for (int i = 0; i < size; i++)
        {
            auto p = monsters.front();
            monsters.pop();
            int row = p.first;
            int col = p.second;

            for (int d = 0; d < 4; d++)
            {
                int newRow = row + dir[d][0];
                int newCol = col + dir[d][1];

                if (newRow < 0 || newCol < 0 || newRow >= m || newCol >= n)
                    continue;

                if (adj[newRow][newCol] != '#' && !vis[newRow][newCol])
                {
                    monsters.push({newRow, newCol});
                    vis[newRow][newCol] = 1;
                    timeStamp[newRow][newCol] = time;
                }
            }
        }
        time++;
    }
    return timeStamp;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> adj(m, vector<char>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    for (int i = 0; i < m; i++)
    {
        if (adj[i][0] == 'A' || adj[i][n - 1] == 'A')
        {
            cout << "YES" << endl;
            cout << 0;
            return 0;
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (adj[0][j] == 'A' || adj[m - 1][j] == 'A')
        {
            cout << "YES" << endl;
            cout << 0;
            return 0;
        }
    }

    vector<vector<int>> timeStamp = calculateMonstersTime(adj, m, n);

    string path = "";
    bool flag = false;
    for (int i = 0; i < m && !flag; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == 'A')
            {
                path = reachDestination(adj, timeStamp, i, j, m, n);
                flag = true;
                break;
            }
        }
    }

    if (path.empty())
        cout << "NO";
    else
    {
        cout << "YES" << endl;
        cout << path.size() << endl;
        cout << path;
    }
    return 0;
}

//Test case
// 8 8
// ###MMMMM
// #.AMMMMM
// #.#MMMMM
// #.#MMMMM
// #.#MMMMM
// #.#MMMMM
// #.#MMMMM
// #.#MMMMM