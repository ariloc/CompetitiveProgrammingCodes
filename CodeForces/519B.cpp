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

const int MAXN = 1e5+4;

vi err;
vi rep1; vi rep2;

int main() {
    FAST_IO;

    int n; cin >> n;

    forn (i,n) {
        int x; cin >> x;
        err.push_back(x);
    }

    forn (i,n-1) {
        int x; cin >> x;
        rep1.push_back(x);
    }

    forn (i,n-2) {
        int x; cin >> x;
        rep2.push_back(x);
    }

    sort(all(err)); sort(all(rep1)); sort(all(rep2));
    int prim = -1, dos = -1;
    forn (i,rep1.size()) {
        if (prim == -1 and err[i] != rep1[i]) prim = err[i];
        if (dos == -1 and i < rep2.size() and rep1[i] != rep2[i]) dos = rep1[i];
    }
    if (prim == -1) prim = err.back();
    if (dos == -1) dos = rep1.back();

    cout << prim << '\n' << dos;

    return 0;
}