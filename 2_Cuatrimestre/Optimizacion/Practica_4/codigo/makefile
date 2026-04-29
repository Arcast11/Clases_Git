# --- Variables de Compilación ---

CXX = g++
CXXFLAGS = 
LDFLAGS = 

# --- Variables del Proyecto ---

# 1. El nombre de tu programa final
EXEC = mi_programa_build2.out

# 2. La lista de TODOS tus archivos fuente (.cc)
SRCS = main.cpp grafo_build2.cpp

# 3. Lista automática de archivos objeto (.o)
OBJS = $(SRCS:.cc=.o)

# --- Reglas de Make ---

# Regla 'all': Es la regla por defecto (la primera)
all: $(EXEC)

# Regla de ENLAZADO (Linking):
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Dice cómo crear CUALQUIER archivo .o a partir de un .cc
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para compilar y ejecutar
run: $(EXEC)
	./$(EXEC)

# Regla para compilar con flags de depuración
debug: CXXFLAGS += -g -DDEBUG
debug: $(EXEC)

.PHONY: all clean run debug

clean:
	rm -f $(EXEC)