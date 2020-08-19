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

    forn (i,t) {
        vi arr;
        int N; cin >> N;

        forn (j,N)
            {int x; cin >> x; arr.pb(x);}

        sort(all(arr));

        int cnt = 1;
        for (int j = (arr.size()/2); j < arr.size(); j++) {
            cout << arr[j] << ' ';
            if (j-cnt >= 0) cout << arr[j-cnt] << ' ';
            cnt+=2;
        }
        cout << '\n';
    }

    return 0;
}