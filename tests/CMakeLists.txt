function(tarfile_add_test test_name)
    add_executable(${test_name} ${test_name}.cpp)
    target_link_libraries(${test_name} Catch2 ${CMAKE_PROJECT_NAME})
    target_include_directories(${test_name} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/catch2)
    add_test(${test_name} ${CMAKE_CURRENT_BINARY_DIR}/${test_name})
endfunction()

tarfile_add_test(TestHeader)
#add_dependencies(TestHeader hello_tar_h)
