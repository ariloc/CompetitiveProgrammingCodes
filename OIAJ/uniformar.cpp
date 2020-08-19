#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i<int(n); i++)
#define fst first
#define snd second

using namespace std;
typedef pair<int,int> ii;
typedef vector<vector<bool> > vbo;
const int xr[4] = {0,-1,0,1};
const int yr[4] = {1,0,-1,0};

vector<string> mat;
vbo done;
int r = 0;
vector<ii> pos  = {{0,0}};

bool valid(int &i, int &j) {
    if (i >= mat.size() or i < 0) return false;
    if (j >= mat.size() or j < 0) return false;
    return true;
}

void bfs() {
    queue<ii> Q;
    r++;
    while(!pos.empty()) {
        ii x = pos.back();
        Q.push(x);
        pos.pop_back();
    }

    while (not Q.empty()) {
        ii x = Q.front(); Q.pop();
        int i = x.fst, j = x.snd;
        forn (k, 4) {
            int ni = i+yr[k], nj = j+xr[k];
            if (!(valid(ni,nj))) continue;
            if (done[ni][nj]) continue;
            if (mat[ni][nj] != mat[i][j]) pos.push_back({ni,nj});
            else Q.push({ni,nj});
            done[ni][nj] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("uniformar.in","r",stdin);
//    freopen("uniformar.out","w",stdout);
    int N;
    cin >> N;
    done.resize(N,vector<bool>(N,false));
    forn (i,N) {
        string x;
        cin >> x;
        mat.push_back(x);
    }
    while (!pos.empty())
        bfs();
    cout << r-1 << endl;
    return 0;
}
