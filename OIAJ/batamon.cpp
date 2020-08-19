#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#define forn(i,n) for (int i = 0; i < int(n); i++)

using namespace std;

const int MAXN = 1e6;

struct mon {
    int pw,pos;
    bool operator<(const mon &o)const {
        return pw<o.pw;
    }
};

bool done[MAXN];

int batamon(vector<int> hechicera, vector<int> rival, vector<int> &enfrentamientos)
{
    vector<mon> h,r;
    queue<int> restantes;
    int win = 0, i;
    h.resize(rival.size(),{0,0});
    r.resize(rival.size(),{0,0});
    forn (i,rival.size()) {
        h[i].pw = hechicera[i];
        h[i].pos = i;
        r[i].pos = i;
        r[i].pw = rival[i];
    }
    sort (h.begin(),h.end());
    sort (r.begin(),r.end());
    enfrentamientos.resize(rival.size(),false);
    for (int i = 0, m = 0; i < rival.size(); m++) {
        if (h[m].pw >= r[i].pw && m < rival.size()) {
            enfrentamientos[r[i].pos] = h[m].pos+1;
            win++;
            done[h[m].pos] = 1;
            i++;
        }
        else if (m < rival.size()) {
            restantes.push(h[m].pos+1);
        }
        else {
            int x = restantes.front();
            restantes.pop();
            enfrentamientos[r[i].pos] = x;
            i++;
        }
    }
    return win;
}
