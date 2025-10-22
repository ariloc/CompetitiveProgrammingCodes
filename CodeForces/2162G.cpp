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

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        if (n == 2) {
            cout << "-1\n"; continue;
        }
        if (n == 3) {
            cout << "1 3\n2 3\n";
            continue;
        }
        if (n == 4)  {
            cout << "1 2\n3 1\n4 1\n";
            continue;
        }
        if (n == 5) {
            cout << "4 3\n3 2\n2 1\n1 5\n";
            continue;
        }
        ll sum = (n*(ll)(n+1))/2 - 1;
        int rt = sqrtl(sum);
        if (rt*rt == sum) {
            forn(i,n-1) cout << 1 << ' ' << i+2 << '\n';
            continue;
        }
        ll prox = (rt+1)*(ll)(rt+1);
        forn(k,2) {
            ll dif = prox - sum;
            if (dif <= 2) {
                prox = (rt+2)*(ll)(rt+2);
                continue;
            }
            else if (dif <= n) {
                forsn(i,2,n+1) if (i != dif) cout << 1 << ' ' << i << '\n';
                cout << 2 << ' ' << dif << '\n';
                break;
            }
            else {
                ll ult = n;
                ll ot = dif-ult;
                if (ot == 1) {
                    ult = n-2;
                    ot = dif - ult;
                }
                else if (ot == 2) {
                    ult = n-1;
                    ot = dif - ult;
                }
                forsn(i,2,n+1) if (i != ot && i != ult) cout << 1 << ' ' << i << '\n';
                cout << 2 << ' ' << ult << '\n';
                cout << 2 << ' ' << ot << '\n';
                break;
            }
        }
    }

    return 0;
}
