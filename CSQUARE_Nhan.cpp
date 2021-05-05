#include <bits/stdc++.h>
using namespace std;
FILE *fi = freopen("CSQUARE.inp", "r", stdin);
FILE *fo = freopen("CSQUARE.out", "w", stdout);
struct hcn
{
  int w, h;
};
hcn a[4];
int d[111], Sum = 0;
bool oke = 0;
bool check()
{
  if (a[1].h+a[2].h == a[3].h)
  
  {
    if (a[1].w == a[2].w)
    {
      if (a[1].w + a[3].w == a[3].h)
        return true;
    }
  }
  if ( a[1].h + a[3].h == a[2].h)
  {
    if (a[1].w == a[3].w)
    {
      if (a[1].w + a[2].w == a[2].h)
        return true;
    }
  }
   if (a[3].h + a[2].h == a[1].h)
   {
    if (a[3].w == a[2].w)
    {
      if (a[3].w + a[1].w == a[1].h)
        return true;
    }
   }
  return false;
}
void Try(int i)
{
  if (oke == 1) return;
  for (int j=0; j<=1; ++j)
  {
    if (j == 1) swap(a[i].w, a[i].h);
    if (i == 3)
    {
      if (check())
      {
        oke =1;
        return ;
      }
    }
    else {
      Try(i+1);
    }
  }
}
bool th1()
{
  int i=1;
  if (count(d+1, d+100+1, 3) == 1)
  {
    for (; i<=100; ++i)
    {
      if (d[i] == 3)
      {
        break;
      }
    }
  }
  if (Sum - i*3 == i) return true;
  return false;

}
int main()
{
  for (int i=1; i<=3; ++i)
  {
    cin>>a[i].h>>a[i].w;
    d[a[i].w] ++;
    d[a[i].h]++;
    Sum += a[i].h + a[i].w;
  }
  if (th1())
  {
    cout<<"YES";
  }
  else {
  Try(1);
  if (oke == 1) cout<<"YES";
  else cout<<"NO";
  }
  
  return 0;
}