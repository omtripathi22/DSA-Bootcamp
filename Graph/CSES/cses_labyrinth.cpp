#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

string calculatePath(vector<vector<pair<int, int>>> &parent, int row, int col)
{
    string path = "";
     while (parent[row][col] != make_pair(-1, -1))
    {
        auto p = parent[row][col];
        int pr = p.first;
        int pc = p.second;

        if (pr == row - 1 && pc == col) path.push_back('D');
        else if (pr == row + 1 && pc == col) path.push_back('U');
        else if (pr == row && pc == col - 1) path.push_back('R');
        else if (pr == row && pc == col + 1) path.push_back('L');

        row = pr;
        col = pc;
    }

    reverse(path.begin(), path.end());
    //cout << path << endl;
    return path;
}

// void print(vector<vector<pair<int, int>>> &parent)
// {
//     {
//         for(int i=0;i<parent.size();i++){
//             for(int j=0;j<parent[0].size();j++){
//                 cout << parent[i][j].first <<"," << parent[i][j].second <<"  ";
//             }
//             cout << endl;
//         }
//     }
// }

string bfs(vector<vector<char>> &grid, int &m, int &n, int row, int col)
{
    vector<vector<bool>> vis(m, vector<bool>(n, 0));
    queue<pair<int, int>> q;
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<pair<int, int>>> parent(m, vector<pair<int, int>>(n));
    string path = "";

    vis[row][col] = true;
    q.push({row, col});
    bool found = false;
    // int len=0;
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
                    continue;
                }
                if (grid[newRow][newCol] == '.' && !vis[newRow][newCol])
                {
                    q.push({newRow, newCol});
                    parent[newRow][newCol] = {i, j};
                    vis[newRow][newCol] = true;
                }
                if (grid[newRow][newCol] == 'B')
                {
                    // len++;
                    // return len;
                    parent[newRow][newCol] = {i, j};
                    parent[row][col]={-1,-1};
                    path = calculatePath(parent, newRow, newCol);
                    //print(parent);
                    found = true;
                    break;
                }
            }
            if (found)
            {
                break;
            }
        }
        if (found)
        {
            break;
        }
        // len++;
    }
    return path;
}

int main()
{
    int n, m;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    // vector<vector<bool>> vis(m, vector<bool>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    // cout << "hii";
    string str = "";
    bool found = false;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 'A')
            {
                str = bfs(grid, m, n, i, j);
                // cout << len;
                found = true;
                break;
            }
        }
        if (found)
        {
            break;
        }
    }

    //cout << "answer" << endl;
    if (str.length() == 0)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES" << endl;
        cout << str.size() << endl;
        cout << str;
    }
    return 0;
}

// test case
//  5 8
//  # # # # # # # #
//  # . A # . . . #
//  # . # # . # B #
//  # . . . . . . #
//  # # # # # # # #

// 10 10
// ...#..A.#.
// ....B...##
// ...#......
// ..........
// ...#.#....
// ..##..#...
// .......#..
// #.......#.
// ...#....#.
// #......#..
