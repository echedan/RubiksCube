#include "Solver.h"

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
