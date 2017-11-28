
#ifndef __F10X_FLASH_IF_H__
#define  __F10X_FLASH_IF_H__

#include "GlobalDef.h"

// �洢��FLASH ��������ص�����
typedef struct
{
    uint8_t  fileName[64];     // �Ƿ�����
	uint32_t fileVersion;      // �汾��
	uint32_t fileLen;           // �ļ���С, unit: Byte
	uint32_t fileSum;           // �ļ�У���
	T_RTC_TIME time;           // ��дʱ��
	uint32_t upgrade;           // �Ƿ�����
	uint32_t upgrade_inverse;  // �Ƿ������ķ���
	uint32_t checkSum;          // ���������ݵĺ�У��
	uint32_t checkSumInverse;  // У��͵ķ���
}T_APP_FLASH_ATTR;

// �洢��SPI FLASH ��ϵͳ��������
typedef struct
{
    uint8_t   is_hcho_cal;       // ��ȩ�Ƿ���У��
    uint8_t   hold;               // �Ƿ񱣳���ʾ
    uint8_t   reserved[2];
	uint16_t  cali_ppb;
	uint16_t  cali_mass;
	uint32_t  checkSum;          // ���������ݵ�У���
	uint32_t checkSumInverse;  // У��͵ķ���
}T_SYS_ENV;

#define  FLASH_SUCCESS     0
#define  FLASH_FAILED      1

uint8_t F10X_FLASH_WriteAppAttr(uint32_t flashAddress, T_APP_FLASH_ATTR * newAttr);
uint8_t F10X_FLASH_ReadAppAttr(uint32_t flashAddress, T_APP_FLASH_ATTR * outAttr);

uint8_t F10X_FLASH_WriteSysEnv(T_SYS_ENV * pEnv);
uint8_t F10X_FLASH_ReadSysEnv(T_SYS_ENV * outEnv);


#define Sys_ReadAppAttr(pAttr)   F10X_FLASH_ReadAppAttr(FLASH_SYS_ENV_START_SECTOR << 12,  pAttr)
#define Sys_WriteAppAttr(pAttr)  F10X_FLASH_WriteAppAttr(FLASH_SYS_ENV_START_SECTOR << 12, pAttr)

#endif
