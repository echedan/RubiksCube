#ifndef CUBE_H
#define CUBE_H
#include "Headers.h"

class Cube {
  public:
    enum Face {
      WHITE = 0,
      YELLOW = 1,
      GREEN = 2,
      BLUE = 3,
      ORANGE = 4,
      RED = 5
    };

    Cube(vector<vector<vector<char>>> newFaces); // read the input from utilities class then use it to init the cube
    void applyMove(string move); // selects one of the moves below
    bool isSolved(); // checks if every side is one color
    string getStateHash(); // not really sure what this one is for

    // -------------------------------------------------------
    // 12 moves (can be combined to simulate more moves)
    // -------------------------------------------------------

    // White face
    void W_clockwise();
    void W_counter_clockwise();

    // Yellow face
    void Y_clockwise();
    void Y_counter_clockwise();

    // Green face
    void G_clockwise();
    void G_counter_clockwise();

    // Blue face
    void B_clockwise();
    void B_counter_clockwise();

    // Orange face
    void O_clockwise();
    void O_counter_clockwise();

    // Red face
    void R_clockwise();
    void R_counter_clockwise();
    
  private:
    static constexpr int NUM_FACES = 6;
    static constexpr int ROWS = 3;
    static constexpr int COLS = 3;
    vector<vector<vector<char>>> cubeFaces;
};

#endif
