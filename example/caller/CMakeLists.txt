set(SRC_LIST calluserservice.cpp ../user.pb.cc)
add_executable(consumer ${SRC_LIST})
target_link_libraries(consumer mysimplerpc protobuf)