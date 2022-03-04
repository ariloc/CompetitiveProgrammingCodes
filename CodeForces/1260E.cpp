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

const int MAXN = (1<<18) + 10;

int arr[MAXN];

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%d",&arr[i]);

    forn(i,n) {
        if (arr[i] == -1) break;
        arr[i] = 0; // los de antes me cuestan 0
    }

    if (arr[n-1] == -1) return printf("0"), 0;

    ll r = arr[n-1];
    multiset<int> bst;
    int tg = n-n/2-1, dv = 4;
    dforn(i,n-1) {
        bst.insert(arr[i]);
        if (i == tg) {
            int aux = (*bst.begin());
            if (aux == -1) break;
            r += (*bst.begin());
            bst.erase(bst.begin());
            tg -= n/dv, dv <<= 1;
        }
    }

    printf("%lld",r);

    return 0;
}