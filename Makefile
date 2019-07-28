AutomatedMakefile = am
CC = g++

FILES = Path.o PathLength.o Romberg.o ModifiedSecant.o PathLengthDriver.o

PROJECT_PATH = $(PROJECT_PATH)

INC_DIRS = -I$(PROJECT_PATH)/include/
LIB_DIRS = -L$(PROJECT_PATH)/lib/
LIBS = -lCSC2110

COMPILE = $(CC) $(INC_DIRS) -c
LINK = $(CC) $(LIB_DIRS) -o

all: PathLength

PathLength: 		$(FILES)
			$(LINK) PathLength.exe $(FILES) $(LIBS)

Romberg.o:		Romberg.h Romberg.cpp
			$(COMPILE) Romberg.cpp

ModifiedSecant.o:	ModifiedSecant.h ModifiedSecant.cpp
			$(COMPILE) ModifiedSecant.cpp

Path.o:			Path.h Path.cpp
			$(COMPILE) Path.cpp

PathLength.o:		PathLength.h PathLength.cpp
			$(COMPILE) PathLength.cpp

PathLengthDriver.o:	PathLengthDriver.cpp
			$(COMPILE) PathLengthDriver.cpp








