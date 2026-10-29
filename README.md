# OUTDOORS

Juego de aventura 2D en C++ con SFML, hecho como proyecto final de Programación Orientada a Objetos (Pontificia Universidad Javeriana, 2026-2).

Un gato curioso sigue a un pequeño fantasma por una biblioteca infinita, de sección en sección, a través de puertas. Cada puerta es un cambio de nivel, y cerrarla con fuerza (un *door slam*) puede hacer caer estanterías sobre los enemigos... o sobre ti.

> **Estado:** en desarrollo.

## Integrantes

| Nombre | Usuario de GitHub |
|--------|-------------------|
| *(completar)* | *(completar)* |
| *(completar)* | *(completar)* |

## Controles

| Tecla | Acción |
|-------|--------|
| X | Ataque normal |
| C | Habilidad |
| V | Habilidad especial |
| E (toque) | Abrir o cerrar una puerta despacio |
| E (mantenida) | Cerrar la puerta con fuerza (portazo) |
| *(por definir)* | Movimiento |

## Requisitos

- Compilador de C++17 (en CLion con MinGW: **GCC 14.2.0 UCRT**, el mismo que usa SFML)
- CMake 3.28 o superior
- [SFML 3.1.0](https://www.sfml-dev.org/download/sfml/3.1.0/)

## Cómo compilar y ejecutar

1. Clonar el repositorio.
2. Descargar SFML 3.1.0 (versión **GCC 14.2.0 MinGW UCRT, 64-bit**) y extraerla en la raíz del proyecto, de modo que exista la carpeta `SFML-3.1.0/`. La carpeta no se sube al repositorio.
3. Abrir el proyecto en CLion, recargar CMake y ejecutar el objetivo `OUTDOORS`.

Las DLL de SFML se copian solas junto al ejecutable durante la compilación.

## Estructura

```
/
├── CMakeLists.txt
├── README.md
├── .gitignore
├── src/          # archivos .cpp
├── include/      # archivos .h
└── docs/         # documentación y entregables
```

## Cómo trabajamos

- Cada avance se sube en un commit pequeño, con un mensaje que dice qué cambió.
- Formato de mensaje: `tipo(área): descripción corta`.
  - Tipos: `feat` (algo nuevo), `fix` (corrección), `docs`, `refactor`, `test`.
  - Ejemplo: `feat(puerta): agrega estado abierta/cerrada`.
- Antes de subir, el código debe compilar.
- Cada integrante hace commits con su propia cuenta, para que los aportes sean visibles.
