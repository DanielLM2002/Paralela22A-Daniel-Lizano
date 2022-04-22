$(OBJ_DIR)/output%.txt: SHELL:=/bin/bash
$(OBJ_DIR)/output%.txt: $(TST_DIR)/input%.txt $(TST_DIR)/output%.txt
	icdiff --no-headers $(word 2,$^) <($(EXEARGS) < $<)

# Documentation
doc: $(INPUTCX)
	doxygen

# Utility rules
.PHONY: lint run memcheck helgrind gitignore clean instdeps

lint:
ifneq ($(INPUTFC),)
	cpplint --filter=$(LINTC) $(INPUTFC)
endif
ifneq ($(INPUTFX),)
	cpplint --filter=$(LINTX) $(INPUTFX)
endif

run: $(EXEFILE)
	$(EXEARGS)

memcheck: $(EXEFILE)
	valgrind --tool=memcheck $(EXEARGS)

helgrind: $(EXEFILE)
	valgrind --quiet --tool=helgrind $(EXEARGS)

gitignore:
	echo $(IGNORES) | tr " " "\n" > .gitignore

clean:
	rm -rf $(IGNORES)

# Install dependencies (Debian)
instdeps:
	sudo apt install build-essential clang valgrind icdiff doxygen graphviz \
	python3-pip python3-gpg && sudo pip3 install cpplint

help:
	@echo "Usage make [-jN] [VAR=value] [target]"
	@echo "  -jN       Compile N files simultaneously [N=1]"
	@echo "  VAR=value Overrides a variable, e.g CC=mpicc DEFS=-DGUI"
	@echo "  all       Run targets: doc lint [memcheck helgrind] test"
	@echo "  asan      Build for detecting memory leaks and invalid accesses"
	@echo "  clean     Remove generated directories and files"
	@echo "  debug     Build an executable for debugging [default]"
	@echo "  doc       Generate documentation from sources with Doxygen"
	@echo "  gitignore Generate a .gitignore file"
	@echo "  helgrind  Run executable for detecting thread errors with Valgrind"
	@echo "  instdeps  Install needed packages on Debian-based distributions"
	@echo "  lint      Check code style conformance using Cpplint"
	@echo "  memcheck  Run executable for detecting memory errors with Valgrind"
	@echo "  msan      Build for detecting uninitialized memory usage"
	@echo "  release   Build an optimized executable"
	@echo "  run       Run executable using ARGS value as arguments"
	@echo "  test      Run executable against test cases in folder tests/"
	@echo "  tsan      Build for detecting thread errors, e.g race conditions"
	@echo "  ubsan     Build for detecting undefined behavior"