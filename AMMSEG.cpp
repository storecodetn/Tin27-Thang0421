#include <bits/stdc++.h>
#define Task "MMSEG"
using namespace std;

const int inf = INT_MAX;
int n, x;
vector<int> a;
int main()
{
    freopen(Task".inp","r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n;
    a.reserve(n);
    for (int i = 0; i < n; i += 1)
    {
       cin >> x;
        a.push_back(x);
    }

    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());

    int imin = 1, imax = n + 1;
    int res = inf;

    for (int i = 0; i < int(a.size()); i++)
    {
        if (a[i] == mn) imin = i;

        if (a[i] == mx) imax = i;

        res = min(res, abs(imin - imax) + 1);
    }

    cout << res;
}
