#include "include/Cube.h"

// read the input from utilities class then use it to init the cube
Cube::Cube(vector<vector<vector<char>>> newFaces){
  cubeFaces = newFaces;
}

// selects one of the moves below
void Cube::applyMove(string move){
  switch(move){
    case "W":
      W_clockwise();
      break;
    case "W'":
      W_counter_clockwise();
      break;
    case "Y":
      Y_clockwise();
      break;
    case "Y'":
      Y_counter_clockwise();
      break; 
    case "G":
      G_clockwise();
      break;
    case "G'":
      G_counter_clockwise();
      break;
    case "B":
      B_clockwise();
      break;
    case "B'":
      B_counter_clockwise();
      break;
    case "O":
      O_clockwise();
      break;
    case "O'":
      O_counter_clockwise();
      break;
    case "R":
      R_clockwise();
      break;
    case "R'":
      R_counter_clockwise();
      break;
    case "WY":
      W_clockwise();
      Y_counter_clockwise();
      break;
    case "WY'":
      Y_clockwise();
      W_counter_clockwise();
      break;
    case "GB":
      G_clockwise();
      B_counter_clockwise();
      break;
    case "GB'":
      B_clockwise();
      G_counter_clockwise();
      break;
    case "OR":
      O_clockwise();
      R_counter_clockwise();
      break;
    case "OR'":
      R_clockwise();
      O_counter_clockwise();
      break;
    default:
      cout << "Invalid move" << endl;
      break;
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

void Cube::W_clockwise(){
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
void Cube::W_counter_clockwise(){
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

void Cube::Y_clockwise(){
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
void Cube::Y_counter_clockwise(){
  // Shift colors on face
  vector<vector<char>> tempFace = cubeFaces[YELLOW];
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      cubeFaces[YELLOW][2 - j][i] = tempFace[i][j];
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

void Cube::G_clockwise(){
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
void Cube::G_counter_clockwise(){
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

void Cube::B_clockwise(){
  // Shift colors on face
  vector<vector<char>> tempFace = cubeFaces[BLUE];
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      cubeFaces[BLUE][j][2 - i] = tempFace[i][j];
  }}
  // Shift colors on side
  vector<char> temp(3);
  for (int i = 0; i < 3; i++) temp[i] = cubeFaces[WHITE][0][i]; // Save top row of white
  for (int i = 0; i < 3; i++) cubeFaces[WHITE][0][i] = cubeFaces[RED][i][2]; // Right column of red -> top row of white
  for (int i = 0; i < 3; i++) cubeFaces[RED][2-i][2] = cubeFaces[YELLOW][2][i]; // Bottom row of yellow -> right column of red
  for (int i = 0; i < 3; i++) cubeFaces[YELLOW][2][i] = cubeFaces[ORANGE][i][0]; // Left column of orange -> bottom row of yellow
  for (int i = 0; i < 3; i++) cubeFaces[ORANGE][2-i][0] = temp[i]; // Saved top row of white -> left column of orange
}
void Cube::B_counter_clockwise(){
  // Shift colors on face
  vector<vector<char>> tempFace = cubeFaces[BLUE];
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      cubeFaces[BLUE][2 - j][i] = tempFace[i][j];
  }}
  // Shift colors on side
  vector<char> temp(3);
  for (int i = 0; i < 3; i++) temp[i] = cubeFaces[WHITE][0][i]; // Save top row of white
  for (int i = 0; i < 3; i++) cubeFaces[WHITE][0][2-i] = cubeFaces[ORANGE][i][0]; // Left column of orange -> top row of white
  for (int i = 0; i < 3; i++) cubeFaces[ORANGE][i][0] = cubeFaces[YELLOW][2][i]; // Bottom row of yellow -> left column of orange
  for (int i = 0; i < 3; i++) cubeFaces[YELLOW][2][2-i] = cubeFaces[RED][i][2]; // Right column of red -> bottom row of yellow
  for (int i = 0; i < 3; i++) cubeFaces[RED][i][2] = temp[i]; // Saved top row of white -> right column of red
}

// ============================================================================================================================
// Orange face
// ============================================================================================================================

void Cube::O_clockwise(){
  // Shift colors on face
  vector<vector<char>> tempFace = cubeFaces[ORANGE];
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      cubeFaces[ORANGE][j][2 - i] = tempFace[i][j];
  }}
  // Shift colors on side
  vector<char> temp(3);
  for (int i = 0; i < 3; i++) temp[i] = cubeFaces[WHITE][i][0]; // Save left column of white
  for (int i = 0; i < 3; i++) cubeFaces[WHITE][i][0] = cubeFaces[BLUE][i][2]; // Right column of blue -> left column of white
  for (int i = 0; i < 3; i++) cubeFaces[BLUE][i][2] = cubeFaces[YELLOW][i][0]; // Left column of yellow -> right column of blue
  for (int i = 0; i < 3; i++) cubeFaces[YELLOW][i][0] = cubeFaces[GREEN][i][0]; // Left column of green -> left column of yellow
  for (int i = 0; i < 3; i++) cubeFaces[GREEN][i][0] = temp[i]; // Saved left column of white -> left column of green
}
void Cube::O_counter_clockwise(){
  // Shift colors on face
  vector<vector<char>> tempFace = cubeFaces[ORANGE];
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      cubeFaces[ORANGE][2 - j][i] = tempFace[i][j];
  }}
  // Shift colors on side
  vector<char> temp(3);
  for (int i = 0; i < 3; i++) temp[i] = cubeFaces[WHITE][i][0]; // Save left column of white
  for (int i = 0; i < 3; i++) cubeFaces[WHITE][i][0] = cubeFaces[GREEN][i][0]; // Left column of green -> left column of white
  for (int i = 0; i < 3; i++) cubeFaces[GREEN][i][0] = cubeFaces[YELLOW][i][0]; // Left column of yellow -> left column of green
  for (int i = 0; i < 3; i++) cubeFaces[YELLOW][i][0] = cubeFaces[BLUE][i][2]; // Right column of blue -> left column of yellow
  for (int i = 0; i < 3; i++) cubeFaces[BLUE][i][2] = temp[i]; // Saved left column of white -> right column of blue
}

