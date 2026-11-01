#include <string>
#include <set>

using namespace std;

int cumplelongitud(string &nombre) {
    return nombre.size() % 2;
}

int cumpleextremos(string &nombre) {
    return nombre[0] != nombre.back();
}

int cumplefinal(string &nombre) {
    if (nombre.size() < 3)
        return 0;
    return nombre.substr(nombre.size()-3) == "son";
}

int cumpleinicio(string &nombre) {
    set<char> vow = {'a','e','i','o','u'};
    return vow.count(nombre[0]);
}
