#include "Cube.h"
#include <iostream>
#include <vector>

using namespace std;

// read the input from utilities class then use it to init the cube
Cube::Cube(vector<vector<vector<char>>> newFaces){
  cubeFaces = newFaces;
}

// selects one of the moves below
void Cube::applyMove(string move){
  switch(move){
    // i do later
  }
}

// checks if every side is one color
bool Cube::isSolved(){
  for(int i = 0; i < NUM_FACES; i++){
    char faceColor = cubeFaces[i][1][1];
    for(int j = 0; j < ROWS; j++){
      for(int k = 0; k < COLS; k++){
        if(cubeFaces[i][j][k] != faceColor) return false;
      }
    }
  }
  return true;
}

// not really sure what this one is for
string Cube::getStateHash();

// -------------------------------------------------------
// 18 possible moves. I tried to make the names make sense
// -------------------------------------------------------

// The layer that you are looking at and the 2 layers behind it

void Cube::layer_facing_you_R(){
  // Shift colors on the face
  vector<vector<char>> tempFace = cubeFaces[FRONT];
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      cubeFaces[FRONT][j][2 - i] = tempFace[i][j];
    }
  }
  // Shift colors on the side
  vector<char> temp(3);
  for (int i = 0; i < 3; i++) temp[i] = cubeFaces[TOP][2][i]; // Save bottom row of TOP face
  for (int i = 0; i < 3; i++) cubeFaces[TOP][2][i] = cubeFaces[LEFT][2 - i][2]; // right column of LEFT -> bottom row of TOP
  for (int i = 0; i < 3; i++) cubeFaces[LEFT][i][2] = cubeFaces[BOTTOM][0][2 - i]; // top row of BOTTOM -> right column of LEFT
  for (int i = 0; i < 3; i++) cubeFaces[BOTTOM][0][i] = cubeFaces[RIGHT][i][0]; // left column of RIGHT -> top row of BOTTOM
  for (int i = 0; i < 3; i++) cubeFaces[RIGHT][i][0] = temp[i]; // Saved bottom row of TOP -> left column of RIGHT
}
void Cube::layer_facing_you_L(){
  // Shift colors on the face
  vector<vector<char>> tempFace = cubeFaces[FRONT];
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      cubeFaces[FRONT][2 - j][i] = tempFace[i][j];
    }
  }
  // Shift colors on the side
  vector<char> temp(3);
  for (int i = 0; i < 3; i++) temp[i] = cubeFaces[TOP][2][i]; // Save bottom row of TOP face
  for (int i = 0; i < 3; i++) cubeFaces[TOP][2][i] = cubeFaces[RIGHT][i][0]; // left column of RIGHT -> bottom row of TOP
  for (int i = 0; i < 3; i++) cubeFaces[RIGHT][i][0] = cubeFaces[BOTTOM][0][2 - i]; // top row of BOTTOM -> left column of RIGHT
  for (int i = 0; i < 3; i++) cubeFaces[BOTTOM][0][i] = cubeFaces[LEFT][2 - i][2]; // right colomn of LEFT -> top row of BOTTOM
  for (int i = 0; i < 3; i++) cubeFaces[LEFT][i][2] = temp[i]; // Saved bottom row of TOP -> right column of LEFT
}

void Cube::middle_wide_layer_R(){
  // Shift colors on the side
  vector<char> temp(3);
  for (int i = 0; i < 3; i++) temp[i] = cubeFaces[TOP][1][i]; // Save middle row of TOP face
  for (int i = 0; i < 3; i++) cubeFaces[TOP][1][i] = cubeFaces[LEFT][2 - i][1]; // middle column of LEFT -> middle row of TOP
  for (int i = 0; i < 3; i++) cubeFaces[LEFT][i][1] = cubeFaces[BOTTOM][1][2 - i]; // middle row of BOTTOM -> middle column of LEFT
  for (int i = 0; i < 3; i++) cubeFaces[BOTTOM][1][i] = cubeFaces[RIGHT][i][1]; // middle column of RIGHT -> middle row of BOTTOM
  for (int i = 0; i < 3; i++) cubeFaces[RIGHT][i][1] = temp[i]; // Saved middle row of TOP -> middle column of RIGHT
}
void Cube::middle_wide_layer_L();
void Cube::back_layer_R();
void Cube::back_layer_L();

// Horizontal layers
void Cube::top_horizontal_R();
void Cube::top_horizontal_L();
void Cube::middle_horizontal_R();
void Cube::middle_horizontal_L();
void Cube::bottom_horizontal_R();
void Cube::bottom_horizontal_L();

// Vertical layers (they go up and down, not left and right)
void Cube::left_vertical_U();
void Cube::left_vertical_D();
void Cube::middle_vertical_U();
void Cube::middle_vertical_D();
void Cube::right_vertical_U();
void Cube::right_vertical_D();

// Helper function (maybe we dont need)
int opposite_face(int current_face) {
    if (current_face % 2 == 0) return current_face + 1; // even
    else return current_face - 1; // odd
}
