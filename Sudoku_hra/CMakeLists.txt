# CMakeList.txt: Projekt CMake pro Sudoku_hra, sem přidejte logiku zdrojového
# kódu a definic specifickou pro projekt.
#

# Přidejte zdrojový kód ke spustitelnému souboru tohoto projektu.
add_executable (Sudoku_hra "Sudoku_hra.cpp" "Sudoku_hra.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Sudoku_hra PROPERTY CXX_STANDARD 20)
endif()

# TODO: V případě potřeby přidejte testy a cíle instalace.
