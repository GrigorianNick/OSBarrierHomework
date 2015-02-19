#include "thread.h"

using namespace std;

Thread::Thread(int id) {
	this->thread_id = id;
	barrier_list_size = 0;
	barrier_counter = 0;
	barrier_list = NULL;
}

// We want to pay attention to the barrier object being passed in
void Thread::subscribe(Barrier* barrier) {
	barrier_list_size++;
	barrier_list = (Barrier**)realloc(barrier_list, sizeof(barrier_list) * barrier_list_size);
	barrier_list[barrier_list_size - 1] = barrier;
}
