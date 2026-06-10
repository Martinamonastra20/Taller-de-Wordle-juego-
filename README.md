[README-wordle.md](https://github.com/user-attachments/files/28797766/README-wordle.md)
# Wordle en C++

Implementación del clásico juego **Wordle** para la terminal, en español, desarrollada como taller individual de la materia *Algoritmos y Estructuras de Datos*.

## El juego

Hay que adivinar una palabra secreta de 5 letras en un máximo de 6 intentos. Después de cada intento, el juego responde letra por letra:

- `X` → la letra está en la palabra secreta, en esa posición
- `-` → la letra está en la palabra, pero en otra posición
- (sin marca) → la letra no está en la palabra

Ejemplo de una partida:

```
Ruta al listado de palabras: ../listado.txt
La palabra secreta tiene 5 letras.
Te quedan 5 intentos
dejar
X--XX
Te quedan 4 intentos
subir
XXX-X
Te quedan 3 intentos
viejo
¡Correcto!
```

## Cómo funciona

- Al iniciar, el programa carga un diccionario de palabras de 5 letras desde un archivo de texto y elige una al azar como palabra secreta.
- Cada intento se **valida** contra el diccionario: si la palabra no es legal, se avisa al usuario y no se descuenta el intento.
- La lógica de evaluación compara el intento con la palabra secreta letra por letra para generar las pistas de posición.

## Estructura del código

| Archivo | Descripción |
|---|---|
| `lib.cpp` | Implementación de las funciones del juego: carga del diccionario, validación de intentos y evaluación letra por letra |
| `wordle.cpp` | Función `main` con el loop interactivo del juego |

El proyecto se desarrolló sobre un esqueleto provisto por la cátedra (con CMake y una suite de tests en Google Test), y la implementación pasa todos los tests automáticos.

## Tecnologías

C++ · CMake · Google Test
