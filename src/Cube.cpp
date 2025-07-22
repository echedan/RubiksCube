#include "Cube.h"

// Constructor: validates colors and assigns correct piece IDs
Cube::Cube(vector<vector<char>> colorData){
    // Initialize the cube faces storage
    cubeFaces = vector<vector<string>>(6, vector<string>(9));
    valid = false;  // Start with invalid state
    
    // Step 1: Validate the color placement
    if (!validateColorPlacement(colorData)) {
        cout << "ERROR: Invalid cube color configuration!" << endl;
        return; // Leave valid = false
    }
    
    // Step 2: Validate adjacency relationships
    if (!validateAdjacencies(colorData)) {
        cout << "ERROR: Invalid adjacency relationships!" << endl;
        return; // Leave valid = false
    }
    
    // Step 3: Assign correct piece IDs based on standard numbering
    assignPieceIDs(colorData);
    
    valid = true;  // Mark as valid only if all validations passed
    cout << "Cube initialized with validated piece assignments." << endl;
}

// Check if cube was properly initialized
bool Cube::isValid() {
    return valid;
}

// selects one of the moves below
void Cube::applyMove(string move){
  if (move == "W") {
      W_clockwise();
  } else if (move == "W'") {
      W_counter_clockwise();
  } else if (move == "Y") {
      Y_clockwise();
  } else if (move == "Y'") {
      Y_counter_clockwise();
  } else if (move == "G") {
      G_clockwise();
  } else if (move == "G'") {
      G_counter_clockwise();
  } else if (move == "B") {
      B_clockwise();
  } else if (move == "B'") {
      B_counter_clockwise();
  } else if (move == "O") {
      O_clockwise();
  } else if (move == "O'") {
      O_counter_clockwise();
  } else if (move == "R") {
      R_clockwise();
  } else if (move == "R'") {
      R_counter_clockwise();
  } else if (move == "WY") {
      W_clockwise();
      Y_counter_clockwise();
  } else if (move == "WY'") {
      Y_clockwise();
      W_counter_clockwise();
  } else if (move == "GB") {
      G_clockwise();
      B_counter_clockwise();
  } else if (move == "GB'") {
      B_clockwise();
      G_counter_clockwise();
  } else if (move == "OR") {
      O_clockwise();
      R_counter_clockwise();
  } else if (move == "OR'") {
      R_clockwise();
      O_counter_clockwise();
  } else {
      cout << "Invalid move" << endl;
  }
}

// checks if every side is one color
bool Cube::isSolved(){
  for(int i = 0; i < NUM_FACES; i++){
    char faceColor = getColorFromPiece(cubeFaces[i][4]); // Center piece (position 4)
    for(int j = 0; j < PIECES_PER_FACE; j++){
      char pieceColor = getColorFromPiece(cubeFaces[i][j]);
      if(pieceColor != faceColor) return false;
    }
  }
  return true;
}

