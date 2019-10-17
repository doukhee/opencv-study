CPP = g++

CPPSRCS = vec.cpp

TARGET = vec

BUILDDIR = buildDir

CPPOBJS = $(addprefix $(BUILDDIR)/, $(CPPSRCS:.cpp=.o))

CPPFLAGS = $(shell pkg-config --cflags --libs opencv3) #-std=c++11

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(CPPOBJS)
	$(CPP) -o $(BUILDDIR)/$(TARGET) $^ $(CPPFLAGS)

$(CPPOBJS):$(BUILDDIR)/%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $<


clean:
	rm -rf ${BUILDDIR}


