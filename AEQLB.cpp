#include <bits/stdc++.h>
using namespace std;
int main() {
    int ntest;
    cin >> ntest;
    while (ntest--) {
        long long a, b;
        cin >> a >> b;
        if ((b >= a  && (b - a) % 2 == 0) || ((b >= a * 2 && (b - a * 2) % 2 == 0)))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
