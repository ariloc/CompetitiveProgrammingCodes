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
const int INF = 2e9;

int arr[MAXN];

int recur (int l, int r, int acc = 0) {
    if (r-l == 1) return arr[l]-acc > 0;
    if (r <= l) return 0;

    int cnt = 0, mini = INF, pos = -1;
    forsn(i,l,r) {
        if (arr[i] < mini) mini = arr[i], pos = i;
        cnt += (arr[i]-acc) > 0;
    }

    return min(recur(l,pos,max(acc,mini)) + recur(pos+1,r,max(acc,mini)) + max(0,mini-acc), cnt);
}

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%d",&arr[i]);

    printf("%d",recur(0,n));

    return 0;
}
