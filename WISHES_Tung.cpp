#include <bits/stdc++.h>
using namespace std;
stack<int> p;
const int nmax=1e5+10;
int n,m,num[nmax],low[nmax],dem,desk[nmax],ans,hs;
bool del[nmax],f[nmax],bo[nmax];
vector<int> a[nmax];
void dfs(int u)
{
    dem++;
    num[u]=dem;
    low[u]=nmax;
    p.push(u);
    for(auto v:a[u])
    if(!del[v])
        if(num[v]==0)
    {
        dfs(v);
        low[u]=min(low[u],low[v]);
    }
    else
        low[u]=min(low[u],num[v]);
    if(low[u]>=num[u])
        {
            hs++;
            while(p.top()!=u)
    {
        del[p.top()]=true;
        desk[p.top()]=hs;
        p.pop();
    }
        del[p.top()]=true;
        desk[p.top()]=hs;
        p.pop();
        ans++;
        }

}
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    f[u]=true;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(auto v:a[x])
            if(!f[v])
        {
            f[v]=true;
            q.push(v);
            if(!bo[desk[v]] && desk[x]!=desk[v])
            {
                bo[desk[v]]=true;
                ans--;
            }
        }
        else
            if(!bo[desk[v]] && desk[x]!=desk[v])
        {
            ans--;
            bo[desk[v]]=true;
        }
    }
}
int main()
{
    freopen("WISHES.inp","r",stdin);
    freopen("WISHES.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        if(num[i]==0)
            dfs(i);
    for(int i=1;i<=n;i++)
        if(!f[i])
            bfs(i);
    cout<<ans;
}
