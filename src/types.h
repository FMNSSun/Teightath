/**
Copyright (c) 2015 Roman Müntener

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
**/

#ifndef _TYPES_H_
#define _TYPES_H_

#include <stdint.h>
#include <stdlib.h>

typedef int8_t TGT_OBJ_TYPE;
typedef double TGT_DECIMAL;
typedef int64_t TGT_INTEGER;
typedef uint32_t TGT_SIZE;

#define TGT_OBJ_TYPE_INT	1
#define TGT_OBJ_TYPE_DEC	2
#define TGT_OBJ_TYPE_ARR	3

struct TGT_OBJECT;

typedef struct
 TGT_ARRAY {
  TGT_SIZE size;
  TGT_SIZE capacity;
  struct TGT_OBJECT* elems;
} TGT_ARRAY;

typedef struct
 TGT_OBJECT {
  TGT_OBJ_TYPE type;
  union TGT_OBJ_VAL {
    TGT_INTEGER i;
    TGT_DECIMAL d;
	struct TGT_ARRAY a;
  } value;
} TGT_OBJECT;

char* tgt_obj_type_to_str(TGT_OBJ_TYPE type);
TGT_OBJECT tgt_obj_new(TGT_OBJ_TYPE type);

#endif
