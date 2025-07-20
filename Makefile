


CXX = g++





CXXFLAGS = -std=c++11 -Wall -g


EXEC = loadbalancer_sim


SOURCES = main.cpp LoadBalancer.cpp WebServer.cpp


OBJECTS = $(SOURCES:.cpp=.o)



all: $(EXEC)



$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)




%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@



clean:
	rm -f $(EXEC) $(OBJECTS)


.PHONY: all clean