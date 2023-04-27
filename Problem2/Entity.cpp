#include "Entity.h"
#include "EntityType.h"
#include <algorithm> // for std::fill

Entity::~Entity() = default;

Entity::Entity(int row, int col) : row(row), col(col) {}

//Entity::~Entity() {}

void Entity::setRow(int row) {
    this->row = row;
}

void Entity::setCol(int col) {
    this->col = col;
}

int Entity::getRow() const {
    return row;
}

int Entity::getCol() const {
    return col;
}

void Entity::demographics(unsigned int population[], const SimulationGrid& g) {
    for (int r = 0; r < g.getRows(); ++r) {
        for (int c = 0; c < g.getCols(); ++c) {
            EntityType type = g.get(r, c)->what();
            switch (type) {
                case EntityType::Empty:
                    ++population[0];
                    break;
                case EntityType::Fox:
                    ++population[1];
                    break;
                case EntityType::Gopher:
                    ++population[2];
                    break;
                case EntityType::Plant:
                    ++population[3];
                    break;
            }
        }
    }
}

Empty::Empty(int row, int col) : Entity(row, col) {}

Empty::~Empty() {}

EntityType Empty::what() const {
    return EntityType::Empty;
}

std::string Empty::toString() const {
    return " ";
}

Entity* Empty::next(const SimulationGrid& g) {
    // The Empty spot stays empty.
    return new Empty(row, col);
}

Plant::Plant(int row, int col) : Entity(row, col) {}

Plant::~Plant() {}

EntityType Plant::what() const {
    return EntityType::Plant;
}

std::string Plant::toString() const {
    return "P";
}

Entity* Plant::next(const SimulationGrid& g) {
    //the Plant always stays in the same spot.
    return new Plant(row, col);
}

Fox::Fox(int row, int col) : Entity(row, col) {}

Fox::~Fox() {}

EntityType Fox::what() const {
    return EntityType::Fox;
}

std::string Fox::toString() const {
    return "F";
}

Entity* Fox::next(const SimulationGrid& g) {
    // The Empty spot stays empty.
    return new Fox(row, col);
}

Gopher::Gopher(int row, int col) : Entity(row, col) {}

Gopher::~Gopher() {}

EntityType Gopher::what() const {
    return EntityType::Gopher;
}

std::string Gopher::toString() const {
    return "G";
}

Entity* Gopher::next(const SimulationGrid& g) {
    // The Empty spot stays empty.
    return new Gopher(row, col);
}

Animal::~Animal() {}

void Animal::setAge(int age) {
    this->age = age;
}

int Animal::getAge() const {
    return age;
}
