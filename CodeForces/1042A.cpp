#include <bits/stdc++.h>

#define forn(i,n) for(ll i = 0; i < ll(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

vi fila;

int main() {
    FAST_IO;

    int N,m,maxB = -1,top;
    cin >> N >> m;

    forn (i,N) {
        int a;
        cin >> a;
        maxB = max(maxB,a);
        fila.push_back(a);
    }
    top = maxB + m;

    while (m--) {
        sort(all(fila));
        fila[0]++;
    }
    sort(all(fila));
    cout << fila.back() << ' ' << top;

    return 0;
}