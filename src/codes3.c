#include <unwind.h>

#include "app.h"

#define UNW_LOCAL_ONLY
#include <libunwind.h>

void show_backtrace (void) {
  unw_cursor_t cursor; unw_context_t uc;
  unw_word_t ip, sp;

  unw_getcontext(&uc);
  unw_init_local(&cursor, &uc);
  printk("stack trace:\n");
  while (unw_step(&cursor) > 0) {
    unw_get_reg(&cursor, UNW_REG_IP, &ip);
    //unw_get_reg(&cursor, UNW_REG_SP, &sp);
    //printk("ip = %lx, sp = %lx\n", (long) ip, (long) sp);
    if (unw_is_signal_frame(&cursor)) {
      ip--;
    }
    printk("0x%lx\n", (long) ip);
  }
  printk("\n");






}

void print_bt(void);

int code3(int val, int inc) {
  int acc = val;
  acc += inc;
  printk("acc = %d\n", acc);
  print_bt();
  acc += inc;
  return acc;
}

static _Unwind_Reason_Code frame_cb(struct _Unwind_Context* ctx, void* udata) {
  int before;
  _Unwind_Ptr ip = _Unwind_GetIPInfo(ctx, &before);
  (void)before;
  printk("%p %d\n", (void*)ip, before);
  return _URC_NO_REASON;
}

void print_bt() {
  // throw "honk";

  //_Unwind_Reason_Code ret = _Unwind_Backtrace(frame_cb, NULL);
  //printk("ret: %d\n", ret);

  show_backtrace();
#define BT_BUF_SIZE 64
  // void* bt_buf[BT_BUF_SIZE];
  // int ret = backtrace(bt_buf, BT_BUF_SIZE);
  // for (int i = 0; i < ret; i++) {
  //     printk("bt: %p\n", bt_buf[i]);
  // }
}
