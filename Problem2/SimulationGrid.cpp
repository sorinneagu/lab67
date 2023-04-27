#include "SimulationGrid.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

Entity* SimulationGrid::get(int row, int col) const {
    //check if the row and column indices are within bounds
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
        return nullptr;
    }

    //return a pointer to the Entity object at the specified location
    return grid[row][col];
}

SimulationGrid::SimulationGrid() {
    grid.resize(MAX_ROWS);
    for (int r = 0; r < MAX_ROWS; ++r) {
        grid[r].resize(MAX_COLS);
        for (int c = 0; c < MAX_COLS; ++c) {
            grid[r][c] = nullptr;
        }
    }
}


//Entity* SimulationGrid::get(int row, int col) const {
//    if (row < 0 || row >= MAX_ROWS || col < 0 || col >= MAX_COLS) {
//        return nullptr;
//    }
//    return grid[row][col];
//}

void SimulationGrid::set(int row, int col, Entity* entity) {
    if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS) {
        grid[row][col] = entity;
    }
}

int SimulationGrid::getRows() const {
    return MAX_ROWS;
}

int SimulationGrid::getCols() const {
    return MAX_COLS;
}

std::ostream& operator<<(std::ostream& os, const SimulationGrid& grid) {
    for (int r = 0; r < grid.getRows(); ++r) {
        for (int c = 0; c < grid.getCols(); ++c) {
            if (grid.get(r, c) == nullptr) {
                os << " ";
            }
            else {
                os << grid.get(r, c)->toString();
            }
            os << " ";
        }
        os << std::endl;
    }
    return os;
}
