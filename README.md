# TallerEstructura-2-
Aca se realizara el taller 2 de estructra de datos
============== Alumnos ===================
Benjamin Vega 21648877-6 (C1), Claudio Monsalve 21724524-9 (C2)
=========================================================================================================================================

Instrucciones para ejecutar el programa en Codespaces:

1. Instalar el compilador g++:
    - Abra una terminal en su Codespace.
    - Ejecute los siguientes comandos para actualizar el sistema e instalar el compilador g++:
        - sudo apt update
        - sudo apt install g++
        - (Esto instalará el compilador de C++ necesario para compilar el programa).

2. Compilar el archivo main.cpp:
    - Asegurar de estar en el directorio donde se encuentra el archivo main.cpp. Puede usar el comando ls para listar los archivos en         el directorio.

    - Compile el archivo con el siguiente comando:
        - g++ -o gato main.cpp
        - (Este comando creará un archivo ejecutable llamado gato en el directorio actual).

3. Ejecutar el programa:
    - Una vez que el archivo se haya compilado correctamente, ejecute el programa con el siguiente comando:
        - ./gato
        - (Esto iniciará el juego, y podrá seleccionar el modo de juego (Dos jugadores, Jugar contra la IA sin poda, Jugar contra la IA           con poda Alfa-Beta) y comenzar a jugar).
   
====================================================================================

Explicación del Algoritmo Utilizado:

1. Clase Tablero: 
    - Es la encargada de gestionar el estado del juego y permitir la interacción entre los jugadores (incluyendo la IA).

    - Métodos:
        - mostrar(): Muestra el estado actual del tablero en la consola.
        - mover(int posicion, char marca): Coloca la marca ('X' o 'O') en la posición indicada si está disponible.
        - verificarEstado(): Determina si alguien ganó, hubo empate o el juego sigue en curso.
        - reiniciar(): Restablece el tablero para una nueva partida.
        - movimientosDisponibles(): Devuelve una lista con las casillas libres para jugar.
        - deshacerMovimiento(int posicion): Revierte un movimiento realizado previamente.
        - obtenerCasilla(int posicion): Devuelve el valor de una casilla específica en el tablero.
        - mostarReglas(): Muestra las reglas del juego.


     
2. Algoritmo Minimax:
    - Este algoritmo permite a la IA analizar todas las posibles jugadas y escoger la mejor para maximizar sus posibilidades de ganar.

    - Parámetros:
        - tablero: Objeto que representa el estado actual del juego.
        - esMax: Indica si es turno de la IA (true) o del jugador humano (false).
        - profundidad: Define hasta cuántas jugadas hacia adelante se exploran.
          
    - Funcionamiento:
        - Evalúa todas las jugadas posibles para ambos jugadores (IA y humano).
        - Escoge la opción que maximiza la puntuación de la IA y minimiza las oportunidades del jugador.
        - Asignación de Valores: Los estados terminales del juego (victoria, derrota, empate) se valoran con
            - 1 si la IA gana.
            - -1 si el jugador gana.
            - 0 si es empate.


         
3. Poda Alfa-Beta:
    - Mejora la eficiencia del algoritmo Minimax al evitar explorar ramas del árbol de decisiones que no afectan el resultado.

    - Funcionamiento:
        - La función minimaxAlfaBeta() toma los siguientes parámetros importantes:
            - tablero: Objeto que representa el estado actual del juego.
            - esMax: Indica si es turno de la IA (true) o del jugador humano (false).
            - alfa: El mejor valor conocido para el jugador MAX (IA).
            - beta: El mejor valor conocido para el jugador MIN (humano).
            - profundidad: Número máximo de niveles a explorar.
              
    - Funcionamiento de la Poda:
        - Si un movimiento no mejora el resultado para un jugador (con base en alfa y beta), se deja de explorar esa rama.
        - Alfa se utiliza para maximizar el valor de la IA (MAX), y Beta se utiliza para minimizar el valor del jugador humano (MIN).
        - Si el valor de una jugada es peor que alfa (en el caso de MIN) o mejor que beta (en el caso de MAX), la rama se poda porque             ya no afectará el resultado final.



4. Función obtenerMejorMovimiento():
    - Es la encargada de seleccionar el mejor movimiento para la IA en cada turno.

    - Parámetros:
        - tablero: Objeto con el estado actual del juego.
        - usarPoda: Si es true, utiliza poda Alfa-Beta; si es false, usa Minimax básico.
          
    - Funcionamiento:
        - La función recorre todas las posiciones vacías del tablero.
        - Simula cada jugada utilizando Minimax o Minimax con poda Alfa-Beta, dependiendo del modo.
        - Después de evaluar todos los movimientos posibles, selecciona el movimiento con el valor más alto.
        - Revierte el tablero después de evaluar cada jugada para seguir probando las demás.



