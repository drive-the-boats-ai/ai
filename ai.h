#ifndef AI_H
#define AI_H

#include "structs.h"

float getSpeedToSet(float distance, float relativeBearing);
float getRudderToSet(float relativeBearing);

int getObstacleInWay(BlockHeadings obstacleHeadings, float targetBearing,  float distance);
float getIntermediateBearing(BlockHeadings obstacleHeadings, float targetBearing);

#endif