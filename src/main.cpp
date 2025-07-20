#include "Cube.h"
#include "Solver.h"
#include "Utilities.h"
#include "Headers.h"
Cube* readCube()
{
    //Vector to store colors only - will validate and assign piece IDs later
    vector<vector<char>> colorData = vector<vector<char>>(6, vector<char>(9));
    bool exists = false;
    string file;
    ifstream iFile;
    char faceColor;
    
    //Reads in/Checks for file name and then opens it 
    while(exists == false)
    {
        cout << "Please Enter the name of the cube file: ";
        cin >> file;
        iFile.open(file);
        if(!iFile)
        {
            cout << "\nFile not found.\n\n";
            iFile.close();
        }
        else
        {
            exists = true;
        }
    }
    
    //Colors are read into vector from file in order: Yellow, Orange, Green, White, Red, Blue
    int currentFace = 0;
    while(getline(iFile, file) && currentFace < 6)
    {
        if(file.length() < 9) continue; // Skip invalid lines (need at least 9 characters)
        
        // Store the 9 face colors for the current face (reading in sequence)
        for(int i = 0; i < 9; ++i) {
            if(i < file.length()) {
                colorData[currentFace][i] = file[i];
            }
        }
        
        currentFace++; // Move to next face after each line
    }
    iFile.close();
    
    // Create cube with color validation and piece assignment
    return new Cube(colorData);
}
int main()
{
    cout << "=== Rubik's Cube BFS Solver ===" << endl;
    
    //Read in vector
    Cube *c;
    c = readCube();
    
    if (c != nullptr) {
        cout << "\nCube loaded successfully!" << endl;
        
        // Check if cube is already solved
        if (c->isSolved()) {
            cout << "Cube is already solved!" << endl;
        } else {
            cout << "Cube needs solving. Starting BFS search..." << endl;
            
            // Solve using BFS
            vector<string> solution = Solver::solveBFS(*c, 10); // Start with depth 10
            
            // Print the solution
            Solver::printSolution(solution);
        }
    }
    
    //clean up
    delete c;
    return 0; 
}