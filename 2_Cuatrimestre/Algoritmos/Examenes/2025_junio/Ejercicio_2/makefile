CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Nombre del ejecutable
TARGET = mi_programa.out

# Archivos fuente
SRCS = int_to_bin.cpp

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

