#include <iostream>
#include <vector>
using namespace std;

// Clase Tablero
class Tablero 
{
    private:
        vector<char> tablero;
        int movimientos;

    public:
        Tablero() : tablero(10), movimientos(0) 
        {
            for (int i = 1; i <= 9; ++i)
            {
                tablero[i] = '0' + i;
            }
        }

        void mostrar() 
        {
            cout << "\n   |   |   \n";
            cout << " " << tablero[1] << " | " << tablero[2] << " | " << tablero[3] << "\n";
            cout << "___|___|___\n";
            cout << "   |   |   \n";
            cout << " " << tablero[4] << " | " << tablero[5] << " | " << tablero[6] << "\n";
            cout << "___|___|___\n";
            cout << "   |   |   \n";
            cout << " " << tablero[7] << " | " << tablero[8] << " | " << tablero[9] << "\n";
            cout << "   |   |   \n";
        }

        bool mover(int posicion, char marca) 
        {
            if (posicion < 1 || posicion > 9 || tablero[posicion] != '0' + posicion) 
            {
                return false;
            }
            tablero[posicion] = marca;
            movimientos++;
            return true;
        }

        int verificarEstado() 
        {
            for (int i = 1; i <= 7; i += 3) 
            {
                if (tablero[i] == tablero[i + 1] && tablero[i + 1] == tablero[i + 2])
                {
                    if (tablero[i] == 'X') 
                    {
                        return 1;
                    } 
                    else 
                    {
                        return -1;
                    }
                }
            }
            for (int i = 1; i <= 3; ++i) 
            {
                if (tablero[i] == tablero[i + 3] && tablero[i + 3] == tablero[i + 6]) 
                {
                    if (tablero[i] == 'X') 
                    {
                        return 1;
                    } 
                    else 
                    {
                        return -1;
                    }
                }
            }
            if (tablero[1] == tablero[5] && tablero[5] == tablero[9])
            {
                if (tablero[1] == 'X') 
                    {
                        return 1;
                    } 
                    else 
                    {
                        return -1;
                    }
            }
            if (tablero[3] == tablero[5] && tablero[5] == tablero[7])
            {
                if (tablero[3] == 'X') 
                    {
                        return 1;
                    } 
                    else 
                    {
                        return -1;
                    }
            }
            if (movimientos == 9) 
            {
                return 0;
            } 
            else 
            {
                return -2;
            }
        }

        void reiniciar() 
        {
            for (int i = 1; i <= 9; ++i)
            {
                tablero[i] = '0' + i;
            }
            movimientos = 0;
        }

        vector<int> movimientosDisponibles() 
        {
            vector<int> disponibles;
            for (int i = 1; i <= 9; ++i) 
            {
                if (tablero[i] == '0' + i)
                {
                    disponibles.push_back(i);
                }
            }
            return disponibles;
        }

        void deshacerMovimiento(int posicion) 
        {
            tablero[posicion] = '0' + posicion;
            movimientos--;
        }

        char obtenerCasilla(int posicion) 
        {
            return tablero[posicion];
        }

        void mostrarReglas() 
        {
            cout << "\n--- Reglas del Juego ---\n";
            cout << "1. El juego se juega en un tablero de 3x3.\n";
            cout << "2. Los jugadores se alternan para colocar su marca (X o O) en una casilla vacía.\n";
            cout << "3. Las casillas están numeradas del 1 al 9 como se muestra a continuación:\n";
            cout << "   |   |   \n";
            cout << " 1 | 2 | 3 \n";
            cout << "___|___|___\n";
            cout << "   |   |   \n";
            cout << " 4 | 5 | 6 \n";
            cout << "___|___|___\n";
            cout << "   |   |   \n";
            cout << " 7 | 8 | 9 \n";
            cout << "   |   |   \n";
            cout << "4. Un jugador gana si logra alinear tres de sus marcas en una fila, columna o diagonal.\n";
            cout << "5. Si todas las casillas se llenan y no hay ganador, el juego termina en empate.\n";
            cout << "6. El juego puede ser jugado por dos jugadores humanos o por un jugador contra la IA.\n";
            cout << "7. Los jugadores deben ingresar un número entre 1 y 9 para hacer su movimiento.\n";
            cout << "8. En caso de que un jugador intente mover en una casilla ya ocupada o fuera de rango, el movimiento será inválido.\n";
            cout << "¡Que comience el juego! ¡Diviértete!\n";
        }
};
        
};

