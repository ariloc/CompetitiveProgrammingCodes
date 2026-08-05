#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef pair<int,int> ii;

int const MAXN = 2e5+5;

int arr[MAXN],auxi[MAXN];
map<ii,int> ma;

int main(){
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;

        int cs = 0, cb = 0;
        forn(i,2*n) {
            cin >> arr[i];
            if (arr[i] == 1) cs++;
            else cb++;
        }
        
        ma.clear();

        int s=0,b=0;
        int mini = 2*n;
        forsn(i,n,2*n) {
            if (arr[i] == 1) s++;
            else b++;
            ii par = {s-min(s,b),b-min(s,b)};
            auto it = ma.find(par);
            if (it == ma.end()) {
                ma[par] = s+b;
            }
            else (*it).snd = min((*it).snd, s+b);
        }

        s=cs,b=cb;
        int as=0,ab=0;
        dforsn(i,-1,n) {
            ii par = {s-min(s,b),b-min(s,b)};
            auto it = ma.find(par);
            if (it != ma.end()) {
                mini = min(mini,as+ab+(*it).snd);
            }
            if (s == b)
                mini = min(mini, as+ab);

            if (i >= 0) {
                if (arr[i] == 1) s--, as++;
                else b--, ab++;
            }
        }

        cout << mini << '\n';
    }

    return 0;
}
