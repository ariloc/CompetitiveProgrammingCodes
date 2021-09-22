#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define fst first
#define snd second

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 3002;

set<int> done;
bool hecho[MAXN];
vi badge;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,sum=0;
    cin >> N;

    forn(i,N*2) done.insert(i+1);

    forn(i,N) {
        int x;
        cin >> x;
        badge.push_back(x);
        if (done.count(x)) done.erase(x);
    }

    sort(badge.begin(),badge.end());

    forn (i,N) {
        int x = badge[i];
        if (!hecho[x]) {
            hecho[x] = true;
            continue;
        }
        int aux = *done.upper_bound(x);
//        cerr << aux << endl;
        sum += aux-x;
        if (done.count(aux)) done.erase(aux);
    }

    cout << sum;

    return 0;
}