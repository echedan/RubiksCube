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
void Cube::layer_facing_you_R(int current_face){
  // Shift colors on the face
  vector<vector<char>> temp = cubeFaces[current_face];
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      cubeFaces[current_face][j][ROWS - 1 - i] = temp[i][j];
    }
  }
  // Shift colors on the side
  
}
void Cube::layer_facing_you_L();
void Cube::middle_wide_layer_R();
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
