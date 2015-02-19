#include <iostream>
#include <pthread.h>
#include <string>
#include <math.h>
#include "thread.cpp"

using namespace std;

void *compare(void *arg) {
	Thread * thread = (Thread*)arg;
	if (Max::data[2 * thread->thread_id] > Max::data[(2 * thread->thread_id) + 1]) {
		Max::lag[thread->thread_id] = Max::data[2 * thread->thread_id];
	}
	else {
		Max::lag[thread->thread_id] = Max::data[(2 * thread->thread_id) + 1];
	}
	(thread->barrier_list[thread->barrier_counter])->enq();
	// We've compared values and moved them up an array. Now let's see if we need to terminate.
	if ((thread->thread_id)%2 == 0) { // We're even, we get to live
		thread->barrier_counter++; // We're going to look at the next barrier 
		thread->thread_id /= 2;
		if (Max::data_size == 1) {
			pthread_exit(NULL);
		}
		compare(thread); // Go for another round
	}
	else {
		pthread_exit(NULL);
	}
}

int main() {
	int num_of_nums = 0;
	string in;
	getline(std::cin, in);
	while(in != "") {
		num_of_nums++;
		Max::data = (int*)realloc(Max::data, sizeof(int*) * num_of_nums);
		Max::data[num_of_nums - 1] = atoi(in.c_str());
		getline(std::cin, in);
	}
	Max::data_size = num_of_nums;
	Max::lag = (int*)malloc(sizeof(int*) * (num_of_nums/2));
	Thread** threads = (Thread**)malloc(sizeof(Thread**) * (num_of_nums/2));
	for (int i = 0; i < num_of_nums/2; i++) {
		threads[i] = new Thread(i);
	}
	Barrier* barrier;
	// This math is supa-nasty
	for (int i = 1; i < num_of_nums/2 + 1; i*=2) { // i governs how 
		barrier = new Barrier(num_of_nums/(2 * i));
		for (int j = 0; j < num_of_nums/2; j+=i) {
			threads[j]->subscribe(barrier);
		}
	}
	for (int i = 0; i < num_of_nums/2; i++) {
		pthread_create(&threads[i]->pthread, NULL, &compare, threads[i]);
	}
	pthread_join(threads[0]->pthread, NULL);
	cout << Max::data[0] << endl;
	return 0;
}
