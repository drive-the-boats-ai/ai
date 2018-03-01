#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct Location {
	//May need to change to double if possible if extra precision is needed
    float lat;
    float lng;
} Location;

typedef struct Vector {
    float angle;
    float magnitude;
} Vector;

typedef struct Pose {
    float heading;
    Location location;
} Pose;

typedef struct Block {
    int signature;
    int x;
    int y;
    int width;
    int height;
} Block;

typedef struct Blocks {
    Block** blocks;
    int length;
} Blocks;

#endif