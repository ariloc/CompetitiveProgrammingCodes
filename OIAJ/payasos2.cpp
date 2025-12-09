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
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 2e5+5;
int const MOD = 1e9+7;

bitset<MAXN> done,done2;
int spf[MAXN], decomp[MAXN], curdec[MAXN];

void criba() {
    done[0] = done[1] = true;
    forn(i,MAXN) spf[i] = i;
    for (int i = 4; i < MAXN; i += 2) done[i] = true, spf[i] = 2;
    for (int i = 3; i*i < MAXN; i += 2)
        if (!done[i])
            for (int j = i+i; j < MAXN; j += i)
                if (!done[j])
                    done[j] = true, spf[j] = i;
}

int payasos2(vector<int> &A) {
    int N = (int)A.size();
    criba();

    vi usedf;
    forn(i,N) if (!done2[i]) {
        done2[i] = true;
        int cur = A[i], cnt = 1;
        while (cur != i) {
            done2[cur] = true; 
            ++cnt, cur = A[cur];
        }
        vi used;
        while (cnt > 1) {
            if (!curdec[spf[cnt]]) used.pb(spf[cnt]);
            curdec[spf[cnt]]++;
            cnt /= spf[cnt];
        }
        for (auto &j : used) {
            if (!decomp[j]) usedf.pb(j);
            decomp[j] = max(decomp[j],curdec[j]);
            curdec[j] = 0;
        }
    }
    int ret = 1;
    for (auto &i : usedf)
        forn(j,decomp[i]) ret = (ret*(ll)i)%MOD;
    
    return ret;
}
