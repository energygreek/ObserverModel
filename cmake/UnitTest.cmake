# 函数名： run_tests
# 功能：  生成自动跑单元测试的cmake目标
# 参数1： test_target_name 是cmake目标
# 参数2： executable 单元测试可执行文件
# 说明： 单元测试在可执行文件有变动或者之前有失败时执行， 状态判断依赖标志'_test_state'
# 即 ./build/run_tests/${executable}.passed 文件
function(run_tests test_target_name executable)
set(_test_state "${PROJECT_BINARY_DIR}/run_tests/${executable}.passed")

# 创建标志文件，此command依赖executable，所以会先编译executable
# 单元测试通过后创建标志文件
add_custom_command(
    COMMENT "Unit Test Execution: ${executable}" 
    OUTPUT ${_test_state}
    COMMAND $<TARGET_FILE:${executable}>
    COMMAND ${CMAKE_COMMAND} -E make_directory "${PROJECT_BINARY_DIR}/run_tests"
    COMMAND ${CMAKE_COMMAND} -E touch ${_test_state}
    DEPENDS ${executable}
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
    )

# 添加 cmake target, 依赖于状态标志_test_state， 故如果存在_test_state则不用执行
add_custom_target(
    ${test_target_name}
    ALL
    DEPENDS ${_test_state}
    )
endfunction()