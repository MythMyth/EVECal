CXX = g++
CC = g++

OUTPUT_DIR = build
OUTPUT_NAME = EveCal
SRC = main.cpp
SRC += BP/Loader.cpp
SRC += BP/Item.cpp
SRC += BP/BP.cpp

TARGET = $(OUTPUT_DIR)/$(OUTPUT_NAME)

OBJ = $(foreach d, $(SRC), $(addsuffix .o, $(basename $d)))

$(TARGET): $(OBJ)
	$(CC) $(foreach d, $(OBJ), $(addprefix $(OUTPUT_DIR)/, $(notdir $d)) -o $(TARGET))
	mv $(TARGET) $(OUTPUT_NAME)

$(OBJ):
	$(CC) -c $(addsuffix .cpp, $(basename $@)) -o $(OUTPUT_DIR)/$(notdir $@)

clean: 
	rm -rf build
	mkdir build