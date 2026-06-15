#include <string>

using namespace std;

string sumadigitos(string &s) {
    if (s[0] == '?') s[0] = s[1];
    if (s.back() == '?') s.back() = s[(int)s.size()-2];
    for (int i = 1; i < (int)s.size()-1; i++)
        if (s[i] == '?') s[i] = s[i-1]-'0' + s[i+1]-'0' + '0';
    return s;
}
