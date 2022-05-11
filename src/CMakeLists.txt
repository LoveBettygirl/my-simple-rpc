aux_source_directory(. SRC_LIST)
add_library(mysimplerpc ${SRC_LIST})
target_link_libraries(mysimplerpc muduo_net muduo_base pthread)