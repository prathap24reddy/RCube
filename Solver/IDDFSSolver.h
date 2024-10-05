//
// Created by prath on 05-10-2024.
//

#include <bits/stdc++.h>
#include "../Model/RubiksCube.h"
#include "DFSSolver.h"

#ifndef IDDFSSOLVER_H
#define IDDFSSOLVER_H

template<typename T, typename H>
class IDDFSSolver {
private:
    int max_search_depth;
    vector<RubiksCube::MOVE>move;
public:
    T rubiksCube;

    IDDFSSolver(T _rubiksCube, int _max_search_depth=7) {
        rubiksCube=_rubiksCube;
        max_search_depth=_max_search_depth;
    }

    // Used DFSSovler with increasing max_search_depth
    vector<RubiksCube::MOVE>solve() {
        for(int i=1;i<=max_search_depth;i++) {
            DFSSolver<T, H>dfsSolver(rubiksCube, i);
            moves=dfsSolver.solve();
            if(dfsSolver.rubiksCube.isSolved()) {
                rubiksCube=dfsSolver.rubiksCube;
                break;
            }
        }
        return moves;
    }
};

#endif //IDDFSSOLVER_H
