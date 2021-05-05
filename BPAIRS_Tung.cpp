#include <bits/stdc++.h>
using namespace std;
int n,d,a[1000000];
long long dem;
long long xuly(int l,int x)
{
    long long kq,mid,r=n;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(a[mid]-x<=d)
        {
            kq=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return kq;
}
int main()
{
    freopen("BPAIRS.inp","r",stdin);
    freopen("BPAIRS.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)
    {
        cout<<a[i]<<"\n";
        dem+=xuly(i,a[i])-i;
    }
    cout<<dem;
}
