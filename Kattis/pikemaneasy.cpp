
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

const int MAXN = 10005;
const int MOD = 1e9+7;

int prob[MAXN];

int main() {
    int n,t; scanf("%d %d",&n,&t);
    int a,b,c; scanf("%d %d %d %d",&a,&b,&c,&prob[0]);

    forsn(i,1,n) prob[i] = ((((ll)a * prob[i-1])%c) + b)%c + 1;

    sort(prob,prob+n);

    int cnt = 0, s = 0, pen = 0;
    forn(i,n) 
        if (s + prob[i] <= t) ++cnt, s += prob[i], pen  = (pen + s)%MOD;

    printf("%d %d",cnt,pen);

    return 0;
}