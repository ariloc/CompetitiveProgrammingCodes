#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 305;
int const INF = 1e9;

int minl[MAXN], minr[MAXN];

int tubitos(vector<string> &muestras) {
    int n = sz(muestras);
    forn(i,n) {
        int cnt = 0;
        int idx = i;
        while (muestras[i][idx] == 'N') {
            idx = (idx-1+n)%n;
            ++cnt;
        }
        minl[i] = cnt;
        idx = i;
        cnt = 0;
        while (muestras[i][idx] == 'N') {
            idx = (idx+1)%n;
            ++cnt;
        }
        minr[i] = cnt;
    }
    int rta = INF;
    forn(i,n) forn(j,n) {
        bool ok = true;
        forn(k,n) if (minl[k] > i && minr[k] > j) ok = false;
        if (ok)
            rta = min(rta,min(2*i+j,2*j+i));
    }
    return rta;
}
