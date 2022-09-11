#include <zephyr/zephyr.h>

#if __cplusplus
extern "C" 
#endif
int code1(int val, int inc);
int code2(int val, int inc);
#if __cplusplus
extern "C"
#endif
int code3(int val, int inc);

#if __cplusplus
extern "C" 
#endif
void init_cc(int val);