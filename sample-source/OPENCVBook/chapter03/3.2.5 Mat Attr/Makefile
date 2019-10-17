CPP = g++

CPPSRCS = mat_attr.cpp

TARGET = MatAttr

BUILDDIR = buildDir

CPPOBJS = $(addprefix $(BUILDDIR)/, $(CPPSRCS:.cpp=.o))

CPPFLAGS = $(shell pkg-config --cflags --libs opencv3)

all:clean createdir build

createdir:
	$(shell mkdir ${BUILDDIR})

build: $(CPPOBJS)
	$(CPP) -o $(BUILDDIR)/$(TARGET) $^ $(CPPFLAGS)

$(CPPOBJS):$(BUILDDIR)/%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -rf ${BUILDDIR}