//
// Created by prath on 30-09-2024.
//

#include "RubiksCube.h"

// Given a color, return its first letter

char RubiksCube::getColorLetter(COLOR color) {
    switch (color) {
        case COLOR::BLUE:
            return 'B';
        case COLOR::RED:
            return 'R';
        case COLOR::GREEN:
            return 'G';
        case COLOR::WHITE:
            return 'W';
        case COLOR::ORANGE:
            return 'O';
        case COLOR::YELLOW:
            return 'Y';
    }
}

// Describe move using an index
string RubiksCube::getMove(Move ind) {
    switch (ind) {
        case MOVE::L:
            return "L";
        case MOVE::LPRIME:
            return "L'";
        case MOVE::L2:
            return "L2";
        case MOVE::B:
            return "B";
        case MOVE::B2:
            return "B2";
        case MOVE::BPRIME:
            return "B'";
        case MOVE::D:
            return "D";
        case MOVE::D2:
            return "D2";
        case MOVE::DPRIME:
            return "D'";
        case MOVE::F:
            return "F";
        case MOVE::F2:
            return "F2";
        case MOVE::FPRIME:
            return "F'";
        case MOVE::R:
            return "R";
        case MOVE::R2:
            return "R2";
        case MOVE::RPRIME:
            return "R'";
        case MOVE::U:
            return "U";
        case MOVE::U2:
            return "U2";
        case MOVE::UPRIME:
            return "U'";
    }
}

RubiksCube &RubiksCube::move(MOVE ind) {
    switch(ind) {
        case MOVE::B:
            return this->b();
        case MOVE::B2:
            return this->b2();
        case MOVE::D:
            return this->d();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->f();
        case MOVE::F2:
            return this->f2();
        case MOVE::L:
            return this->l();
        case MOVE::L2:
            return this->f2();
        case MOVE::R:
            return this->r();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->u();
        case MOVE::U2:
            return this->u2();
        case MOVE::BPRIME:
            return this->bPrime();
        case MOVE::DPRIME:
            return this->dPrime();
        case MOVE::FPRIME:
            return this->fPrime();
        case MOVE::LPRIME:
            return this->lPrime();
        case MOVE::RPRIME:
            return this->rPrime();
        case MOVE::UPRIME:
            return this->uPrime();
    }
}

// Invert a move

RubiksCube &RubiksCube::invert(MOVE ind) {
    switch(ind) {
        case MOVE::B:
            return this->bPrime();
        case MOVE::B2:
            return this->b2();
        case MOVE::D:
            return this->dPrime();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->fPrime();
        case MOVE::F2:
            return this->f2();
        case MOVE::L:
            return this->lPrime();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->rPrime();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->uPrime();
        case MOVE::U2:
            return this->u2();
        case MOVE::BPRIME:
            return this->b();
        case MOVE::DPRIME:
            return this->d();
        case MOVE::FPRIME:
            return this->f();
        case MOVE::LPRIME:
            return l();
        case MOVE::RPRIME:
            return this->r();
        case MOVE::UPRIME:
            return this->u();
    }
}

void RubiksCube::print() const {
    cout<<"Rubik's Cube:\n\n";
    for(int row=0;row<3;row++) {
        for(unsigned i=0;i<7;i++) {
            cout<<" ";
        }
        for(int col=0;col<3;col++) {
            cout<getColorLetter(getColor(FACE::UP,row,col));
        }
        cout<<"\n";
    }
    cout<<"\n";
    for(int row=0;row<3;row++) {
        for(int col=0;col<3;col++) {
            cout<<getColorLetter(getColor(FACE::LEFT,row,col))<<" ";
        }
        cout<<" ";
        for(int col=0;col<3;col++) {
            cout<<getColorLetter(getColor(FACE::FRONT,row, col))<<" ";
        }
        cout<<" ";
        for(int col=0;col<3;col++) {
            cout<<getColorLetter(getColor(FACE::RIGHT,row,col))<<" ";
        }
        cout<<"\n";
    }
    for(int row=0;row<3;row++) {
        for(int i=0;i<7;i++) {
            cout<<" ";
        }
        for(int col=0;col<3;col++) {
            cout<<getColorLetter(getColor(FACE::DOWN,row,col))<<" ";
        }
        cout<<"\n";
    }cout<<"\n";
}
