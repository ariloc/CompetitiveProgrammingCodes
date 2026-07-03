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

int const MAXN = 105;
int const INF = 2e9;

int mis[MAXN], cas[MAXN];

vector<int> millas(int N, vector<int> &a, vector<int> &b, vector<int> &d, vector<int> &m) {
    int v = (int)a.size();
    forn(i,N) mis[i] = -1, cas[i] = INF;
    forn(i,v) {
        if (b[i]-a[i] != 1) continue;
        --b[i], --a[i];
        if (m[i] != -1) {
            if (mis[a[i]] != -1) mis[a[i]] = min(mis[a[i]], m[i]);
            else mis[a[i]] = m[i];
        }
        else cas[a[i]] = min(cas[a[i]], d[i]);
    }

    int ca = 0, mi = 0;
    forn(i,N-1) {
        if (mis[i] == -1) ca += cas[i];
        else mi += mis[i];
    }
    return {ca,mi};
}
