#include "generalizedMagicSquare.h"

int z;

void magicSquare::calcDifferences(int n, int m) {
	int mi, ni, mj, nj;
	bool fn = false, fm = false;
	if (n < (z * z) && m <= (z * z)) {
		int x = 0;
		while (x < (z * z)) {
			int i = (x % z), j = floor(x / z);
			if (n == matrix[i][j]) {
				mi = i;
				mj = j;
				fn = true;
			}
			if (m == matrix[i][j]) {
				ni = i;
				nj = j;
				fm = true;
			}
			int limit = ((z * z) / 2) - (z / 2);
			if (fn && fm) {
 				cout << n << " -> " << m << " | (" << mi << "," << mj << ") - (" << ni << "," << nj << ") " << "\t" <<  " | = (" << (mi - ni) << ", " << (mj - nj) << ") \n";
				fn = false, fm = false;
				//if ((mi - ni == -1) && (mj - nj == -1)) {
				//	cout << "(((" << (mi - ni) << ", " << (mj - nj) << "))) \n";
				//}
				if (n == limit) {
					cout << "Start of differencies: " << "\n";
				}
				if (n == limit + 1 + (z - 2)) {
					cout << "End of differencies" << "\n";
				}
			}

			++x;
		}

		calcDifferences(n + 1, m + 1);
	}
}


/* InitMatrix*/
void magicSquare::initMatrix(int n) {
	matrix.resize(n, std::vector<int>(n, 0));
	// This is princeton CS code(from their site)
	int row = n - 1;
	int col = n / 2;
	matrix[row][col] = 1;

	for (int i = 2; i <= n * n; ++i) {
		if (matrix[(row + 1) % n][(col + 1) % n] == 0) {
			row = (row + 1) % n;
			col = (col + 1) % n;
		}
		else {
			row = (row - 1 + n) % n;
		}
		matrix[row][col] = i;
	}
	// end of princeton CS code(from their site)
}

void magicSquare::print() {
	int n = 1;
	cout << "The square is: " << "\n";
	// Print the square
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[i].size(); ++j) {
			cout << matrix[i][j] << "\t";
		}
		cout << "\n";
	}

	cout << "\n";

	// Print the square indecis, In an order of numbers(Ascending)
	cout << "Indices of the square, arranging the numbers from 1 to n^2" << "\n";
	while (n <= (z * z)) {
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[i].size(); ++j) {
				if (n == matrix[i][j]) {
					cout << "(" << i << "," << j << ")" << "\t";
					++n;
					cout << '\n';
				}
			}
		}
	}
	cout << "\n";

	//calc differences 
	cout << "Differences of positions of numbers in the square are: " << "\n";
	calcDifferences(1, 2);
}

int main(int argc, char* argv[]) {
	cout << "Enter matrix order n : ";
	cin >> z;
	cout << "\n";
	magicSquare square;	
	square.initMatrix(z);
	square.print();

	return 0;
}