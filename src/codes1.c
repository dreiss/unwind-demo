#include "app.h"

int code1(int val, int inc) {
    int acc = val;
    acc += inc;
    acc = code2(acc, 157);
    acc += inc;
    return acc;
}