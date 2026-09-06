#include <string>

using namespace std;

int aprendiendo(string n, int d) {
    int x = 0;
    for (int i = 0; i < (int)n.size(); i++) {
        x = ((x*10)%d + (n[i]-'0'))%d;
    }
    return x;
}
