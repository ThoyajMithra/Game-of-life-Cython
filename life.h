//
// Created by THOYAJ MITHRA on 23-05-2026.
//

#ifndef GAMEOFLIFE_CYTHON_LIFE_H
#define GAMEOFLIFE_CYTHON_LIFE_H

#include <vector>
using namespace std;


class Life {
public:
    int height;     //rows
    int width;      //coluoms
    int size;




    vector<vector<int>> overhead;

    vector<int> world;

    Life(int x, int y,vector<int> w) ;

    vector<int> generation() ;
};

#endif //GAMEOFLIFE_CYTHON_LIFE_H
