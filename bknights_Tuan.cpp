#include <bits/stdc++.h>
using namespace std;

int n,t;
long long m;
int main()
{
    freopen("bknights.inp","r",stdin);
    freopen("bknights.out","w",stdout);
    cin>>t>>n;
    m=pow(2,n-1);
    while (t--)
    {
        long long a,b;
        cin>>a>>b;
        if (a>b) swap(a,b);
        if (a<=m && b>m)cout<<"yes\n";
            else cout<<"no\n";
    }
    return 0;
}
