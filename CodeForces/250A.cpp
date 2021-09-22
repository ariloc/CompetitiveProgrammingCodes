#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define fst first
#define snd second

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

vi folders;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,accum = 0, actSZ = 0;
    cin >> N;

    forn (i,N) {
        int x;
        cin >> x;
        if (accum+1 >= 3 and x < 0) {
            folders.push_back(actSZ);
            actSZ = accum = 0;
        }
        if (x < 0) accum++;
        actSZ++;
    }
    if (actSZ) folders.push_back(actSZ);

    cout << folders.size() << '\n';
    for (auto &i : folders) cout << i << ' ';
    return 0;
}