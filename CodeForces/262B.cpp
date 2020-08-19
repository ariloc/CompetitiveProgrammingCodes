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

const int MAXN = 1e5+5;
pair<int,bool> arr[MAXN];

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;

    int neg = 0;
    forn (i,n) {
        int x; cin >> x;
        bool sign = true;
        if (x < 0) {sign = false; neg++;}

        arr[i] = {abs(x),sign};
    }

    sort(arr,arr+n);

    ll sum = 0;
    dforn(i,n) {
        if (!arr[i].snd and k > 0) {k--; sum += arr[i].fst;}
        else if (arr[i].snd) {sum += arr[i].fst;}
        else sum -= arr[i].fst;
    }

    if (k){
        if (k & 1) {
            sum -= abs(arr[0].fst);
            sum -= abs(arr[0].fst);
        }
    }

    cout << sum;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!