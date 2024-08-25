#include "geometry.h"
#include <math.h>

// ฟังก์ชันคำนวณเวกเตอร์ระหว่างสองจุด
Vector3D subtractPoints(Point3D p1, Point3D p2) {
    Vector3D v;
    v.x = p2.x - p1.x;
    v.y = p2.y - p1.y;
    v.z = p2.z - p1.z;
    return v;
}

// ฟังก์ชันคำนวณ cross product
Vector3D crossProduct(Vector3D v1, Vector3D v2) {
    Vector3D result;
    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;
    return result;
}

// ฟังก์ชันคำนวณ dot product
float dotProduct(Vector3D v1, Vector3D v2) {
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

// ฟังก์ชันคำนวณมุมระหว่างสองเวกเตอร์
float angleBetweenVectors(Vector3D v1, Vector3D v2) {
    float dot = dotProduct(v1, v2);
    float magnitude_v1 = sqrt(dotProduct(v1, v1));
    float magnitude_v2 = sqrt(dotProduct(v2, v2));
    return acos(dot / (magnitude_v1 * magnitude_v2));
}

// ฟังก์ชันสร้างพื้นผิวจากจุดสามจุด
Plane createPlane(Point3D p1, Point3D p2, Point3D p3) {
    Plane plane;
    Vector3D v1 = subtractPoints(p1, p2);
    Vector3D v2 = subtractPoints(p2, p3);
    plane.normal = crossProduct(v1, v2);
    plane.d = - (plane.normal.x * p1.x + plane.normal.y * p1.y + plane.normal.z * p1.z);
    return plane;
}

// ฟังก์ชันการย้ายตำแหน่งจุด
Point3D translatePoint(Point3D p, Vector3D translation) {
    Point3D result;
    result.x = p.x + translation.x;
    result.y = p.y + translation.y;
    result.z = p.z + translation.z;
    return result;
}

// ฟังก์ชันการปรับขนาดจุด
Point3D scalePoint(Point3D p, float scaleFactor) {
    Point3D result;
    result.x = p.x * scaleFactor;
    result.y = p.y * scaleFactor;
    result.z = p.z * scaleFactor;
    return result;
}

// ฟังก์ชันการหมุนจุดรอบแกน X
Point3D rotatePointAroundX(Point3D p, float angle) {
    Point3D result;
    result.x = p.x;
    result.y = p.y * cos(angle) - p.z * sin(angle);
    result.z = p.y * sin(angle) + p.z * cos(angle);
    return result;
}

// ฟังก์ชันการหมุนจุดรอบแกน Y
Point3D rotatePointAroundY(Point3D p, float angle) {
    Point3D result;
    result.x = p.x * cos(angle) + p.z * sin(angle);
    result.y = p.y;
    result.z = -p.x * sin(angle) + p.z * cos(angle);
    return result;
}

// ฟังก์ชันการหมุนจุดรอบแกน Z
Point3D rotatePointAroundZ(Point3D p, float angle) {
    Point3D result;
    result.x = p.x * cos(angle) - p.y * sin(angle);
    result.y = p.x * sin(angle) + p.y * cos(angle);
    result.z = p.z;
    return result;
}

// ฟังก์ชันสำหรับสร้างเมทริกซ์การย้ายตำแหน่ง
Matrix4x4 createTranslationMatrix(float tx, float ty, float tz) {
    Matrix4x4 matrix = {0};
    matrix.m[0][0] = 1;
    matrix.m[1][1] = 1;
    matrix.m[2][2] = 1;
    matrix.m[3][3] = 1;
    matrix.m[0][3] = tx;
    matrix.m[1][3] = ty;
    matrix.m[2][3] = tz;
    return matrix;
}

// ฟังก์ชันสำหรับสร้างเมทริกซ์การหมุนรอบแกน X
Matrix4x4 createRotationMatrixX(float angle) {
    Matrix4x4 matrix = {0};
    matrix.m[0][0] = 1;
    matrix.m[1][1] = cos(angle);
    matrix.m[1][2] = -sin(angle);
    matrix.m[2][1] = sin(angle);
    matrix.m[2][2] = cos(angle);
    matrix.m[3][3] = 1;
    return matrix;
}

// ฟังก์ชันสำหรับสร้างเมทริกซ์การหมุนรอบแกน Y
Matrix4x4 createRotationMatrixY(float angle) {
    Matrix4x4 matrix = {0};
    matrix.m[0][0] = cos(angle);
    matrix.m[0][2] = sin(angle);
    matrix.m[2][0] = -sin(angle);
    matrix.m[2][2] = cos(angle);
    matrix.m[1][1] = 1;
    matrix.m[3][3] = 1;
    return matrix;
}

// ฟังก์ชันสำหรับสร้างเมทริกซ์การหมุนรอบแกน Z
Matrix4x4 createRotationMatrixZ(float angle) {
    Matrix4x4 matrix = {0};
    matrix.m[0][0] = cos(angle);
    matrix.m[0][1] = -sin(angle);
    matrix.m[1][0] = sin(angle);
    matrix.m[1][1] = cos(angle);
    matrix.m[2][2] = 1;
    matrix.m[3][3] = 1;
    return matrix;
}

// ฟังก์ชันสำหรับสร้างเมทริกซ์การปรับขนาด
Matrix4x4 createScalingMatrix(float sx, float sy, float sz) {
    Matrix4x4 matrix = {0};
    matrix.m[0][0] = sx;
    matrix.m[1][1] = sy;
    matrix.m[2][2] = sz;
    matrix.m[3][3] = 1;
    return matrix;
}

// ฟังก์ชันสำหรับคูณเมทริกซ์กับจุด 3D
Point3D applyTransformation(Point3D p, Matrix4x4 matrix) {
    Point3D result;
    result.x = p.x * matrix.m[0][0] + p.y * matrix.m[0][1] + p.z * matrix.m[0][2] + matrix.m[0][3];
    result.y = p.x * matrix.m[1][0] + p.y * matrix.m[1][1] + p.z * matrix.m[1][2] + matrix.m[1][3];
    result.z = p.x * matrix.m[2][0] + p.y * matrix.m[2][1] + p.z * matrix.m[2][2] + matrix.m[2][3];
    return result;
}
