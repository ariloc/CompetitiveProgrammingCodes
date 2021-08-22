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

const ll LIMIT = (1.5e6)*(1.5e6);
const int MAXN = 1e5+2;

ll hipot (pair<ll,ll> &p) {
    return ((p.fst*p.fst)+(p.snd*p.snd));
}

pair<pair<ll,ll>,int> vec[MAXN];
int rta[MAXN];

int main() {
    FAST_IO;

    int N; cin >> N;

    forn (i,N) {cin >> vec[i].fst.fst >> vec[i].fst.snd; vec[i].snd = i;}

    pair<ll,ll> pos = {0,0};
    do {
        pos = {0,0};
        random_shuffle(vec,vec+N);
        forn (i,N) {
            ll x = vec[i].fst.fst, y = vec[i].fst.snd;
            pair<ll,ll> posf1 = {pos.fst+x, pos.snd+y}, posf2 = {pos.fst-x, pos.snd-y};
            //cerr << posf1.fst << ' ' << posf1.snd << ' ' << posf2.fst << ' ' << posf2.snd << endl;

            ll a = hipot(posf1), b = hipot(posf2);
            //cerr << a << ' ' << b << endl;
            if (a < b) {pos.fst = posf1.fst; pos.snd = posf1.snd; rta[vec[i].snd] = 1;}
            else {pos.fst = posf2.fst; pos.snd = posf2.snd; rta[vec[i].snd] = -1;}
        }
        //cerr << hipot(pos) << ' ' << pos.fst << ' ' << pos.snd << ' ' << LIMIT << endl;
    } while (hipot(pos) > LIMIT);

    forn (i,N) cout << rta[i] << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
// test 2