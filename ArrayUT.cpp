#include <stdio.h>
#include <math.h>

#include "Function.h"

void QuadTest()
{
    const int POISON = 666;

    //Expected - ожидаемый, received - полученный

    double Koef_a[] = {1, 1, 1, 1, 1, 1};
    double Koef_b[] = {-3, 2, 2, 0, 4.000000004, 4.000000001, 0, 0, 1};
    double Koef_c[] = {2, 1, 3, 0, 4.000000001, 4.000000004, 3, 0, 1};
    int expected_nRoots[] = {2, 1, 0, 1, 1, 1, POISON, POISON, -2};
    double expectedX1[] = {1, POISON, POISON, POISON, POISON, POISON};
    double expectedX2[] = {2, POISON, POISON, POISON, POISON, POISON};
    double expectedX [] = {POISON, -1, POISON, 0, -2, -2};

    int received_nRoots[] = {0};
    double receivedX1[] = {0};
    double receivedX2[] = {0};
    double receivedX [] = {0};

    int i = 0;

    const char TestOK[] = "Test OK: %d\n";
    const char TestBAD[] = "Test BAD: %d\n";

    for (i; i < 6; i++)
    {
        received_nRoots[i] = SolveQuadratic(Koef_a[i],Koef_b[i],Koef_c[i],&receivedX1[i],&receivedX2[i],&receivedX[i]);

        if (received_nRoots[i] == expected_nRoots[i])
            {
            if (received_nRoots[i] == 2)
                {
                if ((expectedX1[i] == receivedX1[i]) && (expectedX2[i] == receivedX2[i]))
                    {
                    printf(TestOK, i+1);
                    }
                else
                    printf(TestBAD, i+1);
                }
            if (received_nRoots[i] == 1)
                {
                if (expectedX[i] == receivedX[i])
                    printf(TestOK, i+1);
                if (expectedX[i] != receivedX[i])
                    printf(TestBAD, i+1);
                }
            if (received_nRoots[i] == 0)
                printf(TestOK, i+1);
            }
        else printf(TestBAD);
        }

    for (i; i < 9; i++)
    {
        received_nRoots[i] = SolveLinear(Koef_b[i], Koef_c[i], &receivedX [i]);

        if (received_nRoots[i] == expected_nRoots[i])
        {
        if (received_nRoots[i] == 3)
            {
                printf(TestOK, i+1);
            }
        if (received_nRoots[i] == 1)
            {
            if (expectedX[i] == receivedX[i])
                printf(TestOK, i+1);
            if (expectedX[i] != receivedX[i])
                printf(TestBAD, i+1);
            }
        if (received_nRoots[i] == 0)
            printf(TestOK, i+1);

        }
        else printf(TestBAD, i+1);
    }
}
