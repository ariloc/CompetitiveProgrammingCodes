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
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 5005;
const ll NEG = -1;

struct stackMax {
    vector< pair<ll,ll> > stck;

    ll maxi() {return (stck.empty() ? NEG : stck.back().snd);}
    pair<ll,ll> top() {return stck.back();}
    void push(ll x) {stck.pb({x, max(x, this->maxi())});}
    void pop() {if (!stck.empty()) stck.pop_back();}
    void clear() {stck.clear();}
    bool empty() {return stck.empty();};
    int size() {return (int)stck.size();}
};

struct queueMax {
    stackMax s1,s2;

    ll maxi() {return max( s1.maxi(), s2.maxi() );}
    void pop() {
        if (s2.empty()) while (!s1.empty()) 
            s2.push(s1.top().fst), s1.pop();
        s2.pop();
    }
    void push(ll x) {s1.push(x);}
    int size() {return (int)s1.size() + (int)s2.size();}
    void clear() {s1.clear(), s2.clear();}
};

int arr[MAXN];
ll dp[2][MAXN];

int main() {
    FAST_IO;

    int n,k,x; cin >> n >> k >> x;

    forn(i,n) cin >> arr[i+1];

    if (n/k > x) return cout << -1, 0;

    // build -> nada porque ya es todo 0
    forn(i,MAXN) dp[0][i] = dp[1][i] = -1; // init
    forn(i,k) dp[0][i] = 0; // puntos de partida

    queueMax Q;
    forsn(j,1,x+1) {
        Q.clear();
        forsn(i,1,n+1) {
            ll actVal = dp[1^(j&1)][i-1]; dp[1^(j&1)][i-1] = -1; // reset mientras de lo que ya no uso
            Q.push(actVal >= 0 ? actVal + arr[i] : -1);
            if (Q.size() > k) Q.pop();
            dp[j&1][i] = max(dp[j&1][i],Q.maxi()); // el max para evitar irme por el borde
        }
    }

    cout << dp[x&1][n];

    return 0;
}