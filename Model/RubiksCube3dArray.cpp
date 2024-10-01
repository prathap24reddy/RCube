//
// Created by prath on 01-10-2024.
//

#include "RubiksCube.h"

class RubiksCube3dArray: public RubiksCube{
private:
    void rotateFace(int ind) {
        char temp_arr[3][3]={};
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                temp_arr[i][j]=cube[ind][i][j];
            }
        }
        for(int i=0;i<3;i++) {
            cube[ind][0][i]=temp_arr[2-i][0];
        }
        for(int i=0;i<3;i++) {
            cube[ind][i][2]=temp_arr[0][i];
        }
        for(int i=0;i<3;i++) {
            cube[ind][2][2-i]=temp_arr[i][2];
        }
        for(int i=0;i<3;i++) {
            cube[ind][2-i][0]=temp_arr[2][2-i];
        }
    }
public:
    char cube[6][3][3]{};

    RubiksCube3dArray() {
        for(int i=0;i<6;i++) {
            for(int j=0;j<3;j++) {
                for(int k=0;k<3;k++) {
                    cube[i][j][k]=getColorLetter(COLOR(i));
                }
            }
        }
    }

    COLOR getColor(FACE face, unsigned row, unsigned col){
        char color=cube[int(face)][row][col];
        switch (color) {
        case 'W':
            return COLOR::WHITE;
        case 'G':
            return COLOR::GREEN;
        case 'R':
            return COLOR::RED;
        case 'B':
            return COLOR::BLUE;
        case 'O':
            return COLOR::ORANGE;
        case 'Y':
            return COLOR::YELLOW;
        }
    }

    bool isSolved() const override {
        for(int i=0;i<6;i++) {
            for(int j=0;j<3;j++) {
                for(int k=0;k<3;k++) {
                    if(this->cube[i][j][k]==getColorLetter(COLOR(i))) {
                        continue;
                    }else {
                        return false;
                    }
                }
            }
        }
        return false;
    }

    RubiksCube &u()override {
        this->rotateFace(0);
        char temp_arr[3]={};
        for(int i=0;i<3;i++) {
            temp_arr[i]=cube[4][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[4][0][2-i]=cube[1][0][2-i];
        }
        for(int i=0;i<3;i++) {
            cube[1][0][2-i]=cube[2][0][2-i];
        }
        for(int i=0;i<3;i++) {
            cube[2][0][2-i]=cube[3][0][2-i];
        }
        for(int i=0;i<3;i++) {
            cube[3][0][2-i]=temp_arr[2-i];
        }
        return *this;
    }
    RubiksCube &uPrime()override {
        this->u().u().u();
        return *this;
    }
    RubiksCube &u2()override {
        this->u().u();
        return *this;
    }
    RubiksCube &l()override {
        this->rotateFace(1);
        char temp_arr[3]{};
        for(int i=0;i<3;i++) {
            temp_arr[i]=cube[0][i][0];
        }
        for(int i=0;i<3;i++) {
            cube[0][i][0]=cube[4][2-i][2];
        }
        for(int i=0;i<3;i++) {
            cube[4][2-i][2]=cube[5][i][0];
        }
        for(int i=0;i<3;i++) {
            cube[5][i][0]=cube[2][i][0];
        }
        for(int i=0;i<3;i++) {
            cube[2][i][0]=temp_arr[i];
        }
        return *this;
    }
    RubiksCube &lPrime()override {
        this->l().l().l();
        return *this;
    }
    RubiksCube &l2()override {
        this->l().l().l();
        return *this;
    }
    RubiksCube &f() override{
        this->rotateFace(2);
        char temp_arr[3]{};
        for(int i=0;i<3;i++) {
            temp_arr[i]=cube[0][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[0][2][i]=cube[1][2-i][2];
        }
        for(int i=0;i<3;i++) {
            cube[1][2-i][2]=cube[5][0][2-i];
        }
        for(int i=0;i<3;i++) {
            cube[5][0][i-2]=cube[3][i][0];
        }
        for(int i=0;i<3;i++) {
            cube[3][i][0]=temp_arr[i];
        }
        return *this;
    }
    RubiksCube &fPrime()override {
        this->f().f().f();
        return *this;
    }
    RubiksCube &f2()override {
        this->f().f();
        return *this;
    }
    RubiksCube &r()override {
        this->rotateFace(3);
        char temp_arr[3]{};
        for(int i=0;i<3;i++) {
            temp_arr[i]=cube[0][2-i][2];
        }
        for(int i=0;i<3;i++) {
            cube[0][2-i][2]=cube[2][2-i][2];
        }
        for(int i=0;i<3;i++) {
            cube[2][2-i][2]=cube[5][2-i][2];
        }
        for(int i=0;i<3;i++) {
            cube[5][2-i][2]=cube[4][i][0];
        }
        for(int i=0;i<3;i++) {
            cube[4][i][0]=temp_arr[i];
        }
        return *this;
    }
    RubiksCube &rPrime()override {
        this->r().r().r();
        return *this;
    }
    RubiksCube &r2()override {
        this->r().r();
        return *this;
    }
    RubiksCube &b()override {
        this->rotateFace(4);
        char temp_arr[3]{};
        for(int i=0;i<3;i++) {
            temp_arr[i]=cube[0][0][2-i];
        }
        for(int i=0;i<3;i++) {
            cube[0][0][2-i]=cube[3][2-i][2];
        }
        for(int i=0;i<3;i++) {
            cube[3][2-i][2]=cube[5][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[5][2][i]=cube[1][i][0];
        }
        for(int i=0;i<3;i++) {
            cube[1][i][0]=temp_arr[i];
        }
        return *this;
    }
    RubiksCube &bPrime() override{
        this->b().b().b();
        return *this;
    }
    RubiksCube &b2()override {
        this->b().b();
        return *this;
    }
    RubiksCube &d()override {
        this->rotateFace(5);
        char temp_arr[3]{};
        for(int i=0;i<3;i++) {
            temp_arr[i]=cube[2][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[2][2][i]=cube[1][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[1][2][i]=cube[4][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[4][2][i]=cube[3][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[3][2][i]=temp_arr[i];
        }
        return *this;
    }
    RubiksCube &dPrime()override {
        this->d().d().d();
        return *this;
    }
    RubiksCube &d2()override {
        this->d().d();
        return *this;
    }

};