5. Modos de Juego:
    - El juego ofrece dos modos:
        - Dos Jugadores: Donde dos personas juegan alternando turnos para hacer sus movimientos en el tablero.
        - Jugador vs. IA: La IA utiliza el algoritmo Minimax para tomar decisiones, y se puede elegir si la IA usa el                             algoritmo con poda Alfa-Beta o sin poda.
          
====================================================================================

Explicación Teórica del Algoritmo Minimax y la Poda Alfa-Beta:

1. Algoritmo Minimax
    - El algoritmo Minimax es una técnica de decisión utilizada principalmente en juegos de dos jugadores (donde ambos jugadores conocen el estado completo del juego, como en el Ajedrez o el Gato). El objetivo es encontrar el movimiento óptimo para el jugador actual, asumiendo que ambos jugadores juegan de manera perfecta.

    - Conceptos Clave:
        - Árbol de decisiones: Representa todos los estados posibles del juego desde el estado actual. Cada nodo es un estado y las                                    ramas son los movimientos
        - Las hojas del árbol: Son los estados terminales (victoria, derrota o empate).
          
    - Jugadores:
        - Los jugadores se turnan para realizar movimientos.
        - MAX: Busca maximizar su ganancia.
        - MIN: Busca minimizar la ganancia de MAX.
      
    - Evaluación de estados:
        - Cada estado terminal se evalúa asignando un puntaje:
            - Un valor positivo si gana MAX.
            - Un valor negativo si gana MIN.
            - Un valor de 0 si el juego termina en empate.
          
    - Propagación de valores:
        - En los nodos donde juega MAX, se selecciona el valor mas alto.
        - En los nodos donde juega MIN, se selecciona el valor mínimo.
          
     
2. Poda Alfa-Beta:
    - Es una técnica de optimización para algoritmos que realizan búsquedas en árboles de decisiones. Su objetivo es reducir la               cantidad de nodos explorados al descartar ramas que no pueden influir en el resultado final.

    - Conceptos Clave:
        - Alfa y Beta:
            - Alfa: Mejor resultado conocido para MAX.
            - Beta: Mejor resultado conocido para MIN.
    - Podar ramas innecesarias:
        - Si un movimiento no puede mejorar el resultado actual, se descarta
        - MAX ignora jugadas con un valor ≤ Alfa.
        - MIN ignora jugadas con un valor ≥ Beta.
              
====================================================================================

Diagrama de arbol de juego para un caso simple

![diagrama](https://github.com/user-attachments/assets/3c9b0854-8e87-4f48-b73a-5e9090e5acdc)

====================================================================================

Análisis de Complejidad Temporal del Algoritmo:

El desempeño del algoritmo Minimax depende de dos factores principales:
- Factor de ramificación (b): Número de movimientos posibles en cada turno.
- Profundidad del árbol (d): Número máximo de turnos restantes en el juego.
    
A continuación, se compara la complejidad temporal antes y después de aplicar la optimización de poda Alfa-Beta.

1. Minimax sin Poda:
    - Evalúa todas las ramas del árbol de decisiones, lo que lleva a un crecimiento exponencial en el número de nodos explorados
    - Complejidad:
            𝑂(𝑏^d)
      - Donde:
        - b: Movimientos posibles por turno..
        - d: Profundidad máxima del árbol.

   
    - Ejemplo práctico en el juego del Gato:
        - 𝑏: Comienza en 9 y disminuye a medida que se ocupan casillas.
        - 𝑑: Máximo de 9 turnos.
        - El árbol completo tendría 9! = 362,880 estados posibles.
    
    - Aunque es manejable en juegos pequeños como el Gato, sin optimización se vuelve impráctico en juegos más                                complejos debido al crecimiento exponencial del número de nodos.
   

2. Minimax con Poda Alfa-Beta:
    - La poda Alfa-Beta mejora significativamente la eficiencia del algoritmo Minimax al descartar ramas que no afectan el resultado           final.
    - Complejidad:
            - 𝑂(𝑏^(𝑑/2)
   
    - En el mejor caso, reduce el número de nodos explorados drásticamente.
    - Ejemplo práctico en el juego del Gato:
        - Con poda Alfa-Beta, el número de estados explorados se reduce aproximadamente a:
            - (raiz(9))^9 = 19,683 estados explorados.

   - Comparado con los 362,880 estados de Minimax sin poda, la mejora es evidente.

3. Conclusión:
    - Sin optimización, el algoritmo Minimax es poco práctico en juegos complejos por su crecimiento exponencial.
    - Con poda Alfa-Beta, el número de nodos explorados se reduce considerablemente, permitiendo manejar profundidades mayores en menos        tiempo.
    - Aunque en juegos pequeños como el Gato la diferencia en tiempo no es tan evidente, en juegos más complejos la poda Alfa-Beta es         esencial para que el algoritmo sea práctico.

====================================================================================

