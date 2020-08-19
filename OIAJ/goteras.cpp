#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

long long medir(long long x);
vector<ll> rta;
set<ll> touched;
int myN;

void split(ll l, ll r) {
    if (!myN) return;
    ll mid = (l+r)/2;
    ll myMedir = medir(mid);

    if (!medir(mid+myMedir)) {
        if (touched.count(mid+myMedir)) return;
        rta.pb(mid+myMedir); myN--;
        touched.insert(mid+myMedir);
        split(mid+myMedir,r);
        split(l,mid+myMedir);
    } else {
        if (touched.count(mid-myMedir)) return;
        rta.pb(mid-myMedir); myN--;
        touched.insert(mid-myMedir);
        split(mid-myMedir,r);
        split(l,mid-myMedir);
    }
}

vector<long long> goteras(int N, long long L)
{
    ll prim = medir(1)+1; rta.pb(prim); touched.insert(prim);
    N--;

    if (!N) return rta;
    ll sec = L-medir(L); rta.pb(sec); N--; touched.insert(sec);
    if (!N) return rta;

    myN = N;

    split(prim,sec);

    /*while (N) {
        ll low = prim;
        ll high = L;

        bool lastop = false; pair<ll,ll> lastM = {-1,-1};
        while(high-low > 1) {
            ll mid = (high+low)/2;
            swap(lastM.snd,lastM.fst);
            lastM.fst = medir(mid);
            if (lastM.fst != mid-prim)
                {high = mid; lastop = true;}
            else {low = mid; lastop = false;}
        }
        if (lastop) prim = high+lastM.fst;
        else prim = high+lastM.snd;
        rta.pb(prim); N--;
    }*/

    //split(prim,L+1);
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
    int cnt = 0;

    long long MAXIMO_X_PERMITIDO;

    long long medir(long long x) {
        cnt++;
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

        cout << "QUERIES:" << ' ' << cnt << endl;
        return 0;
    }
#endif
