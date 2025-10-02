#include <stdio.h>

typedef struct {
    int Ax, Ay;
    int Bx, By;
    int Cx, Cy;
    int Dx, Dy;
    int Rx, Ry;
} Area;

int main() {
    int N;
    Area a;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &a.Ax, &a.Ay);
        scanf("%d %d", &a.Bx, &a.By);
        scanf("%d %d", &a.Cx, &a.Cy);
        scanf("%d %d", &a.Dx, &a.Dy);
        scanf("%d %d", &a.Rx, &a.Ry);

        if (a.Ax <= a.Rx && a.Dx <= a.Rx &&
            a.Rx <= a.Bx && a.Rx <= a.Cx &&
            a.Ay <= a.Ry && a.By <= a.Ry &&
            a.Ry <= a.Cy && a.Ry <= a.Dy) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }

    return 0;
}