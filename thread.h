#include <iostream>
#include <pthread.h>
#include "barrier.cpp"

using namespace std;

struct Thread {
	public: // Erythang's public
		pthread_t pthread;
		Barrier** barrier_list;
		int barrier_list_size;
		int barrier_counter;
		int thread_id;
		Thread(int id);
		void subscribe(Barrier* barrier);
		//void run();
		//static void* compare(void* This);
};
