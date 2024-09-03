

file(GLOB ENTRIES "${PROJECT_SOURCE_DIR}/leetcode/problem/*")

foreach(ENTRY ${ENTRIES})
	if(IS_DIRECTORY ${ENTRY})
		get_filename_component(item ${ENTRY} NAME)
		project(LeetcodeContest_${item})
		add_executable(LeetcodeContest_${item} problem/${item}/main.cpp)
		target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/../thirdparty/Leetcode-Solutions/C++" ${PROJECT_SOURCE_DIR})
	endif()
endforeach()

