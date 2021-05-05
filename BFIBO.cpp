#include <bits/stdc++.h>
#define task "FIBO"
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define el '\n'
using namespace std;

string ssum(string a,string b)
{
    string res;
    while(a.size()<b.size()) a='0'+a;
    while(b.size()<a.size()) b='0'+b;\
    bool mem=false;
    FORD(i,int(a.size())-1,0)
    {
        int tmp=a[i]+b[i]-96+mem;
        mem=tmp/10;
        res=char( (tmp%10 )+48) + res;
    }
    if(mem) return '1'+res;
    return res;
}

string s[1001];
void init()
{
    s[1]="1";s[2]="1";
    FOR(i,3,1000) s[i]=ssum(s[i-1],s[i-2]);
}

int n;
void input()
{
    while(cin >> n)
    {
      cout << s[n] << el;
    }
}

int main()
{
    #ifndef Shiro
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    #endif // Shiro
    ios::sync_with_stdio(false);cin.tie(NULL);
    init();
    input();
    return 0;
}
