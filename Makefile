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
OBJ=$(SRC:$(CLASS_DIR)/%.cpp=$(OBJ_DIR)/%.o)
LIBS=

#Cibles speciales
EXE=out
RUN=run
DEV=dev
CLEAN=clean
.PHONY: $(CLEAN) $(RUN)

#Cibles
$(EXE): $(OBJ)
	@$(ECHO) Edition des liens
	@$(LD) $^ -o $@ $(LIBS)

$(RUN): $(EXE)
	@$(ECHO) Execution de $^
	@./$(EXE)

$(DEV): CXXFLAGS+=$(DEVFLAGS)
$(DEV): $(EXE)

$(CLEAN):
	@$(RM) $(RMFLAGS) $(EXE) $(OBJ)

#Dependances complementaires

#Regles d'inference
$(OBJ_DIR)/%.o: %.cpp
	@$(ECHO) Compilation de $<
	@$(CXX) $(CXXFLAGS) -c $< -o $@
