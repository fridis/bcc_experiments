# helloworld

A small example for using bcc to run eBPF code, just to check if the build chain
works.

# build and run

To build this, you will have to check out and build bcc. Here is what needs to
be done:

    > mkdir work
    > cd work
    > git clone https://github.com/iovisor/bcc

Note that the directory used for bcc does not matter, it will be provided later
via the `$BCC` env variable.

Now check `bcc/INSTALL.md` what you need to build from source. For Ubuntu 24.04,
this is what is needed:

    > sudo apt install -y zip bison build-essential cmake flex git libedit-dev \
      libllvm18 llvm-18-dev libclang-18-dev python3 zlib1g-dev libelf-dev libfl-dev python3-setuptools \
      liblzma-dev libdebuginfod-dev arping netperf iperf libpolly-18-dev

Then you can build it, again, for Ubuntu:

    > git clone https://github.com/iovisor/bcc.git
    > mkdir bcc/build; cd bcc/build
    > cmake ..
    > make
    > sudo make install

The following should not be needed since we are not using python:

    > cmake -DPYTHON_CMD=python3 .. # build python3 binding
    > pushd src/python/
    > make
    > sudo make install
    > popd

then we can return to the work directory:

    > cd ../..

Now, you can build this example giving the path to the `bcc` directory via env var `BCC`:

    > BCC=bcc make -f ../bcc_experiments/helloworld/Makefile

and run it:

    > BCC=bcc make -f ../bcc_experiments/helloworld/Makefile run
