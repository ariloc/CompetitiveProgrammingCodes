#include <vector>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;

int librero(vector<int> bases, vector<int> libros)
{
    int h;
    sort(bases.rbegin(),bases.rend());
    sort(libros.begin(),libros.end());
    forn (i,bases.size()) {
        if (!i)
            h = bases[i]+libros[i];
        else {
            if (bases[i]+libros[i] != h) return -1;
        }
    }
    return h;
}
