#ifndef __MDES_H_
#define __MDES_H_

#include <linux/module.h>
/*宏定义*/
#define M8_1      0x01                
#define M8_6      0x20                
#define M8_5_2    0x3c                

/*数据类型定义*/
typedef unsigned char  uint8_t;

typedef struct subkey{
    uint8_t byte[6];
}Subkey;

void des_generate_subkey(uint8_t* main_key, Subkey* subkey_buff_address);
void des_unit_process(uint8_t* raw,uint8_t* processed,Subkey* subkey,int mode);
void print_byte(uint8_t* buff,int len,char* notice);
#endif