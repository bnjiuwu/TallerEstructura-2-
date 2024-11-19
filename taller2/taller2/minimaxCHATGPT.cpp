#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Representación del tablero (3x3)
typedef vector<vector<char>> Tablero;

// Función para imprimir el tablero
void imprimirTablero(const Tablero& tablero) {
    for (const auto& fila : tablero) {
        for (const auto& casilla : fila) {
            cout << (casilla == '\0' ? '.' : casilla) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Verifica el ganador
char verificarGanador(const Tablero& tablero) {
    // Comprobación de filas y columnas
    for (int i = 0; i < 3; ++i) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != '\0')
            return tablero[i][0];
        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] != '\0')
            return tablero[0][i];
    }
    // Comprobación de diagonales
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != '\0')
        return tablero[0][0];
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != '\0')
        return tablero[0][2];
    // Comprobar empate
    for (const auto& fila : tablero) {
        for (const auto& casilla : fila) {
            if (casilla == '\0') return '\0'; // El juego sigue
        }
    }
    return 'E'; // Empate
}

// Función Minimax con poda alfa-beta
int minimax(Tablero& tablero, int profundidad, bool esMax, int alfa, int beta) {
    char ganador = verificarGanador(tablero);
    if (ganador == 'X') return 10 - profundidad; // Maximiza
    if (ganador == 'O') return profundidad - 10; // Minimiza
    if (ganador == 'E') return 0; // Empate

    if (esMax) {
        int mejorValor = numeric_limits<int>::min();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (tablero[i][j] == '\0') {
                    tablero[i][j] = 'X'; // Jugador maximizador
                    mejorValor = max(mejorValor, minimax(tablero, profundidad + 1, false, alfa, beta));
                    tablero[i][j] = '\0';
                    alfa = max(alfa, mejorValor);
                    if (beta <= alfa) return mejorValor;
                }
            }
        }
        return mejorValor;
    } else {
        int mejorValor = numeric_limits<int>::max();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (tablero[i][j] == '\0') {
                    tablero[i][j] = 'O'; // Jugador minimizador
                    mejorValor = min(mejorValor, minimax(tablero, profundidad + 1, true, alfa, beta));
                    tablero[i][j] = '\0';
                    beta = min(beta, mejorValor);
                    if (beta <= alfa) return mejorValor;
                }
            }
        }
        return mejorValor;
    }
}

// Encuentra el mejor movimiento
pair<int, int> mejorMovimiento(Tablero& tablero, bool esMax) {
    int mejorValor = esMax ? numeric_limits<int>::min() : numeric_limits<int>::max();
    pair<int, int> movimiento = {-1, -1};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tablero[i][j] == '\0') {
                tablero[i][j] = esMax ? 'X' : 'O';
                int valor = minimax(tablero, 0, !esMax, numeric_limits<int>::min(), numeric_limits<int>::max());
                tablero[i][j] = '\0';
                if ((esMax && valor > mejorValor) || (!esMax && valor < mejorValor)) {
                    mejorValor = valor;
                    movimiento = {i, j};
                }
            }
        }
    }
    return movimiento;
}

// Función principal
int main() {
    Tablero tablero(3, vector<char>(3, '\0')); // Tablero vacío
    cout << "Estado inicial del tablero:" << endl;
    imprimirTablero(tablero);

    // Encuentra el mejor movimiento para el jugador 'X'
    pair<int, int> movimiento = mejorMovimiento(tablero, true);
    cout << "Mejor movimiento para 'X': (" << movimiento.first << ", " << movimiento.second << ")" << endl;

    // Actualiza el tablero con el mejor movimiento
    tablero[movimiento.first][movimiento.second] = 'X';
    imprimirTablero(tablero);

    return 0;
}
