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

int const MAXN = 1e5+5;

int sell[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,m,d; cin >> n >> m >> d;

        int morig = m;

        forn(i,m) cin >> sell[i+1];
        if (sell[1] == 1) {
            forn(i,m) sell[i] = sell[i+1];
        }
        else sell[0] = 1, ++m;

        int cok = 1;
        forsn(i,1,m) {
            cok++;
            cok += (sell[i]-sell[i-1]-1)/d;
        }
        cok += (n-sell[m-1])/d;

        int cnt = morig, mini = cok;
        forsn(i,1,m-1) {
            int a = 1 + (sell[i]-sell[i-1]-1)/d + (sell[i+1]-sell[i]-1)/d;
            int b = (sell[i+1]-sell[i-1]-1) / d;
            int dif = a-b;
            if (dif > 0) {
                if (cok-dif < mini) mini = cok-dif, cnt = 0;
                if (cok-dif == mini) cnt++;
            }
        }
        int a = 1+(sell[m-1]-sell[m-2]-1)/d+(n-sell[m-1])/d;
        int b = (n-sell[m-2])/d;
        int dif = a-b;
        if (dif > 0) {
            if (cok-dif < mini) mini = cok-dif, cnt = 0;
            if (cok-dif == mini) cnt++;
        }

        cout << mini << ' ' << cnt << '\n';
    }

    return 0;

}