// Algoritmo Minimax
int minimax(Tablero &tablero, bool esMax, int profundidad = 0) 
{
    int estado = tablero.verificarEstado();
    if (estado != -2)
    { 
        return estado;
    }
    int mejor;
    if (esMax) 
    {
        mejor = -9999;
    } 
    else 
    {
        mejor = 9999;
    }  
    for (int mov : tablero.movimientosDisponibles()) 
    {
        char marca;
        if (esMax)  
        {
            marca = 'X';
        } 
        else    
        {
            marca = 'O';
        }
        tablero.mover(mov, marca);
        int evaluacion = minimax(tablero, !esMax, profundidad + 1);  
        if (esMax) 
        {
            mejor = max(mejor, evaluacion);
        } 
        else 
        {
            mejor = min(mejor, evaluacion);
        }
        tablero.deshacerMovimiento(mov); 
    }
    return mejor;
}

// Algoritmo Minimax con poda Alfa-Beta
int minimaxAlfaBeta(Tablero &tablero, bool esMax, int alfa, int beta, int profundidad = 0) 
{
    int estado = tablero.verificarEstado();
    if (estado != -2)
    {
        return estado;
    }
    int mejor;
    if (esMax) 
    {
        mejor = -9999;
    } 
    else 
    {
        mejor = 9999;
    } 

    for (int mov : tablero.movimientosDisponibles()) 
    {
        if (esMax) 
        {
            tablero.mover(mov, 'X');
        } 
        else 
        {
            tablero.mover(mov, 'O');
        }       
        int evaluacion = minimaxAlfaBeta(tablero, !esMax, alfa, beta, profundidad + 1); 
        if (esMax) 
        {
            mejor = max(mejor, evaluacion);  
            alfa = max(alfa, mejor);  
        } 
        else 
        {
            mejor = min(mejor, evaluacion);  
            beta = min(beta, mejor);  
        }
        if (beta <= alfa) 
        {
            tablero.deshacerMovimiento(mov);  
            break;
        }
        tablero.deshacerMovimiento(mov);  
    }
    return mejor;
}

// Función para obtener el mejor movimiento con un algoritmo
int obtenerMejorMovimiento(Tablero &tablero, bool usarPoda) 
{
    int mejorValor = -9999;  
    int mejorMovimiento = -1;

    for (int mov : tablero.movimientosDisponibles()) 
    {
        tablero.mover(mov, 'X');
        int valor;
        if (usarPoda) 
        {
            valor = minimaxAlfaBeta(tablero, false, -9999, 9999);
        } 
        else 
        {
            valor = minimax(tablero, false, 0);
        }
        tablero.deshacerMovimiento(mov);

        if (valor > mejorValor) 
        {
            mejorValor = valor;
            mejorMovimiento = mov;
        }
    }
    return mejorMovimiento;
}


void modoDosJugadores(Tablero &tablero) 
{
    int jugador = 1, posicion, estado;
    char marca;

    do {
        tablero.mostrar();
        if (jugador == 1) 
        {
            marca = 'X';
        } 
        else 
        {
            marca = 'O';
        }
        cout << "Jugador " << jugador << ", ingresa tu movimiento (1-9): ";
        cin >> posicion;

        if (!tablero.mover(posicion, marca)) 
        {
            cout << "Movimiento inválido, intenta de nuevo.\n";
            continue;
        }

        estado = tablero.verificarEstado();
        if (estado != -2)
        { 
            break;
        }
        jugador = 3 - jugador;
    } while (true);

    tablero.mostrar();
    if (estado == 0)
    {
        cout << "¡Es un empate!\n";
    }
    else
    {
        int jugador;
        if (estado == 1)
        {
            jugador = 1;
        } 
        else 
        {
            jugador = 2;
        }
        cout << "¡Felicidades! El Jugador " << jugador << " gana.\n";
    }
}

// Modo IA contra el jugador
void modoContraIA(Tablero &tablero, bool usarPoda) 
{
    int jugador = 1, posicion, estado;
    char marca;

    do {
        tablero.mostrar();
        if (jugador == 1) 
        {
            cout << "Jugador, ingresa tu movimiento (1-9): ";
            cin >> posicion;
            if (!tablero.mover(posicion, 'O')) 
            {
                cout << "Movimiento inválido, intenta de nuevo.\n";
                continue;
            }
        } 
        else 
        {
            int mejorMovimiento = obtenerMejorMovimiento(tablero, usarPoda);
            tablero.mover(mejorMovimiento, 'X');
            cout << "La IA juega en la posición " << mejorMovimiento << ".\n";
        }

        estado = tablero.verificarEstado();
        if (estado != -2)
        { 
            break;
        }
        jugador = 3 - jugador;
    } while (true);

    tablero.mostrar();
    if (estado == 0)
    {
        cout << "¡Es un empate!\n";
    }
    else if (estado == 1)
    {
        cout << "¡La IA gana!\n";
    }
    else
    {
        cout << "¡Felicidades! Has ganado.\n";
    }
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
        cout << "4. Ver reglas\n";
        cout << "5. Salir\n";
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
                tablero.mostrarReglas();
                break;
            case 5:
                cout << "¡Gracias por jugar!\n";
                break;
            default:
                cout << "Opción inválida. Intenta de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}
