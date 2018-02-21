#include <math.h>

#include "calculations.h"

double TO_RADIANS = M_PI / 180;
double TO_DEGREES = 180 / M_PI;

Vector getDistanceVector(Location currentLocation, Location targetLocation) {
    Vector distanceVector;

    double y = (double) (targetLocation.lat - currentLocation.lat);
    double x = (double) (targetLocation.lng - currentLocation.lng) * cos(currentLocation.lat * TO_RADIANS);
    
    double distance = 111.36 * sqrt((x*x + y*y));
    double bearing = atan(fabs(x) / fabs(y)) * TO_DEGREES;

    if (x > 0 && y > 0) {
        // do nothing
    } else if (x > 0 && y < 0) {
        bearing = 180 - bearing;
    } else if (x < 0 && y < 0) {    
        bearing = bearing + 180;
    } else {
        bearing = 360.0 - bearing;
    }

    distanceVector.magnitude = distance;
    distanceVector.angle = bearing;
    return distanceVector;
}

float getRelativeBearing(float currentHeading, float targetHeading) {
    float diff = targetHeading - currentHeading;
    if (fabs(diff) <= 180.0) {
        return diff;
    } else {
        if (diff >= 0) {
            return diff - 360.0f;
        } else {
            return diff + 360.0f;
        }
    }
}