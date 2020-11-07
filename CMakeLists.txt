cmake_minimum_required(VERSION 3.12)
project(DiskSim.x)

set(CMAKE_CXX_STANDARD 17)

add_executable(fcfs.x FCFS_Queue/main.cpp FCFS_Queue/FCFSQueue.cpp FCFS_Queue/FCFSQueueNode.cpp CommonFiles/Request.cpp )
add_executable(st.x ST_Queue/main.cpp ST_Queue/STQueue.cpp ST_Queue/STQueueNode.cpp CommonFiles/Request.cpp )
add_executable(pu.x PickUp_Queue/main.cpp PickUp_Queue/PickUpQueue.cpp PickUp_Queue/PickUpQueueNode.cpp CommonFiles/Request.cpp )
add_executable(look.x Look_Queue/main.cpp Look_Queue/LookQueue.cpp Look_Queue/LookQueueNode.cpp CommonFiles/Request.cpp )
add_executable(clook.x CLook_Queue/main.cpp CLook_Queue/CLookQueue.cpp  CLook_Queue/CLookQueueNode.cpp CommonFiles/Request.cpp)