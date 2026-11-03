# OUTDOORS

Juego de aventura en C++ hecho como proyecto final de Programación Orientada a Objetos (Pontificia Universidad Javeriana, 2026-2).

Un gato curioso sigue a un pequeño fantasma con audífonos por una biblioteca infinita, de sección en sección, a través de puertas. Cada puerta es un cambio de nivel, y cerrarla con fuerza (un *door slam*) puede hacer caer estanterías sobre los enemigos... o sobre ti. La meta es alcanzar al fantasma y hablar con él.

> **Estado:** en desarrollo. Versión de texto en construcción.

## Versiones del juego

| Versión | Descripción | Estado |
|---------|-------------|--------|
| **Texto (consola)** | Combate por turnos, habitaciones, puertas, estanterías e inventario. Es la versión de entrega. | En desarrollo |
| **Gráfica (SFML)** | Mismo juego en 2D y en tiempo real, con controles de teclado. | Planeada, depende del tiempo |

La lógica del juego (clases) está separada de la entrada y salida, para poder cambiar de la consola a SFML sin reescribirla.

## Mecánicas principales

- **Habitaciones y puertas:** el mundo es una serie de secciones de biblioteca conectadas por puertas. Se puede volver atrás.
- **Portazo:** al cerrar una puerta con suficiente fuerza, las estanterías de la sección vecina pueden caer y dañar a los enemigos. Las estanterías débiles también pueden caerle encima al gato.
- **Enemigos:** criaturas invisibles que reaccionan al ruido, seres negros de combate directo y peligros que dañan al contacto.
- **Habilidades del gato:** ataque normal, habilidad y habilidad especial.
- **Meta:** alcanzar al fantasma, que aparece de vez en cuando e ignora al gato, y hablar con él.

## Controles previstos

Versión gráfica (SFML):

| Tecla | Acción |
|-------|--------|
| X | Ataque normal |
| C | Habilidad |
| V | Habilidad especial |
| E (toque) | Abrir o cerrar una puerta despacio |
| E (mantenida) | Cerrar la puerta con fuerza (portazo) |
| *(por definir)* | Movimiento |

En la versión de texto, estas mismas acciones se eligen escribiendo la opción en cada turno.

## Hoja de ruta

- [x] Clase base abstracta `Entity` (con `attack()` virtual puro)
- [x] `Player`, el gato, que hereda de `Entity`
- [ ] `Shelf` (estantería) y `Room` (habitación)
- [ ] Dos tipos de enemigo con ataque propio
- [ ] Puertas y portazo
- [ ] Objetos e inventario (`std::vector`)
- [ ] Bucle del juego y combate por turnos
- [ ] Documento final y presentación
- [ ] Versión gráfica con SFML (opcional)

## Estructura del proyecto

```
/
├── CMakeLists.txt
├── README.md
├── .gitignore
├── include/      # archivos .h (Entity.h, Player.h, ...)
└── src/          # archivos .cpp (main.cpp, Entity.cpp, Player.cpp, ...)
```

## Pilares de la POO en el proyecto

| Pilar | Dónde se ve |
|-------|-------------|
| Encapsulamiento | Atributos `protected` en `Entity`, accedidos solo por métodos |
| Abstracción | `Entity` es abstracta: `attack()` es virtual puro |
| Herencia | `Player` y los enemigos heredan de `Entity` |
| Polimorfismo | Cada clase implementa su propio `attack()`; se usa mediante `Entity*` |

*(Se amplía a medida que se agregan clases.)*

## Requisitos

- Compilador de C++17 (en CLion con MinGW: **GCC 14.2.0 UCRT**, el mismo que usa SFML)
- CMake 3.28 o superior
- [SFML 3.1.0](https://www.sfml-dev.org/download/sfml/3.1.0/) (el `CMakeLists.txt` actual la busca)

## Cómo compilar y ejecutar

1. Clonar el repositorio.
2. Descargar SFML 3.1.0 (versión **GCC 14.2.0 MinGW UCRT, 64-bit**) y extraerla en la raíz del proyecto, de modo que exista la carpeta `SFML-3.1.0/`. Esa carpeta no se sube al repositorio.
3. Abrir el proyecto en CLion, recargar CMake y ejecutar el objetivo `OUTDOORS`.

## Cómo se trabaja

- Cada avance se sube en un commit pequeño que compila.
- Formato de mensaje: `tipo(área): descripción corta`.
  - Tipos: `feat` (algo nuevo), `fix` (corrección), `docs`, `refactor`, `test`.
  - Ejemplo: `feat(player): jugador hereda de Entity con attack`.

## Autor

| Nombre                        | Usuario de GitHub |
|-------------------------------|-------------------|
| Steven Fernando Muñoz Hurtado | SFernandoMH |