// This approximation works for small angles (less than about 10 degrees), so it may not be suitable 
// for large FOV values. For precise calculations, especially for larger angles, the small-angle 
// approximation is not adequate, and you would need to calculate the solid angle subtended 
// by the square image more accurately, which involves more complex trigonometry.

#include <math.h>

#define PI 3.14159265358979323846

// Function to convert degrees to radians
double deg2rad(double degrees) {
    return (degrees * PI / 180.0);
}

// Function to calculate the irradiance given a pointer to an array of pixel radiances and FOV in degrees
double calculateIrradiance(float* pixelRadiances, int numPixels, double fovDegrees) {
    // Convert FOV from degrees to radians
    double fovRadians = deg2rad(fovDegrees);

    // Calculate the solid angle for a small FOV approximation
    double solidAngle = pow(fovRadians, 2);

    // Sum all radiance values
    double totalRadiance = 0.0;
    for (int i = 0; i < numPixels; ++i) {
        totalRadiance += pixelRadiances[i];
    }

    // Calculate the average radiance
    double averageRadiance = totalRadiance / numPixels;

    // Calculate the irradiance
    double irradiance = averageRadiance * solidAngle;

    return irradiance;
}
