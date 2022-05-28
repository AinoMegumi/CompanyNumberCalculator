cmake_minimum_required(VERSION 3.12)
enable_language(CXX)
set(CMAKE_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
project(calculator)
project(test)
set(calculator
    main.cpp
    Calculator.hpp
)
set(test
    test.cpp
    Calculator.hpp
)

if(MSVC)
  # Force to always compile with W4
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  # Update if necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-long-long -pedantic")
endif()

add_executable(CompanyNumberCalculator ${calculator})
add_executable(CalculatorTest ${test})
target_include_directories(CalculatorTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/iutest/include)

if(WIN32)
  target_link_libraries(CalculatorTest Ws2_32)
endif()