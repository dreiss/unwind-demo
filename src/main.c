#include <stdlib.h>

#include <zephyr/zephyr.h>

#include "app.h"

void run_benchmark(void);

int main() {
  int ret;

  // init_cc(0);
    printk("go = %d\n", 42);


  for (;;) {
    run_benchmark();
    int tot = code1(6, 42);
    printk("tot = %d\n", tot);
    k_msleep(1000);
  }
  return 0;
}

static volatile uint32_t benchmark_output;

void run_benchmark() {
  uint8_t value[64] = {1};
  size_t i = 0;
  uint32_t hash = 0;
  while (i < sizeof(value)) {
    hash += value[i++];
    hash += hash << 10;
    hash ^= hash >> 6;
  }
  hash += hash << 3;
  hash ^= hash >> 11;
  hash += hash << 15;
  benchmark_output = hash;
}