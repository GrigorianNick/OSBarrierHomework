#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	int thing;

	srand(time(NULL));

	for (int i = 0; i < 4096; i++) {
		thing = rand() % 10000;
		cout << thing << endl;
	}
	cout << endl << endl;
}
