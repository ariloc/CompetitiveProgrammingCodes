// https://ibero1.contest.codeforces.com/group/BXJ6xt3tnH/contest/359568/problem/F
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
typedef long double ld;

const int MAXN = 1e5+5;
const int MAXH = 1e9;

int tablones[MAXN];

bool check (int h, int k, int n) {
    map<int,ll> cnt;
    forn(i,n) {
        cnt[h] += tablones[i]/h;
        int rest = tablones[i]%h;
        if (rest) cnt[rest]++;
    }
    return (cnt[h] >= k);
}

int main() {
    int n,k; scanf("%d %d",&n,&k);
    forn(i,n) scanf("%d",&tablones[i]);

    int low = 0, high = 0;
    forn(i,n) high = max(high,tablones[i]);

    while (high-low > 1) {
        int mid = (high+low)/2;
        if (check(mid,k,n)) low = mid;
        else high = mid;
    }
    if (check(high,k,n)) low = high;

    printf("%d",low);
    
    return 0;
}