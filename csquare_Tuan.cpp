#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
pair<int,int> a[4];
//----------
void nhap()
{
    freopen("csquare.inp","r",stdin);
    freopen("csquare.out","w",stdout);
    for (int i=1;i<=3;i++)
    {
        cin>>a[i].a>>a[i].b;
        if (a[i].a<a[i].b) swap(a[i].a,a[i].b);
    }
}
//----------
bool check()
{
    if (a[1].b+a[2].b+a[3].b==a[3].a && a[1].a==a[2].a && a[2].a==a[3].a)
        return true;
    if (a[1].a==a[2].a && a[1].b+a[2].b==a[3].a && a[1].a+a[3].b==a[3].a)
        return true;
    if (a[1].b==a[2].b && a[1].a+a[2].a==a[3].a && a[1].b+a[3].b==a[3].a)
        return true;
    if (a[1].b==a[2].a && a[1].a+a[2].b==a[3].a && a[1].b+a[3].b==a[3].a)
        return true;
    if (a[2].b==a[1].a && a[2].a+a[1].b==a[3].a && a[2].b+a[3].b==a[3].a)
        return true;
    return false;
}
//------------
void xuly()
{
    sort(a+1,a+4);
    if (check())
        cout<<"YES";
    else cout<<"NO";
}
//-----------
int main()
{
    nhap();
    xuly();
    return 0;
}
