#include <vector>
#include <algorithm>
#include <iostream>

#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;

struct ord {
    int n, pos;
    bool operator<(const ord &o) const{
        return n<o.n;
    }
};

int librero(vector<int> bases, vector<int> libros, vector<int> &orden)
{
    int h = -1;
    vector<ord> b,l;
    b.resize(bases.size(),{0,0});
    l.resize(bases.size(),{0,0});
    forn (i,bases.size()) {
        b[i].n = bases[i];
        b[i].pos = i;
        l[i].n = libros[i];
        l[i].pos = i;
    }
    sort(b.rbegin(),b.rend());
    sort(l.begin(),l.end());
    orden.resize(bases.size(),false);
    forn (i,bases.size()) {
        orden[b[i].pos] = l[i].pos+1;
        if (!i)
            h = b[i].n + l[i].n;
        else {
            if (b[i].n + l[i].n != h) {
                h = -1;
                break;
            }
        }
    }
    if (h == -1) {
        orden.resize(0,false);
    }
    return h;
}
