# Makefile for `hw` example
#
# to build the example, you may be in any directory. The patch to the build bcc
# repo must be given via env var $BCC. To compile, do this:
#
#   > mkdir work
#   > cd work
#   > BCC=<path to bcc repo> make -f ../bcc_experiments/helloworld/Makefile
#
# to run
#
#   > make -f ../bcc_experiments/helloworld/Makefile run
#

# the source directory, i.e., the directory containing this Makefile
HW_SRC = $(patsubst %/,%,$(dir $(lastword $(MAKEFILE_LIST))))

# the build directory is relative to the current dir
BUILD_DIR = ./build

# main name
MAIN = hw

# BCC path, must be set explicitly from outside, or, maybe the default works for
# your config:
#
BCC ?= ../../bcc

# location of include files
INCLUDE = -I$(BCC)/build/src/cc -I$(BCC)/src/cc/api -I$(BCC)/src/cc

# location of libraries
LLVM = /usr/lib/llvm-18/lib
SYS_LIBS = /usr/lib/x86_64-linux-gnu

LLVM_LIBS = \
  $(LLVM)/libclangFrontend.a \
  $(LLVM)/libclangSerialization.a \
  $(LLVM)/libclangDriver.a \
  $(LLVM)/libclangASTMatchers.a \
  $(LLVM)/libclangParse.a \
  $(LLVM)/libclangSema.a \
  $(LLVM)/libclangCodeGen.a \
  $(LLVM)/libclangAnalysis.a \
  $(LLVM)/libclangRewrite.a \
  $(LLVM)/libclangEdit.a \
  $(LLVM)/libclangAST.a \
  $(LLVM)/libclangLex.a \
  $(LLVM)/libclangSupport.a \
  $(LLVM)/libclangAPINotes.a \
  $(LLVM)/libclangBasic.a \
  $(LLVM)/libLLVMFrontendDriver.a \
  $(LLVM)/libLLVMFrontendHLSL.a \
  $(LLVM)/libLLVMWindowsDriver.a \
  $(LLVM)/libLLVMCoverage.a \
  $(LLVM)/libLLVMX86CodeGen.a \
  $(LLVM)/libLLVMX86Desc.a \
  $(LLVM)/libLLVMX86Info.a \
  $(LLVM)/libLLVMBPFDisassembler.a \
  $(LLVM)/libLLVMMCDisassembler.a \
  $(LLVM)/libLLVMBPFAsmParser.a \
  $(LLVM)/libLLVMLTO.a \
  $(LLVM)/libLLVMExtensions.a \
  $(LLVM)/libPolly.a \
  $(LLVM)/libPollyISL.a \
  $(LLVM)/libLLVMPasses.a \
  $(LLVM)/libLLVMCoroutines.a \
  $(LLVM)/libLLVMCFGuard.a \
  $(LLVM)/libLLVMIRPrinter.a \
  $(LLVM)/libLLVMHipStdPar.a \
  $(LLVM)/libLLVMOption.a \
  $(LLVM)/libLLVMMCJIT.a \
  $(LLVM)/libLLVMExecutionEngine.a \
  $(LLVM)/libLLVMOrcTargetProcess.a \
  $(LLVM)/libLLVMOrcShared.a \
  $(LLVM)/libLLVMRuntimeDyld.a \
  $(LLVM)/libLLVMBPFCodeGen.a \
  $(LLVM)/libLLVMipo.a \
  $(LLVM)/libLLVMFrontendOpenMP.a \
  $(LLVM)/libLLVMFrontendOffloading.a \
  $(LLVM)/libLLVMLinker.a \
  $(LLVM)/libLLVMInstrumentation.a \
  $(LLVM)/libLLVMVectorize.a \
  $(LLVM)/libLLVMAsmPrinter.a \
  $(LLVM)/libLLVMGlobalISel.a \
  $(LLVM)/libLLVMSelectionDAG.a \
  $(LLVM)/libLLVMCodeGen.a \
  $(LLVM)/libLLVMObjCARCOpts.a \
  $(LLVM)/libLLVMScalarOpts.a \
  $(LLVM)/libLLVMAggressiveInstCombine.a \
  $(LLVM)/libLLVMInstCombine.a \
  $(LLVM)/libLLVMTransformUtils.a \
  $(LLVM)/libLLVMCodeGenTypes.a \
  $(LLVM)/libLLVMTarget.a \
  $(LLVM)/libLLVMBPFDesc.a \
  $(LLVM)/libLLVMBPFInfo.a \
  $(LLVM)/libLLVMBitWriter.a \
  $(LLVM)/libLLVMAnalysis.a \
  $(LLVM)/libLLVMProfileData.a \
  $(LLVM)/libLLVMSymbolize.a \
  $(LLVM)/libLLVMDebugInfoDWARF.a \
  $(LLVM)/libLLVMDebugInfoPDB.a \
  $(LLVM)/libLLVMDebugInfoMSF.a \
  $(LLVM)/libLLVMDebugInfoBTF.a \
  $(LLVM)/libLLVMObject.a \
  $(LLVM)/libLLVMIRReader.a \
  $(LLVM)/libLLVMAsmParser.a \
  $(LLVM)/libLLVMBitReader.a \
  $(LLVM)/libLLVMCore.a \
  $(LLVM)/libLLVMRemarks.a \
  $(LLVM)/libLLVMBitstreamReader.a \
  $(LLVM)/libLLVMMCParser.a \
  $(LLVM)/libLLVMMC.a \
  $(LLVM)/libLLVMDebugInfoCodeView.a \
  $(LLVM)/libLLVMTextAPI.a \
  $(LLVM)/libLLVMBinaryFormat.a \
  $(LLVM)/libLLVMTargetParser.a \
  $(LLVM)/libLLVMSupport.a \
  $(LLVM)/libLLVMDemangle.a \

