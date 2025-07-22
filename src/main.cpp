#include "../include/Cube.h"
#include "../include/Solver.h"
#include "../include/Utilities.h"
#include "../include/Headers.h"
Cube* readCube()
{
    //Vector to be passed to constructor
    vector<vector<char>> conVec = vector<vector<char>>(6, vector<char>());
    vector<char> temp;
    //Temporary vector stores side of cube;
    bool exists = false;
    string file;
    ifstream iFile;
    int itter;
    char color;
    //Reads in/Checks for file name and then opens it 
    while(exists == false)
    {
        cout << "\nPlease Enter the name of the cube file\nMust be of the format:\nface1\nface2\n...\nOrder of faces doesn't matter\nFile Name: ";
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
    //Colors are read into vector from file
    while(getline(iFile, file))
    {
        temp.clear();
        itter = 0;
        color = file[4];
        for(int i = 0; i < 9; ++i)
        {
            temp.push_back(file[i]);
        }
        if(color == 'W'){conVec[0] = temp;}
        else if(color == 'Y'){conVec[1] = temp;}
        else if(color == 'G'){conVec[2] = temp;}
        else if(color == 'B'){conVec[3] = temp;}
        else if(color == 'O'){conVec[4] = temp;}
        else if(color == 'R'){conVec[5] = temp;}
    }
    iFile.close();
    //Test
    //start
    cout << "\nFile Test\n";
    for(int i = 0; i < 6; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            cout << conVec[i][j];
            cout << endl;
        }
        cout << endl;
    }
    //end
    return new Cube(conVec);
}
Cube *lineCube()
{
    string cube;
    vector<vector<char>> conVec = vector<vector<char>>(6, vector<char>());
    cout << "\nPlease enter all 54 faces of the cube\nExample RWBGROW...YO\nCube: ";
    cin >> cube;
    
    //Test
    cout << endl << "Cube: " << cube << endl;
    int itter = 0;
    for(int i = 0; i < cube.length(); ++i)
    {
        cout << endl << i;
        if(i % 9 == 0 && i != 0)
        {
            //Test
            //for(int j = 0; j < 9; ++j)
            //{
            //    cout << conVec[itter][j];
            //}
            ++itter;
            //Test
            //cout << "\nTest: Itter: " << itter;

        }
        conVec[itter].push_back(cube[i]);
    }
    //Test 
    //start
    cout << "\nCube in Line Test\n";
    for(int i = 0; i < 6; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            cout << conVec[i][j];
            cout << endl;
        }
        cout << endl;
    }
    //end
    return new Cube(conVec);

}
int main()
{
    
    //Read in vector
    Cube *c;
    int choice = 0;
    bool picked = false;
    while(picked == false)
    {
        cout << "\n=== Rubik's Cube BFS Solver ==="
             << "\n1. Input file"
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
