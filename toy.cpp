#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
	int *data = NULL;
	int data_length = 0;
	int max = 0;
	string in;
	getline(std::cin, in);
	while(in != "") {
		data_length++;
	        data = (int*)realloc(data, sizeof(int*) * data_length);
	        data[data_length - 1] = atoi(in.c_str());
	        getline(std::cin, in);
	}
	for (int i = 0; i < data_length; i++) {
		if (data[i] > max) {
			max = data[i];
		}
	}
	cout << max << endl;
}
