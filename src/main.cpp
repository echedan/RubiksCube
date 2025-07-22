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

        if(color == 'Y'){conVec[0] = temp;}
        else if(color == 'O'){conVec[1] = temp;}
        else if(color == 'G'){conVec[2] = temp;}
        else if(color == 'W'){conVec[3] = temp;}
        else if(color == 'R'){conVec[4] = temp;}
        else if(color == 'B'){conVec[5] = temp;}
    }
    iFile.close();
    
    // Create cube with color validation and piece assignment
    return new Cube(colorData);
}
Cube *lineCube()
{
    string cube;
    vector<vector<char>> colorData = vector<vector<char>>(6, vector<char>(9));
    cout << "\nPlease enter all 54 faces of the cube\nExample RWBGROW...YO\nCube: ";
    cin >> cube;
    
    // Parse the 54-character string into 6 faces of 9 characters each
    int index = 0;
    for(int face = 0; face < 6; face++) {
        for(int pos = 0; pos < 9; pos++) {
            if(index < cube.length()) {
                colorData[face][pos] = cube[index];
                index++;
            }
        }
    }
    
    return new Cube(colorData);
}

int main()
{
    cout << "=== Rubik's Cube BFS Solver ===" << endl;
    
    //Read in vector
    Cube *c;
    int choice = 0;
    bool picked = false;
    while(picked == false)
    {
        cout << "\n1. Input file"
             << "\n2. From keyboard"
             << "\n3. Cancel"
             << "\nEnter how you want to load the cube: ";
        cin >> choice;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "\nPlease only enter a number 1-3\n";
        } 
        else if(choice > 3 || choice < 1)
        {
            cout << "\nPlease enter a number 1-3\n";
        }    
        else
        {
            picked = true;
        }
    }
    
    switch(choice)
    {
        case 1:
            c = readCube();
            break;
        case 2: 
            c = lineCube();
            break;
        case 3:
            exit(1);
            break;
        default:
            exit(1);
            break;
    }
    
    if (c != nullptr) {
        if (!c->isValid()) {
            cout << "\nCube initialization failed. Exiting." << endl;
            delete c;
            return 1;
        }
        
        cout << "\nCube loaded successfully!" << endl;
        
        // Debug: Print piece assignments
        c->printCubeState();
        
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