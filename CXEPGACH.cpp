#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100009];
long long c,d;
long long Res;
int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c >> d;
        a[i] = c - d;
        Res += d * (n - 1);
    }
    sort(a,a + n,greater<long long>());
    for (int i = 0; i < n; i++) Res += a[i] * i;
    cout << Res;
}
