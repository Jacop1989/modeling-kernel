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

typedef struct {
    float m[4][4];
} Matrix4x4;

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

// ฟังก์ชันสำหรับสร้างเมทริกซ์การย้ายตำแหน่ง
Matrix4x4 createTranslationMatrix(float tx, float ty, float tz);

// ฟังก์ชันสำหรับสร้างเมทริกซ์การหมุนรอบแกน X, Y, Z
Matrix4x4 createRotationMatrixX(float angle);
Matrix4x4 createRotationMatrixY(float angle);
Matrix4x4 createRotationMatrixZ(float angle);

// ฟังก์ชันสำหรับสร้างเมทริกซ์การปรับขนาด
Matrix4x4 createScalingMatrix(float sx, float sy, float sz);

// ฟังก์ชันสำหรับคูณเมทริกซ์กับจุด 3D
Point3D applyTransformation(Point3D p, Matrix4x4 matrix);

#endif
