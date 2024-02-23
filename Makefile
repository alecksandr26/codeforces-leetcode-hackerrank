CPP = c++
CPP_FLAGS = -ggdb -pedantic -Wall

V = valgrind -s --leak-check=full --show-leak-kinds=all
SRC_DIR = src
BIN_DIR = bin
IN_DIR = input

BINS = $(addprefix $(BIN_DIR)/, valid-anagram.out \
				longest-palindromic-substring.out\
				counting-triangles.out\
				lets-count-words.out\
				shortest_path2.out\
				fixing_subtitles.out\
				hog_fencing.out\
				kilo_waste.out\
				sum_of_round_numbers.out\
				black_and_white.out\
				restore_the_wheather.out\
				karina_and_array.out\
				sort_with_step.out\
				character_blocking.out\
				medium_number.out\
				water_station.out\
				filter.out\
				pi.out\
				new_scheme.out\
				full_moon.out\
				order_something_else.out\
				edge_checker_2.out\
				restaurant.out\
				remeaining_time.out\
				yes_or_yes.out\
				horsesho.out\
				swap_odd_and_even.out\
				gift_carpet.out\
				beautiful_mat.out\
				C_recursion.out\
				new_year_transportation.out\
				two_buttons2.out)

all: $(BIN_DIR) $(BINS)

$(BIN_DIR):
	mkdir -p $@

$(BIN_DIR)/%.out: $(SRC_DIR)/*/%.cpp
	$(CPP) $(CPP_FLAGS) $< -o $@

%.out: $(BIN_DIR)/%.out $(IN_DIR)/*/%.txt
	cat $(word 2, $^) | ./$<


