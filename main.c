#include <stdio.h>
#include <stdlib.h>

#include "ai.h" 
#include "calculations.h"
#include "camera.h"
#include "communications.h"
#include "control_system.h"
#include "pose.h"

int main() {
    Blocks obstacleBlocks;
    BlockHeadings obstacleHeadings;
    float intermediateBearing;
    int obstacleInWay = 0;

    while (1) {
        if (getStop()) {
            break;
        }

        Pose pose = getPose();
        
        sendCurrentLocation(pose.location);
        Location targetLocation = getTargetLocation();

        Vector distanceVector = getDistanceVector(pose.location, targetLocation);
        float targetBearing = getRelativeBearing(pose.heading, distanceVector.angle);

        int newBlocks = newBlocksExist();
        if (newBlocks) {
            resolveAllBlocks();
            obstacleBlocks = getObstacleBlocks();
            obstacleHeadings = blocksToHeadings(obstacleBlocks);
            obstacleInWay = getObstacleInWay(obstacleHeadings, targetBearing, distanceVector.magnitude);
            if (obstacleInWay) {
                intermediateBearing = getIntermediateHeading(obstacleHeadings, targetBearing);
            }
        }

        if (obstacleInWay) {
            targetBearing = intermediateBearing;
        }

        float speedToSet = getSpeedToSet(distanceVector.magnitude, targetBearing);
        float rudderToSet = getRudderToSet(targetBearing);

        setSpeed(speedToSet);
        setRudder(rudderToSet);

        if (newBlocks) {
            free(obstacleBlocks.blocks);
        }
    }

    return 0;
}