// ============================================================================================================================
// Red face
// ============================================================================================================================

void Cube::R_clockwise(){
  // Shift colors on face
  vector<vector<char>> tempFace = cubeFaces[RED];
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      cubeFaces[RED][j][2 - i] = tempFace[i][j];
  }}
  // Shift colors on side
  vector<char> temp(3);
  for (int i = 0; i < 3; i++) temp[i] = cubeFaces[WHITE][i][2]; // Save right column of white
  for (int i = 0; i < 3; i++) cubeFaces[WHITE][i][2] = cubeFaces[GREEN][i][2]; // Right column of green -> right column of white
  for (int i = 0; i < 3; i++) cubeFaces[GREEN][i][2] = cubeFaces[YELLOW][i][2]; // Right column of yellow -> right column of green
  for (int i = 0; i < 3; i++) cubeFaces[YELLOW][i][2] = cubeFaces[BLUE][i][0]; // Left column of blue -> right column of yellow
  for (int i = 0; i < 3; i++) cubeFaces[BLUE][i][0] = temp[i]; // Saved right column of white -> left column of blue
}
void Cube::R_counter_clockwise(){
  // Shift colors on face
  vector<vector<char>> tempFace = cubeFaces[RED];
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      cubeFaces[RED][2 - j][i] = tempFace[i][j];
  }}
  // Shift colors on side
  vector<char> temp(3);
  for (int i = 0; i < 3; i++) temp[i] = cubeFaces[WHITE][i][2]; // Save right column of white
  for (int i = 0; i < 3; i++) cubeFaces[WHITE][i][2] = cubeFaces[BLUE][i][0]; // Left column of blue -> right column of white
  for (int i = 0; i < 3; i++) cubeFaces[BLUE][i][0] = cubeFaces[YELLOW][i][2]; // Right column of yellow -> left column of blue
  for (int i = 0; i < 3; i++) cubeFaces[YELLOW][i][2] = cubeFaces[GREEN][i][2]; // Right column of green -> right column of yellow
  for (int i = 0; i < 3; i++) cubeFaces[GREEN][i][2] = temp[i]; // Saved right column of white -> right column of green
}
