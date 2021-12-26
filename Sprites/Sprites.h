#ifndef SPRITES_H
#define SPRITES_H

const int arrow_up[3][5] = {
    { 0, 0, 1, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 1, 1, 1, 1, 1 },
};

const int arrow_down[3][5] = {
    { 1, 1, 1, 1, 1 },
    { 0, 1, 1, 1, 0 },
    { 0, 0, 1, 0, 0 },
};

const int title_screen_d[10][8] = {
    {1,1,1,1,1,1,0,0},
    {1,1,1,1,1,1,1,0},
    {1,1,0,0,0,1,1,1},
    {1,1,0,0,0,0,1,1},
    {1,1,0,0,0,0,1,1},
    {1,1,0,0,0,0,1,1},
    {1,1,0,0,0,0,1,1},
    {1,1,0,0,0,1,1,1},
    {1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,0,0}
};

const int title_screen_e[10][7] = {
    {0,1,1,1,1,1,1},
    {1,1,1,1,1,1,1},
    {1,1,0,0,0,0,0},
    {1,1,0,0,0,0,0},
    {1,1,1,1,1,0,0},
    {1,1,1,1,1,0,0},
    {1,1,0,0,0,0,0},
    {1,1,0,0,0,0,0},
    {1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1}
};

const int title_screen_f[10][7] = {
    {0,1,1,1,1,1,1},
    {1,1,1,1,1,1,1},
    {1,1,0,0,0,0,0},
    {1,1,0,0,0,0,0},
    {1,1,1,1,1,1,0},
    {1,1,1,1,1,1,0},
    {1,1,0,0,0,0,0},
    {1,1,0,0,0,0,0},
    {1,1,0,0,0,0,0},
    {1,1,0,0,0,0,0}
};

const int title_screen_n[10][7] = {
    {1,1,0,0,0,1,1},
    {1,1,1,0,0,1,1},
    {1,1,1,1,0,1,1},
    {1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1},
    {1,1,0,1,1,1,1},
    {1,1,0,0,1,1,1},
    {1,1,0,0,0,1,1},
    {1,1,0,0,0,1,1},
    {1,1,0,0,0,1,1},
};

const int title_screen_r[10][8] = {
    {0,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1},
    {1,1,0,0,0,0,1,1},
    {1,1,0,0,0,0,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,0},
    {1,1,0,1,1,1,0,0},
    {1,1,0,0,1,1,1,0},
    {1,1,0,0,0,1,1,1},
    {1,1,0,0,0,0,1,1}
};  

#endif   