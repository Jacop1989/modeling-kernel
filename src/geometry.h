#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct {
    float x, y, z;
} Point3D;

typedef struct {
    float x, y, z;
} Vector3D;

// ฟังก์ชันคำนวณเวกเตอร์ระหว่างสองจุด
Vector3D subtractPoints(Point3D p1, Point3D p2);

// ฟังก์ชันคำนวณ cross product
Vector3D crossProduct(Vector3D v1, Vector3D v2);

// ฟังก์ชันคำนวณ dot product
float dotProduct(Vector3D v1, Vector3D v2);

#endif
