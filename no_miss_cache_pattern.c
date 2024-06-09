#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

void access_memory_no_miss(int *array, size_t size) {
    volatile int sum = 0;  // volatile to prevent compiler optimization

    for (size_t i = 0; i < size; i++) {
        sum += array[i];
    }
  
    printf("Sum: %d\n", sum);
}

void main(){
  size_t cache_size = 32 * 1024;
  size_t array_size = cache_size/(sizeof(int));

  int *array = (int *) malloc (array_size * sizeof(int));
  if(array = null){
    printf("Failed to allocate memory\n");
    return EXIT_FAILURE;
  }

  for (size_t i = 0; i < array_size; i++) {
    array[i] = i;
  }

  // Access memory in a way that ensures all accesses hit the cache
  access_memory_no_miss(array, array_size);

  // Free the allocated memory
  free(array);

  return 0;

}
