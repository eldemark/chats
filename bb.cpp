#include <iostream>
#include <cmath>
#include <cstdlib>

// Constant definitions
const double h = 6.62607015e-34; // Planck constant (J*s)
const double c = 2.99792458e8;   // Speed of light (m/s)
const double kb = 1.380649e-23;  // Boltzmann constant (J/K)

// Function to calculate radiance using Planck's law
double plancksLaw(double wavelength, double temperature) {
    double lambda = wavelength * 1e-6; // Convert micron to meters
    double exponent = h * c / (lambda * kb * temperature);
    double numerator = 2.0 * h * c * c;
    double denominator = pow(lambda, 5) * (exp(exponent) - 1.0);
    return numerator / denominator;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <lower bound> <upper bound> <temperature>" << std::endl;
        return 1;
    }

    double lowerBound = atof(argv[1]);
    double upperBound = atof(argv[2]);
    double temperature = atof(argv[3]);

    if(lowerBound <= 0 || upperBound <= 0 || temperature <= 0) {
        std::cerr << "All values must be positive." << std::endl;
        return 1;
    }

    if(lowerBound >= upperBound) {
        std::cerr << "Upper bound must be greater than lower bound." << std::endl;
        return 1;
    }

    // Calculate and print radiance for each wavelength in the range
    for (double wavelength = lowerBound; wavelength <= upperBound; wavelength += 0.1) {
        double radiance = plancksLaw(wavelength, temperature);
        std::cout << "Radiance at " << wavelength << " microns: " << radiance << " W/(m^2*sr)" << std::endl;
    }

    return 0;
}
