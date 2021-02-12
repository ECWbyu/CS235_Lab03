#include "PathfinderInterface.h"
using namespace std;

class Pathfinder : public PathfinderInterface {
    private:
    const int MAZE_DIM = 4;
    int maze[MAZE_DIM][MAZE_DIM][MAZE_DIM];
    
    public:
    Pathfinder();
    ~Pathfinder();
    string toString() const;
    void createRandomMaze();
    bool importMaze(const string& filePath);
    virtual vector<string> solveMaze();
}