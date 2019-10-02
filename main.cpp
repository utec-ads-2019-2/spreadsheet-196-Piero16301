#include<bits/stdc++.h>

using namespace std;

class Hoja {
private:
    int filas = 0, columnas = 0;
    vector < vector <string> > matriz;

public:
    Hoja(int _filas, int _columnas) : matriz(_filas, vector <string> (_columnas) ), filas(_filas), columnas(_columnas) {}

    void insertarDatos() {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                cin >> matriz[i][j];
            }
        }
    }

    void procesarCeldas() {
        vector < vector <int> > temporal(filas, vector <int> (columnas, -1) );
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                if (j > 0) {
                    cout << ' ';
                }
                if (matriz[i][j][0] != '=') {
                    temporal[i][j] = atoi(matriz[i][j].c_str());
                } else {
                    temporal[i][j] = evaluarFormula(temporal, i, j);
                }
                cout << temporal[i][j];
            }
            cout << endl;
        }
    }

    int evaluarFormula(vector < vector <int> > &temporal, int fil, int col) {
        if (temporal[fil][col] != -1) {
            return temporal[fil][col];
        }
        if (matriz[fil][col][0] != '=') {
            return temporal[fil][col] = atoi(matriz[fil][col].c_str());
        }
        vector < pair <int, int> > toParse;
        concatenarFormula(matriz[fil][col], &toParse);
        int resultado = 0;
        for (int i = 0; i < ((int)toParse.size()); ++i) {
            resultado += evaluarFormula(temporal, toParse[i].first, toParse[i].second);
        }
        return temporal[fil][col] = resultado;
    }

    void concatenarFormula(const string &formula, vector < pair<int, int> > *toParse) {
        int i = 1;
        while (i < ((int)formula.size())) {
            string col, fil;
            while (i < ((int)formula.size()) && formula[i] != '+') {
                if (isalpha(formula[i])) {
                    col += formula[i];
                } else {
                    fil += formula[i];
                }
                ++i;
            }
            toParse->push_back(make_pair(atoi(fil.c_str()) - 1, posicionColumna(col) - 1));
            ++i;
        }
    }

    int posicionColumna(const string &col) {
        int posicion = 0;
        int digitos = 1;
        for (int i = ((int)col.size()) - 1; i >= 0; --i) {
            posicion += (toupper(col[i]) - 'A' + 1) * digitos;
            digitos *= 26;
        }
        return posicion;
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
        hoja.procesarCeldas();
    }

    return 0;

}