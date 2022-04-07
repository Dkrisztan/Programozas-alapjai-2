#? Demo Makefile a nagyobb program eloallitasahoz

PROG = nagyobb
SRCS = nagyobb_main.cpp fuggvenyeim.cpp
HDRS = fuggvenyeim.h
OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -g

$(PROG): $(OBJS) 
	$(CXX) -o $(PROG) $(OBJS)

.PHONY:
clean:
	-del /Q /F $(OBJS) $(PROG).exe #! Windows-on -del /Q /F illetve .exe hozzáadása #! Unix-on rm -rf

# Egyszerusites: Minden .o fugg minden header-tol
$(OBJS): $(HDRS)
