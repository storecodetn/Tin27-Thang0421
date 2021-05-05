#include <bits/stdc++.h>
using namespace std;
const int nmax=6*1e5;
const int mod=1e9+7;
vector<tuple<int,int,int> > e;
int n,m,p[nmax],sum,t,val,dem[10000000],tg;
long long sl=1;
vector<pair<int,int> > a[nmax];
bool f[nmax],dd[nmax],vi[nmax],ok;
int root(int u)
{
    while(p[u]!=0)
        u=p[u];
    return u;
}
void krus()
{
    for(int i=0;i<m;i++)
    {
        int ru=root(get<1>(e[i]));
        int rv=root(get<2>(e[i]));
        if(ru!=rv)
        {
            p[rv]=ru;
            sum+=get<0>(e[i]);
            f[get<0>(e[i])]=true;
            a[get<1>(e[i])].push_back({get<2>(e[i]),get<0>(e[i])});
            a[get<2>(e[i])].push_back({get<1>(e[i]),get<0>(e[i])});
            dd[i]=true;
            dem[get<0>(e[i])]=1;
        }
    }
}
void dfs(int u)
{
    vi[u]=true;
    if(u==t)
        {
            ok=true;
            dem[val]+=tg;
        }
    for(auto v:a[u])
    {
        if(!vi[v.first] && !ok)
        {
            if(v.second==val)
                tg++;
            dfs(v.first);
            if(v.second==val)
                tg--;
        }

    }
    vi[u]=false;
}
void xuly()
{
    for(int i=0;i<m;i++)
    {
        if(!dd[i] && f[get<0>(e[i])])
            {
                t=get<2>(e[i]);
                val=get<0>(e[i]);
                tg=0;
                ok=false;
                dfs(get<1>(e[i]));
            }
    }
}
int main()
{
    freopen("DSIMPLIFY.INP","r",stdin);
    freopen("DSIMPLIFY.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        e.push_back(make_tuple(w,u,v));
    }
    sort(e.begin(),e.end());
    krus();
    xuly();
    for(int i=1;i<=1000000;i++)
        if(dem[i]>=1)
            sl=(sl*dem[i])%mod;
    cout<<sum<<" "<<sl;
}
