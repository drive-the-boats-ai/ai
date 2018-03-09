#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include "structs.h"

Vector getDistanceVector(Location currentLocation, Location targetLocation);
float getRelativeBearing(float currentHeading, float targetHeading);

BlockHeadings blocksToHeadings(Blocks blocks);
#endif