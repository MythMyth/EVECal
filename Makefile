CXX = g++
CC = g++

OUTPUT_DIR = build
SRC = main.cpp
SRC += BP/Item.cpp
SRC += BP/BP.cpp

TARGET = build/EveCal

OBJ = $(foreach d, $(SRC), $(addsuffix .o, $(basename $d)))

$(TARGET): $(OBJ)
	$(CC) $(foreach d, $(OBJ), $(addprefix $(OUTPUT_DIR)/, $d) -o $(TARGET)

$(OBJ):
	$(CC) -c $(addsuffix .cpp, $(basename $@)) -o $(OUTPUT_DIR)/$@

clean: 
	rm -rf build
	mkdir build