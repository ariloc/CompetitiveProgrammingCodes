#include <bits/stdc++.h>

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

const int MAXN = 2e5+2;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;

    forn(i,t) {
        int n; cin >> n;

        vi dpL(n,0), dpR(0,n);
        forn (j,n) cin >> arr[j];

        int last = -1, cent = -1;
        dforn (j,n) {
            if (arr[j] < last) {cent = j+1; break;}
            last = arr[j];
        }

        if (cent == -1) {cout << "0\n"; continue;}

        int ind = -1;
        dforn (j,cent)
            if (arr[j] > arr[j+1]) {ind = j+1; break;}

        if (ind == -1) {cout << "0\n"; continue;}

        cout << ind << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!