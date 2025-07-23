#include "../include/Solver.h"

// Static member definition
const vector<string> Solver::MOVES = {
    "W", "W'", "Y", "Y'", "G", "G'", 
    "B", "B'", "O", "O'", "R", "R'"
};

// BFS implementation to solve the Rubik's cube
vector<string> Solver::solveBFS(Cube startCube, int maxDepth) {
    // Check if the cube is already solved
    if (startCube.isSolved()) {
        return vector<string>(); // Empty solution - already solved
    }
    
    // BFS queue to store cube states
    queue<CubeState> bfsQueue;
    
    // Set to keep track of visited states to avoid cycles
    unordered_set<string> visited;
    
    // Initialize with the starting state
    vector<string> initialMoves;
    CubeState initialState(startCube, initialMoves, 0);
    bfsQueue.push(initialState);
    visited.insert(cubeToString(startCube));
    
    cout << "Starting BFS search with maximum depth: " << maxDepth << endl;
    int statesExplored = 0;
    
    while (!bfsQueue.empty()) {
        CubeState currentState = bfsQueue.front();
        bfsQueue.pop();
        statesExplored++;
        
        // Print progress every 1000 states
        if (statesExplored % 1000 == 0) {
            cout << "States explored: " << statesExplored 
                 << ", Current depth: " << currentState.depth 
                 << ", Queue size: " << bfsQueue.size() << endl;
        }
        
        // If we've reached maximum depth, skip this branch
        if (currentState.depth >= maxDepth) {
            continue;
        }
        
        // Try all possible moves
        vector<string> possibleMoves = getAllPossibleMoves();
        
        for (const string& move : possibleMoves) {
            // Create a copy of the current cube
            Cube newCube = currentState.cube;
            
            // Apply the move
            newCube.applyMove(move);
            
            // Get the state hash for the new cube
            string newStateHash = cubeToString(newCube);
            
            // Check if this state has been visited
            if (visited.find(newStateHash) == visited.end()) {
                visited.insert(newStateHash);
                
                // Create new move sequence
                vector<string> newMoves = currentState.moves;
                newMoves.push_back(move);
                
                // Check if the cube is solved
                if (newCube.isSolved()) {
                    cout << "\nSolution found!" << endl;
                    cout << "States explored: " << statesExplored << endl;
                    cout << "Solution depth: " << newMoves.size() << endl;
                    return newMoves;
                }
                
                // Add the new state to the queue
                CubeState newState(newCube, newMoves, currentState.depth + 1);
                bfsQueue.push(newState);
            }
        }
    }
    
    cout << "\nNo solution found within maximum depth of " << maxDepth << endl;
    cout << "Total states explored: " << statesExplored << endl;
    return vector<string>(); // No solution found
}

// Helper function to get all possible moves
vector<string> Solver::getAllPossibleMoves() {
    return MOVES;
}

// Convert cube state to string for hashing
string Solver::cubeToString(const Cube& cube) {
    // Create a copy to call getStateHash (assuming it's const)
    Cube cubeCopy = cube;
    return cubeCopy.getStateHash();
}

// Print the solution moves
void Solver::printSolution(const vector<string>& moves) {
    if (moves.empty()) {
        cout << "Cube is already solved or no solution found!" << endl;
        return;
    }
    
    cout << "\nSolution sequence (" << moves.size() << " moves):" << endl;
    for (size_t i = 0; i < moves.size(); i++) {
        cout << moves[i];
        if (i < moves.size() - 1) {
            cout << " -> ";
        }
        // Print 10 moves per line for readability
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}
int Solver::xDist(int color, int dest)
{
    return 0;
}
int Solver::yDist(int color, int dest)
{
    //if(color == dest)
    return 0;
}
void Solver::setCor()
{
    corrFace = 
    {
        {cubeFaces[BLUE][1], cubeFaces[RED][1], cubeFaces[ORANGE][1], cubeFaces[GREEN][1]}, 
        {cubeFaces[YELLOW][5], cubeFaces[GREEN][5], cubeFaces[BLUE][3], cubeFaces[WHITE][5]},
        {cubeFaces[YELLOW][7], cubeFaces[RED][5], cubeFaces[ORANGE][3], cubeFaces[WHITE][1]},
        {cubeFaces[GREEN][7], cubeFaces[RED][7], cubeFaces[ORANGE][7], cubeFaces[BLUE][7]},
        {cubeFaces[YELLOW][3], cubeFaces[BLUE][5], cubeFaces[GREEN][3], cubeFaces[WHITE][3]},
        {cubeFaces[YELLOW][1], cubeFaces[ORANGE][5], cubeFaces[RED][3], cubeFaces[WHITE][7]}
    };
}
void Solver::crosser()
{
    int x_r, y_r;
    setCor();
    if(cubeFaces[WHITE][1] != 'W' && cubeFaces[GREEN][7] != 'G')
    {
        for(int i = 0; i < 6; ++i)
        {
            for(int j = 1; j < 9; j + 2)
            {
                if(cubeFaces[i][j] == 'W' && corrFace[i][j] == 'G')
                {
                    x_r = xDist(i, GREEN);
                    if(i == WHITE){y_r = 0;}
                    else{y_r = yDist(i, WHITE);};
                }
            }
        }
    }
}