CPP = g++

CPPSRCS = write_image02.cpp

TARGET = WriteImage

BUILDDIR = buildDir

CPPOBJS = $(addprefix ${BUILDDIR}/, ${CPPSRCS:.cpp=.o})

CPPFLAGS = `pkg-config --cflags --libs opencv3`

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(CPPOBJS)
	$(CPP) -o $(BUILDDIR)/$(TARGET) $^ $(CPPFLAGS)

$(CPPOBJS): $(BUILDDIR)/%.o : %.cpp
	$(CPP) -c $(CPPFLAGS) $< -o $@


clean:
	rm -rf ${BUILDDIR}


