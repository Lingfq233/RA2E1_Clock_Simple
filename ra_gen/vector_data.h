/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
#ifdef __cplusplus
        extern "C" {
        #endif
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (12)
#endif
/* ISR prototypes */
void gpt_counter_overflow_isr(void);
void rtc_alarm_periodic_isr(void);
void rtc_carry_isr(void);
void sci_uart_rxi_isr(void);
void sci_uart_txi_isr(void);
void sci_uart_tei_isr(void);
void sci_uart_eri_isr(void);
void ctsu_write_isr(void);
void fcu_frdyi_isr(void);
void ctsu_end_isr(void);
void ctsu_read_isr(void);

/* Vector table allocations */
#define VECTOR_NUMBER_GPT0_COUNTER_OVERFLOW ((IRQn_Type) 0) /* GPT0 COUNTER OVERFLOW (Overflow) */
#define GPT0_COUNTER_OVERFLOW_IRQn          ((IRQn_Type) 0) /* GPT0 COUNTER OVERFLOW (Overflow) */
#define VECTOR_NUMBER_RTC_ALARM ((IRQn_Type) 1) /* RTC ALARM (Alarm interrupt) */
#define RTC_ALARM_IRQn          ((IRQn_Type) 1) /* RTC ALARM (Alarm interrupt) */
#define VECTOR_NUMBER_RTC_PERIOD ((IRQn_Type) 2) /* RTC PERIOD (Periodic interrupt) */
#define RTC_PERIOD_IRQn          ((IRQn_Type) 2) /* RTC PERIOD (Periodic interrupt) */
#define VECTOR_NUMBER_RTC_CARRY ((IRQn_Type) 3) /* RTC CARRY (Carry interrupt) */
#define RTC_CARRY_IRQn          ((IRQn_Type) 3) /* RTC CARRY (Carry interrupt) */
#define VECTOR_NUMBER_SCI9_RXI ((IRQn_Type) 4) /* SCI9 RXI (Received data full) */
#define SCI9_RXI_IRQn          ((IRQn_Type) 4) /* SCI9 RXI (Received data full) */
#define VECTOR_NUMBER_SCI9_TXI ((IRQn_Type) 5) /* SCI9 TXI (Transmit data empty) */
#define SCI9_TXI_IRQn          ((IRQn_Type) 5) /* SCI9 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI9_TEI ((IRQn_Type) 6) /* SCI9 TEI (Transmit end) */
#define SCI9_TEI_IRQn          ((IRQn_Type) 6) /* SCI9 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI9_ERI ((IRQn_Type) 7) /* SCI9 ERI (Receive error) */
#define SCI9_ERI_IRQn          ((IRQn_Type) 7) /* SCI9 ERI (Receive error) */
#define VECTOR_NUMBER_CTSU_WRITE ((IRQn_Type) 9) /* CTSU WRITE (Write request interrupt) */
#define CTSU_WRITE_IRQn          ((IRQn_Type) 9) /* CTSU WRITE (Write request interrupt) */
#define VECTOR_NUMBER_FCU_FRDYI ((IRQn_Type) 10) /* FCU FRDYI (Flash ready interrupt) */
#define FCU_FRDYI_IRQn          ((IRQn_Type) 10) /* FCU FRDYI (Flash ready interrupt) */
#define VECTOR_NUMBER_CTSU_END ((IRQn_Type) 11) /* CTSU END (Measurement end interrupt) */
#define CTSU_END_IRQn          ((IRQn_Type) 11) /* CTSU END (Measurement end interrupt) */
#define VECTOR_NUMBER_CTSU_READ ((IRQn_Type) 14) /* CTSU READ (Measurement data transfer request interrupt) */
#define CTSU_READ_IRQn          ((IRQn_Type) 14) /* CTSU READ (Measurement data transfer request interrupt) */
#ifdef __cplusplus
        }
        #endif
#endif /* VECTOR_DATA_H */
