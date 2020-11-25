// https://www.hackerrank.com/contests/simulacro-4-n2-oia-2020/challenges/equipo-de-atletismo-joacru/problem
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

const int MAXN = 1e5+5;

ll longs[MAXN], TAd[MAXN];

vector<long long> atletismo(vector<int> L, vector<int> T)
{
    int N = (int)L.size();
    forn(i,N) TAd[i] = L[i];
    forsn(i,1,N) TAd[i] += TAd[i-1];
    forn(i,(N+1)/2) {
        int r = N-i-1, l = i-1;
        longs[i] = (i-1 >= 0 ? longs[i-1] : 0) + (r >= l ? TAd[N-i-1] - (l >= 0 ? TAd[l] : 0) : 0);
    }
    int cnt = 1;
    forsn(i,(N+1)/2,N) {
        longs[i] = /*longs[i-1] + */longs[i-cnt-(N&1)];
        cnt += 2;
    }

    vector<ll> r;
    for (auto &i : T) {
        r.pb(longs[i-1]);
    }

    return r;
}

int main()
{
    int N, Q;
    cin>>N>>Q;
    vector<int> L(N);
    for(int i = 0; i < N; i++) cin>>L[i];
    vector<int> T(Q);
    for(int i = 0; i < Q; i++) cin>>T[i];
    vector<long long> A = atletismo(L, T);
    for(int i = 0; i < (int)A.size(); i++) cout<<A[i]<<endl;
    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
