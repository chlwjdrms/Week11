#include <iostream>

using namespace std;

// linear regression
// gradient descent method

const int arrayNum = 5;
const int testCount = 1000000;
const double lr = 0.0001; // learning rate

class LinearHypothesis {
public:
	double a = 0.0;
	double b = 0.0;
public:
	double getY(const double& x_input) {
		return (a * x_input + b);
	}
};

int main() {

	// 0 -> 0
	// 1 -> 3
	// 2 -> 7.5
	// hypothesis
	// y = a * x + b;

	double X0[arrayNum] = {0.1, 0.2, 0.3, 0.4, 0.5}; // study_time
	double X1[arrayNum];
	double Ytargrt[arrayNum] = { 4, 5, 6, 7, 8 }; // score

	LinearHypothesis study;
	LinearHypothesis Doublestudy;

	
	for (int r = 0; r < testCount; r++) {
		// x1 구하기
		for (int i = 0; i < arrayNum; i++) {
			const double error = (Ytargrt[i] - study.getY(X0[i]));
			const double sqr_error = (error * error);

		    const double d_error_over_d_a = 2.0 * -error * X0[i];
			const double d_error_over_d_b = 2.0 * -error * 1.0;


			study.a -= d_error_over_d_a * lr;
			study.b -= d_error_over_d_b * lr;

			X1[i] = study.getY(X0[i]);
		}

		// x2(y) 구하기
		for (int i = 0; i < arrayNum; i++) {
			const double error = (Ytargrt[i] - Doublestudy.getY(X1[i]));
			const double sqr_error = (0.5 * error * error);

			const double d_error_over_d_a = 2.0 * -error * X1[i];
			const double d_error_over_d_b = 2.0 * -error * 1.0;


			Doublestudy.a -= d_error_over_d_a * lr;
			Doublestudy.b -= d_error_over_d_b * lr;

			cout << "X0: " << X0[i] << ", Y->" << Doublestudy.getY(X1[i]) << endl;
		}
		cout << endl;
	}

	return 0;
}