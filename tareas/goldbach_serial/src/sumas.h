#ifndef SUMAS_H
#define SUMAS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <inttypes.h>
#include <ctype.h>
#include "array_uint64.h"

typedef struct sumas sumas_t;

sumas_t* sumas_create(char* entrada);

void sumas_run(sumas_t* sumas);

void sumas_print(sumas_t* sumas);

void sumas_destroy(sumas_t* sumas);

#endif