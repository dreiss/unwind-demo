#include "app.h"

int code2(int val, int inc) {
    int acc = val;
    acc += inc;
    acc = code3(acc, 65000);
    acc += inc;
    return acc;
}