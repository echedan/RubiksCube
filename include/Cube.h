#ifndef CUBE_H
#define CUBE_H
#include "Headers.h"

class Cube {
  public:
    enum Face {
      YELLOW = 0,   // Top face
      ORANGE = 1,   // Right face  
      GREEN = 2,    // Front face
      WHITE = 3,    // Bottom face
      RED = 4,      // Left face
      BLUE = 5      // Back face
    };

    // Constructor: takes colors, validates, and assigns piece IDs
    Cube(vector<vector<char>> colorData); 
    void applyMove(string move);
    bool isSolved();
    string getStateHash();
    
    // Validation and assignment functions
    bool validateColorPlacement(const vector<vector<char>>& colors);
    bool validateAdjacencies(const vector<vector<char>>& colors);
    void assignPieceIDs(const vector<vector<char>>& colors);
    
    // Piece access (returns piece IDs like "Y0", "W4", etc.)
    string getPiece(int face, int position);
    void setPiece(int face, int position, string pieceId);
    
    // Helper function to extract color from piece ID
    char getColorFromPiece(const string& pieceId);

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
    static constexpr int PIECES_PER_FACE = 9;
    
    // Store assigned piece IDs (Y0-Y8, O0-O8, G0-G8, W0-W8, R0-R8, B0-B8)
    vector<vector<string>> cubeFaces;  // Final piece assignments
    
    // Helper functions for piece ID management
    string generatePieceID(char color, int globalIndex);
    int getGlobalIndex(char color, int position);
    bool isValidAdjacency(char color1, char color2);
    bool areOppositeColors(char color1, char color2);
};

#endif
