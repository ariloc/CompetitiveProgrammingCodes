#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;

// areaT = 1/2 | areaC = 1
float areaPaj = 0, areaP = 1/2 + 1;
int h = 0, tot = 0;
vector<int> alts;

int main() {
    freopen("pajaros.in","r",stdin);

    int n, ant = 0;
    cin >> n;
    forn (i,n) {
        int x;
        cin >> x;
        areaPaj += (ant+x)/(float)2;
        ant = x;
        alts.push_back(x);
    }
    forn (i,n) {
        if (areaP < areaPaj) {
            h++;
            areaP += 1/2 + n-i-1;
        }
        else {
            h--;
            areaP -= 1/2 + n-i-1;
        }
        tot += abs(h-alts[i]);
        cout << h << endl;
    }
    cout << tot;
    return 0;
}
