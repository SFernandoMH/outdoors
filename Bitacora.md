# Bitácora de desarrollo

> Una entrada por cada avance, la más reciente arriba. Se escribe en el momento de terminar cada fase, justo después del commit.

## Plantilla de entrada

```
### AAAA-MM-DD · Fase N · Título corto
- **Autor:**
- **Qué se hizo:**
- **Decisiones de diseño (y por qué):**
- **Pilar de POO aplicado:**
- **Archivos tocados:**
- **Commit(s):**
- **Pendiente / siguiente paso:**
```

---

### 2026-11-08 · Fase 3 · Habitaciones y movimiento
- **Autor:** SFernandoMH
- **Qué se hizo:** Se implementó `Room` (descripción, estantes, entidades y puertas, con límites `MAX_SHELVES` y `MAX_DOORS`, métodos `addShelf`, `addEntity`, `addDoor` y `applySlam`). Se probó el portazo en `main` con estantes de distinta resistencia. Se creó `Game` con `buildMap()` y `run()`, y se agregó `getOtherRoom()` a `Door`. El jugador ya puede moverse entre dos habitaciones.
- **Decisiones de diseño (y por qué):**
    - El constructor de `Room` solo recibe la descripción; el mapa se arma aparte en `Game::buildMap()`, para que cada habitación sea distinta sin complicar el constructor.
    - `Room` es dueña de sus estantes y entidades (composición) y los libera en su destructor, pero no de las puertas, porque cada puerta pertenece a dos habitaciones; las libera `Game`.
    - Declaración adelantada (`class Room;`) entre `Door` y `Room` para evitar la dependencia circular de includes.
    - Los límites de estantes y puertas son constantes `static const` de la clase.
- **Pilar de POO aplicado:** Encapsulamiento (vectores privados con métodos de acceso que validan límites). Composición y agregación entre clases.
- **Archivos tocados:** `Room.h/.cpp`, `Game.h/.cpp`, `Door.h/.cpp`, `main.cpp`.
- **Commit(s):** *(completar)*
- **Pendiente / siguiente paso:** Abrir y cerrar puertas con fuerza desde el menú, enemigos, combate por turnos y objetos en estantes.

### 2026-11-07 · Fase 2 · Objetos, estantes y puertas
- **Autor:** SFernandoMH
- **Qué se hizo:** Se diseñaron e implementaron `Item` (con `Bandage` y `Spell`), `Shelf` y `Door`. Se actualizó el diagrama UML con las relaciones de herencia, composición, agregación y asociación.
- **Decisiones de diseño (y por qué):**
    - Se eliminó la clase intermedia `Enemy`: no aportaba comportamiento, y las dos criaturas heredan directamente de `Entity`.
    - `Item` es abstracta; el inventario es `std::vector<Item*>` y `Player` libera los objetos en su destructor.
    - Venda y hechizo son de un solo uso: se marcan como usados y `Player` los borra del inventario, porque el dueño de un objeto es quien debe liberarlo, no el objeto mismo.
    - `Shelf` hace `delete` de sus objetos cuando cae. Si el jugador saca un objeto, el estante lo quita del vector sin borrarlo.
    - `Door` tiene `open()` y `close(int force)` separados, porque cerrar necesita la fuerza del portazo y abrir no.
- **Pilar de POO aplicado:** Abstracción (`Item` abstracta), Herencia (`Bandage`, `Spell`), Polimorfismo (`use()` distinto en cada objeto).
- **Archivos tocados:** `Item`, `Bandage`, `Spell`, `Shelf`, `Door`, `Player`, `Entity`, diagrama UML.
- **Commit(s):** *(completar)*
- **Pendiente / siguiente paso:** `Room` y `Game`.

### 2026-10-29 · Fase 1 · Jerarquía de entidades
- **Autor:** SFernandoMH
- **Qué se hizo:** Se creó `Entity` (clase base abstracta) y `Player`, que hereda de ella. Se probó el ataque entre dos jugadores usando punteros.
- **Decisiones de diseño (y por qué):**
    - `Entity` tiene `attack(Entity& objective)` como método virtual puro, para que cada clase hija defina su propio ataque.
    - La vida y el daño se definen por clase: cada hija se los pasa al constructor de `Entity`, no se piden por teclado.
    - Se instancia con `Entity* gato = new Player();` para aprovechar el polimorfismo, y el destructor de `Entity` es virtual para liberar bien la memoria.
- **Pilar de POO aplicado:** Abstracción, Encapsulamiento, Herencia y Polimorfismo.
- **Archivos tocados:** `Entity.h/.cpp`, `Player.h/.cpp`, `main.cpp`, `CMakeLists.txt`.
- **Commit(s):** *(completar)*
- **Pendiente / siguiente paso:** Objetos, estantes y puertas.

### 2026-10-29 · Fase 0 · Repositorio y estructura
- **Autor:** SFernandoMH
- **Qué se hizo:** Se creó el repositorio en GitHub, el `README.md`, el `.gitignore` y la estructura de carpetas (`include/` y `src/`). Se configuró CMake en CLion con SFML 3.1.0.
- **Decisiones de diseño (y por qué):** Se desarrolla primero la versión de texto, que cumple el enunciado, y se deja SFML (2D, tiempo real) como mejora opcional según el tiempo. La lógica del juego se mantiene separada de la entrada y salida para poder cambiar de consola a gráficos sin reescribirla.
- **Pilar de POO aplicado:** — (aún sin código de clases)
- **Archivos tocados:** `README.md`, `.gitignore`, `CMakeLists.txt`.
- **Commit(s):** `Se inicia el proyecto`
- **Pendiente / siguiente paso:** `Entity` y `Player`.