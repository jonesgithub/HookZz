#ifndef thread_support_thread_stack_h
#define thread_support_thread_stack_h

#include "core.h"
#include "hookzz.h"
#include "std_kit/std_list.h"
#include "std_kit/std_map.h"

typedef struct _thread_stack_manager_t {
    int thread_id;
    list_t *call_stacks;
} thread_stack_manager_t;

typedef struct _call_stack_t {
    int deep;
    thread_stack_manager_t *thread_stack_manager;
    void *reg_sp;
    void *ret_addr;

    map_t *context_kv;
} call_stack_t;

#define thread_stack_cclass(member) cclass(thread_stack, member)

thread_stack_manager_t *thread_stack_cclass(shared_instance)();

#endif