# Sample static library
add_library(samplelib STATIC)

set_target_properties(samplelib PROPERTIES OUTPUT_NAME "sample")

target_sources(
    samplelib
    PRIVATE
        "CLI.h"
        "library.cpp"
        "library.h"
        "figures/Triangle.h"
        "figures/Triangle.cpp" 
        "doubleEQ.cpp"
        "figures/Rectangle.h"
        "figures/Rectangle.cpp"
 "figures/Circle.h" "figures/Circle.cpp" "figures/FigureFactory.h" "figures/FigureFactory.cpp" "figures/StreamFigureFactory.h" "figures/StreamFigureFactory.cpp" "figures/RandomFigureFactory.h" "figures/RandomFigureFactory.cpp" "figures/FigureFactoryFactory.h" "figures/FigureFactoryFactory.cpp" "CLI.cpp")


# Executable target for the application
add_executable(application)

set_target_properties(application PROPERTIES OUTPUT_NAME "calc")

target_link_libraries(
    application
    PRIVATE
        samplelib
)

target_sources(
    application
    PRIVATE
        "CLI.h"
        "application.cpp"
        "figures/Triangle.h"    
        "doubleEQ.cpp"
        "figures/Rectangle.h"
     "figures/Circle.h" "figures/Circle.cpp" "figures/FigureFactory.h" "figures/FigureFactory.cpp" "figures/StreamFigureFactory.h" "figures/StreamFigureFactory.cpp" "figures/RandomFigureFactory.h" "figures/RandomFigureFactory.cpp" "figures/FigureFactoryFactory.h" "figures/FigureFactoryFactory.cpp"  "CLI.cpp")