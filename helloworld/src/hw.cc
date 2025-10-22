/*
 * Copyright (c) Facebook, Inc.
 * Licensed under the Apache License, Version 2.0 (the "License")
 */

/* This is based on bcc/examples/cpp/HelloWorld.cc from
 *
 *   https://github.com/iovisor/bcc/blob/master/examples/cpp/HelloWorld.cc
 *
 */

#include <unistd.h>
#include <fstream>
#include <iostream>
#include <string>

#include "bcc_version.h"
#include "BPF.h"

const std::string BPF_PROGRAM = R"(
int on_sys_clone(void *ctx) {
  bpf_trace_printk("Hello, World! Here I did a sys_clone call!\n");
  return 0;
}
)";

int main()
{
  ebpf::BPF bpf;
  ebpf::StatusTuple res = bpf.init(BPF_PROGRAM);
  if (res.ok())
    {
      std::string clone_fnname = bpf.get_syscall_fnname("clone");
      res = bpf.attach_kprobe(clone_fnname, "on_sys_clone");
      if (res.ok())
        {
          printf("Starting HelloWorld with BCC %s\n", LIBBCC_VERSION);
          std::ifstream pipe("/sys/kernel/debug/tracing/trace_pipe");
          std::string line;
          while (!std::getline(pipe, line))
            {
              printf("Waiting for a sys_clone event\n");
              sleep(1);
            }
          printf("%s\n",line.c_str());
          res = bpf.detach_kprobe(clone_fnname);
        }
    }
  if (res.ok())
    {
      return 0;
    }
  else
    {
      fprintf(stderr, "%s\n", res.msg().c_str());
      return 1;
    }
}
