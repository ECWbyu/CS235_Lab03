#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "PathfinderInterface.h"
using namespace std;

int main(int argc, char* argv []) {

    const int MAZE_DIM = 5;

    int maze[MAZE_DIM][MAZE_DIM][MAZE_DIM] = {0};


    // --- Initialize maze with 1's ---
    for (int x = 0; x < MAZE_DIM; x++) {
        for (int y = 0; y < MAZE_DIM; y++) {
            for (int z = 0; z < MAZE_DIM; z++) {
                maze[x][y][z] = 1;
            }
        }
    }


    // --- Output maze[][][] to file ---
    cout << "Outputting maze to file..." << endl;
    string outfilePath = "test_out.txt";
    ofstream outfile;
    outfile.open(outfilePath, ios::out | ios::trunc);
    for (int x = 0; x < MAZE_DIM; x++) {
        for (int y = 0; y < MAZE_DIM; y++) {
            for (int z = 0; z < MAZE_DIM; z++) {
                outfile << maze[x][y][z] << ' ';
            }
            outfile << endl;
        }
        outfile << endl;
    }
    outfile.close();
    cout << "Output complete." << endl;


    // --- Import maze from file ---
    cout << "Importing maze from file..." << endl;
    string infilePath = "Mazes/Solvable2.txt";
    ifstream infile;
    infile.open(infilePath);
    string line;
    string item;
    int value;
    stringstream ss;
    for (int x = 0; x < MAZE_DIM; x++) {
        for (int y = 0; y < MAZE_DIM; y++) {
            if (getline(infile, line)) {
                ss << line;
                for (int z = 0; z < MAZE_DIM; z++) {
                    ss >> item;
                    if (item == "") {
                        break;
                    }
                    else {
                        value = stoi(item);
                        if (value == 0 || value == 1) {
                            maze[x][y][z] = value;
                        }
                    }
                }
            }
        }
    }


    cout << "Program finished with code 0" << endl;

    return 0;
}