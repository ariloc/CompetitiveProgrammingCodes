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

int const MAXN = 2e5+5;
int const MAXQ = 2e5+5;
int const MAXB = 450;

int L[MAXB], R[MAXB];
ll best[MAXB], sum[MAXB];
ll a[MAXN], b[MAXN];
vector<ll> rta;

void update(int pos) {
    pos /= MAXB;
    ll acc = 0, maxi = 0;
    forsn(i,L[pos],R[pos]+1) {
        acc += a[i];
        maxi = max(maxi, b[i]+acc);
    }
    best[pos] = maxi;
    sum[pos] = acc;
}

ll query(int l, int r) {
    int posl = l/MAXB, posr = r/MAXB;
    ll acc = 0, maxi = 0;
    if (posl == posr) {
        forsn(i,l,r+1) acc += a[i], maxi = max(maxi,b[i]+acc);
        return maxi;
    }
    forsn(i,l,R[posl]+1) acc += a[i], maxi = max(maxi,b[i]+acc);
    forsn(i,posl+1,posr) {
        maxi = max(maxi, best[i]+acc);
        acc += sum[i];
    }
    forsn(i,L[posr],r+1) acc += a[i], maxi = max(maxi,b[i]+acc);
    return maxi;
}

vector<long long> pomelos(int N, vector<string> &e, vector<int> &p1, vector<int> &p2) {
    for (int i = 0; i < MAXN; i += MAXB)
        L[i/MAXB] = i, R[i/MAXB] = min(MAXN-1,i+MAXB-1);

    int q = (int)e.size();
    forn(i,q) {
        if (e[i] == "A") {
            a[p1[i]] = p2[i];
            update(p1[i]);
        }
        if (e[i] == "B") {
            b[p1[i]] = p2[i];
            update(p1[i]);
        }
        if (e[i] == "C") {
            rta.pb(query(p1[i],p2[i]));
        }
    }
    return rta;
}
