cmake_minimum_required(VERSION 3.0)
project(tkvenviroment)

# Defina o nome da biblioteca
set(LIB_NAME tkvenviroment)

# Localize todos os arquivos .cpp em todos os níveis de subdiretórios
file(GLOB_RECURSE LIB_SOURCE_FILES "*.cpp")

# Crie uma biblioteca de objetos (object library) com base nos arquivos .cpp encontrados
add_library(${LIB_NAME}_objects OBJECT ${LIB_SOURCE_FILES})

# Defina quaisquer opções de compilação específicas aqui, se necessário
# target_compile_options(${LIB_NAME}_objects PUBLIC -Wall -Wextra)

# Define as características do compilador aqui, se necessário
# target_compile_features(${LIB_NAME}_objects PUBLIC cxx_std_11)

# Defina outros diretórios de inclusão, se necessário
# target_include_directories(${LIB_NAME}_objects PUBLIC path/to/include)

# Defina o caminho de saída para os arquivos objetos (.o) preservando a estrutura de diretórios
set_target_properties(${LIB_NAME}_objects PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/obj"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/obj"
)

# Repita o processo para outros subdiretórios do projeto, se houver
# Por exemplo, para o subdiretório tkBase:
file(GLOB_RECURSE LIB_SOURCE_FILES_BASE "TKBase/TKString/*.cpp")
add_library(tkvenviroment_base_objects OBJECT ${LIB_SOURCE_FILES_BASE})
set_target_properties(tkvenviroment_base_objects PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/obj/TKBase/TKString"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/obj/TKBase/TKString"
)


# Se desejar adicionar testes, você pode usar o GTest ou outro framework de teste

# Por exemplo, com GTest:
# enable_testing()
# add_executable(test_${LIB_NAME} test/test_main.cpp)
# target_link_libraries(test_${LIB_NAME} ${LIB_NAME}_objects gtest gtest_main)
# add_test(NAME test_${LIB_NAME} COMMAND test_${LIB_NAME})
