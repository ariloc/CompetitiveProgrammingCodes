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

const int MAXN = 4e5+5;

pair<int,bool> arr[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;

    forn(i,n) {
        int l,r; cin >> l >> r;
        arr[2*i] = {l,1}; arr[2*i+1] = {r,0};
    }

    sort(arr,arr+n+n);

    int cust = 0, maxi = 0;
    forn (i,2*n) {
        if (arr[i].snd) cust++;
        else cust--;
        maxi = max(maxi,cust);
    }

    cout << maxi;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
