#include "Cube.h"
#include "Solver.h"
#include "Utilities.h"
void readCube(Cube &cu)
{
    vector<vector<char>> temp;
    bool exists = false;
    string file;
    ifstream iFile;
    int itter;
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
    while(!iFile.eof())
    {
        getline(iFile, file);
        itter = 0;
        for(int i = 0; i < 9; ++i)
        {
            temp[itter].push_back(file[i]);
            if(i % 3 == 0 && i != 0)
            {
                ++itter;
            }
        }
        if(file[5] == 'w' || file[5] == 'W')
        {

        }
    }
    
}
int main()
{
    //Read in vector
    Cube c;

    return 0; 
}
