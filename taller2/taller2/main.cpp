#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Clase Tablero
class Tablero {
private:
    vector<char> board;
    int moves;

public:
    Tablero() : board(10), moves(0) {
        for (int i = 1; i <= 9; ++i) board[i] = '0' + i;
    }

    void mostrar() {
        cout << "\n   |   |   \n";
        cout << " " << board[1] << " | " << board[2] << " | " << board[3] << "\n";
        cout << "___|___|___\n";
        cout << "   |   |   \n";
        cout << " " << board[4] << " | " << board[5] << " | " << board[6] << "\n";
        cout << "___|___|___\n";
        cout << "   |   |   \n";
        cout << " " << board[7] << " | " << board[8] << " | " << board[9] << "\n";
        cout << "   |   |   \n";
    }

    bool mover(int posicion, char marca) {
        if (posicion < 1 || posicion > 9 || board[posicion] != '0' + posicion) {
            return false;
        }
        board[posicion] = marca;
        moves++;
        return true;
    }

    int verificarEstado() {
        for (int i = 1; i <= 7; i += 3) {
            if (board[i] == board[i + 1] && board[i + 1] == board[i + 2]) return board[i] == 'X' ? 1 : -1;
        }
        for (int i = 1; i <= 3; ++i) {
            if (board[i] == board[i + 3] && board[i + 3] == board[i + 6]) return board[i] == 'X' ? 1 : -1;
        }
        if (board[1] == board[5] && board[5] == board[9]) return board[1] == 'X' ? 1 : -1;
        if (board[3] == board[5] && board[5] == board[7]) return board[3] == 'X' ? 1 : -1;
        return (moves == 9) ? 0 : -2;
    }

    void reiniciar() {
        for (int i = 1; i <= 9; ++i) board[i] = '0' + i;
        moves = 0;
    }

    vector<int> movimientosDisponibles() {
        vector<int> disponibles;
        for (int i = 1; i <= 9; ++i) {
            if (board[i] == '0' + i) disponibles.push_back(i);
        }
        return disponibles;
    }

    void deshacerMovimiento(int posicion) {
        board[posicion] = '0' + posicion;
        moves--;
    }

    char obtenerCasilla(int posicion) {
        return board[posicion];
    }
};

// Algoritmo Minimax
int minimax(Tablero &tablero, bool esMax, int profundidad = 0) {
    int estado = tablero.verificarEstado();
    if (estado != -2) return estado;

    if (esMax) {
        int mejor = numeric_limits<int>::min();
        for (int mov : tablero.movimientosDisponibles()) {
            tablero.mover(mov, 'X');
            mejor = max(mejor, minimax(tablero, false, profundidad + 1));
            tablero.deshacerMovimiento(mov);
        }
        return mejor;
    } else {
        int peor = numeric_limits<int>::max();
        for (int mov : tablero.movimientosDisponibles()) {
            tablero.mover(mov, 'O');
            peor = min(peor, minimax(tablero, true, profundidad + 1));
            tablero.deshacerMovimiento(mov);
        }
        return peor;
    }
}

// Algoritmo Minimax con poda Alfa-Beta
int minimaxAlfaBeta(Tablero &tablero, bool esMax, int alfa, int beta, int profundidad = 0) {
    int estado = tablero.verificarEstado();
    if (estado != -2) return estado;

    if (esMax) {
        int mejor = numeric_limits<int>::min();
        for (int mov : tablero.movimientosDisponibles()) {
            tablero.mover(mov, 'X');
            mejor = max(mejor, minimaxAlfaBeta(tablero, false, alfa, beta, profundidad + 1));
            tablero.deshacerMovimiento(mov);
            alfa = max(alfa, mejor);
            if (beta <= alfa) break;
        }
        return mejor;
    } else {
        int peor = numeric_limits<int>::max();
        for (int mov : tablero.movimientosDisponibles()) {
            tablero.mover(mov, 'O');
            peor = min(peor, minimaxAlfaBeta(tablero, true, alfa, beta, profundidad + 1));
            tablero.deshacerMovimiento(mov);
            beta = min(beta, peor);
            if (beta <= alfa) break;
        }
        return peor;
    }
}

// Función para obtener el mejor movimiento con un algoritmo
int obtenerMejorMovimiento(Tablero &tablero, bool usarPoda) {
    int mejorValor = numeric_limits<int>::min();
    int mejorMovimiento = -1;

    for (int mov : tablero.movimientosDisponibles()) {
        tablero.mover(mov, 'X');
        int valor = usarPoda ? minimaxAlfaBeta(tablero, false, numeric_limits<int>::min(), numeric_limits<int>::max())
                             : minimax(tablero, false);
        tablero.deshacerMovimiento(mov);

        if (valor > mejorValor) {
            mejorValor = valor;
            mejorMovimiento = mov;
        }
    }

    return mejorMovimiento;
}

// Modo de dos jugadores
void modoDosJugadores(Tablero &tablero) {
    int jugador = 1, posicion, estado;
    char marca;

    do {
        tablero.mostrar();
        marca = (jugador == 1) ? 'X' : 'O';
        cout << "Jugador " << jugador << ", ingresa tu movimiento (1-9): ";
        cin >> posicion;

        if (!tablero.mover(posicion, marca)) {
            cout << "Movimiento inválido, intenta de nuevo.\n";
            continue;
        }

        estado = tablero.verificarEstado();
        if (estado != -2) break;
        jugador = 3 - jugador;
    } while (true);

    tablero.mostrar();
    if (estado == 0) cout << "¡Es un empate!\n";
    else cout << "¡Felicidades! El Jugador " << ((estado == 1) ? 1 : 2) << " gana.\n";
}

// Modo IA contra el jugador
void modoContraIA(Tablero &tablero, bool usarPoda) {
    int jugador = 1, posicion, estado;
    char marca;

    do {
        tablero.mostrar();
        if (jugador == 1) {
            cout << "Jugador, ingresa tu movimiento (1-9): ";
            cin >> posicion;
            if (!tablero.mover(posicion, 'O')) {
                cout << "Movimiento inválido, intenta de nuevo.\n";
                continue;
            }
        } else {
            int mejorMovimiento = obtenerMejorMovimiento(tablero, usarPoda);
            tablero.mover(mejorMovimiento, 'X');
            cout << "La IA juega en la posición " << mejorMovimiento << ".\n";
        }

        estado = tablero.verificarEstado();
        if (estado != -2) break;
        jugador = 3 - jugador;
    } while (true);

    tablero.mostrar();
    if (estado == 0) cout << "¡Es un empate!\n";
    else if (estado == 1) cout << "¡La IA gana!\n";
    else cout << "¡Felicidades! Has ganado.\n";
}

// Menú principal
int main() {
    Tablero tablero;
    int opcion;

    do {
        cout << "\n--- JUEGO DEL GATO ---\n";
        cout << "1. Dos jugadores\n";
        cout << "2. Jugar contra la IA (Minimax sin poda)\n";
        cout << "3. Jugar contra la IA (Minimax con poda Alfa-Beta)\n";
        cout << "4. Salir\n";
        cout << "Selecciona una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                tablero.reiniciar();
                modoDosJugadores(tablero);
                break;
            case 2:
                tablero.reiniciar();
                modoContraIA(tablero, false);
                break;
            case 3:
                tablero.reiniciar();
                modoContraIA(tablero, true);
                break;
            case 4:
                cout << "¡Gracias por jugar!\n";
                break;
            default:
                cout << "Opción inválida. Intenta de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}