SHARED_LIBS = \
  $(SYS_LIBS)/libz.so \
  $(SYS_LIBS)/libzstd.so \
  $(SYS_LIBS)/libtinfo.so \
  $(SYS_LIBS)/libelf.so \
  $(SYS_LIBS)/liblzma.so \
  $(SYS_LIBS)/libdebuginfod.so \

BCC_LIBS = \
  $(BCC)/build/src/cc/libbcc.a \
  $(BCC)/build/src/cc/frontends/clang/libclang_frontend.a \
  $(BCC)/build/src/cc/libbcc_bpf.a \
  $(BCC)/build/src/cc/usdt/libusdt-static.a \
  $(BCC)/build/src/cc/libbcc-loader-static.a \

# build all binaries
all: $(BUILD_DIR)/bin/$(MAIN)

$(BUILD_DIR)/obj/$(MAIN).o: $(HW_SRC)/src/$(MAIN).cc
	(test -f $(BCC)/build/src/cc/libbcc.a || (echo "env var $BCC not set correctly: $(BCC)" && fail))
	mkdir -p $(@D)
	clang $(INCLUDE) -o $@ -c $^

$(BUILD_DIR)/bin/$(MAIN): $(BUILD_DIR)/obj/$(MAIN).o
	mkdir -p $(@D)
	clang -Wall -fPIC -O3 -DNDEBUG $^ -o $@  \
           -Wl,--whole-archive \
           $(LLVM_LIBS) \
           -Wl,--no-whole-archive \
           $(SHARED_LIBS) \
           $(BCC_LIBS) \
           -lrt \
           -ldl \
           -lm \
           -lstdc++ \
           -lelf \
           -lz \

# run the binary
run: $(BUILD_DIR)/bin/$(MAIN)
	sudo $(BUILD_DIR)/bin/$(MAIN)

# remove all built files
clean:
	rm -rf $(BUILD_DIR)
