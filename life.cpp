#include <iostream>
#include <vector>
using namespace std;
#include "Life.h"


Life::Life(int x, int y,vector<int> w) {
    height = x;
    width = y;
    size=height*width;

    overhead.assign(size,vector<int>(8,0));

    world=w;

    // world.assign(size,false);

    for(int x=0;x<height;x++) {
        for(int y=0;y<width;y++) {

            int skip=0;
            int index=0;

            //continue here in the Morning
            // broooo wasted 1 fucking hour here
            for (int x1=x-1;x1<=x+1;x1++) {
                for (int y1=y-1;y1<=y+1;y1++) {
                    if (x1<0||y1<0||x1 > width-1||y1 > height-1) {
                        skip++;
                        index++;
                        continue;
                    }
                    if (skip==4) {
                        skip++;//fuking forgot it
                        continue;
                    }
                    overhead[x*width+y][index]=x1*width+y1;
                    index++;
                    skip++;
                }
            }
        }
    }
}
vector<int> Life:: generation() {
    vector<vector<int>> rules={
        {0,0,0,1,0,0,0,0,0},
        {0,0,1,1,0,0,0,0,0}
    };
    
    vector<int> otherWorld=world;

    for (int i=0;i<size;i++) {
        int t=0;

        for (int nig=0;nig<8;nig++) {
            if (world[overhead[i][nig]]) t+=1;
        }
        otherWorld[i]=(rules[world[i]][t]);
    }

    world=otherWorld;

    return otherWorld;
}
