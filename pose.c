#include "pose.h"

Location getCurrentLocation() {
	//Get current location from data filter
    Location currentLocation;
	//Call function to get lat and long values
    currentLocation.lat = 0.00;
    currentLocation.lng = 0.00;
    return currentLocation;
}

float getCurrentHeading() {
	//Get current heading in degrees from data filter
	//Call function to get heading
    return 0.0000;
}

Pose getPose() {
    Pose pose;
    pose.heading = getCurrentHeading();
    pose.location = getCurrentLocation();
    return pose;
}

