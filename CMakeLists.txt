cmake_minimum_required(VERSION 3.15)
project(newProject1 C)

set(CMAKE_C_STANDARD 99)

add_executable(newProject1 main.c BinFile.c BinFile.h ErrorsHandlings.c ErrorsHandlings.h MovesArray.c MovesArray.h MovesList.c MovesList.h PathCalculation.c PathCalculation.h PathFromFile.c PathFromFile.h tree.c tree.h Types.h List_Tests.c List_Tests.h Amitest.c Amitest.h Trash.c)