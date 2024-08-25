#include <stdio.h>
#include "geometry.h"

int main() {
    Point3D p = {1, 2, 3};

    // สร้างเมทริกซ์การย้ายตำแหน่ง
    Matrix4x4 translation = createTranslationMatrix(2, 3, 4);
    Point3D translated = applyTransformation(p, translation);
    printf("Translated Point: (%f, %f, %f)\n", translated.x, translated.y, translated.z);

    // สร้างเมทริกซ์การหมุนรอบแกน Z
    Matrix4x4 rotationZ = createRotationMatrixZ(3.14159 / 4);  // หมุน 45 องศา
    Point3D rotated = applyTransformation(p, rotationZ);
    printf("Rotated Point (Z-axis): (%f, %f, %f)\n", rotated.x, rotated.y, rotated.z);

    // สร้างเมทริกซ์การปรับขนาด
    Matrix4x4 scaling = createScalingMatrix(2, 2, 2);
    Point3D scaled = applyTransformation(p, scaling);
    printf("Scaled Point: (%f, %f, %f)\n", scaled.x, scaled.y, scaled.z);

    return 0;
}

