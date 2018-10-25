TARGET := PwdClip
CXX := g++
CXXFLAGS := -Wall -O3 -c -std=c++11
LD := g++ -o

SRCDIR = src
BINDIR = bin

SRC := $(wildcard $(SRCDIR)/*.cpp)
OBJ := $(patsubst %.cpp,%.o,$(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	$(LD) $(BINDIR)/$(TARGET) $(SRCDIR)/*.o

%.o: %.c
	$(CXX) $(CXXFLAGS) $(SRCDIR)/$<

.PHONY: clean
clean:
	rm -f *.o
	rm -f $(SRCDIR)/*.o