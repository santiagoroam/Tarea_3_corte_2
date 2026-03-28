#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string texto = "If man was meant to stay on the ground, god would have given us roots.";
    string limpio = "";

    for (int i = 0; i < texto.length(); i++) {
        char c = texto[i];

        if (c >= 'A' && c <= 'Z') {
            limpio = limpio + char(c + 32);
        } else if (c >= 'a' && c <= 'z') {
            limpio = limpio + c;
        }
    }

    int n = limpio.length();

    int c = ceil(sqrt(n));
    int r = n / c;

    if (r * c < n) {
        r = r + 1;
    }

    string matriz = limpio;

    while (matriz.length() < r * c) {
        matriz = matriz + " ";
    }

    string resultado = "";

    for (int col = 0; col < c; col++) {
        for (int fila = 0; fila < r; fila++) {
            resultado = resultado + matriz[fila * c + col];
        }
        resultado = resultado + " ";
    }

    cout << resultado << endl;

    return 0;
}