#include <vector>
#include <optional>
#include <cmath>

struct Point3D {
    float x, y, z;

    Point3D operator-(const Point3D& v) const {
        return {x - v.x, y - v.y, z - v.z};
    }

    Point3D operator+(const Point3D& v) const {
        return {x + v.x, y + v.y, z + v.z};
    }

    Point3D operator*(float scalar) const {
        return {x * scalar, y * scalar, z * scalar};
    }

    static Point3D cross(const Point3D& a, const Point3D& b) {
        return {
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        };
    }

    static float dot(const Point3D& a, const Point3D& b) {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }
};

struct Ray {
    Point3D origin;
    Point3D direction;
};

// Now, here's the function that uses this data structure:

std::vector<std::optional<Point3D>> intersectTrianglesWithRay(
    const std::vector<Point3D>& vertices,
    const std::vector<std::array<int, 3>>& triangles,
    const Ray& ray
) {
    const float EPSILON = 0.0000001f;
    std::vector<std::optional<Point3D>> intersections(triangles.size());

    for (size_t i = 0; i < triangles.size(); ++i) {
        const Point3D& vertex0 = vertices[triangles[i][0]];
        const Point3D& vertex1 = vertices[triangles[i][1]];
        const Point3D& vertex2 = vertices[triangles[i][2]];

        Point3D edge1 = vertex1 - vertex0;
        Point3D edge2 = vertex2 - vertex0;
        Point3D h = Point3D::cross(ray.direction, edge2);
        float a = Point3D::dot(edge1, h);

        if (std::fabs(a) < EPSILON) {
            // This means the ray is parallel to this triangle.
            continue;
        }

        float f = 1.0f / a;
        Point3D s = ray.origin - vertex0;
        float u = f * Point3D::dot(s, h);
        if (u < 0.0f || u > 1.0f) {
            // The intersection is outside of the triangle.
            continue;
        }

        Point3D q = Point3D::cross(s, edge1);
        float v = f * Point3D::dot(ray.direction, q);

        if (v < 0.0f || u + v > 1.0f) {
            // The intersection is outside of the triangle.
            continue;
        }

        // At this stage, we can compute t to find out where 
        // the intersection point is on the line.
        float t = f * Point3D::dot(edge2, q);
        if (t > EPSILON) { // Ray intersection
            intersections[i] = ray.origin + ray.direction * t;
        }
    }

    return intersections;
}
