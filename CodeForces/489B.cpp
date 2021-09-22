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

const int MAXN = 101;

int boys[MAXN], girls[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn (i,n) cin >> boys[i];
    int m; cin >> m;
    forn (i,m) cin >> girls[i];

    sort(boys,boys+n); sort(girls,girls+m);

    int cnt = 0;

    int j = 0;
    forn (i,n) {
        while (i < n and j < m and abs(boys[i]-girls[j]) > 1) {
            if (boys[i] < girls[j]) i++;
            else j++;
        }
        if (i >= n or j >= m) break;

        if (abs(boys[i]-girls[j]) <= 1) {
            cnt++; j++;
        }
    }

    cout << cnt;

    return 0;
}