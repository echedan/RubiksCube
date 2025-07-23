#ifndef SOLVER_H
#define SOLVER_H
#include "Headers.h"
#include "Cube.h"
#include <queue>
#include <unordered_set>

class Solver : private Cube {
public:
    // Structure to represent a state in the search
    struct CubeState {
        Cube cube;
        vector<string> moves;  // Sequence of moves to reach this state
        int depth;             // Depth in the search tree
        
        CubeState(const Cube& c, const vector<string>& m, int d) 
            : cube(c), moves(m), depth(d) {}
    };
    
    // BFS solver
    static vector<string> solveBFS(Cube startCube, int maxDepth = 20);
    
    // Helper functions
    static vector<string> getAllPossibleMoves();
    static string cubeToString(const Cube& cube);  // For state hashing
    static void printSolution(const vector<string>& moves);

    //Function for Generating the White Cross
    int xDist(int color, int dest);
    int yDist(int color, int dest);
    void setCor();
    void crosser();
private:
    // All possible single moves for a Rubik's cube
    static const vector<string> MOVES;
    vector<vector<char>> corrFace;
};

#endif
