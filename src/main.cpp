#include "Cube.h"
#include "Solver.h"
#include "Utilities.h"
Cube* readCube()
{
    //Vector to be passed to constructor
    vector<vector<vector<char>>> conVec = vector<vector<vector<char>>>(6, vector<vector<char>>());
    //Temporary vector stores side of cube;
    vector<vector<char>> temp; 
    bool exists = false;
    string file;
    ifstream iFile;
    int itter;
    char color;
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
    //Colors are read into vector from file
    while(getline(iFile, file))
    {
        itter = 0;
        color = file[4];
        temp = vector<vector<char>>(3, vector<char>());
        for(int i = 0; i < 9; ++i)
        {
            if(i % 3 == 0 && i != 0)
            {
                ++itter;
            }
            temp[itter].push_back(file[i]);
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
    /*
    for(int i = 0; i < 6; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            for(int k = 0; k < 3; ++k)
            {
                cout << conVec[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }

    return new Cube(conVec);
    */
}
int main()
{
    //Read in vector
    Cube *c;
    c = readCube();
    //clean up
    delete c;
    return 0; 
}
