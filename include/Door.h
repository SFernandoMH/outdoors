#pragma once

class Room;

class Door {
    private:
        bool open_;
        Room roomA;
        Room roomB;
    public:
        Door(Room roomA, Room roomB);
        ~Door();
        bool isOpen();
        void open();
        void close(int force);

};

