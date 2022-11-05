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

const int MAXN = 1005;

int arr[MAXN], n;

bool isSorted() {
    forsn(i,1,n) if (arr[i] < arr[i-1]) return false;
    return true;
}

void op (int i) {
    if (arr[i] > arr[i+1]) swap(arr[i], arr[i+1]);
}

void strangeSort (int iter) {
    if (!(iter&1))
        for (int i = 0; i < n-1; i += 2)
            op(i);
    else
        for (int i = 1; i < n-1; i += 2)
            op(i);
}

int main() {
    int t; scanf("%d",&t);

    forn(_,t) {
        scanf("%d",&n);

        forn(i,n) scanf("%d",&arr[i]);

        int iter = 0;
        while (!isSorted()) {
            strangeSort(iter++);
        }

        printf("%d\n",iter);
    }

    return 0;
}
