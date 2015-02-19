#include "thread.h"

using namespace std;

Thread::Thread(int id) {
	this->thread_id = id;
	barrier_list_size = 0;
	barrier_counter = 0;
	barrier_list = NULL;
}

void Thread::subscribe(Barrier* barrier) {
	barrier_list_size++;
	barrier_list = (Barrier**)realloc(barrier_list, sizeof(barrier_list) * barrier_list_size);
	barrier_list[barrier_list_size - 1] = barrier;
}

/*void Thread::run() {
	pthread_create(&pthread, NULL, compare, this); // Create our thread
	//pthread_join(this->pthread, NULL); // Join the thread, because I derped on the design.
}*/

/*void *compare(void* This) {
	This = (Thread*)This;
	// Run the comparison on Thread.data[] and move the bigger value to Thread.lag[]
	if (Max::data[2 * This->thread_id] > Max::data[(2 * This->thread_id) + 1]) {
		Max::lag[This->thread_id] = Max::data[2 * This->thread_id];
	}
	else {
		Max::lag[This->thread_id] = Max::data[(2 * This->thread_id) + 1];
	}
	(thread->barrier_list[This->barrier_counter]).enq();
	// We've compared values and moved them up an array. Now let's see if we need to terminate.
	if ((This->thread_id)%2 == 0) { // We're even, we get to live
		This->barrier_counter++; // We're going to look at the next barrier
		compare(thread); // Go for another round
	}
	else {
		pthread_exit(NULL);
	}
}*/
