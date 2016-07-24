/**
 * @file  load_main.c
 * @brief load function
 */

/*** include ***/
#include <stdio.h>
#include <common/define.h>
#include <load/prototype.h>

/*** function ***/
/**
 * load main function
 * 
 * @return DCOM_OK : success
 * @return DCOM_NG : failed
 */
int main (int argc, char * argv[]) {
    int ret = 0;
    
    printf("start load test\n");
    ret = thd_start_load();
    if (DCOM_NG == ret) {
        printf("failed load\n");
        return DCOM_NG;
    }
    
    return DCOM_OK;
}
/* end of file */
