#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 50;
const int dy[] = {0, 1, 1, 0, -1, -1};
int dx[2][6] = {-1, 0, 1, 1, 1, 0,
                -1, -1, 0, 1, 0, -1};
 
string s[N*5];
int r, c, S, T;
 
int head[N * N], etop;
struct Edge
{
    int v, nxt;
}e[6 * N * N];
void add(int u, int v)
{
    //cout<<"add: "<<u<<" "<<v<<endl;
    e[++etop] = Edge{v, head[u]};
    head[u] = etop;
}
 
int id(int x, int y) {return (x - 1) * c + y;}
void build(int i, int j, int idi, int idj)
{
    if (s[i][j] == 'S') S = id(idi, idj);
    if (s[i][j] == 'T') T = id(idi, idj);
    for (int k = 0; k < 6; k++)
    {
        int u = idi + dx[idj & 1][k], v = idj + dy[k];
        if (u <= 0 || u > r || v <= 0 || v > c) continue;
        if (k == 0 && s[i - 2][j] == ' ') add(id(idi, idj), id(u, v));
        if (k == 1 && s[i - 1][j + 3] == ' ') add(id(idi, idj), id(u, v));
        if (k == 2 && s[i + 1][j + 3] == ' ') add(id(idi, idj), id(u, v));
        if (k == 3 && s[i + 2][j] == ' ') add(id(idi, idj), id(u, v));
        if (k == 4 && s[i + 1][j - 3] == ' ') add(id(idi, idj), id(u, v));
        if (k == 5 && s[i - 1][j - 3] == ' ') add(id(idi, idj), id(u, v));
    }
}
 
int vis[N * N], dis[N * N], tim;
int bfs()
{
    vis[S] = ++tim;
    dis[S] = 1;
    queue <int> q;
    q.push(S);
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int v, i = head[u]; i; i = e[i].nxt)
        {
            v = e[i].v;
            if (vis[v] == tim) continue;
            vis[v] = tim;
            dis[v] = dis[u] + 1;
            if (v == T) break;
            q.push(v);
        }
    }
    return vis[T] == tim ? dis[T] : -1;
}
void init()
{
    for (int i = 1; i <= r * c; i++)
        head[i] = 0;
    etop = 0;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin>>T;
    while (T--)
    {
        cin>>r>>c; getline(cin, s[0]);
        init();
        for (int i = 1; i <= 4 * r + 3; i++)
            getline(cin, s[i]);
        for (int idi = 1, i = 3; idi <= r; i += 4, idi++)
            for (int idj = 1, j = 4; idj <= c; j += 12, idj += 2)
                build(i, j, idi, idj);
 
        for (int idi = 1, i = 5; idi <= r; i += 4, idi++)
            for (int idj = 2, j = 10; idj <= c; j += 12, idj += 2)
                build(i, j, idi, idj);
        cout<<bfs()<<endl;
    }
    return 0;
}