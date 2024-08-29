#include <iostream>
#include <iomanip>

using namespace std;

const float L = 8.0;   // Length of the rod (8 cm)
const float T = 0.625; // Total time (5 * 0.125 = 0.625 seconds)
const float dx = 1.0;  // Spatial step (1 cm)
const float dt = 0.125; // Time step (0.125 s)
const float alpha = 4.0; // Diffusivity constant

void solveTridiagonal(float* a, float* b, float* c, float* d, float* u, int n) {
    float* alpha_coeff = new float[n];
    float* beta_coeff = new float[n];

    // Initialize alpha0 and beta0
    alpha_coeff[0] = b[0];
    beta_coeff[0] = d[0] / b[0];

    // Forward sweep: compute alpha and beta coefficients
    for (int i = 1; i < n; ++i) {
        alpha_coeff[i] = b[i] - (a[i] * c[i - 1]) / alpha_coeff[i - 1];
        beta_coeff[i] = (d[i] - a[i] * beta_coeff[i - 1]) / alpha_coeff[i];
    }

    // Backward substitution to find the solution
    u[n - 1] = beta_coeff[n - 1];

    for (int i = n - 2; i >= 0; --i) {
        u[i] = beta_coeff[i] - (c[i] * u[i + 1]) / alpha_coeff[i];
    }

    delete[] alpha_coeff;
    delete[] beta_coeff;
}

int main() {
    int n = static_cast<int>(L / dx) + 1; // Number of spatial points
    int m = static_cast<int>(T / dt);     // Number of time steps

    // Allocate memory for arrays
    float* u = new float[n];
    float* u_prev = new float[n];
    float* a = new float[n - 2];
    float* b = new float[n - 2];
    float* c = new float[n - 2];
    float* d = new float[n - 2];

    // Initialize arrays and initial condition u(x,0) = x(8-x)/2
    for (int i = 0; i < n; ++i) {
        float x = i * dx;
        u[i] = (x * (8.0 - x)) / 2.0;
        u_prev[i] = u[i];
    }

    // Boundary conditions
    u[0] = 0.0;
    u[n - 1] = 0.0;
    u_prev[0] = 0.0;
    u_prev[n - 1] = 0.0;

    float r = (alpha * dt) / (dx * dx);

    // Initialize coefficients of the tridiagonal matrix
    for (int i = 0; i < n - 2; ++i) {
        a[i] = -r;
        b[i] = 1 + 2 * r;
        c[i] = -r;
    }

    cout << "Temperature distribution after zeroth time level:\n";
    for (int i = 0; i < n; ++i) {
        cout << "u(" << i * dx << ") = " << setprecision(3) << u[i] << "   ";
    }
    cout <<endl<<endl;

    // Time-stepping loop
    for (int j = 0; j < m; ++j) {
        // Prepare the right-hand side vector `d`
        for (int i = 1; i < n - 1; ++i) {
            d[i - 1] = u_prev[i];
        }

        d[0] += r * u[0];         // Adjust the first entry to account for the left boundary
        d[n - 3] += r * u[n - 1]; // Adjust the last entry to account for the right boundary

        // Solve the tridiagonal system for the current time step
        solveTridiagonal(a, b, c, d, u + 1, n - 2);

        // Update the previous time step solution
        for (int i = 1; i < n - 1; ++i) {
            u_prev[i] = u[i];
        }

        // Print the temperature distribution at the current time level
        cout << "Temperature distribution after time level " << (j + 1) * dt << " seconds:\n";
        for (int i = 0; i < n; ++i) {
            cout << "u(" << i * dx << ") = " << setprecision(3) << u[i] << "   ";
        }
        cout <<endl<<endl;
    }

    // Free allocated memory
    delete[] u;
    delete[] u_prev;
    delete[] a;
    delete[] b;
    delete[] c;
    delete[] d;

    return 0;
}