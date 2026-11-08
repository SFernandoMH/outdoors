#include "Game.h"
#include "iostream"

Game::Game() : player(new Player()), currentRoom(nullptr) {
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
    rooms.push_back(entrada);
    rooms.push_back(pasillo);

    Door* d = new Door(entrada, pasillo);
    doors.push_back(d);
    entrada->addDoor(d);
    pasillo->addDoor(d);

    currentRoom = entrada;
}

void Game::run() {
    bool playing = true;
    while (playing) {
        std::cout << "Estas en: " << currentRoom->getDescription()<< "\n";

        std::vector<Door*> exits = currentRoom->getDoors();
        for (size_t i = 0; i < exits.size(); i++) {
            std::cout << i + 1 << ". Ir por la puerta " << i + 1 << "\n";

        }
        std::cout << "0. Salir" << "\n";
        int option;
        std::cin >> option;
        if (option == 0) {
            playing = false;
        } else if (option >= 1 && option <= exits.size()) {
            Door* door = exits[option - 1];
            door->open();
            currentRoom = door->getOtherRoom(currentRoom);
        } else {
            std::cout << "Opcion no valida!\n";
        }

    }
}