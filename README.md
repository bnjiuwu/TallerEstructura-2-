# TallerEstructura-2-
Aca se realizara el taller 2 de estructra de datos
============== Alumnos ===================
Benjamin Vega 21648877-6, Claudio Monsalve 21724524-9
=========================================================================================================================================

Instrucciones para Ejecutar el Programa en GitHub Codespaces:

1. Instalar el compilador g++:
    - Abra una terminal en su GitHub Codespace.
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
