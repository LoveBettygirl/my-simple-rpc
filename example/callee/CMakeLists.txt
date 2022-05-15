add_executable(userservice userservice.cpp ../protobuf/user.pb.cc)
add_executable(friendservice friendservice.cpp ../protobuf/friend.pb.cc)
target_link_libraries(userservice mysimplerpc protobuf)
target_link_libraries(friendservice mysimplerpc protobuf)