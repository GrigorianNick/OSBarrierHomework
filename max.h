/* max.h
 * 
 * Author: Nicholas Grigorian
 * CompID: ngg3vm
 *
 * Summary:
 * 	max.h is the header file for the Max class. Max is used for shuttling
 * 	data between threads.
 */
#include <iostream>

using namespace std;

class Max {

	public:
		static int* data;
		static int* lag;
		static int data_size;
};
