#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "terminal.h"

#define CHAR_WIDTH 7
#define CHAR_HEIGHT 14

#define SCREEN_WIDTH (COLS * CHAR_WIDTH)
#define SCREEN_HEIGHT (ROWS * CHAR_HEIGHT)

struct screen {
  color_t buffer[SCREEN_WIDTH * SCREEN_HEIGHT];
};

void screen_clear_rows(struct screen *screen, size_t from_row, size_t to_row,
                       color_t inactive);

void screen_clear_cols(struct screen *screen, size_t row, size_t from_col,
                       size_t to_col, color_t inactive);

void screen_scroll(struct screen *screen, enum scroll scroll, size_t from_row,
                   size_t to_row, size_t rows, color_t inactive);

void screen_draw_character(struct screen *screen, size_t row, size_t col,
                           uint8_t character, enum font font, bool italic,
                           bool underlined, bool crossedout, color_t active,
                           color_t inactive);

void screen_draw_cursor(struct screen *screen, size_t row, size_t col,
                        color_t color);

void screen_test_fonts(struct screen *screen);

void screen_test_mandelbrot(struct screen *screen, float window_x,
                            float window_y, float window_r, bool (*cancel)());

void screen_test_colors(struct screen *screen);

void screen_shift_characters_right(struct screen *screen, size_t row,
                                   size_t col, color_t inactive);

void screen_shift_characters_left(struct screen *screen, size_t row, size_t col,
                                  color_t inactive);

#endif
