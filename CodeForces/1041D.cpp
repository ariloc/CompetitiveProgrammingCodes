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

const int MAXN = 2e5+4;

ii airflow[MAXN];
int gaps[MAXN], largo[MAXN];

int main() {
    FAST_IO;

    int n,h; cin >> n >> h;

    int accum = 0, xdist = 0;
    forn (i,n) {
        int x,y; cin >> x >> y;
        airflow[i] = {x,y};
        if (i) gaps[i-1] = airflow[i].fst-airflow[i-1].snd;
        xdist += (y-x);
        largo[i] = xdist;
    }

    int j = 0, sum = 0;
    int bestL = -1;
    forn (i,n) {
        while (j < n && sum < h) {
            sum += gaps[j];
            j++;
        }

        bestL = max(bestL,largo[j-1]-(i-1 < 0 ? 0 : largo[i-1]));
        sum -= gaps[i];
    }

    cout << h+bestL;

    return 0;
}