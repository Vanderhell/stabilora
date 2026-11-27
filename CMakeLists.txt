cmake_minimum_required(VERSION 3.16)
project(Stabilora VERSION 0.2.0 LANGUAGES C)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(STABILORA_BUILD_TESTS "Build Stabilora host tests" OFF)
option(STABILORA_STRICT_WARNINGS "Treat supported compiler warnings as errors" ON)

function(stabilora_apply_warnings target)
    if(MSVC)
        target_compile_options(${target} PRIVATE /W4)
        if(STABILORA_STRICT_WARNINGS)
            target_compile_options(${target} PRIVATE /WX)
        endif()
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
        if(STABILORA_STRICT_WARNINGS)
            target_compile_options(${target} PRIVATE -Werror)
        endif()
    endif()
endfunction()

add_library(stabilora STATIC
    src/stabilora_checked_shl_u32.c
    src/stabilora_control_output_clamp_i32.c
    src/stabilora_debounce_counter_bool.c
    src/stabilora_debounce_dual_threshold_i32.c
    src/stabilora_hist_clip_limit_u32.c
    src/stabilora_timeout_backoff_cap_u32.c
)
add_library(Stabilora::Stabilora ALIAS stabilora)
target_compile_features(stabilora PUBLIC c_std_99)
set_target_properties(stabilora PROPERTIES
    C_STANDARD 99 C_STANDARD_REQUIRED YES C_EXTENSIONS NO
    EXPORT_NAME Stabilora
)
target_include_directories(stabilora PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
stabilora_apply_warnings(stabilora)

if(STABILORA_BUILD_TESTS)
    enable_testing()
    enable_language(CXX)
    set(STABILORA_TESTS
        control_output_clamp_i32
        debounce_counter_bool
        debounce_dual_threshold_i32
        hist_clip_limit_u32
        timeout_backoff_cap_u32
        checked_shl_u32
    )
    foreach(test_name IN LISTS STABILORA_TESTS)
        add_executable(stabilora_test_${test_name} tests/test_${test_name}.c)
        target_link_libraries(stabilora_test_${test_name} PRIVATE Stabilora::Stabilora)
        target_compile_features(stabilora_test_${test_name} PRIVATE c_std_99)
        set_target_properties(stabilora_test_${test_name} PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED YES C_EXTENSIONS NO)
        stabilora_apply_warnings(stabilora_test_${test_name})
        add_test(NAME stabilora.${test_name} COMMAND stabilora_test_${test_name})
    endforeach()
    set(STABILORA_PUBLIC_HEADERS
        control_output_clamp_i32.h debounce_counter_bool.h debounce_dual_threshold_i32.h
        hist_clip_limit_u32.h checked_shl_u32.h timeout_backoff_cap_u32.h
    )
    foreach(header IN LISTS STABILORA_PUBLIC_HEADERS)
        string(REPLACE ".h" "" header_test_name "${header}")
        set(header_smoke_source "${CMAKE_CURRENT_BINARY_DIR}/header_${header_test_name}.c")
        file(WRITE "${header_smoke_source}"
            "#include <stabilora/control/${header}>\nint main(void) { return 0; }\n")
        add_executable(stabilora_header_${header_test_name} "${header_smoke_source}")
        target_include_directories(stabilora_header_${header_test_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
        target_compile_features(stabilora_header_${header_test_name} PRIVATE c_std_99)
        set_target_properties(stabilora_header_${header_test_name} PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED YES C_EXTENSIONS NO)
        stabilora_apply_warnings(stabilora_header_${header_test_name})
        add_test(NAME stabilora.header.${header_test_name} COMMAND stabilora_header_${header_test_name})
    endforeach()
    add_executable(stabilora_headers_cpp tests/headers_cpp.cpp)
    target_link_libraries(stabilora_headers_cpp PRIVATE Stabilora::Stabilora)
    stabilora_apply_warnings(stabilora_headers_cpp)
    add_test(NAME stabilora.headers_cpp COMMAND stabilora_headers_cpp)
endif()

install(TARGETS stabilora EXPORT StabiloraTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT StabiloraTargets FILE StabiloraTargets.cmake NAMESPACE Stabilora::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Stabilora)
configure_package_config_file(cmake/StabiloraConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/StabiloraConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Stabilora)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/StabiloraConfigVersion.cmake
    VERSION ${PROJECT_VERSION} COMPATIBILITY SameMinorVersion)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/StabiloraConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/StabiloraConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Stabilora)
