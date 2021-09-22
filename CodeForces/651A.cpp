#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define fst first
#define snd second

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

bool valido(int &j1, int &j2) {
    if (j1 < 1 or j2 < 1) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int j1,j2,sum=0;
    cin >> j1 >> j2;

    int &carga = j2, &desc = j1;
    if (j1 < j2) swap(carga,desc);

    while (valido(j1,j2)) {
        if (j1 == 1 and j2 == 1) break;
        if (desc <= 2) swap(carga,desc);
        carga++; desc-=2;
        sum++;
    }

    cout << sum;
    return 0;
}