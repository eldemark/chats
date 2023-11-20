#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

// ... [Previous code definitions]

// Function to read sensor response data from a CSV file
void readSensorData(const std::string& filename, std::vector<double>& wavelengths, std::vector<double>& responses) {
    std::ifstream file(filename);
    std::string line, cell;

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    // Skip header
    std::getline(file, line);

    // Read data
    while (std::getline(file, line)) {
        std::stringstream lineStream(line);
        double wavelength, response;
        std::getline(lineStream, cell, ',');
        wavelength = std::stod(cell);
        std::getline(lineStream, cell, ',');
        response = std::stod(cell);
        wavelengths.push_back(wavelength);
        responses.push_back(response);
    }
}

// Function for simple linear interpolation
double interpolate(double x, const std::vector<double>& xVals, const std::vector<double>& yVals) {
    if(xVals.empty() || yVals.empty() || xVals.size() != yVals.size())
        throw std::runtime_error("Invalid data for interpolation");

    // Find the interval x is in
    auto it = std::lower_bound(xVals.begin(), xVals.end(), x);
    if (it == xVals.begin() || it == xVals.end()) {
        throw std::runtime_error("Interpolation out of range");
    }

    int i = it - xVals.begin() - 1;
    double x0 = xVals[i], x1 = xVals[i + 1];
    double y0 = yVals[i], y1 = yVals[i + 1];

    // Linear interpolation
    return y0 + (x - x0) * (y1 - y0) / (x1 - x0);
}

int main(int argc, char *argv[]) {
    // ... [Previous main function code]

    std::vector<double> sensorWavelengths, sensorResponses;
    try {
        readSensorData("sensor_data.csv", sensorWavelengths, sensorResponses);
    } catch(const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    double totalRadiance = 0.0;
    for (double wavelength = lowerBound; wavelength <= upperBound; wavelength += 0.1) {
        double sensorResponse = interpolate(wavelength, sensorWavelengths, sensorResponses);
        double radiance = plancksLaw(wavelength, temperature);
        totalRadiance += radiance * sensorResponse;
    }

    std::cout << "Total apparent radiance for the sensor: " << totalRadiance << " W/(m^2*sr)" << std::endl;

    return 0;
}
