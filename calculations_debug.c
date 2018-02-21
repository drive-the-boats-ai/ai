#include <stdio.h>
#include <stdlib.h>

#include "calculations.h"

int main() {

    // getRelativeBearing
    for (int currentHeading = 0; currentHeading < 360; currentHeading+= 15) {
        for (int targetHeading = 0; targetHeading < 360; targetHeading+= 15) {
            float relativeBearing = getRelativeBearing(currentHeading, targetHeading);
            printf("current: %d,\t target: %d,\t relative: %f\n", currentHeading, targetHeading, relativeBearing);
        }
    }
    return 0;
}