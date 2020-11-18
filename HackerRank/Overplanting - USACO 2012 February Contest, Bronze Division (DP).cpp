// https://www.hackerrank.com/contests/simulacro-3-oia-2020/challenges/problem-1-overplanting
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast") // sin pragma no entra!
#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 2e4+2;
const int ADD = 1e4+1;

char plane[MAXN][MAXN]; // reduce memoria, pues cada char consume 1 byte

int overplanting(vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2) {
    forn(i,x1.size()) {
        x1[i] += ADD; x2[i] += ADD;
        y1[i] += ADD; y2[i] += ADD;

        plane[y1[i]][x1[i]]++;
        plane[y1[i]][x2[i]]--;
        plane[y2[i]][x1[i]]--;
        plane[y2[i]][x2[i]]++;
    }
    int cnt = 0;
    forsn(i,1,MAXN) forsn(j,1,MAXN) {
        if (i+1 < MAXN) plane[i+1][j] += plane[i][j];
        plane[i][j] += plane[i][j-1];
        if (plane[i][j]) cnt++;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector <int> x1(N), y1(N), x2(N), y2(N);
    for(int i=0; i<N; i++)
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

    cout << overplanting(x1, y1, x2, y2) << endl;

    return 0;
}
