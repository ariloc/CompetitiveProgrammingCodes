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

bool byX (ii &a, ii &b) {
    if (a.fst == b.fst) {
        return a.snd < b.snd;
    }

    return a.fst < b.fst;
}

bool byY (ii &a, ii &b) {
    if (a.snd == b.snd) {
        return a.fst < b.fst;
    }

    return a.snd < b.snd;
}

int main() {
    FAST_IO;

    int N;
    cin >> N;

    forn(i,N) {
        int p;
        cin >> p;
        vector<ii> packages;

        forn(j,p) {
            int x,y;
            cin >> x >> y;
            packages.push_back({x,y});
        }

        sort(all(packages),byX);

        int actX = 0, actY = 0, actpkg = 0;
        string path;
        bool posib = true;
        while (true) {
            ii act = packages[actpkg];
            if (actX+1 <= act.fst) {
                path+='R';
                actX++;
            }
            else {
                path+='U';
                actY++;
            }
            if (actX > act.fst or actY > act.snd)
                {posib = false; break;}
            if (actX == act.fst and actY == act.snd) actpkg++;
            if (actpkg >= p) break;
        }
        if (posib) {
            cout << "YES" << '\n';
            cout << path << '\n';
        }
        else cout << "NO" << '\n';
    }

    return 0;
}