#ifndef CONFIG_H
#define CONFIG_H

// Matrix size
#define MATRIX_ROWS 5
#define MATRIX_COLUMNS 15
#define MATRIX_KEYS (MATRIX_ROWS * MATRIX_COLUMNS)

// Keys pressed/released less than N consecutive cycles are ignored
// To define N set the N least significant bits of DEBOUNCER_MASK
#define DEBOUNCER_MASK 0b0000001111111111 // N = 10

#endif // CONFIG_H