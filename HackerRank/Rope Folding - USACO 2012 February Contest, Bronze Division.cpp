// https://www.hackerrank.com/contests/simulacro-3-oia-2020/challenges/problem-0-rope-folding/problem
#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

int rope_folding(int L, vector <int> v) {
    int cnt = 0;
    sort(all(v));
    set<double> pts;
    forn(i,v.size()) forsn(j,i+1,v.size()) {
        double m = ((double)v[i]+v[j])/2;
        map<double,int> dists;
        for (auto &k : v) {
            dists[abs(k-m)]++;
            if (!abs(k-m)) dists[abs(k-m)]++;
        }

        bool posib = true;
        double mini = min(abs(L-m),abs(0-m));
        for (auto &k : v) {
            double x = abs(k-m);
            if (x > mini) continue;
            if (dists[x] < 2) {posib = false; break;}
        }
        if (posib) pts.insert(m);
    }
    return (int)pts.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L;
    cin >> N >> L;
    vector <int> v(N);
    for(int i=0; i<N; i++)
        cin >> v[i];

    cout << rope_folding(L, v) << endl;

    return 0;
}
