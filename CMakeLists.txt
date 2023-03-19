cmake_minimum_required(VERSION 3.13)
project(TestWriting)
set(CMAKE_CXX_STANDARD 11)


# Add sources files.
set(SOURCE_FILES
    main.cpp
    Game.cpp
    GameElement/Menu.cpp
    GameElement/Field.cpp
)

# Add headers files.
set(HEADER_FILES
    Game.h
    GameElement/Menu.h
    GameElement/Field.h
)

# Add subdirectory.
set(DIRS
    GameElements
)

# set (CMAKE_CXX_STANDARD_LIBRARIES "-lncurses")

# Add executable target.
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${DIRS})