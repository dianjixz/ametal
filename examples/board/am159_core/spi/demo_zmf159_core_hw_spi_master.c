/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/
/**
 * \file
 * \brief SPI �������̣�ͨ�� HW ��ӿ�ʵ��
 *
 * - �������裺
 *   1. �� SPI �� MOSI ���ź� MISO ��������������ģ��ӻ��豸���ػ����ԡ�
 *
 * - ʵ������
 *   1. ����ͨ�� MISO �������ݣ����������ݴ� MOSI ���أ�
 *   2. �ȽϷ����Ͷ��ص����ݣ������ͬ LED0 ����,������ 200ms ʱ������˸��
 *
 * \note
 *    ����۲촮�ڴ�ӡ�ĵ�����Ϣ����Ҫ�� PIOA_10 �������� PC ���ڵ� TXD��
 *    PIOA_9 �������� PC ���ڵ� RXD��
 *
 * \par Դ����
 * \snippet demo_zmf159_hw_spi_master.c src_zmf159_hw_spi_master
 *
 * \internal
 * \par History
 * - 1.00 17-04-27  ari, first implementation.
 * \endinternal
 */

/**
 * \addtogroup demo_if_zmf159_hw_spi_master
 * \copydoc demo_zmf159_hw_spi_master.c
 */

/** [src_zmf159_hw_spi_master] */
#include <demo_zmf159_core_entries.h>
#include "ametal.h"
#include "am_zmf159.h"
#include "am_zmf159_clk.h"
#include "am_gpio.h"
#include "am_vdebug.h"
#include "demo_zlg_entries.h"
#include "am_zmf159_inst_init.h"

/**
 * \brief �������
 */
void demo_zmf159_core_hw_spi_master_entry (void)
{
    am_kprintf("demo zmf159_core hw spi master!\r\n");

    /* ����ʱ�� */
    am_clk_enable(CLK_SPI1);

    /* �������� */
    am_gpio_pin_cfg(PIOB_3, PIOB_3_SPI1_SCK | PIOB_3_AF_PP);

    am_gpio_pin_cfg(PIOB_4, PIOB_4_SPI1_MISO | PIOB_4_INPUT_PU);
    am_gpio_pin_cfg(PIOB_5, PIOB_5_SPI1_MOSI | PIOB_5_AF_PP);
    am_gpio_pin_cfg(PIOA_15, PIOA_15_SPI1_NSS | PIOA_15_AF_PP);

    demo_zlg_hw_spi_master_entry(ZMF159_SPI1,
                                 PIOA_15,
                                 am_clk_rate_get(CLK_SPI1));
}
/** [src_zmf159_hw_spi_master] */

/* end of file */