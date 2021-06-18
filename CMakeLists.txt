cmake_minimum_required(VERSION 3.20)

project(ObserverModel)

add_executable(${PROJECT_NAME}
    main.cpp
    platform.cpp
    TestObserver.cpp
    TestProvider.cpp
)
