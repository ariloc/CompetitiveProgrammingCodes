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

int const MAXK = 30;

int query (int i, int x) {
    cout << "? " << i << ' ' << x << endl;
    int r;
    cin >> r;
    if (x == -1)
        exit(0);
    return r;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;

        int rta = 0;

        vi a,b;
        forn(i,n-1) a.pb(i);
        forn(r,MAXK) {
            if ((rta|(1<<r)) > n)
                break;

            vi cur;
            swap(cur,a);
            b.clear();

            int biton = 0, pref = 0;
            while (((pref<<(r+1))|(rta|(1<<r))) <= n) biton++, pref++;

            for (auto &i : cur) {
                if (query(i+1,1<<r)) b.pb(i);
                else a.pb(i);
            }

            if ((int)b.size() < biton || cur.empty()) {
                rta |= (1<<r);
                swap(a,b);
            }
        }

        cout << "! " << rta << endl;
    }

    return 0;

}
