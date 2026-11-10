#include "Game.h"

#include "Bandage.h"
#include "DarkBeing.h"
#include "iostream"
#include "Spell.h"
Game::Game() : player(new Player()), currentRoom(nullptr) , lastDoor(nullptr) {
    buildMap();
}

Game::~Game() {
    delete player;
    for (Room* room : rooms) {
        delete room;
    }
    for (Door* door : doors) {
        delete door;
    }

}

std::vector<Entity*> Game::getEntitiesCurrentRoom() const {
    return currentRoom->getEntities();
}

void Game::buildMap() {
    Room* entrada = new Room("Entrada de la biblioteca");
    Room* pasillo = new Room("Pasillo de libros");
    Room* esquinaMisteriosa = new Room("Esquina abandonada");

    rooms.push_back(entrada);
    rooms.push_back(pasillo);
    rooms.push_back(esquinaMisteriosa);

    //Entrada
    entrada->addShelf(new Shelf(3));
    entrada->addShelf(new Shelf(4));

    entrada->getShelves()[0]->addItem(new Spell("Aumento de dano x2", 2));
    for (Shelf* shelf : entrada->getShelves()) {
        shelf->addItem(new Bandage("Benda"));
    }

    //conexion entrada a pasillo

    Door* doorEPone = new Door(entrada, pasillo);
    doors.push_back(doorEPone);
    entrada->addDoor(doorEPone);
    pasillo->addDoor(doorEPone);


    //pasillo
    pasillo->addShelf(new Shelf(5));
    pasillo->addShelf(new Shelf(8));
    pasillo->addShelf(new Shelf(9));


    pasillo->getShelves()[2]->addItem(new Spell("Aumento de dano x4",4));
    pasillo->addEntity(new DarkBeing());

    //conexion pasillo a esquina

    Door* doorPEtwo = new Door(pasillo, esquinaMisteriosa);
    doors.push_back(doorPEtwo);
    pasillo->addDoor(doorPEtwo);
    esquinaMisteriosa->addDoor(doorPEtwo);

    //Esquina

    esquinaMisteriosa->addShelf(new Shelf(10));
    esquinaMisteriosa->getShelves()[0]->addItem(new Bandage("Botiquin")); // posible armadura

    esquinaMisteriosa->addEntity(new DarkBeing());
    esquinaMisteriosa->addEntity(new DarkBeing());



    //Por defecto inicias en entrada

    currentRoom = entrada;
}


int Game::showMenuRoom() const {
    std::cout << "Estas en: " << currentRoom->getDescription()<< "\n";
    if (currentRoom->hasLivinEntities()) {return 4;}
    std::cout<< "Que deseas hacer?\n"
                "0. Abandonar juego\n"
                "1. Que tengo en mi inventario?\n"
                "2. Revisar estanterias\n"
                "3. Abrir puertas\n"
                "4. Pelear contra enemigos\n>";
    int option;
    std::cin >> option;
    std::cout << "\n";
    return option;
}



void Game::showInventory() {
    int option;
    if (player->getInventory().empty()) {
        std::cout << "No tienes nada!\n";
        return;
    }
    std::cout << "Tienes: \n";
    for (size_t i = 0; i < player->getInventory().size(); i++) {
        std::cout << i + 1 << " . " << player->getInventory()[i]->getName() << "\n";
    }
    std::cout << "Quieres usar algo?\n1 . Si\n2 . No(salir)\n";
    std::cin >> option;
    if (option == 1) {
        std::cout << "Que quieres usar?\n>";
        std::cin >> option;
        std::cout << "Se uso " << player->getInventory()[option - 1]->getName() << "\n";
        player->useItem(option-1);
        return;
    } else {
        return;
    }
}

void Game::checkShelves() {
    std::vector<Shelf*> currentShelves= currentRoom->getShelves();
    if (currentShelves.empty()) {
        std::cout << "No hay ningun estante!\n";
        return;
    }
    for (size_t i = 0; i < currentShelves.size(); i++) {
        std::cout << i + 1 << ". Revisar la estanteria " <<  i + 1 << "\n";
    }
    std::cout << "0. Salir" << "\n";
    int option;
    std::cin >> option;

    if (option <=0 || option > currentShelves.size()) {
        std::cout << "Numero invalido!\n";
    }

    Shelf* shelf = currentShelves[option -1];
    if (shelf->getItemsOnIt().empty()) {
        std::cout << "El estante esta vacio\n";
        return;
    }

    Item* item = shelf->takeItem(0);        // saca el primero del estante
    while (item != nullptr) {
        player->addItem(item);              // pasa al inventario
        std::cout << "Obtuviste: " << item->getName() << "\n";
        item = shelf->takeItem(0);          // el siguiente
    }
    /*if (option == 0) {
        return;
    } else if (option >= 1 && option <= currentShelves.size()) {
        Shelf* shelf = currentShelves[option - 1];
        player->searchInShelf(shelf);
        for (Item* item : shelf->getItemsOnIt()) { // Eliminar items en el estante
            std::cout << "Obtuviste : " << item->getName() << "\n";
            currentRoom->removeitemFromShelf(option -1, item);
        }
        return;
    }*/
}

