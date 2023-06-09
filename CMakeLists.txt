cmake_minimum_required(VERSION 3.13)
project(TestWriting)
set(CMAKE_CXX_STANDARD 11)


# Add sources files.
set(SOURCE_FILES
    main.cpp
    Game.cpp
    GameElement/Menu.cpp
    GameElement/Field.cpp
    GameElement/PPBall.cpp
    GameElement/Player/Player.cpp
    GameElement/Player/AI/PlayerAI.cpp
    GameElement/Timer.cpp
)

# Add headers files.
set(HEADER_FILES
    Game.h
    Utils.h
    GameElement/Menu.h
    GameElement/Field.h
    GameElement/PPBall.h
    GameElement/Player/Player.h
    GameElement/Player/AI/PlayerAI.h
    GameElement/Timer.h
)

# Add subdirectory.
set(DIRS
    GameElements
    GameElement/Player/
    GameElement/Player/AI/
)

# set (CMAKE_CXX_STANDARD_LIBRARIES "-lncurses")

# Add executable target.
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${DIRS})