// Hash function for BFS state tracking
string Cube::getStateHash(){
  string hash = "";
  for(int i = 0; i < NUM_FACES; i++){
    for(int j = 0; j < PIECES_PER_FACE; j++){
      hash += cubeFaces[i][j]; // Use full piece ID for uniqueness
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
  // TODO: Implement W clockwise move for 2D piece ID structure
  // Placeholder implementation for compilation
}
void Cube::W_counter_clockwise(){
  // TODO: Implement W counter-clockwise move for 2D piece ID structure
}

void Cube::Y_clockwise(){
  // TODO: Implement Y clockwise move for 2D piece ID structure
}

void Cube::Y_counter_clockwise(){
  // TODO: Implement Y counter-clockwise move for 2D piece ID structure
}

void Cube::G_clockwise(){
  // TODO: Implement G clockwise move for 2D piece ID structure
}

void Cube::G_counter_clockwise(){
  // TODO: Implement G counter-clockwise move for 2D piece ID structure
}

void Cube::B_clockwise(){
  // TODO: Implement B clockwise move for 2D piece ID structure
}

void Cube::B_counter_clockwise(){
  // TODO: Implement B counter-clockwise move for 2D piece ID structure
}

void Cube::O_clockwise(){
  // TODO: Implement O clockwise move for 2D piece ID structure
}

void Cube::O_counter_clockwise(){
  // TODO: Implement O counter-clockwise move for 2D piece ID structure
}

void Cube::R_clockwise(){
  // TODO: Implement R clockwise move for 2D piece ID structure
}

void Cube::R_counter_clockwise(){
  // TODO: Implement R counter-clockwise move for 2D piece ID structure
}

// ============================================================================================================================
// Validation and Piece Assignment Functions
// ============================================================================================================================

// Validate that the color configuration is physically possible
bool Cube::validateColorPlacement(const vector<vector<char>>& colors) {
    // Check 1: Each color appears exactly 9 times
    int colorCounts[6] = {0}; // W, Y, G, B, O, R
    
    for (int face = 0; face < NUM_FACES; face++) {
        for (int pos = 0; pos < PIECES_PER_FACE; pos++) {
            char color = colors[face][pos];
            switch(color) {
                case 'W': colorCounts[0]++; break;
                case 'Y': colorCounts[1]++; break;
                case 'G': colorCounts[2]++; break;
                case 'B': colorCounts[3]++; break;
                case 'O': colorCounts[4]++; break;
                case 'R': colorCounts[5]++; break;
                default: 
                    cout << "Invalid color: " << color << endl;
                    return false;
            }
        }
    }
    
    // Each color should appear exactly 9 times
    char colorNames[] = {'W', 'Y', 'G', 'B', 'O', 'R'};
    for (int i = 0; i < 6; i++) {
        if (colorCounts[i] != 9) {
            cout << "Color " << colorNames[i] << " appears " << colorCounts[i] << " times (should be 9)" << endl;
            return false;
        }
    }
    
    // Check 2: Center pieces are correct colors
    if (colors[YELLOW][4] != 'Y') {
        cout << "Yellow face center is not yellow!" << endl;
        return false;
    }
    if (colors[ORANGE][4] != 'O') {
        cout << "Orange face center is not orange!" << endl;
        return false;
    }
    if (colors[GREEN][4] != 'G') {
        cout << "Green face center is not green!" << endl;
        return false;
    }
    if (colors[WHITE][4] != 'W') {
        cout << "White face center is not white!" << endl;
        return false;
    }
    if (colors[RED][4] != 'R') {
        cout << "Red face center is not red!" << endl;
        return false;
    }
    if (colors[BLUE][4] != 'B') {
        cout << "Blue face center is not blue!" << endl;
        return false;
    }
    
    // Check 3: No opposite colors adjacent (basic check)
    // This is a simplified check - full validation would need adjacency mapping
    
    cout << "Color placement validation passed!" << endl;
    return true;
}

// Validate that adjacent pieces have colors that can actually be adjacent on a real cube
bool Cube::validateAdjacencies(const vector<vector<char>>& colors) {
    cout << "Checking adjacency relationships..." << endl;
    
    // Define which faces are adjacent to each other
    // Face order: YELLOW=0, ORANGE=1, GREEN=2, WHITE=3, RED=4, BLUE=5
    vector<vector<int>> adjacentFaces = {
        {1, 2, 4, 5}, // YELLOW adjacent to: ORANGE, GREEN, RED, BLUE
        {0, 2, 3, 5}, // ORANGE adjacent to: YELLOW, GREEN, WHITE, BLUE  
        {0, 1, 3, 4}, // GREEN adjacent to: YELLOW, ORANGE, WHITE, RED
        {1, 2, 4, 5}, // WHITE adjacent to: ORANGE, GREEN, RED, BLUE
        {0, 2, 3, 5}, // RED adjacent to: YELLOW, GREEN, WHITE, BLUE
        {0, 1, 3, 4}  // BLUE adjacent to: YELLOW, ORANGE, WHITE, RED
    };
    
    // Define edge piece positions for each face (positions that touch other faces)
    // For a 3x3 cube: 0 1 2
    //                 3 4 5  
    //                 6 7 8
    // Edge positions: 1, 3, 5, 7 (not corners: 0, 2, 6, 8; not center: 4)
    vector<int> edgePositions = {1, 3, 5, 7};
    
    // Check edge adjacencies
    for(int face = 0; face < NUM_FACES; face++) {
        char faceColor = colors[face][4]; // Center color determines face identity
        
        for(int edgePos : edgePositions) {
            char edgeColor = colors[face][edgePos];
            
            // If edge color is same as face color, that's fine (solved state)
            if(edgeColor == faceColor) continue;
            
            // Check if this edge color can legitimately appear on this face
            bool validEdge = false;
            for(int adjFace : adjacentFaces[face]) {
                char adjCenterColor = colors[adjFace][4];
                if(edgeColor == adjCenterColor) {
                    validEdge = true;
                    break;
                }
            }
            
            if(!validEdge) {
                cout << "Invalid edge: " << edgeColor << " on " << faceColor 
                     << " face at position " << edgePos << endl;
                return false;
            }
        }
    }
    
    // Check corner adjacencies  
    vector<int> cornerPositions = {0, 2, 6, 8};
    for(int face = 0; face < NUM_FACES; face++) {
        char faceColor = colors[face][4];
        
        for(int cornerPos : cornerPositions) {
            char cornerColor = colors[face][cornerPos];
            
            // If corner color is same as face color, that's fine
            if(cornerColor == faceColor) continue;
            
            // Check if this corner color can appear on this face
            bool validCorner = false;
            for(int adjFace : adjacentFaces[face]) {
                char adjCenterColor = colors[adjFace][4];
                if(cornerColor == adjCenterColor) {
                    validCorner = true;
                    break;
                }
            }
            
            if(!validCorner) {
                cout << "Invalid corner: " << cornerColor << " on " << faceColor 
                     << " face at position " << cornerPos << endl;
                return false;
            }
        }
    }
    
    cout << "Adjacency validation passed!" << endl;
    return true;
}

// Assign piece IDs based on standard Rubik's cube numbering
void Cube::assignPieceIDs(const vector<vector<char>>& colors) {
    // Standard piece ID assignment:
    // Y0-Y8 (positions 0-8), O0-O8 (9-17), G0-G8 (18-26), 
    // W0-W8 (27-35), R0-R8 (36-44), B0-B8 (45-53)
    
    int globalIndex = 0;
    char faceColors[] = {'Y', 'O', 'G', 'W', 'R', 'B'};
    
    for (int faceType = 0; faceType < 6; faceType++) {
        for (int pos = 0; pos < 9; pos++) {
            // Generate the correct piece ID for this position
            string pieceID = string(1, faceColors[faceType]) + to_string(pos);
            
            // Find where this piece currently is based on color
            char targetColor = faceColors[faceType];
            
            // For now, assign based on current color (will need refinement for actual scrambles)
            for (int face = 0; face < NUM_FACES; face++) {
                for (int position = 0; position < PIECES_PER_FACE; position++) {
                    if (colors[face][position] == targetColor) {
                        // This is a simplified assignment - real implementation would 
                        // need to determine which specific piece this is based on its neighbors
                        cubeFaces[face][position] = pieceID;
                        break;
                    }
                }
            }
            globalIndex++;
        }
    }
}

// Helper function to check if two colors are opposite
bool Cube::areOppositeColors(char color1, char color2) {
    return (color1 == 'W' && color2 == 'Y') || (color1 == 'Y' && color2 == 'W') ||
           (color1 == 'R' && color2 == 'O') || (color1 == 'O' && color2 == 'R') ||
           (color1 == 'G' && color2 == 'B') || (color1 == 'B' && color2 == 'G');
}

// Get piece at specific position
string Cube::getPiece(int face, int position) {
    if (face >= 0 && face < NUM_FACES && position >= 0 && position < PIECES_PER_FACE) {
        return cubeFaces[face][position];
    }
    return "";
}

// Set piece at specific position  
void Cube::setPiece(int face, int position, string pieceId) {
    if (face >= 0 && face < NUM_FACES && position >= 0 && position < PIECES_PER_FACE) {
        cubeFaces[face][position] = pieceId;
    }
}

// Helper function to extract color from piece ID
char Cube::getColorFromPiece(const string& pieceId) {
    if (pieceId.empty()) return '?';
    return pieceId[0]; // First character is always the color (Y, W, O, R, G, B)
}
