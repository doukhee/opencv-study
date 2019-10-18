CPP = g++

CPPSRCS = saturate_cast.cpp

BUILDDIR = buildDir

TARGET = StaturateCast

CPPOBJS = $(addprefix $(BUILDDIR)/, $(CPPSRCS:.cpp=.o))

CPPFLAGS = $(shell pkg-config --cflags --libs opencv3)

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build:$(CPPOBJS)
	$(CPP) -o $(BUILDDIR)/$(TARGET) $^ $(CPPFLAGS)

$(CPPOBJS): $(BUILDDIR)/%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -rf ${BUILDDIR}


