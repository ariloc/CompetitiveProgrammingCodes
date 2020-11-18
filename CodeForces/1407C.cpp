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

const int MAXN = 10002;

int arr[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    if (n == 1) {cout << "! 1" << endl; return 0;}
    int l = 0, a, b;
    forsn(i,1,n) {
        cout << "? " << l+1 << ' ' << i+1 << endl;
        int a,b; cin >> a;
        cout << "? " << i+1 << ' ' << l+1 << endl;
        cin >> b;
        if (a > b) {arr[l] = a; l = i;}
        else arr[i] = b;
    }
    arr[l] = n;

    cout << "! "; forn(i,n) cout << arr[i] << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
