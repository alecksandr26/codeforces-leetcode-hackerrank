CPP = c++
CPP_FLAGS = -ggdb -pedantic -Wall

V = valgrind -s --leak-check=full --show-leak-kinds=all
SRC_DIR = src
BIN_DIR = bin
IN_DIR = input

BINS = $(addprefix $(BIN_DIR)/, valid_anagram.out)

all: $(BIN_DIR) $(BINS)

$(BIN_DIR):
	mkdir -p $@

$(BIN_DIR)/%.out: $(SRC_DIR)/*/%.cpp
	$(CPP) $(CPP_FLAGS) $< -o $@

%.out: $(BIN_DIR)/%.out $(IN_DIR)/*/%.txt
	cat $(word 2, $^) | $(V) $<


