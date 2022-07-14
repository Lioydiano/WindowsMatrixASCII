#pragma once

#include <algorithm>
#include <map>
#include <experimental/map>

#include "style.hpp"
#include "cursor.hpp"


int currentID = 0;
const char void_matrix[20][50] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};


class Field;


class Object {
public:
    // Position is matrix[y][x] where matrix[0][0] is the top left corner of the field
    int ID;
    int x;
    int y;
    char skin;
    Style style;
    Field *field;
    bool alive;
    bool toBeMoved;

    Object(int x, int y, char skin, Style style) {
        this->ID = currentID++;
        this->x = x;
        this->y = y;
        this->skin = skin;
        this->style = style;
        this->alive = true;
        this->toBeMoved = true;
    }
    Object(int x, int y, char skin, Style style, Field *field);
    ~Object();

    void moveTo(int x, int y) {
        this->field->objects_by_row[this->y].erase(std::remove(this->field->objects_by_row[this->y].begin(), this->field->objects_by_row[this->y].end(), [this](Object *o) {
            return this->ID == o->ID;
        }), this->field->objects_by_row[this->y].end());
        this->x = x;
        this->y = y;
        this->toBeMoved = true;
        this->field->objects_by_row[this->y].push_back(this);
    }
    void moveBy(int x, int y) {
        this->moveTo(this->x + x, this->y + y);
    }

    void draw() {
        if (toBeMoved) {
            toBeMoved = false;
            // TODO: Move to the correct position

        }
    }
};


class Field {
public:
    std::vector<Object> objects; // Objects populating the field
    std::map<int, Object*> objects_by_id;
    std::map<int, std::vector<Object*>> objects_by_row; // Objects by rows (so that you can iterate over the objects in a row)
    Cursor cursor;
    int shift[20][50] = {0}; // Gives the shifting between the coordinates and the real coordinates
    std::vector<std::vector<char>> matrix; // Tracks down what's going on in the console character by character

    void print();
    void print(const char matrix[20][50]);

    Field() {
        this->cursor = Cursor(0, 0, this);
        std::cout << cursor::visibility::hide;
        print(void_matrix);
        this->objects = {};
        this->objects_by_id = {};
        this->objects_by_row = {};

        // Set the matrix to the void matrix
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 50; j++) {
                this->matrix.push_back(std::vector<char>());
                for (int k = 0; k < 50; k++) {
                    this->matrix[i].push_back(' ');
                }
            }
        }
    }
    Field(std::vector<Object> objects) {
        Field();
        this->objects = objects;
        for (Object object: objects) {
            this->objects_by_id[object.ID] = &object;
            this->objects_by_row[object.y].push_back(&object);
        }
    }
    ~Field() {
        this->objects.clear();
        std::cout << SS;
    }

    void addObject(Object object) {
        this->objects.push_back(object);
        this->objects_by_id[object.ID] = &object;
        this->objects_by_row[object.y].push_back(&object);
        object.field = this;
    }
    void addObject(Object *object) {
        this->objects.push_back(*object);
        this->objects_by_id[object->ID] = object;
        this->objects_by_row[object->y].push_back(object);
        object->field = this;
    }

    void removeObject(Object object) {
        this->objects.erase(std::remove_if(this->objects.begin(), this->objects.end(), [object](Object o) {
            return o.ID == object.ID;
        }), this->objects.end());
        this->objects_by_id.erase(object.ID);
        this->objects_by_row[object.y].erase(std::remove_if(this->objects_by_row[object.y].begin(), this->objects_by_row[object.y].end(), [object](Object *o) {
            return o->ID == object.ID;
        }), this->objects_by_row[object.y].end());
    }
    void removeObject(int ID) {
        this->objects.erase(std::remove_if(this->objects.begin(), this->objects.end(), [ID](Object o) {
            return o.ID == ID;
        }), this->objects.end());
        this->objects_by_id.erase(ID);
        this->objects_by_row[this->objects_by_id[ID]->y].erase(std::remove_if(this->objects_by_row[this->objects_by_id[ID]->y].begin(), this->objects_by_row[this->objects_by_id[ID]->y].end(), [ID](Object *o) {
            return o->ID == ID;
        }), this->objects_by_row[this->objects_by_id[ID]->y].end());
    }

    void removeObjectsByCoordinates(int x, int y) {
        this->objects.erase(std::remove_if(this->objects.begin(), this->objects.end(), [x, y](Object o) {
            return o.x == x && o.y == y;
        }), this->objects.end());
        std::experimental::erase_if(this->objects_by_id, [x, y](Object* o) {
            return o->x == x && o->y == y;
        });
        this->objects_by_row[y].erase(std::remove_if(this->objects_by_row[y].begin(), this->objects_by_row[y].end(), [x, y](Object *o) {
            return o->x == x;
        }), this->objects_by_row[y].end());
    }
};


Object::Object (int x, int y, char skin, Style style, Field *field) {
    this->field = field;
    Object(x, y, skin, style);
    this->field->addObject(this);
}
Object::~Object() {
    field->removeObject(*this);
}


void Field::print() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 50; j++) {
            std::cout << void_matrix[i][j];
        }
        std::cout << std::endl;
    }
}
void Field::print(const char matrix[20][50]) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 50; j++) {
            std::cout << matrix[i][j];
        }
        std::cout << LF;
    }
    std::cout << std::flush;
}