#include "barrier.h"

using namespace std;

int Max::data_size;
int* Max::data;
int* Max::lag;

void Barrier::enq() {
	pthread_mutex_lock(&(this->count_mutex));
	count--;
	if (this->count <= 0) { // We're the nth thread to unlock. Time to let everybody advance.
		pthread_mutex_unlock(&(this->count_mutex)); // Releasing count mutex because we don't need it.
		// Shift Thread.lag down into Thread.data and reprep Thread.lag
		if (Max::data_size > 1) { // We don't want prep Thread.lag to 0
			Max::data_size /= 2;
			free(Max::data);
			Max::data = Max::lag;
			Max::lag = NULL;
			Max::lag = (int*)malloc(sizeof(int) * (Max::data_size/2));
		}
		pthread_mutex_unlock(&(this->gate_mutex));
	}
	else {
		pthread_mutex_unlock(&(this->count_mutex));
		pthread_mutex_lock(&(this->gate_mutex)); // Waiting for the proper number of threads to lock
		pthread_mutex_unlock(&(this->gate_mutex)); // We're free!
	}
}

Barrier::Barrier(int init_count) {
	pthread_mutex_init(&(this->gate_mutex), NULL);
	pthread_mutex_lock(&(this->gate_mutex)); // Erecting the barrier
	pthread_mutex_init(&(this->count_mutex), NULL);
	this->count = init_count;
}

Barrier::~Barrier() {
	pthread_mutex_destroy(&(this->gate_mutex));
	pthread_mutex_destroy(&(this->count_mutex));
}
