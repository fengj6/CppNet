#ifndef HEADER_INCLUDE_CPPNET
#define HEADER_INCLUDE_CPPNET

#include "CppDefine.h"
#include "Socket.h"

namespace cppnet {

    //common
    // init cppnet library.
    // thread_num:       the number of running threads.
    // log:              print log out?
    // per_handl_thread: every thread with a epoll handle. only useful in linux.
    void Init(int32_t thread_num, bool log = false, bool per_handl_thread = true);
    void Dealloc();

    // thread join
    void Join();

    // must set callback before listen
    void SetReadCallback(const read_call_back& func);
    void SetWriteCallback(const write_call_back& func);
    void SetDisconnectionCallback(const connection_call_back& func);

    //timer
    uint64_t SetTimer(int32_t interval, const timer_call_back& func, void* param = nullptr, bool always = false);
    void RemoveTimer(uint64_t timer_id);

    //server
    void SetAcceptCallback(const connection_call_back& func);
    bool ListenAndAccept(int16_t port, std::string ip, uint32_t listen_num);

    //client
    void SetConnectionCallback(const connection_call_back& func);
}

#endif