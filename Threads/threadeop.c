#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

#define N 50  // Limit

int counter = 0;  // Shared global variable
pthread_mutex_t lock;  // Mutex for synchronization

// Function to check if a number is prime
bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Thread function for even numbers
void* print_even(void* arg) {
    while (counter <= N) {
      
        if (counter % 2 == 0) {
            printf("Even Thread: %d\n", counter);
            counter++;  
        }
      
    }
    return NULL;
}

// Thread function for odd numbers
void* print_odd(void* arg) {
    while (counter <= N) {
      
        if (counter % 2 == 1) {
            printf("Odd Thread: %d\n", counter);
            counter++;  // Increment counter
        }
       
    }
    return NULL;
}

// Thread function for prime numbers
void* print_prime(void* arg) {
    while (counter <= N) {
        pthread_mutex_lock(&lock);
        if (is_prime(counter)) {
            printf("Prime Thread: %d\n", counter);
        }
        counter++;  // Increment counter for next check
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;
    pthread_mutex_init(&lock, NULL);

    // Creating threads
    pthread_create(&t1, NULL, print_even, NULL);
    pthread_create(&t2, NULL, print_odd, NULL);
    pthread_create(&t3, NULL, print_prime, NULL);

    // Waiting for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    pthread_mutex_destroy(&lock);
    printf("Threads execution completed.\n");
    return 0;
}