void Game::crossDoor() {
    int option;
    std::vector<Door*> exits = currentRoom->getDoors();
    for (size_t i = 0; i < exits.size(); i++) {
        std::cout << i + 1 << ". Abrir la puerta " << i + 1 << "\n";
    }
    std::cout << "0. Quedarse en la habitacion " << "\n";
    std::cin >> option;
    if (option == 0) {
        return;
    } else if (option >= 1 && option <= exits.size()) {
        Door* door = exits[option - 1];
        door->open();
        currentRoom = door->getOtherRoom(currentRoom);   // ahora estás en la nueva
        Room* previous = door->getOtherRoom(currentRoom); // la que dejaste

        std::cout << "1. Dejar la puerta abierta\n"
                     "2. Cerrar la puerta (suave)\n"
                     "3. Cerrar la puerta (fuerte)\n";
        int choice;
        std::cin >> choice;

        if (choice == 2) {
            door->close();
        } else if (choice == 3) {
            door->close();
            previous->applySlam(8);   // cae lo que la fuerza supere; daña a los enemigos
            for (Shelf* shelf : previous->getShelves()) {
                if (shelf->getisStanding() == false) {
                    std::cout << "Un estante de la habitacion " << previous->getDescription()<< " se cayo!\n";
                    std::cout << "le aplica 60 de dano a todas los enemigos!\n";
                    for (Entity* entity : previous->getEntities()) {
                        if (entity->isAlive() == false) {
                            std::cout << "Un enemigo murio\n";
                        }
                    }
                }
            }

        }
    }
}

void Game::fight() {




    std::vector<Entity*> enemies = currentRoom->getEntities();
    if (std::empty(enemies)) {
        std::cout << "No hay enemigos en esta habitacion!\n";
        return;
    }

    //Menu Pelea
    std::cout << "Has entrado en combate!\n";

    while (player->isAlive() && currentRoom->hasLivinEntities()) {
        std::cout << "Estas peleando contra :\n";
        for (size_t i = 0; i < enemies.size(); i++) {
            std::cout << i + 1 << " . " << enemies[i]->getName() << "\n";
        }
        std::cout << "Que deseas hacer?\n"
                     "1. Atacar\n2. Usar objeto\n>";
        int option;
        std::cin >> option;
        if (option == 1) {
            std::cout << "A que criatura atacaras?\n";
            for (size_t i = 0; i < enemies.size(); i++) {
                std::cout << i + 1 << " . " << enemies[i]->getName() << " Vida: " << enemies[i]->getHp()<< "\n";
            }
            std::cin >> option;
            if (!(option >= 1 && option <= enemies.size())) {
                std::cout << "Ese enemigo no existe!\n";
                continue;
            }
            if (!enemies[option -1]->isAlive()) {
                std::cout  << "El enemigo esta muerto";
            }
            if (option >= 1 && option <= enemies.size()) {player->attack(*enemies[option - 1]);}
            else { std::cout << "Ingresa una opcion valida!\n";
                continue;
            }
        } else if (option == 2) {
            if (std::empty(player->getInventory())) {
                std::cout << "No tienes ningun item!\n";
                continue;//Sales de usar objeto
            }
            std::cout << "Que objeto quieres usar?\n";
            for (size_t i = 0; i < player->getInventory().size(); i++ ) {
                std::cout << i + 1 << " . "<<  player->getInventory()[i]->getName() << "\n";
            } std::cout << ">";
            std::cin >> option;
            if (option >= 1 && option <= player->getInventory().size()) {
                std::cout << "Se uso : " << player->getInventory()[option - 1]->getName() << "\n";
                player->useItem(option - 1);
            } else {
                continue;
            }

        } else {
            std::cout << "Ingresa una opcion valida!\n";
            continue;
        }

        // Turno de los enemigos
        for (Entity* e : enemies) {
            if (e->isAlive()) {
                e->attack(*player);
            }
        }
        std::cout << "Tu vida: " << player->getHp() << "\n";


    }
    if (!player->isAlive()) std::cout << "Has caido...\n";
    else std::cout << "Ganaste el combate!\n";
    currentRoom->removeDeadEntities();


}


void Game::run() {
    std::cout << this->player->getHp() << "\n";
    this->showInventory();

}