
#find_program(BIN2CPP_CMD bin2cpp)
#if (BIN2CPP_CMD)
    #message("Found ${BIN2CPP_CMD}")
    #add_custom_target(hello_tar_h
        #COMMAND ${BIN2CPP_CMD} -i ${CMAKE_CURRENT_SOURCE_DIR}/hello.tar -t char -a hello_tar 
            #-o ${CMAKE_CURRENT_BINARY_DIR}/hello.tar.h -l 512
        #)
#else()
    #message(FATAL "Command bin2cpp is required for the tests")
#endif()

function(tarfile_add_test test_name)
    add_executable(${test_name} ${test_name}.cpp)
    target_link_libraries(${test_name} Catch2 ${CMAKE_PROJECT_NAME})
    target_include_directories(${test_name} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_SOURCE_DIR}/3rdparty/catch2)
    add_test(${test_name} ${CMAKE_CURRENT_BINARY_DIR}/${test_name})
endfunction()

tarfile_add_test(TestHeader)
#add_dependencies(TestHeader hello_tar_h)
