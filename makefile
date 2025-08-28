CXX       ?= clang++
CXXFLAGS  ?= -Wall -flto -O3
LDFLAGS   ?= -ltermbox

CXX_SRC   := $(wildcard src/*.cc)
OBJ       := $(CXX_SRC:.cc=.o)
TARGET    := spedit

DESTDIR   ?=
PREFIX    ?= /usr/bin

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

install: $(TARGET)
	install -Dm755 $(TARGET) $(DESTDIR)$(PREFIX)/$(TARGET)

clean:
	rm -rf $(TARGET) $(OBJ)
