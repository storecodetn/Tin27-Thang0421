#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,q,r[N],ng[N];
int root(int u)
{
    while(r[u]!=u)
    {
        u=r[u];
        r[u]=r[r[u]];
    }
    return u;
}
int main()
{
    freopen("DPARTICLE.inp","r",stdin);
    freopen("DPARTICLE.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        r[i]=i;
    while(q--)
    {
        char a;
        int u,v,ru,rv;
        cin>>a>>u>>v;
        ru=root(u);
        rv=root(v);
        if(a=='R')
        {
            if(ru!=rv)
                {
                    r[rv]=ru;
                    if(ng[rv]!=0 && ng[ru]==0)
                        ng[ru]=ng[rv];
                    if(ng[ru]!=0 && ng[rv]!=0 && ng[ru]!=ng[rv])
                    {
                        int rngv=root(ng[rv]);
                        int rngu=root(ng[ru]);
                        if(rngv!=rngu)
                            r[rngv]=rngu;
                        ng[ru]=rngu;
                    }
                }

        }
        if(a=='A')
        {
            if(ng[ru]==0)
                ng[ru]=rv;
            if(ng[rv]==0)
                ng[rv]=ru;
            int rng=root(ng[ru]);
            if(rng!=rv)
                r[rng]=rv;
            int rngv=root(ng[rv]);
            if(rngv!=ru)
                r[rngv]=ru;
        }
        if(a=='Q')
        {
            if(ru==rv)
                {
                    cout<<"R\n";
                    continue;
                }
            if(root(ng[ru])==rv)
                {
                    cout<<"A\n";
                    continue;
                }
            cout<<"?\n";
        }
    }
}
