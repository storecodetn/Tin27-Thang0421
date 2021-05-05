#include <bits/stdc++.h>
using namespace std;
const string namefile = "BFIBO";
FILE *fi = freopen((namefile + ".inp").c_str(), "r", stdin);
FILE *fo = freopen((namefile + ".out").c_str(), "w", stdout);
const int maxn = 1e3+10;
int t;
struct bignum{
    int sign;
    string value;
};
bignum fibo[maxn];
string addbignum(bignum a, bignum b)
{
  int sum, carry, x, y;
  string c;
  carry = 0; c="";
  while (a.value.size()<b.value.size()) a.value =  '0' + a.value;
  while (b.value.size()<a.value.size()) b.value = '0' + b.value;
  for (int i=a.value.size() - 1; i>=0; --i)
  {
    x = a.value[i] - '0';
    y = b.value[i] - '0';
    sum = x + y + carry;
    carry = sum/10;
    c = char(sum % 10 + 48) + c;
  }
  if (carry > 0) c = '1' + c;
    return c;
}

int main()
{
  fibo[1].value = '1';
  fibo[2].value = '1';
  for (int i=3; i<=1000; ++i)
  {
    fibo[i].value = addbignum(fibo[i-1], fibo[i-2]);
  }
  while (cin>>t)
  {
    cout<<fibo[t].value<<"\n";
  }
  return 0;
}