#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct {
    float x, y, z;
} Point3D;

typedef struct {
    float x, y, z;
} Vector3D;

typedef struct {
    Vector3D normal;
    float d;
} Plane;

// ฟังก์ชันคำนวณเวกเตอร์ระหว่างสองจุด
Vector3D subtractPoints(Point3D p1, Point3D p2);

// ฟังก์ชันคำนวณ cross product
Vector3D crossProduct(Vector3D v1, Vector3D v2);

// ฟังก์ชันคำนวณ dot product
float dotProduct(Vector3D v1, Vector3D v2);

// ฟังก์ชันคำนวณมุมระหว่างสองเวกเตอร์
float angleBetweenVectors(Vector3D v1, Vector3D v2);

// ฟังก์ชันสร้างพื้นผิวจากจุดสามจุด
Plane createPlane(Point3D p1, Point3D p2, Point3D p3);

// ฟังก์ชันการย้ายตำแหน่งจุด
Point3D translatePoint(Point3D p, Vector3D translation);

// ฟังก์ชันการปรับขนาดจุด
Point3D scalePoint(Point3D p, float scaleFactor);

// ฟังก์ชันการหมุนจุดรอบแกน X, Y, Z
Point3D rotatePointAroundX(Point3D p, float angle);
Point3D rotatePointAroundY(Point3D p, float angle);
Point3D rotatePointAroundZ(Point3D p, float angle);

#endif
