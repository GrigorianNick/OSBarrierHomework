/* thread.h
 * 
 * Author: Nicholas Grigorian
 * CompID: ngg3vm
 *
 * Summary:
 *      thread.h is the header file for the Thread class. Originally meant to
 *      encapsulate pthreads, it evolved into a record-keeper for pthreads. It has
 *      two primary jobs: keep track of thread_id and to manage the Barrier
 *      subscriptions.
 * 
 * Methods:
 *      subscribe:
 *              Adds a Barrier to the barrier list, thereby signing the object up for
 *              that particular barrier's breaking.
 */

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
		void subscribe(Barrier* barrier); // Keep track of barriers we need to work through
};
