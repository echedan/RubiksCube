#ifndef CUBE_H
#define CUBE_H

class Cube{
  public:
    enum Face {
      FRONT = 0,
      BACK = 1,
      LEFT = 2,
      RIGHT = 3,
      TOP = 4,
      BOTTOM = 5
    };

    Cube(vector<vector<vector<char>>> newFaces); // read the input from utilities class then use it to init the cube
    void applyMove(string move); // selects one of the moves below
    bool isSolved(); // checks if every side is one color
    string getStateHash(); // not really sure what this one is for

    // -------------------------------------------------------
    // 18 possible moves. I tried to make the names make sense
    // -------------------------------------------------------

    // The layer that you are looking at and the 2 layers behind it
    void layer_facing_you_R();
    void layer_facing_you_L();
    void middle_wide_layer_R();
    void middle_wide_layer_L();
    void back_layer_R();
    void back_layer_L();

    // Horizontal layers
    void top_horizontal_R();
    void top_horizontal_L();
    void middle_horizontal_R();
    void middle_horizontal_L();
    void bottom_horizontal_R();
    void bottom_horizontal_L();

    // Vertical layers (they go up and down, not left and right)
    void left_vertical_U();
    void left_vertical_D();
    void middle_vertical_U();
    void middle_vertical_D();
    void right_vertical_U();
    void right_vertical_D();
    
  private:
    static constexpr int NUM_FACES = 6;
    static constexpr int ROWS = 3;
    static constexpr int COLS = 3;
    vector<vector<vector<char>>> cubeFaces = vector<vector<vector<char>>>(NUM_FACES, vector<vector<char>>(ROWS, vector<char>(COLS)));
    int opposite_face(int current_face);
};

#endif
