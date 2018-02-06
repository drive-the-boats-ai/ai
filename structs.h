#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct Location {
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

#endif