/**
 * @file  temperture.c
 * @brief get cpu temperture in raspberry pi
 */
/*** include ***/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <common/define.h>
#include <temperture/prototype.h>
#include <temperture/define.h>

/*** function ***/
/**
 * monitoring cpu temperture
 * 
 * @return DCOM_OK : end monitoring
 * @return DCOM_NG : failed monitoring
 */
int tmp_start_monitor (void) {
    int loop     = 0;
    int cpu_temp = 0;
    
    for(loop=0; loop < DTMP_MONI_COUNT ;loop++) {
        /* get temperture */
        cpu_temp = tmp_get_temperture();
        if (DCOM_NG == cpu_temp) {
            continue;
        }
        
        /* display cpu temperture */
        printf("cpu temperture : %d 'C\n", cpu_temp/1000);
        
        sleep(DTMP_MONI_INTERVAL);
    }
    
    return DCOM_OK;
}


int tmp_get_temperture(void) {
    int ret_val     = 0;
    FILE *fp        = NULL;
    char *temp_path = DTMP_CPUTEMP_PATH;
    char line[16];
    
    memset(&line, 0x00, sizeof(line));
    
    fp = fopen( temp_path, "r" );
    if( fp == NULL ){
        return DCOM_NG;
    }
    
    while( fgets( &line[0], sizeof(line)-1, fp ) != NULL ) {
        ret_val = atoi(&line[0]);
        if (0 == ret_val) {
            return DCOM_NG;
        }
    }
    
    fclose( fp );
    return ret_val;
}
/* end of file */
