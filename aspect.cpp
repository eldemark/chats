
// clang++ -Wall -o aspect aspect.cpp

#include <cmath>
#include <iostream>

double rad2deg(double radians)
{
    return radians * 180.0 / M_PI;
}

struct aspect_t {
    double az = 0.0; // deg
    double el = 0.0; // deg
};

struct point_t {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

aspect_t find_aspect(const point_t& A, const point_t& B)
{
    aspect_t aspect;
    double dx = B.x - A.x; // Difference in east
    double dy = B.y - A.y; // Difference in north
    double dz = B.z - A.z; // Difference in down

    aspect.az = rad2deg(atan2(dy, dx));

    if (aspect.az < 0)
        aspect.az += 360; // Ensure azimuth is in the range [0, 360)

    double den = sqrt(dx * dx + dy * dy); // distance in x-y plane
    aspect.el = rad2deg(atan2(-dz, den)); // -dz because z is down in NED

    return aspect;
}

int main(int argc, char* argv[])
{
    if (argc != 7) {
        std::cerr << "Usage: $ ./aspect x1 y1 z1 x2 y2 z2\n";
        return 1;
    }

    try {
        double x1 = std::stod(argv[1]);
        double y1 = std::stod(argv[2]);
        double z1 = std::stod(argv[3]);
        double x2 = std::stod(argv[4]);
        double y2 = std::stod(argv[5]);
        double z2 = std::stod(argv[6]);

        point_t A = { x1, y1, z1 };
        point_t B = { x2, y2, z2 };

        aspect_t ans = find_aspect(A, B);

        std::cout << "Azimuth: "
                  << ans.az
                  << " degrees, Elevation: "
                  << ans.el
                  << " degrees" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
