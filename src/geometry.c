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
