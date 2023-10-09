#include<iostream>
#include<vector>
#include<queue>

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

int const MAXN = 105;
int const X[] = {1,-1,0,0};
int const Y[] = {0,0,-1,1};

int mat[MAXN][MAXN];
bool done[MAXN][MAXN];

int main() {
    FAST_IO;

    int r,c; cin >> r >> c;
    forn(i,r) forn(j,c) cin >> mat[i][j];

    int maxi = 0;
    forn(i,r) forn(j,c) {
        forn(p,r) forn(q,c) done[p][q] = false;

        priority_queue<pair<int,ii>,vector<pair<int,ii>>,greater<pair<int,ii>>> Q;
        int act = mat[i][j];
        Q.push({mat[i][j],{i,j}});
        done[i][j] = true;
        int cnt = 0;

        while (!Q.empty()) {
            auto e = Q.top(); Q.pop();

            if (e.fst < act) continue;
            act = e.fst;
            ++cnt;

            forn(k,4) {
                int tY = e.snd.fst + Y[k], tX = e.snd.snd + X[k];
                if (tY < 0 || tX < 0 || tY >= r || tX >= c) continue;
                if (done[tY][tX]) continue;
                done[tY][tX] = true;
                Q.push({mat[tY][tX],{tY,tX}});
            }
        }

        maxi = max(maxi,cnt);
    }

    cout << maxi << '\n';

    return 0;
}
