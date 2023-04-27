#pragma once
#define MAX_ROWS 100
#define MAX_COLS 100
#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
//#include "Entity.h"

// forward class declaration for Entity
class Entity;

class SimulationGrid
{
    friend class Entity;

private:
    std::vector<std::vector<Entity*>> grid;
    int rows;
    int cols;

public:
    SimulationGrid();
    SimulationGrid(int rows, int cols);
    SimulationGrid(const std::string& fileName);
    SimulationGrid(const SimulationGrid& other);
    SimulationGrid& operator=(const SimulationGrid& other);
    ~SimulationGrid();

    Entity* get(int row, int col) const;
    void set(int row, int col, Entity* entity);
    int getRows() const;
    int getCols() const;

    friend std::ostream& operator<<(std::ostream& os, const SimulationGrid& grid);
    friend std::istream& operator>>(std::istream& is, SimulationGrid& grid);

    static Entity* createEntity(std::string s);
};