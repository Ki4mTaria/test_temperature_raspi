#define _GNU_SOURCE 
#include <stdio.h>
#include <string.h>
#include <sched.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <thread/prototype.h>
#include <thread/define.h>
#include <common/define.h>
#include <load/prototype.h>

int thd_start_load(void) {
    pthread_t load_thd[DTHD_MAX_THREAD];
    int       cpu_id[DTHD_MAX_THREAD];
    int       loop = 0;
    int       ret  = 0;
    
    memset(&load_thd[0], 0x00, sizeof(pthread_t)*DTHD_MAX_THREAD);
    memset(&cpu_id[0],   0x00, sizeof(int)*DTHD_MAX_THREAD);
    
    for(loop=0;loop < get_nprocs();loop++) {
        if (loop > DTHD_MAX_THREAD-1) {
            break;
        }
        cpu_id[loop] = loop;
        /* start thread */
        pthread_create(&load_thd[loop], NULL, thd_worker, (void *)&cpu_id[loop]);
    }
    
    for(loop=0;loop < get_nprocs();loop++) {
        pthread_join(load_thd[loop], NULL);
    }
    
    return DCOM_OK;
}

void * thd_worker(void * args) {
    int *     cpu_num = NULL;
    cpu_set_t cpu_set;
    pid_t     pid;
    int       ret = 0;
    
    if (NULL == args) {
        printf("argument is null\n");
        return;
    }
    
    CPU_ZERO(&cpu_set);
    memset(&pid, 0x00, sizeof(pid_t));
    
    pid = syscall(SYS_gettid);
    
    cpu_num = (int *) args;
    CPU_SET(*cpu_num, &cpu_set);
    
    ret = sched_setaffinity(pid, sizeof(cpu_set_t), &cpu_set);
    if (ret != 0) {
        return;
    }
    
    tmp_fullwork();
     
    return;
}
/* end of file */
