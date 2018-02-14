#include "ai.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float START_RADIUS = 9;
float DEAD_ZONE_RADIUS = 3;
float BEARING_LIMIT = 162.0;

/*
Determines the speed percentage to be set by the AI.
Inputs:
distance - floating point representation of the distance to target in meters
relativeBearing - floating point representation of the relative heading needed to get to the target in degrees

Output:
Overall speed percentage to be sent to the ESC
*/


float getSpeedToSet(float distance, float relativeBearing) {
	float absBearing = (float)(fabs(relativeBearing));
	absBearing = (absBearing > BEARING_LIMIT) ? BEARING_LIMIT : absBearing;
	float bearingSpeed = (180.0 - absBearing) / 180.0;
	
	
	float distanceCopy = distance;
	if(distanceCopy > START_RADIUS){
		distanceCopy = START_RADIUS;
	}else if(distanceCopy < DEAD_ZONE_RADIUS){
		distanceCopy = DEAD_ZONE_RADIUS;
	}
	
	float distanceSpeed = (distanceCopy - DEAD_ZONE_RADIUS) / (START_RADIUS - DEAD_ZONE_RADIUS); 
		
	
    return bearingSpeed * distanceSpeed;
}
float getRudderToSet(Vector distanceVector, float relativeBearing) {
    return 0.0;
}