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

int main() {
    FAST_IO;

    int t; cin >> t;

    forn(i,t) {
        vector<ii> arr;
        forn (j,4) {int x; cin >> x; arr.pb({x,(j%4 < 2)});}
        sort(all(arr));
        int got = -1;
        dforn (j,3)
            if (arr[j].fst == arr[j+1].fst and arr[j].snd != arr[j+1].snd) {got = arr[j].fst; break;}
        if (got == -1) cout << "NO\n";
        else {
            int sum = 0;
            forn (j,4) if (arr[j].fst != got) sum += arr[j].fst;
            if (sum == got) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}