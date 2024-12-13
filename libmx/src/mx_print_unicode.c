#include "libmx.h"

void mx_print_unicode(wchar_t c) {
    char buf[4];
    if (c <= 0x7F) {
        buf[0] = (char)c;
        write(1, buf, 1);
    } else if (c <= 0x7FF) {
        buf[0] = (char)((c >> 6) | 0xC0);
        buf[1] = (char)((c & 0x3F) | 0x80);
        write(1, buf, 2);
    } else if (c <= 0xFFFF) {
        buf[0] = (char)((c >> 12) | 0xE0);
        buf[1] = (char)(((c >> 6) & 0x3F) | 0x80);
        buf[2] = (char)((c & 0x3F) | 0x80);
        write(1, buf, 3);
    } else if (c <= 0x10FFFF) {
        buf[0] = (char)((c >> 18) | 0xF0);
        buf[1] = (char)(((c >> 12) & 0x3F) | 0x80);
        buf[2] = (char)(((c >> 6) & 0x3F) | 0x80);
        buf[3] = (char)((c & 0x3F) | 0x80);
        write(1, buf, 4);
    }
}
