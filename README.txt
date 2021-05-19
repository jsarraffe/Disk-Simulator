Jacques Sarraffe

Stimulates Hard disk drive actions using priority queues in C++


An example of compiling and running each queue:


1. Compile and run FCFS queue

$ g++ -std=c++17 CommonFiles/Request.cpp FCFS_Queue/FCFSQueue.cpp FCFS_Queue/FCFSQueueNode.cpp FCFS_Queue/main.cpp -o fcfs.x
$ ./fcfs.x inputRequest.txt

------------------------------------------------------------------------------

2. Compile and run ST queue

$ g++ -std=c++17 CommonFiles/Request.cpp ST_Queue/STQueue.cpp ST_Queue/STQueueNode.cpp ST_Queue/main.cpp -o st.x
$ ./st.x inputRequest.txt

------------------------------------------------------------------------------

3. Compile and run PickUp Queue

$ g++ -std=c++17 CommonFiles/Request.cpp PickUp_Queue/PickUpQueue.cpp PickUp_Queue/PickUpQueueNode.cpp PickUp_Queue/main.cpp -o pu.x
$ ./pu.x inputRequest.txt

-------------------------------------------------------------------------------

4. Compile and run LookUp queue

$ g++ -std=c++17 CommonFiles/Request.cpp Look_Queue/LookQueue.cpp Look_Queue/LookQueueNode.cpp Look_Queue/main.cpp -o lu.x
$ ./lu.x inputRequest.txt

--------------------------------------------------------------------------------

5. Compile and run CLookUp queue

$ g++ -std=c++17 CommonFiles/Request.cpp CLook_Queue/CLookQueue.cpp CLook_Queue/CLookQueueNode.cpp CLook_Queue/main.cpp -o cl.x
$ ./clu.x inputRequest.txt
