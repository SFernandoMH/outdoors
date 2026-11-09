#include "Game.h"

#include "Bandage.h"
#include "DarkBeing.h"
#include "iostream"

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

void Game::buildMap() {
    Room* entrada = new Room("Entrada de la biblioteca");
    Room* pasillo = new Room("Pasillo de libros");

    //
    entrada->addShelf(new Shelf(3));
    entrada->addShelf(new Shelf(4));
    entrada->addEntity(new DarkBeing());

    for (Shelf* shelf : entrada->getShelves()) {
        shelf->addItem(new Bandage("Benda"));
    }


    rooms.push_back(entrada);
    rooms.push_back(pasillo);

    Door* doorEone = new Door(entrada, pasillo);
    doors.push_back(doorEone);
    entrada->addDoor(doorEone);
    pasillo->addDoor(doorEone);

    currentRoom = entrada;
}


int Game::showMenuRoom() const {
    std::cout << "Estas en: " << currentRoom->getDescription()<< "\n";

    std::cout<< "Que deseas hacer?\n"
                "0. Abandonar juego\n"
                "1. Que tengo en mi inventario?\n"
                "2. Revisar estanterias\n"
                "3. Abrir puertas\n>";
    int option;
    std::cin >> option;
    std::cout << "\n";
    return option;
}



int Game::showInventory() const{
    int option;
    if (player->getInventory().empty()) {
        std::cout << "No tienes nada!\n";
        return 0;
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
        return 0;
    } else {
        return 0;
    }
}

int Game::checkShelves() const  {
    std::vector<Shelf*> currentShelves= currentRoom->getShelves();
    if (currentShelves.empty()) {
        std::cout << "No hay ningun estante!\n";
        return 0;
    }
    for (size_t i = 0; i < currentShelves.size(); i++) {
        std::cout << i + 1 << ". Revisar la estanteria " <<  i + 1 << "\n";
    }
    std::cout << "0. Salir" << "\n";
    int option;
    std::cin >> option;
    if (option == 0) {
        return 0;
    } else if (option >= 1 && option <= currentShelves.size()) {
        Shelf* shelf = currentShelves[option - 1];
        player->searchInShelf(shelf);
        for (Item* item : shelf->getItemsOnIt()) { // Eliminar items en el estante
            std::cout << "Obtuviste : " << item->getName() << "\n";
            currentRoom->removeitemFromShelf(option -1, item);
        }
        return 0;
    } return 0;
}

void Game::crossDoor() {
    int option;
    std::vector<Door*> exits = currentRoom->getDoors();
    for (size_t i = 0; i < exits.size(); i++) {
        std::cout << i + 1 << ". Abrir la puerta " << i + 1 << "\n";
    }
    std::cout << "0. Salir" << "\n";
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
                        entity->takeDamage(60);
                        if (entity->isAlive() == false) {
                            std::cout << "Un enemigo murio\n";
                        }
                    }
                }
            }

        }
    }
}


void Game::run() {
    std::cout << this->player->getHp() << "\n";

}