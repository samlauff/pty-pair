#ifndef SRC_PTY_PAIR_H_
#define SRC_PTY_PAIR_H_

#include <nan.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pty.h>
#include <pthread.h>

NAN_METHOD(Hello);

struct OpenBaton {
  int result;
};

#endif // SRC_SERIALPORT_H_