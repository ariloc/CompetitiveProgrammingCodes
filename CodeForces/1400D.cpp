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

const int MAXN = 3005;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;

    forn(i,t) {
        int n; cin >> n;
        forn(j,n) cin >> arr[j];
        ll cnt = 0;
        map<int,int> l;
        forn(j,n) {
            ll myCnt = 0;
            forsn(k,j+1,n) {
                if (arr[k] == arr[j]) cnt += myCnt;
                myCnt += l[arr[k]]; // no me importa crear nuevos elementos, meh
            }
            l[arr[j]]++;
        }

        cout << cnt << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
