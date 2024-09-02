

set(leetcode-problem-list neighboring-bitwise-xor)

foreach(item IN LISTS leetcode-problem-list)
	project(LeetcodeContest_${item})
	add_executable(LeetcodeContest_${item} problem/${item}/main.cpp)
	target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/../thirdparty/Leetcode-Solutions/C++" ${PROJECT_SOURCE_DIR})
endforeach()