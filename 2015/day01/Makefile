OUTPUT := main

SRCS := $(shell find . -name "*.c" | sort)

.PHONY: all
all: $(OUTPUT)

.PHONY: run
run: $(OUTPUT)
	./$(OUTPUT)

.PHONY: clean
clean:
	rm -rf $(OUTPUT)

$(OUTPUT): $(SRCS)
	clang -O3 $(OUTPUT).c -o $(OUTPUT)
