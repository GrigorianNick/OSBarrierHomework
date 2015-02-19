/* barrier.h
 * 
 * Author: Nicholas Grigorian
 * CompID: ngg3vm
 *
 * Summary:
 *      barrier.h is the header file for the Barrier class. Barriers are
 * 	one-time use classes. After its count is initalized, it will wait for a
 *	certain number of threads to call the enq method. Once that number has been
 * 	reached, it "breaks" and releases the attendent threads.
 * 
 * Methods:
 * 	enq:
 *		enq is what threads call when they want to rendevous with other
 * 		threads. First the method decrements count. If count is above
 * 		zero, then that indicates not all threads have made it to the
 * 		rendevous point. Thus, the thread will lock on the alread
 * 		locked gate_mutex. If count is zero, then that indicates that
 * 		thread is the last to join. It will then perform any adjustments
 * 		to memory (in this case shuffling Max's variables around) then
 * 		it'll unlock the gate_mutex. This will give the lock to another
 *		thread, which will immediatly unlock thus repeating the process
 * 		until all threads at the rendevous have been released.
 */

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
