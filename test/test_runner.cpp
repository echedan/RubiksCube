#include "../include/Cube.h"
#include "../include/Headers.h"
#include <iostream>
#include <vector>
#include <string>

class TestRunner {
public:
    static void runAllTests() {
        cout << "=== Rubik's Cube Test Suite ===" << endl << endl;
        
        // Test cases
        vector<string> testFiles = {
            "test/solved_cube.txt",
            "test/scrambled_cube.txt", 
            "test/invalid_colors.txt",
            "test/invalid_centers.txt",
            "test/invalid_adjacency.txt"
        };
        
        vector<string> expectedResults = {
            "VALID - Solved cube should pass all validation",
            "VALID - Scrambled cube should pass validation", 
            "INVALID - Wrong color count should fail",
            "INVALID - Wrong center pieces should fail",
            "INVALID - Invalid adjacencies should fail"
        };
        
        for (int i = 0; i < testFiles.size(); i++) {
            cout << "Test " << (i+1) << ": " << testFiles[i] << endl;
            cout << "Expected: " << expectedResults[i] << endl;
            
            try {
                Cube* testCube = readCubeFromFile(testFiles[i]);
                if (testCube != nullptr) {
                    cout << "Result: CUBE CREATED SUCCESSFULLY" << endl;
                    if (testCube->isSolved()) {
                        cout << "Cube is SOLVED!" << endl;
                    } else {
                        cout << "Cube is NOT solved." << endl;
                    }
                    delete testCube;
                } else {
                    cout << "Result: CUBE CREATION FAILED" << endl;
                }
            } catch (const exception& e) {
                cout << "Result: EXCEPTION - " << e.what() << endl;
            }
            
            cout << "----------------------------------------" << endl << endl;
        }
    }
    
private:
    static Cube* readCubeFromFile(const string& filename) {
        vector<vector<char>> colorData = vector<vector<char>>(6, vector<char>(9));
        ifstream iFile(filename);
        
        if (!iFile) {
            cout << "ERROR: Cannot open file " << filename << endl;
            return nullptr;
        }
        
        string line;
        int currentFace = 0;
        
        while (getline(iFile, line) && currentFace < 6) {
            if (line.length() < 9) continue;
            
            for (int i = 0; i < 9; ++i) {
                if (i < line.length()) {
                    colorData[currentFace][i] = line[i];
                }
            }
            currentFace++;
        }
        
        iFile.close();
        return new Cube(colorData);
    }
};

int main() {
    TestRunner::runAllTests();
    return 0;
}
