# TallerEstructura-2-
Aca se realizara el taller 2 de estructra de datos
============== Alumnos ===================
Benjamin Vega 21648877-6, Claudio Monsalve 21724524-9
=========================================================================================================================================

Instrucciones para ejecutar el programa en Codespaces:

1. Instalar el compilador g++:
    - Abra una terminal en su Codespace.
    - Ejecute los siguientes comandos para actualizar el sistema e instalar el compilador g++:
        - sudo apt update
        - sudo apt install g++
        - (Esto instalará el compilador de C++ necesario para compilar el programa).

2. Compilar el archivo main.cpp:
    - Asegure de estar en el directorio donde se encuentra el archivo main.cpp. Si no está seguro, puede usar el comando ls para listar los archivos en el directorio.

    - Compile el archivo con el siguiente comando:
        - g++ -o gato main.cpp
        - (Este comando creará un archivo ejecutable llamado gato en el directorio actual).

3. Ejecutar el programa:
    - Una vez que el archivo se haya compilado correctamente, ejecute el programa con el siguiente comando:
        - ./gato
        - (Esto iniciará el juego, y podrá seleccionar el modo de juego (Dos jugadores, Jugar contra la IA sin poda, Jugar contra la IA             con poda Alfa-Beta) y comenzar a jugar).
   
====================================================================================

Explicación del Algoritmo Utilizado:
1. Clase Tablero: 
    - La clase Tablero gestiona el estado del juego y los movimientos de los jugadores. Proporciona las funcionalidades necesarias           para que tanto el jugador como la IA puedan interactuar con el tablero.

    - Métodos clave:
        - mostrar(): Muestra el estado actual del tablero en la consola.
        - mover(int posicion, char marca): Realiza un movimiento en una posición específica, colocando la marca ('X' o 'O').
        - verificarEstado(): Verifica si el juego ha terminado, indicando el ganador o un empate.
        - reiniciar(): Restaura el tablero a su estado inicial.
        - movimientosDisponibles(): Devuelve un vector con las posiciones disponibles en el tablero.
        - deshacerMovimiento(int posicion): Revierte un movimiento realizado previamente.
        - obtenerCasilla(int posicion): Devuelve el valor de una casilla específica en el tablero.


     
2. Algoritmo Minimax:
    - El algoritmo Minimax se utiliza para que la IA (jugador MAX) decida el mejor movimiento posible en el juego, evaluando todas las jugadas disponibles y simulando las jugadas de ambos jugadores. La IA selecciona la jugada que maximiza su puntuación y minimiza las del jugador humano (jugador MIN).

    - Parámetros:
        - tablero: Representa el estado actual del juego. Es un objeto que contiene el tablero con las posiciones de las casillas y                        permite simular los movimientos.
        - esMax: Indica si es el turno de la IA (cuando es true, la IA busca maximizar su puntuación; cuando es false, el jugador                        humano busca minimizar la puntuación de la IA).
        - profundidad: Un parámetro opcional que limita la profundidad de la exploración en el árbol de decisiones. Mientras más                               profunda sea la búsqueda, más jugadas futuras se consideran.
    - Funcionamiento:
        - Evaluación Recursiva: La función minimax() simula las jugadas posibles y las evalúa, considerando las jugadas tanto de la IA            como del jugador humano. Para cada movimiento, se evalúa el resultado de la partida (victoria, derrota, empate).
        - Decisión de la IA: Si es el turno de la IA, el algoritmo selecciona la jugada que maximiza su puntuación. Si es el turno del            jugador humano, selecciona la jugada que minimiza las posibilidades de la IA.
        - Asignación de Valores: Los estados terminales del juego (victoria, derrota, empate) se valoran con:
              - 1 si la IA gana.
              - -1 si el jugador gana.
              - 0 si es empate.


         
