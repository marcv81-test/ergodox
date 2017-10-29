#include "matrix.h"

#include "matrix_right.h"
#include "matrix_left.h"

matrix_t matrix;

void matrix_init()
{
    matrix_left_init();
    matrix_right_init();
}

// Update the rows for the specified column
static void update_rows(uint8_t rows, uint8_t column)
{
    for (uint8_t row=0; row<MATRIX_ROWS; row++)
    {
        matrix.array[row][column] = (rows & (1 << row)) != 0;
    }
}

// Update the entire matrix
// Interleave left and right matrix scans
void matrix_update()
{
    for (uint8_t left_column=0; left_column<(MATRIX_COLUMNS/2); left_column++)
    {
        uint8_t right_column = MATRIX_COLUMNS - left_column - 1;
        // Select the column
        matrix_left_select_column(left_column);
        matrix_right_select_column(right_column);
        // Read the rows and update the matrix
        update_rows(matrix_left_read_rows(), left_column);
        update_rows(matrix_right_read_rows(), right_column);
    }
}
