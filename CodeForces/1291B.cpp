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

int main() {
    FAST_IO;

    int t;
    cin >> t;

    forn (i,t) {
        int n;
        vi arr;
        int levelI = 0, levelD = 0;
        bool decreasing = false, posib = true;

        cin >> n;
        bool fin = false;
        forn (j,n) {
            int x;
            cin >> x;
            arr.push_back(x);

            if (!fin) if (x >= levelI) levelI++;
            else {levelI = j-1; fin = true;}
        }
        if (!fin) levelI = n-1;

        fin = false;
        dforn (j,n) {
            //cerr << arr[j] << ' ' << levelD << ' ' << fin << "!!" << endl;
            if (arr[j] >= levelD) levelD++;
            else {levelD = j+1; fin = true; break;}
        }
        if (!fin) levelD = 0;
        //cerr << levelD << ' ' << levelI << "!!!" << endl;

        if (levelI >= levelD and levelD <= levelI) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

    return 0;
}