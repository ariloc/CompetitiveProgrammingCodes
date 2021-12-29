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

const int MAXN = 1e5+5;

int arr[MAXN];
int steps = 1,n,k;

void mergesort (int l, int r) {
    if (r-l <= 1) return;
    if (steps < k) {
        steps += 2;
        int mid = (l+r)/2;
        for (int i = l, j = mid; i < mid && j < r; i++, j++)
            swap(arr[i],arr[j]);
        mergesort(l,mid);
        mergesort(mid,r);
    }
}

int main() {
    scanf("%d %d",&n,&k);
    forn(i,n) arr[i] = i+1;

    mergesort(0,n);

    if (steps != k) printf("-1");
    else forn(i,n) printf("%d ",arr[i]);

    return 0;
}