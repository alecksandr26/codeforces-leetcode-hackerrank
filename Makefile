CPP = c++
CPP_FLAGS = -ggdb -pedantic -Wall

SRC_DIR = src
BIN_DIR = bin

BINS = $(addprefix $(BIN_DIR)/, \
				sum_of_round_numbers.out)

all: $(BIN_DIR) $(BINS)

$(BIN_DIR):
	mkdir -p $@

$(BIN_DIR)/%.out: $(SRC_DIR)/%.cpp
	$(CPP) $(CPP_FLAGS) $< -o $@
