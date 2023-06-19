CPP = c++
CPP_FLAGS = -ggdb -pedantic -Wall

SRC_DIR = src
BIN_DIR = bin
IN_DIR = input

BINS = $(addprefix $(BIN_DIR)/, \
				sum_of_round_numbers.out\
				black_and_white.out\
				restore_the_wheather.out\
				karina_and_array.out\
				sort_with_step.out\
				character_blocking.out)

all: $(BIN_DIR) $(BINS)

$(BIN_DIR):
	mkdir -p $@

$(BIN_DIR)/%.out: $(SRC_DIR)/%.cpp
	$(CPP) $(CPP_FLAGS) $< -o $@

%.out: $(BIN_DIR)/%.out $(IN_DIR)/%.txt
	cat $(word 2, $^) | ./$<
