# --- Variables de Compilación ---

CXX = g++
CXXFLAGS =
LDFLAGS = 

# --- Variables del Proyecto ---

# 1. El nombre de tu programa final
EXEC = mi_programa.out

# 2. La lista de TODOS tus archivos fuente (.cc)
SRCS = 

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


.PHONY: all clean

clean:
	rm -f $(OBJS) $(EXEC) *~

