/*
 *    This file is part of acados.
 *
 *    acados is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    acados is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with acados; if not, write to the Free Software Foundation,
 *    Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#include "acados/utils/print.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_matrix(char *file_name, const real_t *matrix, const int_t nrows,
    const int_t ncols) {

    FILE *output;
    if (strcmp(file_name, "stdout") == 0) {
        output = stdout;
    } else {
        output = fopen(file_name, "w");
    }
    if (output == NULL) {
        fprintf(stderr, "Opening of file `%s' failed!\n", file_name);
    }
    // Assumes column major ordering
    for (int_t i = 0; i < nrows; i++) {
        for (int_t j = 0; j < ncols; j++) {
            fprintf(output, "%+.3e ", matrix[j*nrows+i]);
        }
        fprintf(output, "\n");
    }
    if (output != stdout) fclose(output);
}

void print_matrix_name(char *file_name, char *name, const real_t *matrix,
        const int_t nrows, const int_t ncols) {
    FILE *output;
    if (strcmp(file_name, "stdout") == 0) {
        output = stdout;
    } else {
        output = fopen(file_name, "w");
    }
    if (output == NULL) {
        fprintf(stderr, "Opening of file `%s' failed!\n", file_name);
    }
    fprintf(output, "%s:\n", name);
    // Assumes column major ordering
    for (int_t i = 0; i < nrows; i++) {
        for (int_t j = 0; j < ncols; j++) {
            fprintf(output, "%+.3e ", matrix[j*nrows+i]);
        }
        fprintf(output, "\n");
    }
    if (output != stdout) fclose(output);
}

void print_int_matrix(char *file_name, const int_t *matrix, const int_t nrows,
    const int_t ncols) {

    FILE *output;
    if (strcmp(file_name, "stdout") == 0) {
        output = stdout;
    } else {
        output = fopen(file_name, "w");
    }
    if (output == NULL) {
        fprintf(stderr, "Opening of file `%s' failed!\n", file_name);
    }
    // Assumes column major ordering
    for (int_t i = 0; i < nrows; i++) {
        for (int_t j = 0; j < ncols; j++) {
            fprintf(output, "%d ", matrix[j*nrows+i]);
        }
        fprintf(output, "\n");
    }
    if (output != stdout) fclose(output);
}

void print_array(char *file_name, real_t *array, int_t size) {
    print_matrix(file_name, array, size, 1);
}

void print_int_array(char *file_name, const int_t *array, int_t size) {
    print_int_matrix(file_name, array, size, 1);
}

// Read space delimited file into column-major matrix
void read_matrix(const char *file_name, real_t* array, const int_t nrows,
        const int_t ncols) {
    FILE *file;
    file = fopen(file_name, "r");

    if (file == NULL) {
        printf("Error Reading File %s!\n", file_name);
        exit(1);
    }

    // Read numbers from file into buffer.
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            if (!fscanf(file, "%lf", &array[nrows*j+i])) {
                break;
            }
        }
    }

    fclose(file);
}


