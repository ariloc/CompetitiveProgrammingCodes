#include <string>
#include <vector>
#include <set>

using namespace std;

int esxoroes(string &nacionalidad) {
    return nacionalidad == "xoroes" || nacionalidad == "xoroesa";
}

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

int nombrevalido(string &nombre) {
    if ((int)nombre.size() < 3) return 0;
    set<char> vow = {'a','e','i','o','u'};
    return (int)nombre.size() % 2 && nombre[0] != nombre.back() && nombre.substr((int)nombre.size()-3,3) == "son" && vow.count(nombre[0]);
}
