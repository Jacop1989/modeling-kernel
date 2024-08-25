#include <stdio.h>
#include "geometry.h"

int main() {
    Point3D p1 = {1.0, 2.0, 3.0};
    Point3D p2 = {4.0, 5.0, 6.0};

    Vector3D v = subtractPoints(p1, p2);
    
    printf("Vector between p1 and p2: (%f, %f, %f)\n", v.x, v.y, v.z);
    
    return 0;
}
