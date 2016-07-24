#include <stdio.h>
#include <common/define.h>
#include <temperture/prototype.h>

int main (int argc, char * argv[]) {
    int ret = 0;
    
    ret = tmp_start_monitor();
    if (DCOM_NG == ret) {
        printf("failed monitor\n");
    }
    
    return DCOM_OK;
}
