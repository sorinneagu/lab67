#include <iostream>
#include "Entity.h"
#include "EntityType.h"
#include "SimulationGrid.h"
/*
//assert tests for Entity
void testEntity() {
    Entity* e = new Empty(0, 0);
    assert(e->getRow() == 0);
    assert(e->getCol() == 0);
    e->setRow(1);
    e->setCol(1);
    assert(e->getRow() == 1);
    assert(e->getCol() == 1);
    delete e;
    std::cout << "Entity tests passed!" << std::endl;
}

//assert tests for Simulation Grid
void testSimulationGrid() {
    SimulationGrid g(10, 10);
    assert(g.getRows() == 10);
    assert(g.getCols() == 10);
    assert(g.get(0, 0)->what() == EntityType::Empty);
    assert(g.get(0, 0)->toString() == " ");
    assert(g.get(0, 0)->getRow() == 0);
    assert(g.get(0, 0)->getCol() == 0);
    assert(g.get(0, 0)->next(g)->what() == EntityType::Empty);
    assert(g.get(0, 0)->next(g)->toString() == " ");
    assert(g.get(0, 0)->next(g)->getRow() == 0);
    assert(g.get(0, 0)->next(g)->getCol() == 0);
    std::cout << "SimulationGrid tests passed!" << std::endl;
}*/

