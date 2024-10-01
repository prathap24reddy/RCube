//
// Created by prath on 30-09-2024.
//

#ifndef RUBIKSCUBE_H
#define RUBIKSCUBE_H

#include "bits/stdc++.h"

using namespace std;

class RubiksCube {
public:
    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };
    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };
    enum class MOVE {
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };
    // Returns the color of the cubie at (row, col)
    virtual COLOR getColor(FACE face, unsigned int row, unsigned int col) const =0;

    // Returns the first letter of the given color
    static char getColorLetter(COLOR color);

    // Returns true if the Cube is solved, vice versa
    virtual bool isSolved() const = 0;

    // Returns the move in the string format
    static string getMove(MOVE ind);

    // print the cube
    void print () const;

    // Randomly shuffle the cube with 'times' moves and returns the moves performed.
    vector<MOVE> randomShuffleCube(unsigned int times);

    // Perform moves on the cube
    RubiksCube &move(MOVE ind);

    // Invert a move
    RubiksCube &invert(MOVE ind);

    // Moves
    virtual RubiksCube &f() = 0;

    virtual RubiksCube &fPrime() = 0;

    virtual RubiksCube &f2() = 0;

    virtual RubiksCube &u() = 0;

    virtual RubiksCube &uPrime() = 0;

    virtual RubiksCube &u2() = 0;

    virtual RubiksCube &l() = 0;

    virtual RubiksCube &lPrime() = 0;

    virtual RubiksCube &l2() = 0;

    virtual RubiksCube &r() = 0;

    virtual RubiksCube &d() = 0;

    virtual RubiksCube &dPrime() = 0;

    virtual RubiksCube &d2() = 0;

    virtual RubiksCube &rPrime() = 0;

    virtual RubiksCube &r2() = 0;

    virtual RubiksCube &b() = 0;

    virtual RubiksCube &bPrime() = 0;

    virtual RubiksCube &b2() = 0;

    string getCornerColorString(uint8_t ind) const;

    uint8_t getCornerIndex(uint8_t ind) const;

    uint8_t getCornerOrientation(uint8_t ) const;
};


#endif //RUBIKSCUBE_H
