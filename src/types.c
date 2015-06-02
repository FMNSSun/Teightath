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

#include "types.h"

char*
 tgt_obj_type_to_str(
  TGT_OBJ_TYPE type
 )
{
  switch(type) {
    case TGT_OBJ_TYPE_INT:
      return "INT";
    case TGT_OBJ_TYPE_DEC:
      return "DEC";
    case TGT_OBJ_TYPE_ARR:
      return "ARR";
    default:
      return "N/A";
  }
}

TGT_OBJECT
 tgt_obj_new(
  TGT_OBJ_TYPE type
 )
{
  TGT_OBJECT obj;
  switch(type) {
    case TGT_OBJ_TYPE_INT:
      obj.type = TGT_OBJ_TYPE_INT;
      obj.value.i = 0;
      break;
  }
  return obj;
}

void
 tgt_obj_destroy(
  TGT_OBJECT* object
 )
{
  TGT_ARRAY array;
  TGT_SIZE i, s;

  if(object->type != TGT_OBJ_TYPE_ARR)
    return;

  array = (object->value).a;
  s = array.size;
  
  for(i = 0; i < s; i++) {
    tgt_obj_destroy(&(array.elems[i]));
  }

  free(array.elems);
}
