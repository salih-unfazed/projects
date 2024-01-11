#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

// operatörün tüm noktalarını bulma

struct point
{
    int row;
    int col;
};

struct operator
{
    char type;
    struct point center;
    struct point *points;
};

void findpoint(struct operator yeni)
{

    switch (yeni.type)

    {

    case '+':

        yeni[0].points.row = (yeni.center.row - 1);
        yeni[0].points.col = (yeni.center.col);

        yeni[1].points.row = (yeni.center.row);
        yeni[1].points.col = (yeni.center.col - 1);

        yeni[2].points.row = (yeni.center.row + 1);
        yeni[2].points.col = (yeni.center.col);

        yeni[3].points.row = (yeni.center.row);
        yeni[3].points.col = (yeni.center.col + 1);
        break;

    case '-':

        yeni[0].points.row = (yeni.center.row);
        yeni[0].points.col = (yeni.center.col - 1);

        yeni[1].points.row = (yeni.center.row);
        yeni[1].points.col = (yeni.center.col + 1);
        break;

    case '/':

        yeni[0].points.row = (yeni.center.row + 1);
        yeni[0].points.col = (yeni.center.col - 1);

        yeni[1].points.row = (yeni.center.row - 1);
        yeni[1].points.col = (yeni.center.col + 1);
        break;

    case 'x':
        yeni[0].points.row = (yeni.center.row + 1);
        yeni[0].points.col = (yeni.center.col - 1);

        yeni[1].points.row = (yeni.center.row - 1);
        yeni[1].points.col = (yeni.center.col + 1);

        yeni[2].points.row = (yeni.center.row - 1);
        yeni[2].points.col = (yeni.center.col - 1);

        yeni[3].points.row = (yeni.center.row + 1);
        yeni[3].points.col = (yeni.center.col + 1);
        break;
    }
}

int main(int argc, char argv[])
{
    struct operator tür;

    int const artçarp = 5;

    int const böleksi = 3;

    FILE *grid;

    grid = fopen(argv[1], "r");

    if (grid == NULL)
    {
        return 1;
    }

    fscanf(grid, "%c %d %d", tür.type, tür.center.row, tür.center.col);
    findpoint(tür);

    if (strcmp(tür.type, "x") == 0 || strcmp(tür.type, "+") == 0)
    {
        for (int i = 1; i < artçarp; i++)
        {
            printf("%d. Nokta satir:%d sütun:%d ", artçarp, tür.points[artçarp].row, tür.points[artçarp].col);
            printf("\n");
        }
    }

    if (strcmp(tür.type, "-") == 0 || strcmp(tür.type, "/") == 0)
    {
        for (int i = 1; i < böleksi; i++)
        {
            printf("%d. Nokta satir:%d sütun:%d ", böleksi, tür.points[böleksi].row, tür.points[böleksi].col);
            printf("\n");
        }
    }

    fclose(grid);
    return 0;
}
