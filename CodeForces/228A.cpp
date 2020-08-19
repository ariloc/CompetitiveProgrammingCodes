#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int main() {
    FAST_IO;

    vi arr;
    int ap = 0;
    forn (i,4) {int x; cin >> x; arr.pb(x);}
    sort(all(arr));
    forn (i,4) {
        int cnt = 0;
        while (i+cnt < 4 and arr[i+cnt] == arr[i]) cnt++;
        ap += (cnt-1);
        i += (cnt-1);
    }

    cout << ap;

    return 0;
}