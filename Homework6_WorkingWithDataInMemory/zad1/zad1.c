#include <stdio.h>
#include <limits.h>

//name, printf form, bytes, max_value_signed, min_value_signed, unsigned_printf_form, unsigned_max_value
#define PRINT(NAME, FORM, SIZE, MAX_SIGNED, MIN_SIGNED, FORM_UNSIGNED, MAX_UNSIGNED)\
printf("| %-20s | %-20s | %-20d | %-20d | %-20d | %-20s | %-20d |\n", #NAME, FORM, SIZE, MAX_SIGNED, MIN_SIGNED, FORM_UNSIGNED, MAX_UNSIGNED);

int main(){

    printf("| %-20s | %-20s | %-20s | %-20s | %-20s | %-20s | %-20s |\n", 
    "Type","PrintForm","Bytes Size","Max_Signed", "Min_Signed", "Printf_Unsgined", "Max_unsigned");

    PRINT(short_int, "%%hd", sizeof(short), SHRT_MAX, SHRT_MIN, "%%hu", USHRT_MAX);
    PRINT(int, "%%d", sizeof(int), INT_MAX, INT_MIN, "%%u", UINT_MAX);
    PRINT(Long_int, "%%ld", sizeof(long), LONG_MAX, LONG_MIN, "%%lu", ULONG_MAX);
    PRINT(Long_Long_int, "%%lld", __SIZEOF_LONG_LONG__ , LLONG_MAX, LLONG_MIN, "%%llu", ULLONG_MAX);

    return 0;
}