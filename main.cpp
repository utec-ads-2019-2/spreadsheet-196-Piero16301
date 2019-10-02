#include<bits/stdc++.h>

using namespace std;

class Hoja {
private:
    int filas = 0, columnas = 0;
    string **matrizPrimitiva = nullptr;
    int **matrizFinal = nullptr;

public:
    Hoja() {}

    Hoja(int _filas, int _columnas) {
        filas = _filas;
        columnas = _columnas;
        
        matrizFinal = new int*[filas];
        for (int i = 0; i < filas; ++i) {
            matrizFinal[i] = new int[columnas];
        }

        matrizPrimitiva = new string*[filas];
        for (int j = 0; j < filas; ++j) {
            matrizPrimitiva[j] = new string[columnas];
        }
    }

    void insertarDatos() {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                string datos;
                cin >> datos;
                matrizPrimitiva[i][j] = datos;
            }
        }
    }

    void procesarFormulas() {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                int valorCasilla;
                if (matrizPrimitiva[i][j][0] == '=') {
                    valorCasilla = evaluarFormula(matrizPrimitiva[i][j]);
                } else {
                    valorCasilla = stoi(matrizPrimitiva[i][j]);
                }
                matrizFinal[i][j] = valorCasilla;
            }
        }
    }

    int evaluarFormula(string formula) {
        return 123;
    }

    void imprimirHoja() {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                cout << matrizFinal[i][j] << ' ';
            }
            cout << endl;
        }
    }

    ~Hoja() {
        for (int i = 0; i < filas; ++i) {
            delete [] matrizFinal[i];
        }
        delete [] matrizFinal;

        for (int j = 0; j < filas; ++j) {
            delete [] matrizPrimitiva[j];
        }
        delete [] matrizPrimitiva;
    }

};

int main() {
    
    int numeroHojas;
    cin >> numeroHojas;
    for (int i = 0; i < numeroHojas; ++i) {
        int columnas, filas;
        cin >> columnas >> filas;
        Hoja hoja(filas, columnas);
        hoja.insertarDatos();
        hoja.procesarFormulas();
        hoja.imprimirHoja();
    }

    return 0;

}