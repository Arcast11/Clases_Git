CXX = g++
CXXFLAGS = 

# Nombre del ejecutable
TARGET = programa.out

# Archivos fuente
SRCS = extract_main.cpp

# Archivos objeto
OBJS = $(SRCS:.cpp=.o)

# Regla principal
all: $(TARGET)

# Enlazar objeto para crear ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilar .cpp a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJS) $(TARGET)

# Limpiar y recompilar
rebuild: clean all

# Ejecutar el programa
run: $(TARGET)
	./$(TARGET)

# Reglas phony
.PHONY: all clean rebuild run

