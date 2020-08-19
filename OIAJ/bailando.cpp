#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i<int(n); i++)

using namespace std;
const int MAXN = 1e5;
const int maxD = 1500; //máxima diferencia
typedef vector<int> vi;
typedef pair<int,int> ii;

int bailando(vector<int> famosos, vector<int> bailarines)
{
    sort(famosos.begin(), famosos.end());
    sort(bailarines.begin(), bailarines.end());

    int low = -1;
    int high = maxD;
    int cnt = 0;
    int r;

    // |F-B| <= x
    while (abs(high-low) > 1) {
        int mid = (high+low)/2;

        bool posible = true;
        int j = 0;
        forn (i,famosos.size()) {
            bool yes = false;
            for (; j < bailarines.size(); j++) {
                if (abs(bailarines[j]-famosos[i]) <= mid) {
                    //cerr << mid << ' ' << abs(bailarines[j]-famosos[i]) << ' ' << j << ' ' << i << endl;
                    yes = true;
                    j++;
                    break;
                }
            }
            if (!yes) {
                low = mid;
                posible = false;
                break;
            }
        }
        if (posible)
            high = mid;
    }
    return high;
}
