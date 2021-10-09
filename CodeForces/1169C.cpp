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

const int MAXN = 3e5+5;
const int INF = 1e9+5;

int arr[MAXN], aux[MAXN];

bool isPosib (int mid, int n, int m) {
    forn(i,n) aux[i] = arr[i];
    if ((m-aux[0]) <= mid) aux[0] = 0;

    forsn(i,1,n) {
        if (aux[i] < aux[i-1]) {
            if ((aux[i-1] - aux[i]) > mid) return false;
            else aux[i] = aux[i-1];
        }
        if (aux[i] > aux[i-1] && (m-aux[i]+aux[i-1]) <= mid)
            aux[i] = aux[i-1];
    }

    return true;
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) cin >> arr[i];

    int low = 0, high = m-1;
    while (high - low > 1) {
        int mid = (high + low)/2;

        if (isPosib(mid,n,m)) high = mid;
        else low = mid; 
    }

    if (!isPosib(low,n,m)) low = high;

    cout << low;

    return 0;
}