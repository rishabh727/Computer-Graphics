#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

void applyTransformation(float matrix[3][3], int &x, int &y) {
    int xNew = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2];
    int yNew = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2];
    x = xNew;
    y = yNew;
}

void drawTransformedObject(float matrix[3][3]) {
    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 100;
    int x3 = 200, y3 = 200;
    int x4 = 100, y4 = 200;

    applyTransformation(matrix, x1, y1);
    applyTransformation(matrix, x2, y2);
    applyTransformation(matrix, x3, y3);
    applyTransformation(matrix, x4, y4);

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);
}

void translate(int tx, int ty) {
    float translationMatrix[3][3] = {
        {1, 0, tx},
        {0, 1, ty},
        {0, 0, 1}
    };
    drawTransformedObject(translationMatrix);
}

void scale(float sx, float sy) {
    float scaleMatrix[3][3] = {
        {sx, 0, 0},
        {0, sy, 0},
        {0,  0, 1}
    };
    drawTransformedObject(scaleMatrix);
}

void rotate(float angle) {
    float rad = angle * M_PI / 180.0;
    float rotationMatrix[3][3] = {
        {cos(rad), -sin(rad), 0},
        {sin(rad), cos(rad), 0},
        {0, 0, 1}
    };
    drawTransformedObject(rotationMatrix);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Original object
    setcolor(WHITE);
    int x1 = 100, y1 = 100, x2 = 200, y2 = 100, x3 = 200, y3 = 200, x4 = 100, y4 = 200;
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);

    // Apply transformations
    setcolor(YELLOW);
    translate(50, 50);

    setcolor(RED);
    scale(0.5, 0.5);

    setcolor(GREEN);
    rotate(45);

    getch();
    closegraph();
    return 0;
}
