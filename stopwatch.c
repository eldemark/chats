#include <stdio.h>
#include <time.h>

void precise_delay(long nanoseconds) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    long elapsed;
    do {
        clock_gettime(CLOCK_MONOTONIC, &end);
        elapsed = end.tv_nsec - start.tv_nsec;
        elapsed += (end.tv_sec - start.tv_sec) * 1000000000L;
    } while (elapsed < nanoseconds);
}

int main() {
    struct timespec requestStart, requestEnd;
    clock_gettime(CLOCK_MONOTONIC, &requestStart);

    // Your code to time here
    precise_delay(100000000); // Delay for 100 milliseconds as an example

    clock_gettime(CLOCK_MONOTONIC, &requestEnd);

    double accum = ( requestEnd.tv_sec - requestStart.tv_sec )
      + ( requestEnd.tv_nsec - requestStart.tv_nsec )
      / 1E9;
    printf("Time taken: %lf seconds\n", accum);

    return 0;
}

// Or run with:
// $ perf stat -e cycles,instructions ./your_program

// Using Intel

#include <stdio.h>
#include <stdint.h>

// Function to read the Time Stamp Counter
static inline uint64_t rdtsc() {
    uint32_t lo, hi;
    // Use inline assembly to read TSC
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    uint64_t start, end;

    start = rdtsc();
    // Code to time here
    end = rdtsc();

    printf("Elapsed TSC ticks: %llu\n", (unsigned long long)(end - start));

    return 0;
}

