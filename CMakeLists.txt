cmake_minimum_required(VERSION 3.10)
project(RAM_Simulator)

# Estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Directorio de salida para ejecutables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Incluir directorios
include_directories(${PROJECT_SOURCE_DIR}/include)

# Archivos fuente
set(SOURCES
    src/main.cc
    src/utilidades.cc
    src/cinta_entrada.cc
)

# Crear ejecutable
add_executable(ram_sim ${SOURCES})

# Opciones de compilación
if(MSVC)
    target_compile_options(ram_sim PRIVATE /W4 /O2)
else()
    target_compile_options(ram_sim PRIVATE -Wall -Wextra -Wpedantic -O3)
endif()

# Flags adicionales para debugging
if(CMAKE_BUILD_TYPE MATCHES Debug)
    if(MSVC)
        target_compile_options(ram_sim PRIVATE /Zi)
    else()
        target_compile_options(ram_sim PRIVATE -g -O0)
    endif()
endif()