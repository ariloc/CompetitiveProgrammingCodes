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

long long medir(long long x);

vector<ll> rta;
int n;

bool valid (ll pos, ll l, ll r) {
    if (pos < l || pos > r)
        return false;
    return pos%2 == 0;
}

void go (ll l, ll r) {
    if (sz(rta) == n) return;
    if (r < l) return;
    if (r == l) {
        if (!medir(l)) rta.pb(l);
        return;
    }
    ll mid = (l+r)/2;

    ll len = r-l+1;
    if (len % 2 == 0) {
        ll div = len / 2;
        if (valid(mid+div,l,r))
            mid = (l+r+1)/2;
    }

    ll val = medir(mid);

    if (!val) {
        rta.pb(mid);
        go(mid+1,r);
        go(l,mid-1);
        return;
    }

    if (!valid(mid+val,l,r) && !valid(mid-val,l,r))
        return;

    bool right = false;
    if (valid(mid+val,l,r) && valid(mid-val,l,r))
        right = !medir(mid+val);

    if (!valid(mid-val,l,r)) right = true;

    if (right) {
        rta.pb(mid+val);
        go(mid+val+1,r);
        go(l,mid-val);
    }
    else {
        rta.pb(mid-val);
        go(mid+val,r);
        go(l,mid-val-1);
    }
}

vector<long long> goteras(int N, long long L) {
    ll l = 1+medir(1);
    if (N == 1) return {l};
    
    ll r = L-medir(L);
    if (N == 2) return {l,r};

    n = N;

    if (l == r) return {l};
    rta.pb(l); rta.pb(r);

    go(l+1,r-1);

    return rta;
}


// ***************** EVALUADOR LOCAL *******************

#ifndef EVAL

    #include <iostream>
    #include <vector>
    #include <set>
    #include <cassert>
    #include <cstdlib>

    using namespace std;

    vector<long long> goteras(int N, long long L);

    set<long long> setDeLasGoteras;

    long long MAXIMO_X_PERMITIDO;

    long long medir(long long x) {
        cout << "medir(" << x << ") = ";
        if (x < 1 || x > MAXIMO_X_PERMITIDO)
        {
            cout << "MEDICION INVALIDA" << endl;
            exit(0);
        }
        long long ret;
        set<long long>::iterator sig = setDeLasGoteras.lower_bound(x);
        if (sig == setDeLasGoteras.end()) {
            assert(sig != setDeLasGoteras.begin());
            --sig;
            assert(x - *sig > 0LL);
            ret = x - *sig;
        }
        else {
            ret = *sig - x;
            assert(ret >= 0LL);
            if (sig != setDeLasGoteras.begin()) {
                --sig;
                long long otra = x - *sig;
                assert(otra > 0LL);
                if (otra < ret)
                    ret = otra;
            }
        }
        cout << ret << endl;
        return ret;
    }

    int main()
    {
        int N;
        cin >> N >> MAXIMO_X_PERMITIDO;
        for (int i=0;i<N;i++) {
            long long x; cin >> x;
            setDeLasGoteras.insert(x);
        }
        bool pri = true;
        for (long long x : goteras(N,MAXIMO_X_PERMITIDO)) {
            if (pri) pri = false;
            else cout << " ";
            cout << x;
        }
        cout << endl;
        return 0;
    }
#endif
