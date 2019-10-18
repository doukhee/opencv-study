CPP = g++

CPPSRCS = set_cameraAttr.cpp

BUILDDIR = buildDir

TARGET = SetCameraAttr

CPPOBJS = $(addprefix $(BUILDDIR)/, $(CPPSRCS:.cpp=.o))

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
