CXX = g++
CXXFLAGS = -std=c++14 -Wall -O2
TARGET = code
OBJ = main.cpp

$(TARGET) : $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ) $(CXXFLAGS)
	
clean : 
	rm -f