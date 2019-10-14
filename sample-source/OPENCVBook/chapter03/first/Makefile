
CPP = g++

SRCS = first.cpp

TARGET = first

BUILDDIR = buildDir

CPPOBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.cpp=.o))

CPPFLAGS = $(shell pkg-config --cflags --libs opencv4) -std=c++11

#LDFLAGS = -lopencv_highgui

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})


build:$(CPPOBJS)
	$(CPP) -o $(BUILDDIR)/$(TARGET) $^ $(CPPFLAGS)


$(CPPOBJS): $(BUILDDIR)/%.o:%.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $<


clean:
	rm -rf $(BUILDDIR)
