CC         = g++
FLAGS      = -Wall -std=c++11
LDFLAGS    = -lallegro -lallegro_dialog -lallegro_primitives -lallegro_image -lallegro_font -lallegro_ttf
PROG_NAME  = Allegro_Engine

SRC_DIR    = ./src
BUILD_DIR  = ./build
BIN_DIR    = ./bin

SRC_LIST  = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_LIST  = $(addprefix $(BUILD_DIR)/, $(notdir $(SRC_LIST:.cpp=.o)))

SUCCESS_COMPILE_TEXT="\033[1;32mProgram skompilowany pomyślnie!\033[0m"

$(PROG_NAME): $(OBJ_LIST)
	$(CC) $(OBJ_LIST) -o $(BIN_DIR)/$(PROG_NAME) $(LDFLAGS)
	@echo $(SUCCESS_COMPILE_TEXT)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(BIN_DIR)/* $(BUILD_DIR)/*.o
