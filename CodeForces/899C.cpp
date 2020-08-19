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

const ll INF = 9e18;

int main() {
    FAST_IO;

    ll N; cin >> N;

    ll tot = (N*(N+1))/2;
    ll half = tot/2;

    int r = 1; ll sum = 0;
    ll dif = INF; ii best;
    forsn (i,1,N+1) {
        while (r <= N and sum <= (tot/2)) {
            if (abs((tot-sum)-sum) < dif) {dif = abs((tot-sum)-sum); best = {i,r};}
            sum += r; r++;
        }
        sum -= i;
    }

    cout << dif << '\n';
    cout << best.snd-best.fst << ' ';
    forsn(i,best.fst,best.snd) cout << i << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!