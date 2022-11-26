#include <bits/stdc++.h>
 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
 
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int INF = 2e9;

vector<int> robosort(vector<int> &muestras) {
    int n = (int)muestras.size();
    vi rta;

    forn(k,n) {
        int mini = INF, pos = -1;
        forsn(i,k,n)
            if (muestras[i] < mini) mini = muestras[i], pos = i;

        rta.pb(pos+1);
        reverse(muestras.begin()+k, muestras.begin()+pos+1);
    }

    return rta;
}
