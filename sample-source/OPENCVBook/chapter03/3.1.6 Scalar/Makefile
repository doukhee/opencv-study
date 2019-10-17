CPP = g++

CPPSRCS = scalar.cpp

TARGET = scalar

BUILDDIR = buildDir

CPPFLAGS = $(shell pkg-config --cflags --libs opencv3)

CPPOBJS = $(addprefix ${BUILDDIR}/, $(CPPSRCS:.cpp=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build:$(CPPOBJS)
	$(CPP) -o $(BUILDDIR)/$(TARGET) $^ $(CPPFLAGS)

$(CPPOBJS):$(BUILDDIR)/%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -rf ${BUILDDIR}
