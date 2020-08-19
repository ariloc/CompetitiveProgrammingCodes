#include <string>

#define forn(i,n) for(int i = 0; i<int(n); i++)

using namespace std;
const char let[] = {'B','G','N'};

void caminito(string &baldosas)
{
    forn(i,baldosas.size()) {
        if (baldosas[i] == 'R') {
            for (auto &j : let) {
                baldosas[i] = j;
                if (i > 0 and baldosas[i] == baldosas[i-1]) continue;
                if (i != baldosas.size()-1 and baldosas[i] == baldosas[i+1]) continue;
                break;
            }
        }
    }
}
