#pragma once
#include "EntityType.h"
#include "SimulationGrid.h"
#include <string>
#include <cassert>
#include <iostream>

class Entity
{
public:
	// TODO make pure abstract method
	Entity(int row, int col);
    virtual ~Entity();

    virtual EntityType what() const = 0;
    virtual std::string toString() const = 0;
    virtual Entity* next(const SimulationGrid& g) = 0;

    void setRow(int row);
    void setCol(int col);
    int getRow() const;
    int getCol() const;

    static void demographics(unsigned int population[], const SimulationGrid& g);
    friend std::ostream& operator<<(std::ostream& os, const SimulationGrid& g);
protected:
	 int row;
	 int col;
private:
};

class Empty : public Entity {
public:
    Empty(int row, int col);
    ~Empty();

    EntityType what() const override;
    std::string toString() const override;
    Entity* next(const SimulationGrid& g) override;
};

class Plant : public Entity {
public:
    Plant(int row, int col);
    ~Plant();

    EntityType what() const override;
    std::string toString() const override;
    Entity* next(const SimulationGrid& g) override;
};

class Fox : public Entity {
public:
    Fox(int row, int col);
    ~Fox();

    EntityType what() const override;
    std::string toString() const override;
    Entity* next(const SimulationGrid& g) override;
};

class Gopher : public Entity {
public:
    Gopher(int row, int col);
    ~Gopher();

    EntityType what() const override;
    std::string toString() const override;
    Entity* next(const SimulationGrid& g) override;
};

class Animal : public Entity {
public:
    virtual ~Animal() override;

    virtual EntityType what() const override = 0;
    virtual std::string toString() const override = 0;
    virtual Entity* next(const SimulationGrid& g) override = 0;

    void setAge(int age);
    int getAge() const;

protected:
    int age;
};

