#include "Game.h"

#include "Bandage.h"
#include "DarkBeing.h"
#include "InvisibleCreature.h"
#include "iostream"
#include "Spell.h"
#include "Armor.h"
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
    Room* entrada = new Room("Entrada de la biblioteca");        // 0
    Room* esquinaReluciente = new Room("Esquina Reluciente");    // 1
    Room* pasillo = new Room("Pasillo de libros");               // 2
    Room* esquinaMisteriosa = new Room("Esquina abandonada");    // 3
    Room* bordeLuciente = new Room("Borde Luciente");            // 4
    Room* segundoPasillo = new Room("Segundo Pasillo de libros");// 5
    Room* bordeOscuro = new Room("Borde Oscuro");                // 6
    Room* noEnd = new Room("Pasillo estrellado");



    // 8 habitaciones
    rooms.push_back(entrada);
    rooms.push_back(esquinaReluciente);
    rooms.push_back(pasillo);
    rooms.push_back(esquinaMisteriosa);
    rooms.push_back(bordeLuciente);
    rooms.push_back(segundoPasillo);
    rooms.push_back(bordeOscuro);
    rooms.push_back(noEnd);


    // 0 Entrada
    entrada->addShelf(new Shelf(3));
    entrada->addShelf(new Shelf(4));

    entrada->getShelves()[0]->addItem(new Spell("Aumento de dano x2", 2));
    for (Shelf* shelf : entrada->getShelves()) {
        shelf->addItem(new Bandage("Venda"));
    }


    // 1 esquina reluciente

    esquinaReluciente->addShelf(new Shelf(10));
    esquinaReluciente->addShelf(new Shelf(8));
    esquinaReluciente->addShelf(new Shelf(9));
    esquinaReluciente->getShelves()[0]->addItem(new Spell("Aumento de dano x2",2));
    esquinaReluciente->getShelves()[2]->addItem(new Bandage("Venda"));


    // 2 pasillo
    pasillo->addShelf(new Shelf(5));
    pasillo->addShelf(new Shelf(8));
    pasillo->addShelf(new Shelf(9));


    pasillo->getShelves()[2]->addItem(new Spell("Aumento de dano x4",4));
    pasillo->addEntity(new DarkBeing());

    // 3 Esquina

    esquinaMisteriosa->addShelf(new Shelf(10));
    esquinaMisteriosa->getShelves()[0]->addItem(new Bandage("Botiquin")); // posible armadura

    esquinaMisteriosa->addEntity(new DarkBeing());
    esquinaMisteriosa->addEntity(new DarkBeing());

    // 4 borde Luciente

    bordeLuciente->addShelf(new Shelf(10));

    bordeLuciente->getShelves()[0]->addItem(new Armor("Armadura de cuero",8));
    bordeLuciente->getShelves()[0]->addItem(new Bandage("Venda"));
    bordeLuciente->getShelves()[0]->addItem(new Bandage("Venda"));


    // 5 Segundo Pasillo

    segundoPasillo->addShelf(new Shelf(6));
    segundoPasillo->addShelf(new Shelf(10));
    segundoPasillo->addShelf(new Shelf(8));
    segundoPasillo->addShelf(new Shelf(10));
    segundoPasillo->getShelves()[1]->addItem(new Spell("Aumento de dano x2",4));
    segundoPasillo->getShelves()[3]->addItem(new Armor("armadura",20));

    segundoPasillo->addEntity(new DarkBeing());
    segundoPasillo->addEntity(new DarkBeing());
    segundoPasillo->addEntity(new DarkBeing());
    segundoPasillo->addEntity(new DarkBeing());

    segundoPasillo->getEntities()[0]->setDamagePA(9);
    segundoPasillo->getEntities()[1]->setDamagePA(9);
    segundoPasillo->getEntities()[2]->setDamagePA(9);
    segundoPasillo->getEntities()[3]->setDamagePA(9);


    //  6 Borde Oscuro

    bordeOscuro->addShelf(new Shelf(2));
    bordeOscuro->addShelf(new Shelf(10));
    bordeOscuro->getShelves()[0]->addItem(new Spell("Aumento de dano x10",10));

    bordeOscuro->addEntity(new DarkBeing());
    bordeOscuro->addEntity(new DarkBeing());

    // 8 Noend

    noEnd->addEntity(new InvisibleCreature());
    noEnd->addEntity(new InvisibleCreature());

    // 0A2 FILA 0

    Door* doorEPone = new Door(entrada, pasillo);
    doors.push_back(doorEPone);
    entrada->addDoor(doorEPone);
    pasillo->addDoor(doorEPone);

    // 2A3 FILA 1

    Door* doorPEtwo = new Door(pasillo, esquinaMisteriosa);
    doors.push_back(doorPEtwo);
    pasillo->addDoor(doorPEtwo);
    esquinaMisteriosa->addDoor(doorPEtwo);

    // 2A5

    Door* doorPP2 = new Door(pasillo, segundoPasillo);
    doors.push_back(doorPP2);
    pasillo->addDoor(doorPP2);
    segundoPasillo->addDoor(doorPP2);

    // 2A1

    Door* door2A1 = new Door(pasillo,esquinaReluciente);
    doors.push_back(door2A1);
    pasillo->addDoor(door2A1);
    esquinaReluciente->addDoor(door2A1);

    // 1A4 FILA 2

    Door* door1A4 = new Door(esquinaReluciente,bordeLuciente);
    doors.push_back(door1A4);
    esquinaReluciente->addDoor(door1A4);
    bordeLuciente->addDoor(door1A4);

    // 4A5

    Door* door4A5 = new Door(bordeLuciente,segundoPasillo);
    doors.push_back(door4A5);
    bordeLuciente->addDoor(door4A5);
    segundoPasillo->addDoor(door4A5);


    // 3A6

    Door* door3A6 = new Door(esquinaMisteriosa,bordeOscuro);
    doors.push_back(door3A6);
    esquinaMisteriosa->addDoor(door3A6);
    bordeOscuro->addDoor(door3A6);

    // 6A5

    Door* door6A5 = new Door(bordeOscuro,segundoPasillo);
    doors.push_back(door6A5);
    bordeOscuro->addDoor(door6A5);
    segundoPasillo->addDoor(door6A5);

    // 6A8

    Door* door6A8 = new Door(segundoPasillo,noEnd);
    doors.push_back(door6A8);
    segundoPasillo->addDoor(door6A8);
    noEnd->addDoor(door6A8);


    //Por defecto inicias en entrada

    currentRoom = entrada;
}


