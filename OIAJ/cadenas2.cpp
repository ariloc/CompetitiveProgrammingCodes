#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define pb push_back
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXA = 20000005;
const int MAXN = 1000005;

bitset<MAXA> done;
int spf[MAXA];

void criba (int N) {
    done[1] = true;
    forn(i,MAXA) spf[i] = i;

    for (int i = 4; i < MAXA; i += 2) {
        done[i] = true;
        spf[i] = 2;
    }

    for (int i = 3; i*i <= MAXA; i += 2) {
        if (!done[i])
            for (int j = i+i; j < MAXA; j += i) {
                done[j] = true;
                if (spf[j] == j) spf[j] = i;
            }
    }
}

vector<int> cadenas(vector<int> &a) {
    criba(MAXA);

    vi rta;
    for (auto &i : a) {
        int v = i, s = 1; // +1
        while (v > 1) {
            s += v;
            v /= spf[v];
        }
        rta.pb(s);
    }

    return rta;
}
