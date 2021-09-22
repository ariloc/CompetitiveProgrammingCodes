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

struct point {
    int x; double y;
};

const int MAXN = 1004;
point disc[MAXN];

double difH (int &r, int &x1, int &x2) {
    double calc = (((double)4*r*r)) - (abs((double)x1-x2)*abs((double)x1-x2));
    return sqrt(calc);
}

int main() {
    FAST_IO;

    int n,R; cin >> n >> R;

    cout << fixed << setprecision(10);

    forn (i,n) {
        int x; cin >> x;
        disc[i] = {x,R};

        forn (j,i)
            if (abs(x-disc[j].x <= R*2))
                disc[i].y = max(disc[i].y,difH(R,disc[j].x,x)+disc[j].y);
    }

    forn (i,n) cout << disc[i].y << ' ';

    return 0;
}