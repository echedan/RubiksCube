#include "include/Cube.h"

// read the input from utilities class then use it to init the cube
Cube::Cube(vector<vector<char>> newFaces){
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
    char faceColor = cubeFaces[i][4];
    for(int j = 0; j < SQUARES; j++){
      if(cubeFaces[i][j] != faceColor) return false;
    }
  }
  return true;
}

// returns hash
string Cube::getStateHash(){
  string hash = "";
  for(int i = 0; i < NUM_FACES; i++){
    for(int j = 0; j < SQUARES; j++){
      hash += cubeFaces[i][j];
    }
  }
  return hash;
}

// -------------------------------------------------------
// 12 moves (they can be combined to simulate more moves)
// -------------------------------------------------------

// ============================================================================================================================
// White face
// ============================================================================================================================

void Cube::W_clockwise(){
  // Shift colors on face
  vector<char> tempFace = cubeFaces[WHITE];
  for(int i = 0; i < SQUARES; i++){
    if(i < 3) cubeFaces[WHITE][3*i+2] = tempFace[i];
    else if(i > 5) cubeFaces[WHITE][3*i-18] = tempFace[i];
    else cubeFaces[WHITE][3*i-8] = tempFace[i];
  }
  // Shift colors on side
  vector<char> temp = {cubeFaces[RED][6], cubeFaces[RED][7], cubeFaces[RED][8]}; // Save bottom row of red
  for (int i = 6; i < 9; i++) cubeFaces[RED][i] = cubeFaces[BLUE][i]; // Bottom row of blue -> bottom row of red
  for (int i = 6; i < 9; i++) cubeFaces[BLUE][i] = cubeFaces[ORANGE][i]; // Bottom row of orange -> bottom row of blue
  for (int i = 6; i < 9; i++) cubeFaces[ORANGE][i] = cubeFaces[GREEN][i]; // Bottom row of green -> bottom row of orange
  for (int i = 0; i < 3; i++) cubeFaces[GREEN][i+6] = temp[i]; // Saved row of red -> bottom row of green
}
void Cube::W_counter_clockwise(){
  // Shift colors on face
  vector<char> tempFace = cubeFaces[WHITE];
  for(int i = 0; i < SQUARES; i++){
    if(i < 3) cubeFaces[WHITE][-3*i+6] = tempFace[i];
    else if(i > 5) cubeFaces[WHITE][-3*i+26] = tempFace[i];
    else cubeFaces[WHITE][-3*i+16] = tempFace[i];
  }
  // Shift colors on side
  vector<char> temp = {cubeFaces[RED][6], cubeFaces[RED][7], cubeFaces[RED][8]}; // Save bottom row of red
  for (int i = 6; i < 9; i++) cubeFaces[RED][i] = cubeFaces[GREEN][i]; // Bottom row of green -> bottom row of red
  for (int i = 6; i < 9; i++) cubeFaces[GREEN][i] = cubeFaces[ORANGE][i]; // Bottom row of orange -> bottom row of green
  for (int i = 6; i < 9; i++) cubeFaces[ORANGE][i] = cubeFaces[BLUE][i]; // Bottom row of blue -> bottom row of orange
  for (int i = 0; i < 3; i++) cubeFaces[BLUE][i+6] = temp[i]; // Saved bottom row of red -> bottom row of blue
}

// ============================================================================================================================
// Yellow face
// ============================================================================================================================

