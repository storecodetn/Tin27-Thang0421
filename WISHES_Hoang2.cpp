#include <bits/stdc++.h>

using namespace std;
FILE *fi = freopen("WISHES.inp", "r", stdin);
FILE *fo = freopen("WISHES.out", "w", stdout);
const int nxm = 1e5 + 10;
vector <int> g[nxm];
pair <int, int> d[nxm];
bool f[nxm];
int n, m;
void nhap()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        d[i].second = i;//luu thu tu dinh i, vi chut se sap xep
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        d[v].first++;//so luong cha truc tiep cua v
    }
}
void dfs(int u)
{
    f[u] = 1;
    for(auto v:g[u])
        if(!f[v])
            dfs(v);
}
int main()
{
    int res = 0;
    nhap();
    sort(d + 1, d + n + 1);//sap xep tang theo so luong cha truc tiep
    for(int i = 1; i <= n; i++)
        if(!f[d[i].second])
        {
            res++;
            dfs(d[i].second);
        }
    cout << res;
    return 0;
}
