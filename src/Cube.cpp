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
// 12 moves (they can be combined to simulate more moves)
// -------------------------------------------------------

// ============================================================================================================================
// White face
// ============================================================================================================================

void W_clockwise(){
  // Shift colors on face
  vector<vector<char>> tempFace = cubeFaces[WHITE];
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      cubeFaces[WHITE][j][2 - i] = tempFace[i][j];
  }}
  // Shift colors on side
  vector<char> temp(3);
  for (int i = 0; i < 3; i++) temp[i] = cubeFaces[ORANGE][0][i]; // Save top row of orange
  for (int i = 0; i < 3; i++) cubeFaces[ORANGE][0][i] = cubeFaces[GREEN][0][i]; // Top row of green -> top row of orange
  for (int i = 0; i < 3; i++) cubeFaces[GREEN][0][i] = cubeFaces[RED][0][i] // Top row of red -> top row of green
  for (int i = 0; i < 3; i++) cubeFaces[RED][0][i] = cubeFaces[BLUE][0][i] // Top row of blue -> top row of red
  for (int i = 0; i < 3; i++) cubeFaces[BLUE][0][i] = temp[i]; // Saved top row of orange -> top row of blue
}
void W_counter_clockwise(){
  // Shift colors on face
  vector<vector<char>> tempFace = cubeFaces[WHITE];
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      cubeFaces[WHITE][2 - j][i] = tempFace[i][j];
  }}
  // Shift colors on side
  vector<char> temp(3);
  for (int i = 0; i < 3; i++) temp[i] = cubeFaces[ORANGE][0][i]; // Save top row of orange
  for (int i = 0; i < 3; i++) cubeFaces[ORANGE][0][i] = cubeFaces[BLUE][0][i]; // Top row of blue -> top row of orange
  for (int i = 0; i < 3; i++) cubeFaces[BLUE][0][i] = cubeFaces[RED][0][i] // Top row of red -> top row of blue
  for (int i = 0; i < 3; i++) cubeFaces[RED][0][i] = cubeFaces[GREEN][0][i] // Top row of green -> top row of red
  for (int i = 0; i < 3; i++) cubeFaces[GREEN][0][i] = temp[i]; // Saved top row of orange -> top row of green
}

// ============================================================================================================================
// Yellow face
// ============================================================================================================================

void Y_clockwise(){
  // Shift colors on face
  vector<vector<char>> tempFace = cubeFaces[YELLOW];
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      cubeFaces[YELLOW][j][2 - i] = tempFace[i][j];
  }}
  // Shift colors on side
  vector<char> temp(3);
  for (int i = 0; i < 3; i++) temp[i] = cubeFaces[ORANGE][2][i]; // Save bottom row of orange
  for (int i = 0; i < 3; i++) cubeFaces[ORANGE][2][i] = cubeFaces[BLUE][2][i]; // Bottom row of blue -> bottom row of orange
  for (int i = 0; i < 3; i++) cubeFaces[BLUE][2][i] = cubeFaces[RED][2][i] // Bottom row of red -> bottom row of blue
  for (int i = 0; i < 3; i++) cubeFaces[RED][2][i] = cubeFaces[GREEN][2][i] // Bottom row of green -> bottom row of red
  for (int i = 0; i < 3; i++) cubeFaces[GREEN][2][i] = temp[i]; // Saved bottom row of orange -> bottom row of green
}
void Y_counter_clockwise(){
  // Shift colors on face
  vector<vector<char>> tempFace = cubeFaces[WHITE];
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      cubeFaces[WHITE][2 - j][i] = tempFace[i][j];
  }}
  // Shift colors on side
  vector<char> temp(3);
  for (int i = 0; i < 3; i++) temp[i] = cubeFaces[ORANGE][2][i]; // Save bottom row of orange
  for (int i = 0; i < 3; i++) cubeFaces[ORANGE][2][i] = cubeFaces[GREEN][2][i]; // Bottom row of green -> bottom row of orange
  for (int i = 0; i < 3; i++) cubeFaces[GREEN][2][i] = cubeFaces[RED][2][i] // Bottom row of red -> bottom row of green
  for (int i = 0; i < 3; i++) cubeFaces[RED][2][i] = cubeFaces[BLUE][2][i] // Bottom row of blue -> bottom row of red
  for (int i = 0; i < 3; i++) cubeFaces[BLUE][2][i] = temp[i]; // Saved bottom row of orange -> bottom row of blue
}

// ============================================================================================================================
// Green face
// ============================================================================================================================

void G_clockwise(){
  // Shift colors on face
  vector<vector<char>> tempFace = cubeFaces[GREEN];
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      cubeFaces[GREEN][j][2 - i] = tempFace[i][j];
  }}
  // Shift colors on side
  vector<char> temp(3);
  for (int i = 0; i < 3; i++) temp[i] = cubeFaces[WHITE][2][i]; // Save bottom row of white
  for (int i = 0; i < 3; i++) cubeFaces[WHITE][2][2-i] = cubeFaces[ORANGE][i][2]; // Right column of orange -> bottom row of white
  for (int i = 0; i < 3; i++) cubeFaces[ORANGE][i][2] = cubeFaces[YELLOW][0][i]; // Top row of yellow -> right column of orange
  for (int i = 0; i < 3; i++) cubeFaces[YELLOW][0][2-i] = cubeFaces[RED][i][0]; // Left column of red -> top row of yellow
  for (int i = 0; i < 3; i++) cubeFaces[RED][i][0] = temp[i]; // Saved bottom row of white -> left column of red
}
void G_counter_clockwise(){
  // Shift colors on face
  vector<vector<char>> tempFace = cubeFaces[GREEN];
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      cubeFaces[GREEN][2 - j][i] = tempFace[i][j];
  }}
  // Shift colors on side
  vector<char> temp(3);
  for (int i = 0; i < 3; i++) temp[i] = cubeFaces[WHITE][2][i]; // Save bottom row of white
  for (int i = 0; i < 3; i++) cubeFaces[WHITE][2][i] = cubeFaces[RED][i][0]; // Left column of red -> bottom row of white
  for (int i = 0; i < 3; i++) cubeFaces[RED][2-i][0] = cubeFaces[YELLOW][0][i]; // Top row of yellow -> left column of red
  for (int i = 0; i < 3; i++) cubeFaces[YELLOW][0][i] = cubeFaces[ORANGE][i][2]; // Right column of orange -> top row of yellow
  for (int i = 0; i < 3; i++) cubeFaces[ORANGE][2-i][2] = temp[i]; // Saved bottom row of white -> right column of orange
}

// ============================================================================================================================
// Blue face
// ============================================================================================================================

void B_clockwise();
void B_counter_clockwise();

// ============================================================================================================================
// Orange face
// ============================================================================================================================

void O_clockwise();
void O_counter_clockwise();

// ============================================================================================================================
// Red face
// ============================================================================================================================

void R_clockwise();
void R_counter_clockwise();
