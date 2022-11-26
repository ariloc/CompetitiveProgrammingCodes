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

const int INF = 1e9;
const int MAXN = 2e5+5;

int mad(vector<int> &x) {
    int n = (int)x.size();

    sort(all(x));

    int w = (n+1)/2;
    int mad = 2*INF+2, t = -1;
    forn(i,n-w+1) {
        int mid = x[i] + x[i+w-1];
        int m_mad, m_t = mid/2;

        if (mid&1) m_mad = max(abs(x[i+w-1] - mid/2), abs(x[i] - mid/2));
        else m_mad = abs(mid/2 - x[i]);

        if (m_mad < mad) mad = m_mad, t = m_t;
    }

    return t;
}
