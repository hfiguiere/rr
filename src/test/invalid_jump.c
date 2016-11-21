/* -*- Mode: C; tab-width: 8; c-basic-offset: 2; indent-tabs-mode: nil; -*- */

#include "rrutil.h"

static void sighandler(int sig) {
  atomic_printf("caught signal %d, exiting\n", sig);
  _exit(0);
}

char invalid_jump_here[] = { 0x00, 0x00, 0x00, 0x00, 0x00 };

int main(void) {
  // Just for clean exit to not worry people running the test manually ;).
  signal(SIGSEGV, sighandler);
  ((void(*)(void))invalid_jump_here)();
  assert(0 && "Shouldn't reach here");
}
