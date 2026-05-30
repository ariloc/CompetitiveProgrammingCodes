#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

pair<char,int> const MAPFIG[] = {{'r',16},{'b',8},{'n',4},{'c',2},{'s',1}};

int const MAXN = 2505;
int const COMPAS = 16;
int const MAXS = MAXN*COMPAS;
int const MAXM = 2*MAXS;
int const MAXA = 26;

unsigned short dp[MAXM][MAXN];
int mapval[MAXA];

string conciertos(string &figuras) {
    int m = (int)figuras.size();

    for (auto p : MAPFIG) mapval[p.fst-'a'] = p.snd;
    
    vi vals;
    forn(i,m) {
        if (figuras[i] == '*') {
            int x = vals.back();
            vals.pop_back();
            vals.pb(x+x/2);
        }
        else vals.pb(mapval[figuras[i]-'a']);
    }

    m = (int)vals.size();

    dp[0][0] = 1;
    int acc = 0;
    forsn(i,1,m+1) {
        int figval = vals[i-1];

        int limit = acc/COMPAS;
        int calc = acc%COMPAS;
        forn(j,min(limit+1,MAXN)) {
            int mk1 = dp[i-1][j];
            int r = mk1 << figval;

            int mk2 = mk1 & ((1<<(calc+1))-1);
            if (calc-COMPAS+figval >= 0)
                mk2 &= -1 & ~((1<<(calc-COMPAS+figval)) - 1);

            int mk3 = 0;
            if (acc - j*COMPAS >= COMPAS)
                mk3 = mk1 & (-1 & ~((1<<(calc+figval))-1));

            int f = r | mk2 | mk3;
            dp[i][j] |= f & ((1<<COMPAS) - 1);
            if (j < MAXN-1 && f & (1<<COMPAS))
                dp[i][j+1] |= 1;
        }
        
        acc += figval;
    }

    string ret = string(m,'1');
    int curcomp = acc/COMPAS/2, r = 0;
    int curacc = acc;
    dforsn(i,1,m+1) {
        int figval = vals[i-1];
        int ots = curacc - curcomp*COMPAS - r;
        if (!r) {
            if ((figval <= ots%COMPAS || (!(ots%COMPAS) && ots)) && dp[i-1][curcomp] & (1<<r)) 
                ret[i-1] = '2';
            else {
                ret[i-1] = '1';
                r = COMPAS - figval;
                --curcomp;
            }
        }
        else {
            if ((figval <= ots%COMPAS || (!(ots%COMPAS) && ots)) && dp[i-1][curcomp] & (1<<r))
                ret[i-1] = '2';
            else {
                ret[i-1] = '1';
                r -= figval;
            }
        }
        curacc -= figval;
    }

    return ret;
}
