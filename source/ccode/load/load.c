/**
 * @file  load.c
 * @brief load to cpu
 */
/*** include ***/
#include <stdio.h>
#include <common/define.h>
#include <load/prototype.h>

/*** function ***/
/**
 * load to cpu
 * 
 * @return DCOM_OK : end monitoring
 * @return DCOM_NG : failed monitoring
 */
void tmp_fullwork(void) {
    int i = 0;
    
    printf("start load\n");
    while(1){
        i++;
        i--;
    }
    return;
}
/* end of file */
