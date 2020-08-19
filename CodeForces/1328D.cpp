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

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int arr[MAXN], rta[MAXN];
        set<int> cant;
        int N; cin >> N;

        forn (j,N) {cin >> arr[j]; if (cant.size() < 3) cant.insert(arr[j]);};

        if (cant.size() < 3) {
            cout << cant.size() << '\n';
            map<int,int> col; int prox_libre = 1;
            forn (j,N) {
                if (!col.count(arr[j])) col[arr[j]] = prox_libre++;
                cout << col[arr[j]] << ' ';
            }
            cout << '\n';
        }
        else {
            int cnt = 2;
            int col = 1;
            rta[0] = col;

            bool done = false;
            forsn (j,1,N) {
                if (!done and arr[j] == arr[j-1] and N%2)
                    {done = true; rta[j] = rta[j-1];}
                else {
                    if (col == 1) col = 2; else col = 1;
                    rta[j] = col;
                }
            }

            if (rta[N-1] == rta[0] and arr[0] != arr[N-1]) {cnt++; rta[N-1] = 3;}

            cout << cnt << '\n';
            forn (j,N) cout << rta[j] << ' ';
            cout << '\n';
        }
    }

    return 0;
}