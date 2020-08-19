#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    forn(i,t) {
        int n,p,k,r = 0;
        vi goods;
        cin >> n >> p >> k;

        forn(j,n) {
            int x;
            cin >> x;
            goods.push_back(x);
        }

        sort(all(goods));

        int rest = 0;
        forn (j,k) {
            int sum = rest;
            int cant = 0;
            if (j >= n or sum > p) break;
            for (int m = k+j-1; m < n; m+=k) {
                sum += goods[m];
                if (sum > p) break;
                cant += k;
            }
            if ((cant+j) > r) r = cant+j;
            rest += goods[j];
        }

        cout << r << '\n';
    }

    return 0;
}