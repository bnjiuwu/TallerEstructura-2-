#include <iostream>
#include <vector>
using namespace std;

// Clase Tablero
class Tablero {
private:
    vector<char> board; // Tablero de 9 posiciones
    int moves;          // Número de movimientos realizados

public:
    // Constructor inicializa el tablero
    Tablero() : board(10), moves(0) {
        for (int i = 1; i <= 9; ++i) board[i] = '0' + i;
    }

    // Muestra el estado actual del tablero
    void mostrar() {
        cout << "\nJugador 1 (X)  -  Jugador 2 (O)\n\n";
        cout << "   |   |   \n";
        cout << " " << board[1] << " | " << board[2] << " | " << board[3] << "\n";
        cout << "___|___|___\n";
        cout << "   |   |   \n";
        cout << " " << board[4] << " | " << board[5] << " | " << board[6] << "\n";
        cout << "___|___|___\n";
        cout << "   |   |   \n";
        cout << " " << board[7] << " | " << board[8] << " | " << board[9] << "\n";
        cout << "   |   |   \n";
    }

    // Realiza un movimiento en el tablero
    bool mover(int posicion, char marca) {
        if (posicion < 1 || posicion > 9 || board[posicion] != '0' + posicion) {
            return false; // Movimiento inválido
        }
        board[posicion] = marca;
        moves++;
        return true; // Movimiento válido
    }

    // Verifica si hay un ganador o empate
    int verificarEstado() {
        // Revisión horizontal
        if (board[1] == board[2] && board[2] == board[3]) return 1;
        if (board[4] == board[5] && board[5] == board[6]) return 1;
        if (board[7] == board[8] && board[8] == board[9]) return 1;

        // Revisión vertical
        if (board[1] == board[4] && board[4] == board[7]) return 1;
        if (board[2] == board[5] && board[5] == board[8]) return 1;
        if (board[3] == board[6] && board[6] == board[9]) return 1;

        // Revisión diagonal
        if (board[1] == board[5] && board[5] == board[9]) return 1;
        if (board[3] == board[5] && board[5] == board[7]) return 1;

        // Empate (si todas las posiciones están ocupadas)
        if (moves == 9) return 0;

        // Aún no hay ganador
        return -1;
    }
};

// Función principal del juego
int main() {
    Tablero tablero;
    int jugador = 1, estado = -1, posicion;
    char marca;

    cout << "\n\n\t¡BIENVENIDO AL JUEGO DEL GATO!\n\n";

    do {
        tablero.mostrar();

        // Determinar el jugador actual
        jugador = (jugador % 2) ? 1 : 2;
        marca = (jugador == 1) ? 'X' : 'O';

        bool movimientoValido = false;

        // Solicitar y validar movimiento
        while (!movimientoValido) {
            cout << "Jugador " << jugador << ", ingresa tu movimiento (1-9): ";
            cin >> posicion;

            // Validar entrada
            if (cin.fail()) {
                cin.clear();                // Restablecer el estado de cin
                cin.ignore(1000, '\n');     // Descartar entrada inválida
                cout << "Entrada inválida. Ingresa un número entre 1 y 9.\n";
            } else if (posicion < 1 || posicion > 9) {
                cout << "Posición fuera de rango. Ingresa un número entre 1 y 9.\n";
            } else if (!tablero.mover(posicion, marca)) {
                cout << "Posición ocupada. Intenta de nuevo.\n";
            } else {
                movimientoValido = true; // Movimiento válido
            }
        }

        // Verificar estado del juego
        estado = tablero.verificarEstado();
        jugador++;

    } while (estado == -1); // Continuar hasta que haya un ganador o empate

    tablero.mostrar();

    if (estado == 1) {
        cout << "¡Felicidades! El Jugador " << --jugador << " gana.\n";
    } else {
        cout << "¡Es un empate!\n";
    }

    return 0;
}
