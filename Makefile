#Outils
CXX=g++
LD=g++
RM=rm
ECHO=echo

#Options
CXXFLAGS=-ansi -pedantic -Wall -std=c++11 -g
DEVFLAGS=-DMAP
RMFLAGS=-rf

#Fichiers
CLASS_DIR=src
OBJ_DIR=objects
SRC=$(wildcard $(CLASS_DIR)/*.cpp)
OBJ=$(SRC:.cpp=.o)
LIBS=

#Cibles speciales
EXE=out
RUN=run
BUILD=build
DEV=dev
CLEAN=clean
.PHONY: $(CLEAN) $(RUN) $(BUILD)

#Cibles
$(EXE): $(OBJ)
	@$(ECHO) [MAKE] Edition des liens
	@$(LD) $^ -o $@ $(LIBS)

$(RUN): $(EXE)
	@./$(EXE)

$(BUILD): $(CLEAN) $(EXE)
	@$(ECHO) [MAKE] Mode standard

$(DEV): CXXFLAGS+=$(DEVFLAGS)
$(DEV): $(CLEAN) $(EXE)
	@$(ECHO) [MAKE] Mode développement

$(CLEAN):
	@$(ECHO) [MAKE] Suppression des fichiers compilés et de $(EXE)
	@$(RM) $(RMFLAGS) $(EXE) $(OBJ)


#Dependances complementaires

#Regles d'inference
%.o: %.cpp
	@$(ECHO) [MAKE] Compilation de $<
	@$(CXX) $(CXXFLAGS) -c $< -o $@