int Game::showMenuRoom() const {

    if (currentRoom == rooms[7] && !rooms[7]->hasLivinEntities()) {
        std::cout << "Bibliotecario : hola...\n";
        std::cout << "Has completado el juego\n";
        return 0;
    }

    if (player->isAlive() == false) {
        std::cout << "Solo queria encontrarlo...";
        return 0;
    }
    std::cout << "Estas en: " << currentRoom->getDescription()<< " // "
                 "Tu vida : "<< player->getHp() << "\n";

    if (currentRoom->hasLivinEntities() && player->isAlive()) {return 4;}

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
}

void Game::crossDoor() {
    int option;
    std::vector<Door*> exits = currentRoom->getDoors();
    for (size_t i = 0; i < exits.size(); i++) {
        std::cout << i + 1 << ". Abrir la puerta " << i + 1 << " lleva a : "  << exits[i]->whereItGoes(currentRoom)->getDescription()<<"\n";
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
                    }
                }
            int counter = 0;
            for (Entity* e : previous->getEntities()) {
                if ( e->isAlive() == false ) {
                    counter += 1;
                }
            }
            std::cout << "Murieron : "<< counter << " entidades.\n";
            previous->removeDeadEntities();
            }
        }
    }


void Game::fight() {
    
    std::vector<Entity*> enemies = currentRoom->getEntities();
    if (std::empty(enemies)) {
        std::cout << "No hay enemigos en esta habitacion!\n";
        return;
    } else if (player->isAlive() == false) {
        return;
    }


    //Menu Pelea
    std::cout << "Has entrado en combate!\n";

    while (player->isAlive() && currentRoom->hasLivinEntities()) {
        std::cout << "Estas peleando contra :\n";
        for (size_t i = 0; i < enemies.size(); i++) {
            std::cout << i + 1 << " . " << enemies[i]->getName() << " vida : " << enemies[i]->getHp() <<"\n";
        }
        std::cout << "Que deseas hacer?\n"
                     "1. Atacar\n2. Usar objeto\n3. Huir\n>";
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
                std::cout  << "El enemigo esta muerto\n";
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
        } else if (option == 3) {
            return;
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

}