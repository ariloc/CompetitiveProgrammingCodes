#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

int const MAXN = 105;

int arr[MAXN];

int main(){
    FAST_IO;

    int n; cin >> n;

    forn(i,n) cin >> arr[i];

    bool fin = true;
    int s = 0;
    int prv = arr[n-1];
    dforn(i,n-1) {
        int x = arr[i];

        int a = prv, b = x;
        if (a > b) swap(a,b);
        
        if (a == 2 && b == 3) fin = false;
        if (a == 1 && b == 3) s += 4;
        if (a == 1 && b == 2) s += 3;

        if (i+2 < n) {
            if (arr[i+2] == 2 && prv == 1 && x == 3)
                s--;
        }

        prv = x;
    }

    if (fin) {
        cout << "Finite\n";
        cout << s << '\n';
    }
    else {
        cout << "Infinite\n";
    }

    return 0;
}
