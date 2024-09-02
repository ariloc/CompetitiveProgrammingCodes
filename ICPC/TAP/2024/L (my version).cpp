#include<bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 2e5+5;

int arr[MAXN], sumpot[MAXN], sumodd[MAXN], sumone[MAXN];

bool ispot2(int x) {
    while (x > 1) {
        if (x%2) return false;
        x /= 2;
    }
    return true;
}

int main() {
    FAST_IO;

    int n,q; cin >> n >> q;
    forn(i,n) cin >> arr[i];
    forn(i,n) if (ispot2(arr[i]) && arr[i] != 1) sumpot[i+1] = arr[i];
    forn(i,n) if ((arr[i]&1) && arr[i] != 1) sumodd[i+1] = arr[i];
    forn(i,n) if (arr[i] == 1) sumone[i+1] = arr[i];

    forn(i,n) sumpot[i+1] += sumpot[i];
    forn(i,n) sumodd[i+1] += sumodd[i];
    forn(i,n) sumone[i+1] += sumone[i];

    forn(i,q) {
        int l,r; cin >> l >> r;

        int sone = sumone[r] - sumone[l-1];
        int sa = sumpot[r] - sumpot[l-1] + (sone+1)/2;
        int sb = sumodd[r] - sumodd[l-1] + (sone/2);

        if (sa > sb) cout << 'A';
        else if (sa < sb) cout << 'B';
        else cout << 'E';
        cout << '\n';
    }

    return 0;
}
