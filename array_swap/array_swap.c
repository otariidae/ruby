#include <ruby/ruby.h>

/**
 * Swaps two elements in the array.
*/
void ary_swap(VALUE self, VALUE pos1, VALUE pos2)
{
    long i1 = NUM2LONG(pos1);
    long i2 = NUM2LONG(pos2);
    VALUE tmp = RARRAY_AREF(self, i1);
    rb_ary_aset(self, i1, RARRAY_AREF(self, i2));
    rb_ary_aset(self, i2, tmp);
}


void Init_array_swap()
{
    rb_define_method(rb_cArray, "swap", ary_swap, 2);
}
