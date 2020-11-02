// https://www.hackerrank.com/contests/simulacro-1-oia-2020/challenges/problem-2-cow-lineup
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

const int MAXN = 50005;
const int INF = 2e9+5;

map<int,int> ids;
int cowInRange[MAXN];

int cow_lineup(vector <int> x, vector <int> id) {
    vector<ii> cows;
    forn(i,x.size()) cows.pb({x[i],id[i]});
    sort(all(cows)); int prox_libre = 0;
    forn(i,x.size()) {
        auto it = ids.find(cows[i].snd);
        if (it == ids.end()) {ids[cows[i].snd] = prox_libre; cows[i].snd = prox_libre++;}
        else cows[i].snd = (*it).snd;
    }
    forn(i,x.size()) cerr << cows[i].fst << ' ' << cows[i].snd << endl;
    int uniqueCows = ids.size();
    int j = 0, mini = INF, cnt = 0;
    forn(i,cows.size()) {
        while (j < (int)cows.size() && cnt < uniqueCows) {
            if (!cowInRange[cows[j].snd]) cnt++;
            cowInRange[cows[j].snd]++; j++;
        }
        if (cnt == uniqueCows)
            mini = min(mini,cows[j-1].fst-cows[i].fst);
        cowInRange[cows[i].snd]--;
        if (!cowInRange[cows[i].snd]) cnt--;
    }
    return mini;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector <int> x(N), id(N);
    for(int i=0; i<N; i++)
        cin >> x[i] >> id[i];

    cout << cow_lineup(x, id) << endl;

    return 0;
}
