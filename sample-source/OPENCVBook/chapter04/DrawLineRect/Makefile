CPP = g++

CPPSRCS = draw_line_rect.cpp

TARGET = DrawLineRect

BUILDDIR = buildDir

CPPOBJS = $(addprefix ${BUILDDIR}/, $(CPPSRCS:.cpp=.o))

CPPFLAGS = `pkg-config --cflags --libs opencv3`

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build:$(CPPOBJS)
	$(CPP) -o $(BUILDDIR)/$(TARGET) $^ $(CPPFLAGS)

$(CPPOBJS):$(BUILDDIR)/%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -rf ${BUILDDIR}


