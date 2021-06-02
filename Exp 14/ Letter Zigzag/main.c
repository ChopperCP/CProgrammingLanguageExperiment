#include <stdio.h>

#define MAXROW 100
#define MAXCOL 100
char canvas[MAXROW][MAXCOL];
int row_cnt, col_cnt;
char currletter = 'A';
int x = 0, y = 0;
int steps = 0;      // How many steps taken, used for termination.

int max(int a,int b){
    if (a>b)
        return a;
    return b;
}
int min (int a,int b){
    if (a<b){
        return a;
    }
    return b;
}

void go_right();

void go_up() {
    if (steps == row_cnt * col_cnt) {
        return;
    }

    while (x >= 0 && y >= 0 && x < row_cnt && y < col_cnt && canvas[x][y] == 0) {
        canvas[x--][y] = currletter;
        if (currletter == 'Z') {
            currletter = 'A';
        } else {
            ++currletter;
            ++steps;
        }
    }

    if (x == -1) {
        ++x;
    }

    y=min(y+1,col_cnt-1);
    return go_right();
}

void go_left() {
    if (steps == row_cnt * col_cnt) {
        return;
    }

    while (x >= 0 && y >= 0 && x < row_cnt && y < col_cnt && canvas[x][y] == 0) {
        canvas[x][y--] = currletter;
        if (currletter == 'Z') {
            currletter = 'A';
        } else {
            ++currletter;
            ++steps;
        }
    }

    if (y == -1) {
        ++y;
    }

    x=max(x-1,0);
    return go_up();
}

void go_down() {
    if (steps == row_cnt * col_cnt) {
        return;
    }

    while (x >= 0 && y >= 0 && x < row_cnt && y < col_cnt && canvas[x][y] == 0) {
        canvas[x++][y] = currletter;
        if (currletter == 'Z') {
            currletter = 'A';
        } else {
            ++currletter;
            ++steps;
        }
    }

    if (x == row_cnt) {
        --x;
    }

    y=max(y-1,0);
    return go_left();
}

void go_right() {
    if (steps == row_cnt * col_cnt) {
        return;
    }

    while (x >= 0 && y >= 0 && x < row_cnt && y < col_cnt && canvas[x][y] == 0) {
        canvas[x][y++] = currletter;
        if (currletter == 'Z') {
            currletter = 'A';
        } else {
            ++currletter;
            ++steps;
        }
    }

    if (y == col_cnt) {
        --y;
    }

    x=min(x+1,col_cnt-1);
    return go_down();
}

int main() {
    scanf("%d %d", &row_cnt, &col_cnt);

    go_right();

    for (int i = 0; i < col_cnt; ++i) {
        for (int j = 0; j < row_cnt; ++j) {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }


    return 0;
}
