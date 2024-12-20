// This example shows how to implement a naive sum reduction 
// using round-trip RPC and a barrier
//
// This reduction algorithm is non-scalable and only shown here for 
// demonstration purposes. UPC++ includes scalable reduction operations 
// upcxx::reduce_{one,all}() that should be preferred in real codes.

// need to declare a global variable to use with RPC
int64_t hits = 0; 
int64_t reduce_to_rank0(int64_t my_hits)
{
    // wait for an rpc that updates rank 0's count
    upcxx::rpc(0, [](int64_t my_hits) { hits += my_hits; }, my_hits).wait();
    // wait until all ranks have updated the count
    upcxx::barrier();
    // hits is only set for rank 0 at this point, which is OK because only 
    // rank 0 will print out the result
    return hits;
}
