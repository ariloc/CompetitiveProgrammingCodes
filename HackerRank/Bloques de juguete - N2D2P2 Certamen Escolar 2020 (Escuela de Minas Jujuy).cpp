// https://www.hackerrank.com/contests/simulacro-4-n2-oia-2020/challenges/bloques-de-juguete-joacru
#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int MOD = 1e9+7;
const int MAXN = 1e6+5;

int factorial[MAXN];

void triggerFact() {
    ll r = 1;
    forsn(i,1,MAXN) {
        r = (r*(ll)i)%MOD;
        factorial[i] = r;
    }
}

int bloques(vector<int> A)
{
    triggerFact();
    map<int,int> h;
    for (auto &i : A)
        h[i]++;
    ll ways = 1;
    for (auto &i : h)
        ways = (ways*factorial[i.snd])%MOD;
    return ways;
}

int main()
{
    int N;
    cin>>N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin>>A[i];
    cout<<bloques(A)<<endl;
    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!

