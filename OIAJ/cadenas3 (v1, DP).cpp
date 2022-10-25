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
const int MOD = 1e9+7;

bitset<MAXA> done;
int spf[MAXA];
int dp[MAXA]; // ojo overflow

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

int sumMod (int a, int b) {
    ll aux = a+b;
    if (aux >= MOD) aux -= MOD;
    return aux;
}

int solve (int num) {
    if (num == 1) return 1;
    if (dp[num] != -1) return dp[num];

    int x = num;
    int aux = 0;
    while (x > 1) {
        x /= spf[x];
        aux = max(aux, solve(x));
    }
    return dp[num] = sumMod(aux, num);
}

// ojo caso 1!
vector<int> cadenas(vector<int> &a) {
    criba(MAXA);
    forn(i,MAXA) dp[i] = -1;

    vi rta;
    for (auto &i : a)
        rta.pb(solve(i));

    return rta;
}
