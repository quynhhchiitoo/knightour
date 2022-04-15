#include <iostream>
using namespace std;

void knight(int **cell, int cnt, int n, int i, int j, bool **vis, int p[], int q[]);
int main()
{
    int **cell;
    int N;
    cin >> N;
    cell = new int *[N];
    for (int i = 0; i < N; i++)
    {
        cell[i] = new int[N];
        for (int j = i; j < N; j++)
            cell[i][j] = 0;
    }
    bool **vis;
    vis = new bool *[N];
    for (int i = 0; i < N; i++)
    {
        vis[i] = new bool[N];
        for (int j = i; j < N; j++)
            vis[i][j] = false;
    }
    int p[] = {2, 2, 1, -1, -2, -2, -1, 1};
    int q[] = {1, -1, -2, -2, -1, 1, 2, 2};
    knight(cell, 0, N, 0, 0, vis, p, q);
}
void knight(int **cell, int cnt, int n, int i, int j, bool **vis, int p[], int q[])
{
    if (i < 0 || j < 0 || i >= n || j >= n)
        return;
    if (vis[i][j] == false)
    {
        vis[i][j] = true;
        cnt += 1;
        cell[i][j] = cnt;
        if (cnt == n * n)
        {
            for (int a = 0; a < n; a++)
            {
                for (int b = 0; b < n; b++)
                {
                    cout << cell[a][b] << " ";
                }
                cout << endl;
            }
            exit(0);
        }
    }
    else
        return;
    for (int l = 0; l < 8; l++)
    {
        knight(cell, cnt, n, i + p[l], j + q[l], vis, p, q);
    }
    vis[i][j] = false;
}