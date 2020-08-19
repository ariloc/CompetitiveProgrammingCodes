#include <iostream>
#include <vector>

#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;

int main() {
    //freopen("antivirus.in","r",stdin);
    //freopen("antivirus.out","w",stdout);
    char a,b;
    string inf;
    int i, n, len;

    cin >> n >> a >> b;
    cin >> inf;
    len = n;

    forn (i,inf.size()+1) {
        if (inf[i] == b) {
            if (inf[i-1] == a and inf[i+1] == a) {
                inf[i] = 255;
                len--;
            }
        }
    }

    cout << len << endl;
    forn(i,inf.size()+1) if (isalpha(inf[i])) cout << inf[i];
    return 0;
}
