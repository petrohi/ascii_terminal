#ifndef __TERMINAL_INTERNAL_H__
#define __TERMINAL_INTERNAL_H__

#include "terminal.h"

void terminal_uart_init(struct terminal *terminal);

void terminal_uart_transmit_character(struct terminal *terminal,
                                      character_t character);
void terminal_uart_transmit_string(struct terminal *terminal,
                                   const char *string);
void terminal_uart_transmit_printf(struct terminal *terminal,
                                   const char *format, ...);

void terminal_uart_receive_string(struct terminal *terminal,
                                  const char *string);

void terminal_keyboard_init(struct terminal *terminal);

void terminal_keyboard_update_repeat_counter(struct terminal *terminal);

void terminal_update_keyboard_leds(struct terminal *terminal);

void terminal_screen_init(struct terminal *terminal);

int16_t terminal_screen_cursor_row(struct terminal *terminal);

int16_t terminal_screen_cursor_col(struct terminal *terminal);

void terminal_screen_update_cursor_counter(struct terminal *terminal);

void terminal_screen_move_cursor_absolute(struct terminal *terminal,
                                          int16_t row, int16_t col);

void terminal_screen_move_cursor(struct terminal *terminal, int16_t rows,
                                 int16_t cols);

void terminal_screen_carriage_return(struct terminal *terminal);

void terminal_screen_scroll(struct terminal *terminal, enum scroll scroll,
                            size_t from_row, size_t rows);

void terminal_screen_clear_to_right(struct terminal *terminal);

void terminal_screen_clear_to_left(struct terminal *terminal);

void terminal_screen_clear_row(struct terminal *terminal);

void terminal_screen_clear_to_top(struct terminal *terminal);

void terminal_screen_clear_to_bottom(struct terminal *terminal);

void terminal_screen_clear_all(struct terminal *terminal);

void terminal_screen_index(struct terminal *terminal, int16_t rows);

void terminal_screen_reverse_index(struct terminal *terminal, int16_t rows);

void terminal_screen_put_character(struct terminal *terminal,
                                   character_t character);

void terminal_screen_enable_cursor(struct terminal *terminal, bool enable);

void terminal_screen_save_visual_state(struct terminal *terminal);

void terminal_screen_restore_visual_state(struct terminal *terminal);

void terminal_screen_delete(struct terminal *terminal, size_t cols);

void terminal_screen_insert(struct terminal *terminal, size_t cols);

void terminal_screen_erase(struct terminal *terminal, size_t cols);

#endif

