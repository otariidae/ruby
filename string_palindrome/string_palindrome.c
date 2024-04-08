#include <ruby/ruby.h>

static VALUE
str_palindrome_p(VALUE self)
{
  const char *pat = "[^A-z0-9\\p{hiragana}\\p{katakana}]";
  VALUE argv[2] = {rb_reg_regcomp(rb_utf8_str_new_cstr(pat)),
                  rb_str_new_cstr("")};
  VALUE filtered_str = rb_str_downcase(0, NULL, str_gsub(2, argv, self, FALSE));
  return rb_str_empty(filtered_str) ? Qfalse :
         rb_str_equal(filtered_str, rb_str_reverse(filtered_str));
}

void Init_string_palindrome() {
    rb_define_method(rb_cString, "palindrome?", str_palindrome_p, 0);
}
