#include <iostream>
#include "gwindow.h"
#include "simpio.h"

using namespace std;

void drawFractal(GWindow& gw, double size, int level, double width, double height, double x1, double y1, double x2, double y2, double x3, double y3) {
    if (level == 0) {
        gw.drawPolarLine(x1, y1, size, 60);
        gw.drawPolarLine(x2, y2, size, -60);
        gw.drawPolarLine(x3, y3, size, 180);
    }
    else {
        drawFractal(gw, size / 2, level - 1, width, height, x1, y1, (x1 + x2)/2, (y1 + y2)/2, x2, y1);
        drawFractal(gw, size / 2, level - 1, width, height, (x1 + x2)/2, (y1 + y2)/2, x2, y2, (x2 + x3)/2, (y1 + y2)/2);
        drawFractal(gw, size / 2, level - 1, width, height, x2, y1, (x2 + x3)/2, (y1 + y2)/2, x3, y3);
    }

}

int main() {
    GWindow gw;
    double width = gw.getWidth();
    double height = gw.getHeight();

    double size = getReal("Enter size in double: ");
    int level = getInteger("Enter level of fractal: ");

    double altitude = sqrt(size * size - (size / 2) * (size / 2));

    double x1 = width / 2 - size / 2;
    double y1 = height / 2 + altitude / 2;

    double x2 = width / 2;
    double y2 = height / 2 - altitude / 2;

    double x3 = width / 2 + size / 2;
    double y3 = height / 2 + altitude / 2;

    drawFractal(gw, size, level, width, height, x1, y1, x2, y2, x3, y3);

    return 0;
}
