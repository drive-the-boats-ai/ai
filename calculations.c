#include "calculations.h"

Vector getDistanceVector(Location currentLocation, Location targetLocation) {
    Vector distanceVector;
    distanceVector.magnitude = 0.0;
    distanceVector.angle = 0,0;
    return distanceVector;
}

float getRelativeBearing(float currentHeading, float targetHeading) {
    return 0.0;
}