#include "pose.h"

Location getCurrentLocation() {
    Location currentLocation;
    currentLocation.lat = 0.00;
    currentLocation.lng = 0.00;
    return currentLocation;
}

float getCurrentHeading() {
    return 0.0000;
}

Pose getPose() {
    Pose pose;
    pose.heading = getCurrentHeading();
    pose.location = getCurrentLocation();
    return pose;
}

