#include <stdio.h>
#include <stdlib.h>

#include "ai.h" 
#include "calculations.h"
#include "communications.h"
#include "control_system.h"
#include "pose.h"

int main() {

    while (1) {
        if (getStop()) {
            break;
        }

        Pose pose = getPose();
        
        sendCurrentLocation(pose.location);
        Location targetLocation = getTargetLocation();

        Vector distanceVector = getDistanceVector(pose.location, targetLocation);
        float relativeBearing = getRelativeBearing(pose.heading, distanceVector.angle);

        float speedToSet = getSpeedToSet(distanceVector.magnitude, relativeBearing);
        float rudderToSet = getRudderToSet(relativeBearing);

        setSpeed(speedToSet);
        setRudder(rudderToSet);
    }

    return 0;
}
