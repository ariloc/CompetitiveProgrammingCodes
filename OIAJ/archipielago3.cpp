#include <string>
#include <vector>
#include <set>

using namespace std;

int dnivencido(int dia, int mes, int anio) {
    if (anio < 2026) return 1;
    if (anio == 2026 && mes < 9) return 1;
    if (anio == 2026 && mes == 9 && dia < 25) return 1;
    return 0;
}

int diferenciahijos(vector<int> &edades) {
    for (int i = 1; i < (int)edades.size(); i++)
        if (edades[i]-edades[i-1] <= 4) return 1;
    return 0;
}

int sonxoroeses(vector<string> &nacionalidades) {
    int cnt = 0;
    for (auto &s : nacionalidades) cnt += (s == "xoroes" || s == "xoroesa");
    return cnt;
}

int nombresvalidos(vector<string> &nombres) {
    int cnt = 0;
    set<char> vow = {'a','e','i','o','u'};
    for (auto &s : nombres) {
        if ((int)s.size() < 3) continue;
        cnt += (int)s.size() % 2 && s[0] != s.back() && s.substr((int)s.size()-3,3) == "son" && vow.count(s[0]);
    }
    return cnt;
}
