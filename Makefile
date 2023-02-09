SRCDIR := src
HDRDIR := include
OBJDIR := build

STRUCTURE := $(shell find $(SRCDIR) -type d)
OBJSTRUCTURE := $(subst $(SRCDIR),$(OBJDIR),$(STRUCTURE))

CODEFILES := $(addsuffix /*,$(STRUCTURE))
CODEFILES := $(wildcard $(CODEFILES))

SRCFILES := $(filter %.cc,$(CODEFILES))
OBJFILES := $(subst $(SRCDIR),$(OBJDIR),$(SRCFILES:%.cc=%.o))

CXX := g++
CXXFLAGS := -Wall -O3 -I$(HDRDIR) -std=c++11 -DGLFW_INCLUDE_NONE -DSTB_IMAGE_IMPLEMENTATION
LDFLAGS := -lglfw -lGL -lm -lX11 -lpthread -lXi -lXrandr -ldl
GLFWPKGC := `pkg-config --cflags glfw3`
GLFWPKGLIB := `pkg-config --static --libs glfw3`


.PHONY: clean $(OBJDIR) $(OBJSTRUCTURE)

all: main

main: $(OBJDIR) $(OBJFILES) $(OBJDIR)/gl.o
	$(CXX) $(GLFWPKGC) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJFILES) $(OBJDIR)/gl.o $(GLFWPKGLIB)

$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJSTRUCTURE)

$(OBJDIR)/gl.o: $(SRCDIR)/gl.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJDIR)