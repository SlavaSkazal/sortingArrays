#include <iostream>

using namespace std;

int lengthOfArray() {

	int lengthArr;

	cout << "Enter length of array: ";
	cin >> lengthArr;

	return lengthArr;
}

void printArray(int arr[], int lengthArr, string nameArr) {

	cout << "Array " + nameArr + ":" << endl;

	for (int i = 0; i < lengthArr; i++) {
		cout << arr[i] << endl;
	}

	cout << endl;
}

int main(int argc, char** argv) {

	int lengthA, lengthB, lengthC, temporary;
	float geometricMean;

	lengthA = lengthOfArray();
	lengthB = lengthOfArray();
	lengthC = lengthA + lengthB;

	if (lengthA < 0 || lengthB < 0) {

		cout << "Array length cannot be less than 0";
		return 0;
	}
	else if (lengthA == 0 && lengthB == 0) {
	
		cout << "Arrays are empty";
		return 0;
	}

	int* A = new int[lengthA];
	int* B = new int[lengthB];
	int* С = new int[lengthC];

	srand(time(NULL));

	for (int i = 0; i < lengthA; i++) {
		A[i] = rand();
	}

	for (int i = 0; i < lengthB; i++) {
		B[i] = rand();
	}

	cout << endl;
	printArray(A, lengthA, "A");
	printArray(B, lengthB, "B");

	for (int i = 0; i < lengthA; i++) {
		С[i] = A[i];
	}

	for (int i = 0; i < lengthB; i++) {
		С[i + lengthA] = B[i];
	}

	for (int i = 0; i < lengthC - 1; i++) {

		for (int y = 0; y < lengthC - i - 1; y++) {

			if (С[y] > С[y + 1]) {

				temporary = С[y];
				С[y] = С[y + 1];
				С[y + 1] = temporary;
			}
		}
	}

	for (int i = 0; i < lengthC - 1; i++) {
		temporary = С[i] * С[i + 1];
	}

	geometricMean = pow(temporary, 1. / 3.);

	printArray(С, lengthC, "C");

	cout << endl;
	cout << "min C: " << С[0] << endl;
	cout << "max C: " << С[lengthC - 1] << endl;
	cout << "geometric mean C: " << geometricMean;

	delete A, B, С;

	return 0;
}