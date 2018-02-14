#include <stdio.h>
#include <stdlib.h>

#include "ai.h" 
#include "calculations.h"
#include "communications.h"
#include "control_system.h"
#include "pose.h"


int main() {
	
	float NUM_BEARING_TESTS = 30;
	float NUM_DISTANCE_TESTS = 30;
	float START_DISTANCE = 100.0;
	float DISTANCE_INC = START_DISTANCE / NUM_DISTANCE_TESTS;
	float BEARING_INC = 360 / NUM_BEARING_TESTS;

	
	

    for(float distance = START_DISTANCE; distance > 0; distance -= DISTANCE_INC){
		for(float relativeBearing = -180; relativeBearing < 180; relativeBearing += BEARING_INC){
			float result = getSpeedToSet(distance, relativeBearing);
			printf("Distance: %f Relative Bearing: %f Result: %f \n", distance, relativeBearing, result);
		}
	}

    return 0;
}