3. Poda Alfa-Beta:
    -La poda Alfa-Beta es una optimización del algoritmo Minimax que mejora su eficiencia al reducir el número de nodos explorados, descartando aquellas ramas del árbol de decisiones que no afectarán el resultado final.

    - Funcionamiento:
        - La función minimaxAlfaBeta() toma los siguientes parámetros importantes:
            - tablero: Representa el estado actual del juego, que se va actualizando conforme a los movimientos realizados.
            - esMax: Indica si es el turno de la IA (MAX) o del jugador humano (MIN).
            - alfa: El mejor valor conocido hasta ahora para la IA (MAX). A medida que el algoritmo evalúa las jugadas, alfa se                       actualiza si se encuentra un valor mejor.
            - beta: El mejor valor conocido hasta ahora para el jugador humano (MIN). Al igual que alfa, beta se actualiza con cada                   evaluación.
            - profundidad: Controla el nivel de profundidad en el árbol de decisiones, limitando la cantidad de jugadas evaluadas.
              
    - Funcionamiento de la Poda:
        - Durante la exploración de los nodos, el algoritmo evalúa los posibles movimientos de ambos jugadores. Si encuentra un valor             que no puede mejorar el resultado para uno de los jugadores (basado en los valores de alfa y beta), esa rama del árbol se               descarta.
        - Alfa se utiliza para maximizar el valor de la IA (MAX), y beta se utiliza para minimizar el valor del jugador humano (MIN).
        - Si el valor de una jugada es peor que alfa (en el caso de MIN) o mejor que beta (en el caso de MAX), la rama se poda porque             ya no afectará el resultado final.



4. Función obtenerMejorMovimiento():
    - La función es responsable de elegir el mejor movimiento para la IA. Evalúa todas las posiciones disponibles y selecciona la que genere el mejor resultado, utilizando el algoritmo Minimax o Minimax con poda Alfa-Beta, según el modo seleccionado.

    - Parámetros:
        - tablero: Es el objeto que contiene el estado actual del juego. Se pasa por referencia para que la función pueda modificar el                     tablero y simular los movimientos de la IA.
        - usarPoda: Un valor booleano que indica si la poda Alfa-Beta debe ser utilizada. Si es true, la función emplea la poda Alfa-                        Beta para mejorar la eficiencia al evaluar las jugadas; si es false, utiliza el algoritmo Minimax sin poda.
          
    - Funcionamiento:
        - La función recorre todas las posiciones vacías del tablero.
        - Para cada posible movimiento, simula la jugada y evalúa el resultado utilizando el algoritmo Minimax o Minimax con poda Alfa-           Beta.
        - Después de evaluar todos los movimientos posibles, selecciona el movimiento con el valor más alto.
        - Deshace los movimientos simulados para seguir evaluando las opciones restantes.
        - Este método asegura que la IA elija siempre el mejor movimiento disponible en cada turno.



5. Modos de Juego:
    - El juego ofrece dos modos:
        - Dos Jugadores: Donde dos personas juegan alternando turnos para hacer sus movimientos en el tablero.
        - Jugador vs. IA: Donde el jugador se enfrenta a la IA. La IA utiliza el algoritmo Minimax para tomar decisiones, y se puede e            legir si la IA usa el algoritmo con poda Alfa-Beta o sin poda.
    - Modo IA:
        - El jugador puede elegir entre jugar contra una IA que usa Minimax sin poda o Minimax con poda Alfa-Beta para mejorar la                 eficiencia.
          
====================================================================================

Explicación Teórica del Algoritmo Minimax y la Poda Alfa-Beta:

1. Algoritmo Minimax
    - El algoritmo Minimax es una técnica de decisión utilizada principalmente en juegos de dos jugadores (donde ambos jugadores conocen el estado completo del juego, como en el Ajedrez o el Gato). El objetivo es encontrar el movimiento óptimo para el jugador actual, asumiendo que ambos jugadores juegan de manera perfecta.

    - Conceptos Clave:
        - Árbol de decisiones: Cada nodo en el árbol representa un estado del juego.
        - Las ramas: Representan posibles movimientos.
        - Las hojas del árbol: Son los estados terminales (victoria, derrota o empate).
          
    - Turnos alternos:
        - Los jugadores se turnan para realizar movimientos.
        - Uno de ellos es MAX, que intenta maximizar su ganancia.
        - El otro es MIN, que intenta minimizar la ganancia de MAX.
      
    - Evaluación de estados:
        - Cada estado terminal se evalúa asignando un puntaje:
            - Un valor positivo (por ejemplo, +10) si gana MAX.
            - Un valor negativo (por ejemplo, -10) si gana MIN.
            - Un valor de 0 si el juego termina en empate.
          
    - Propagación de valores:
        - Los valores de las hojas del árbol (estados terminales) se propagan hacia arriba.
        - En los nodos donde juega MAX, se selecciona el valor máximo de las ramas.
        - En los nodos donde juega MIN, se selecciona el valor mínimo.
          
     
