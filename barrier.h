#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include "max.h"

using namespace std;

class Barrier {
	public:
		int count;
		void enq();
		Barrier(int init_count);
		~Barrier();
		pthread_mutex_t count_mutex; // Lock on this whenever you want to touch count.
		pthread_mutex_t gate_mutex; // Lock on this when you're waiting for rendezvous. Unlock as soon as you get it.
};
