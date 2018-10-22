TARGET := PwdClip
CXX := g++
CXXFLAGS := -Wall -O3 -c
LD := g++ -o

SRCDIR = src
BINDIR = bin

$(TARGET): obj
	$(LD) $(BINDIR)/$(TARGET) *.o
	rm -f *.o

obj: $(SRCDIR)/*.cpp
	$(CXX) $(CXXFLAGS) $^

