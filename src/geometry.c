#include "geometry.h"

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