void Cube::Y_clockwise(){
  // Shift colors on face
  vector<char> tempFace = cubeFaces[YELLOW];
  for(int i = 0; i < SQUARES; i++){
    if(i < 3) cubeFaces[YELLOW][3*i+2] = tempFace[i];
    else if(i > 5) cubeFaces[YELLOW][3*i-18] = tempFace[i];
    else cubeFaces[YELLOW][3*i-8] = tempFace[i];
  }
  // Shift colors on side
  vector<char> temp = {cubeFaces[RED][0], cubeFaces[RED][1], cubeFaces[RED][2]}; // Save top row of red
  for (int i = 0; i < 3; i++) cubeFaces[RED][i] = cubeFaces[GREEN][i]; // Top row of green -> top row of red
  for (int i = 0; i < 3; i++) cubeFaces[GREEN][i] = cubeFaces[ORANGE][i]; // Top row of orange -> top row of green
  for (int i = 0; i < 3; i++) cubeFaces[ORANGE][i] = cubeFaces[BLUE][i]; // Top row of blue -> top row of orange
  for (int i = 0; i < 3; i++) cubeFaces[BLUE][i] = temp[i]; // Saved top row of red -> top row of blue
}
void Cube::Y_counter_clockwise(){
  // Shift colors on face
  vector<char> tempFace = cubeFaces[YELLOW];
  for(int i = 0; i < SQUARES; i++){
    if(i < 3) cubeFaces[YELLOW][-3*i+6] = tempFace[i];
    else if(i > 5) cubeFaces[YELLOW][-3*i+26] = tempFace[i];
    else cubeFaces[YELLOW][-3*i+16] = tempFace[i];
  }
  // Shift colors on side
  vector<char> temp = {cubeFaces[RED][0], cubeFaces[RED][1], cubeFaces[RED][2]}; // Save top row of red
  for (int i = 0; i < 3; i++) cubeFaces[RED][i] = cubeFaces[BLUE][i]; // Top row of blue -> top row of red
  for (int i = 0; i < 3; i++) cubeFaces[BLUE][i] = cubeFaces[ORANGE][i]; // Top row of orange -> top row of blue
  for (int i = 0; i < 3; i++) cubeFaces[ORANGE][i] = cubeFaces[GREEN][i]; // Top row of green -> top row of orange
  for (int i = 0; i < 3; i++) cubeFaces[GREEN][i] = temp[i]; // Saved top row of red -> top row of GREEN
}

// ============================================================================================================================
// Green face
// ============================================================================================================================

void Cube::G_clockwise(){
  // Shift colors on face
  vector<char> tempFace = cubeFaces[GREEN];
  for(int i = 0; i < SQUARES; i++){
    if(i < 3) cubeFaces[GREEN][3*i+2] = tempFace[i];
    else if(i > 5) cubeFaces[GREEN][3*i-18] = tempFace[i];
    else cubeFaces[GREEN][3*i-8] = tempFace[i];
  }
  // Shift colors on side
  vector<char> temp = {cubeFaces[YELLOW][6], cubeFaces[YELLOW][7], cubeFaces[YELLOW][8]}; // Save bottom row of yellow
  cubeFaces[YELLOW][6] = cubeFaces[RED][8]; cubeFaces[YELLOW][7] = cubeFaces[RED][5]; cubeFaces[YELLOW][8] = cubeFaces[RED][2]; // Right column of red -> bottom row of yellow
  cubeFaces[RED][2] = cubeFaces[WHITE][0]; cubeFaces[RED][5] = cubeFaces[WHITE][1]; cubeFaces[RED][8] = cubeFaces[WHITE][2]; // Top row of white -> right column of red
  cubeFaces[WHITE][0] = cubeFaces[ORANGE][6]; cubeFaces[WHITE][1] = cubeFaces[ORANGE][3]; cubeFaces[WHITE][2] = cubeFaces[ORANGE][0]; // Left column of orange -> top row of white
  cubeFaces[ORANGE][0] = temp[0]; cubeFaces[ORANGE][3] = temp[1]; cubeFaces[ORANGE][6] = temp[2]; // Saved bottom row of yellow -> left column of orange
}
void Cube::G_counter_clockwise(){
  // Shift colors on face
  vector<char> tempFace = cubeFaces[GREEN];
  for(int i = 0; i < SQUARES; i++){
    if(i < 3) cubeFaces[GREEN][-3*i+6] = tempFace[i];
    else if(i > 5) cubeFaces[GREEN][-3*i+26] = tempFace[i];
    else cubeFaces[GREEN][-3*i+16] = tempFace[i];
  }
  // Shift colors on side
  vector<char> temp = {cubeFaces[YELLOW][6], cubeFaces[YELLOW][7], cubeFaces[YELLOW][8]}; // Save bottom row of yellow
  cubeFaces[YELLOW][6] = cubeFaces[ORANGE][0]; cubeFaces[YELLOW][7] = cubeFaces[ORANGE][3]; cubeFaces[YELLOW][8] = cubeFaces[ORANGE][6]; // Left column of orange -> bottom row of yellow
  cubeFaces[ORANGE][0] = cubeFaces[WHITE][2]; cubeFaces[ORANGE][3] = cubeFaces[WHITE][1]; cubeFaces[ORANGE][6] = cubeFaces[WHITE][0]; // Top row of white -> left column of orange
  cubeFaces[WHITE][0] = cubeFaces[RED][2]; cubeFaces[WHITE][1] = cubeFaces[RED][5]; cubeFaces[WHITE][2] = cubeFaces[RED][8]; // Right column of red -> top row of white
  cubeFaces[RED][2] = temp[2]; cubeFaces[RED][5] = temp[1]; cubeFaces[RED][8] = temp[0]; // Saved bottom row of yellow -> right column of red
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
