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

vi arr;

int main() {
    FAST_IO;

    int N;
    cin >> N;

    forn (i,N-1) {
        int x;
        cin >> x;
        arr.pb(x);
    }

    sort(all(arr));

    int prev = arr[0], r = -1;
    forsn (i,1,arr.size()) {
        if (arr[i]-prev > 1) {r = arr[i]-1; break;}
        prev = arr[i];
    }
    if (r == -1) {
        if (arr[0] == 2) r = 1;
        else if (N == 2) r = 2;
        else r = N;
    }

    cout << r;

    return 0;
}
