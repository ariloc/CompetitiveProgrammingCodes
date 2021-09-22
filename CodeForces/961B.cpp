#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1e5+2;

int them[MAXN];
bool awake[MAXN];

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;
    forn (i,n) cin >> them[i];
    forn (i,n) cin >> awake[i];
    int rta = 0;
    forn (i,n) if (awake[i]) rta += them[i];

    int j = 0, sum = 0, maxi = -1;
    forn (i,n) {
        while (j < n and (j-i) < k)
            {if (!awake[j]) sum += them[j]; j++;}

        if (sum > maxi) maxi = sum;
        if (!awake[i]) sum -= them[i];
    }

    cout << rta+maxi;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!