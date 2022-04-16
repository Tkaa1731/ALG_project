CPP = g++
 
  # compiler flags:
  #  -g     - this flag adds debugging information to the executable file
  #  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall
 
  # The build target 
TARGET = main
DOC = graph_doc
LAB = graph_labyrinth
PEAK = graph_peak
 
  all: $(TARGET)
 
  $(TARGET): $(TARGET).cpp
			$(CPP) $(CFLAGS) -o $(TARGET) $(TARGET).cpp $(DOC).cpp $(LAB).cpp $(PEAK).cpp
	./$(TARGET)
	doxygen Doxyfile
  clean:
	$(RM) $(TARGET)