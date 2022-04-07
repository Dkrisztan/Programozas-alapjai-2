# A filmpédia nagyházihoz készített makefile

PROG = main   						# a program neve
PROG_O = main.o string.o  # program object fájljai 
PROG_H = string.h			    # program header fájljai

MTRACE_O = memtrace.o 		# memtrace object fájl
MTRACE_H = memtrace.h 		# memtrace és memcheck header fájlja

# A C++ fordító neve
CXX = g++
# Kapcsolók: legyen bőbeszédű és pedáns
CXXFLAGS = -pedantic -Wall -Werror
# és legyen debug info is
CXXFLAGS += -ggdb -DMEMTRACE
# debug a linkelésnél
LDFLAGS = -ggdb

# Összes object, összes header
OBJS = $(PROG_O) $(MTRACE_O)
HEADS = $(PROG_H) $(MTRACE_H)

# Alapértelmezett cél: program
.PHONY: all
all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@
	@echo ------------------------
	@echo Here begins the program:
	./$(PROG)

# Feltételezzük, hogy az összes obj függ az összes headertől
$(OBJS): $(HEADS)

# Takarítás
.PHONY: clean
clean:
	del $(OBJS) $(PROG)
	del *.exe