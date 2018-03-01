#include <stdlib.h>

#include "camera.h"

int OBSTACLE_SIGNATURE = 0;
int BOAT_SIGNATURE = 1;


typedef struct BlocksArray {
    Block* blocks;
    int length;
} BlocksArray;


Blocks obstacles;
Blocks boats;

int newBlocksExist() {
    // get flag from driver team that signals if there are new blocks
    // to be processed from the pixy
    return 0;
}

void resolveAllBlocks() {
    BlocksArray allBlocks = getAllBlocksFromPixy();

    int numObstacles = 0;
    int numBoats = 0;
    for (int i = 0; i < allBlocks.length; i++) {
        int signature = allBlocks.blocks[i].signature;
        if (signature == OBSTACLE_SIGNATURE) {
            numObstacles++;
        } else if (signature == BOAT_SIGNATURE) {
            numBoats++;
        }
    }

    obstacles.length = numObstacles;
    obstacles.blocks = (Blocks**) malloc(numObstacles * sizeof(Blocks*));

    boats.length = numBoats;
    boats.blocks = (Blocks**) malloc(numBoats * sizeof(Blocks*));

    int obstacleIndex = 0;
    int boatIndex = 0;
    for (int i = 0; i < allBlocks.length; i++) {
        int signature = allBlocks.blocks[i].signature;
        if (signature == OBSTACLE_SIGNATURE) {
            obstacles.blocks[obstacleIndex] = &allBlocks.blocks[i];
            obstacleIndex++;
        } else if (signature == BOAT_SIGNATURE) {
            boats.blocks[boatIndex] = &allBlocks.blocks[i];
            boatIndex++;
        }
    }
    
}

Blocks getObstacleBlocks() {
    return obstacles;
}

Blocks getBoatBlocks() {
    return boats;
}


BlocksArray getAllBlocksFromPixy() {
     // get pointer to blocks array and number of blocks from pixy
    BlocksArray allBlocks;
    allBlocks.blocks = (Block*) 0;
    allBlocks.length = 0;
    return allBlocks;
}