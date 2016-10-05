#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct {
  int kind; // 0 = camera, 1 = sphere, 2 = plane
  double color[3];
  union {
    struct {
      double center[3];
      double width;
      double hiehgt;
    } camera;
    struct {
      double center[3];
      double radius;
    } sphere;
    struct {
      double center[3];
      double normal;
    } plane;
  };
} Object;
