/*
    montecarlopi.cpp
    A program "challenge" for Pi Day in 2017.
    http://www.fluentcpp.com/2017/03/02/the-pi-day-challenge-for-expressive-code-in-c/
    This contains a Monte Carlo method for calculating pi using the included
    "random" C++ libary.
*/

// The random header requires C++ 11 support
#include <random>
#include <iostream>
#include <iomanip>
#include <cmath>

/*
    Define pi using mathematical functions; not all implementations provide
    an implicit value.
    Also, I just don't want to define my own constant of arbitrary precision.
    Better to leave precision in the hands of implementation when calculating
    errors.
*/
constexpr double const_pi() {
    return std::atan2(0,-1);
}

double CalcPiError(double n, double m) {
    double radius = std::pow(10.0, n);
    std::random_device generator;  // "True" generator implementation
    std::uniform_real_distribution<double> distribution(-radius, radius);
    double x, y, distance;
    int incircle = 0;  // Count of points within circle
    int numpoints = (int)std::pow(10.0, m);
    // Using a Cartesian coordinate system with geometry centroid at origin
    for (int num = 0; num < numpoints; num++) {
        // x coordinate
        x = distribution(generator);
        // y coordinate
        y = distribution(generator);
        // Pythagorean theorem for distance, match to radius
        distance = std::sqrt(x*x + y*y);
        if (distance < radius) {
            incircle++;
        }
    }
    // The probability of a point lying in a circle that is generated within
    // a square is equivalent to pi/4
    double estimate = (double)incircle / (double)numpoints * 4.0;
    return std::abs(estimate - const_pi());
}

// Sensitivity analysis is housed in main()
int main(int argc, char *argv[]) {
    // Calculate pi as a matter of a circle of radius 10^n unit length
    // n from 0 to 9
    double errormatrix[7][9];
    std::cout << "Calculating..." << std::endl;
    for (int n = 0; n < 10; n++) {
        // Display progress...
        std::cout << "n = " << n << std::endl;
        // The value m defines the number of points as 10^m
        // m from 0 to 7
        for (int m = 0; m < 8; m++) {
            errormatrix[m][n] = CalcPiError(static_cast<double>(n), static_cast<double>(m));
        }
    }
    // Display results in given character precision
    // Columns printed control increasing particle counts
    // Rows printed control increasing radius
    std::cout << std::fixed << std::setprecision(8);
    for (int n = 0; n < 10; n++) {
        for (int m = 0; m < 8; m++) {
            std::cout << errormatrix[m][n] << " ";
        }
        std::cout << std::endl;
    }
}
