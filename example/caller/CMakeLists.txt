add_executable(calluserservice calluserservice.cpp ../protobuf/user.pb.cc)
add_executable(callfriendservice callfriendservice.cpp ../protobuf/friend.pb.cc)
target_link_libraries(calluserservice mysimplerpc protobuf)
target_link_libraries(callfriendservice mysimplerpc protobuf)