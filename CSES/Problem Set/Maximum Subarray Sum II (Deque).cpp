#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2e5+2;
const ll INF = 2e15;

deque<pair<ll,int>> Q;
ll arr[MAXN];

void fastscan(ll &x) {
    register int c = 0;
    c = getchar(); bool neg = false;
    if (c == '-') {neg = true; c = getchar();}
    for(; c <= '9' && c >= '0'; c=getchar()) x = x*10 + c-'0';
    if (neg) x*=-1;
}

int main() {
    ll n=0,a=0,b=0; fastscan(n); fastscan(a); fastscan(b);
    forn(i,n) fastscan(arr[i+1]);
    forsn(i,1,n+1) arr[i] += arr[i-1];

    ll maxi = -INF;
    forsn(i,a,n+1) {
        while (!Q.empty() and Q.front().snd < i-b) Q.pop_front();
        if (arr[i-a] <= Q.front().fst) {deque<pair<ll,int>> empt; Q.swap(empt);}
        while (!Q.empty() and Q.back().fst >= arr[i-a]) Q.pop_back();
        Q.push_back({arr[i-a],i-a});
        maxi = max(maxi,arr[i]-Q.front().fst);
    }

    printf("%lld",maxi);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
