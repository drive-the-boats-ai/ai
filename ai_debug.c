#include <stdio.h>
#include <stdlib.h>

#include "ai.h" 
#include "calculations.h"
#include "communications.h"
#include "control_system.h"
#include "pose.h"

int main() {

    float result = getSpeedToSet(7.62, 5.2);
	printf("result: %f \n", result);

    return 0;
}