2. Poda Alfa-Beta:
    - Es una técnica de optimización para algoritmos que realizan búsquedas en árboles de decisiones. Su objetivo es reducir la cantidad de nodos explorados al descartar ramas que no pueden influir en el resultado final. Es ampliamente conocida por su uso en el algoritmo Minimax.

    - Conceptos Clave:
        - Alfa y Beta:
            - Alfa: El mejor valor garantizado para MAX en el camino actual.
            - Beta: El mejor valor garantizado para MIN en el camino actual.
    - Podar ramas innecesarias:
        - Si un nodo no puede proporcionar un mejor resultado que el rango actual de Alfa y Beta, se descarta (no se explora).
        - Esto ocurre cuando:
            - Para MAX: 𝑣𝑎𝑙𝑜𝑟 ≤ Alfa.
            - Para MIN: 𝑣𝑎𝑙𝑜𝑟 ≥ Beta.
              
================================================================

Análisis de Complejidad Temporal del Algoritmo:

El desempeño del algoritmo Minimax depende de dos factores principales:
- Factor de ramificación (b): Número de movimientos posibles en cada turno.
- Profundidad del árbol (d): Número máximo de turnos restantes en el juego.
    
A continuación, se compara la complejidad temporal antes y después de aplicar la optimización de poda Alfa-Beta.

1. Minimax sin Poda:
    - El algoritmo Minimax evalúa todas las ramas posibles del árbol de decisiones, lo que puede resultar de alto costo.
    - Complejidad:
            𝑂(𝑏^d)
      - Donde:
        - b es el número de movimientos posibles por turno.
        - d es la profundidad máxima del árbol de decisiones.

   
    - Ejemplo práctico en el juego del Gato:
        - 𝑏 = 9,8,7,... (número de casillas disponibles en cada turno).
        - 𝑑 = 9 (número máximo de turnos).
        - El árbol completo tendría 9! = 362, 880 estados posibles.
    
    - Aunque este número es manejable en juegos pequeños como el Gato, Minimax sin optimización se vuelve impráctico en juegos más             complejos como Connect 4 o Ajedrez, debido al crecimiento exponencial del número de nodos.
   

2. Minimax con Poda Alfa-Beta:
    - La poda Alfa-Beta mejora significativamente la eficiencia del algoritmo Minimax al descartar ramas que no afectan el resultado           final.
    - Complejidad optimizada:
            - 𝑂(𝑏^(𝑑/2)
   
    - En el mejor caso (cuando los nodos están perfectamente ordenados), el número de nodos explorados se reduce drásticamente.

    - Ejemplo práctico en el juego del Gato:
        - Con poda Alfa-Beta, el número de estados explorados se reduce aproximadamente a:
            - (raiz(9))^9 = 3^9 = 19,683 estados explorados.

   - Comparado con los 362,880 estados de Minimax sin poda, la mejora es evidente.

3. Conclusión:
    - Sin optimización, el algoritmo Minimax es costoso porque explora todos los nodos posibles.
    - Con poda Alfa-Beta, el número de nodos explorados se reduce considerablemente, permitiendo manejar profundidades mayores en menos        tiempo.
    - Aunque en juegos pequeños como el Gato la diferencia en tiempo no es tan evidente, en juegos más complejos la poda Alfa-Beta es          esencial para que el algoritmo sea práctico.

====================================================================================
