/* *****************************************************************************
 * File:   lora.h
 * Author: XX
 * 
 * Description: ...
 * 
 **************************************************************************** */
#pragma once

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */



#include <sdkconfig.h>
#if CONFIG_USE_LORA
#include <stdint.h>

/*
 * Register definitions
 */
#define LORA_REG_FIFO                       0x00
#define LORA_REG_OP_MODE                    0x01
#define LORA_REG_FRF_MSB                    0x06
#define LORA_REG_FRF_MID                    0x07
#define LORA_REG_FRF_LSB                    0x08
#define LORA_REG_PA_CONFIG                  0x09
#define LORA_REG_LNA                        0x0c
#define LORA_REG_FIFO_ADDR_PTR              0x0d
#define LORA_REG_FIFO_TX_BASE_ADDR          0x0e
#define LORA_REG_FIFO_RX_BASE_ADDR          0x0f
#define LORA_REG_FIFO_RX_CURRENT_ADDR       0x10
#define LORA_REG_IRQ_FLAGS                  0x12
#define LORA_REG_RX_NB_BYTES                0x13
#define LORA_REG_PKT_SNR_VALUE              0x19
#define LORA_REG_PKT_RSSI_VALUE             0x1a
#define LORA_REG_MODEM_CONFIG_1             0x1d
#define LORA_REG_MODEM_CONFIG_2             0x1e
#define LORA_REG_PREAMBLE_MSB               0x20
#define LORA_REG_PREAMBLE_LSB               0x21
#define LORA_REG_PAYLOAD_LENGTH             0x22
#define LORA_REG_MODEM_CONFIG_3             0x26
#define LORA_REG_RSSI_WIDEBAND              0x2c
#define LORA_REG_DETECTION_OPTIMIZE         0x31
#define LORA_REG_DETECTION_THRESHOLD        0x37
#define LORA_REG_SYNC_WORD                  0x39
#define LORA_REG_DIO_MAPPING_1              0x40
#define LORA_REG_DIO_MAPPING_2              0x41
#define LORA_REG_VERSION                    0x42

/*
 * Transceiver modes
 */
#define LORA_MODE_LONG_RANGE_MODE           0x80
#define LORA_MODE_SLEEP                     0x00
#define LORA_MODE_STDBY                     0x01
#define LORA_MODE_TX                        0x03
#define LORA_MODE_RX_CONTINUOUS             0x05
#define LORA_MODE_RX_SINGLE                 0x06

void lora_reset(void);
void lora_explicit_header_mode(void);
void lora_implicit_header_mode(int size);
void lora_idle(void);
void lora_sleep(void); 
void lora_receive(void);
void lora_set_tx_power(int level);
void lora_set_frequency(long frequency);
void lora_set_spreading_factor(int sf);
void lora_set_bandwidth(long sbw);
void lora_set_coding_rate(int denominator);
void lora_set_preamble_length(long length);
void lora_set_sync_word(int sw);
void lora_enable_crc(void);
void lora_disable_crc(void);
int lora_init(void);
void lora_send_packet(uint8_t *buf, int size);
void lora_send_packet_non_blocking(uint8_t *buf, int size);
int lora_receive_packet(uint8_t *buf, int size);
int lora_received(void);
int lora_packet_rssi(void);
float lora_packet_snr(void);
void lora_close(void);
int lora_initialized(void);
void lora_dump_registers(void);
void lora_write_reg(int reg, int val);
int lora_read_reg(int reg);

#endif  /* #if CONFIG_USE_LORA */


#ifdef __cplusplus
}
#endif /* __cplusplus */
