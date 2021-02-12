#include "Pathfinder.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

Pathfinder::Pathfinder() {
    for (int x = 0; x < MAZE_DIM; x++) {
        for (int y = 0; y < MAZE_DIM; y++) {
            for (int z = 0; z < MAZE_DIM; z++) {
                maze[x][y][z] = 1;
            }
        }
    }
}

Pathfinder::~Pathfinder() {
    // Nothing special
}

string Pathfinder::toString() const {
    stringstream ss;
    for (int x = 0; x < MAZE_DIM; x++) {
        for (int y = 0; y < MAZE_DIM; y++) {
            for (int z = 0; z < MAZE_DIM; z++) {
                ss << maze[x][y][z] << ' ';
            }
            ss << endl;
        }
        ss << endl;
    }
    return ss.str();
}

void Pathfinder::createRandomMaze() {
    for (int x = 0; x < MAZE_DIM; x++) {
        for (int y = 0; y < MAZE_DIM; y++) {
            for (int z = 0; z < MAZE_DIM; z++) {
                maze[x][y][z] = rand() % 2;
            }
        }
    }
    maze[0][0][0] = 1;
    maze[MAZE_DIM-1][MAZE_DIM-1][MAZE_DIM-1] = 1;
}

bool Pathfinder::importMaze(const string& filePath) {
    ifstream infile (filePath.c_str());
    if (!infile.is_open()) {
        return false;
    }
    string line;
    int row_count = 0;
    for (int x = 0; x < MAZE_DIM; x++) {
        for (int y = 0; y < MAZE_DIM; y++) {
            if (getline(infile, line)) {
                stringstream ss (line);
                for (int z = 0; z < MAZE_DIM; z++) {
                    int value;
                    ss >> value;
                    maze[x][y][z] = value;
                }
            } else {
                cout << "Invalid maze file, ran out of data." << endl;
                return false;
            }
        }
        getline(infile, line);
    }
    getline(infile, line);
    if (getline(infile, line)) {
        cout << "Invalid maze file, more than required data." << endl;
        return false;
    }
}
