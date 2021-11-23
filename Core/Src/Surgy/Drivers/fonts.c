/*
 * fonts.c
 *
 *  Created on: Sep 9, 2019
 *      Author: fil
 */
/* vim: set ai et ts=4 sw=4: */
#include "main.h"
#include "fonts.h"

__attribute__((section(".table"))) static const uint16_t Font11x18 [] = {
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // sp
0x0000, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0000, 0x0C00, 0x0C00, 0x0000, 0x0000, 0x0000,   // !
0x0000, 0x1B00, 0x1B00, 0x1B00, 0x1B00, 0x1B00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // "
0x0000, 0x1980, 0x1980, 0x1980, 0x1980, 0x7FC0, 0x7FC0, 0x1980, 0x3300, 0x7FC0, 0x7FC0, 0x3300, 0x3300, 0x3300, 0x3300, 0x0000, 0x0000, 0x0000,   // #
0x0000, 0x1E00, 0x3F00, 0x7580, 0x6580, 0x7400, 0x3C00, 0x1E00, 0x0700, 0x0580, 0x6580, 0x6580, 0x7580, 0x3F00, 0x1E00, 0x0400, 0x0400, 0x0000,   // $
0x0000, 0x7000, 0xD800, 0xD840, 0xD8C0, 0xD980, 0x7300, 0x0600, 0x0C00, 0x1B80, 0x36C0, 0x66C0, 0x46C0, 0x06C0, 0x0380, 0x0000, 0x0000, 0x0000,   // %
0x0000, 0x1E00, 0x3F00, 0x3300, 0x3300, 0x3300, 0x1E00, 0x0C00, 0x3CC0, 0x66C0, 0x6380, 0x6180, 0x6380, 0x3EC0, 0x1C80, 0x0000, 0x0000, 0x0000,   // &
0x0000, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // '
0x0080, 0x0100, 0x0300, 0x0600, 0x0600, 0x0400, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0400, 0x0600, 0x0600, 0x0300, 0x0100, 0x0080,   // (
0x2000, 0x1000, 0x1800, 0x0C00, 0x0C00, 0x0400, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0400, 0x0C00, 0x0C00, 0x1800, 0x1000, 0x2000,   // )
0x0000, 0x0C00, 0x2D00, 0x3F00, 0x1E00, 0x3300, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // *
0x0000, 0x0000, 0x0000, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0xFFC0, 0xFFC0, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // +
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0C00, 0x0C00, 0x0400, 0x0400, 0x0800,   // ,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1E00, 0x1E00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // -
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0C00, 0x0C00, 0x0000, 0x0000, 0x0000,   // .
0x0000, 0x0300, 0x0300, 0x0300, 0x0600, 0x0600, 0x0600, 0x0600, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x1800, 0x1800, 0x1800, 0x0000, 0x0000, 0x0000,   // /
0x0000, 0x1E00, 0x3F00, 0x3300, 0x6180, 0x6180, 0x6180, 0x6D80, 0x6D80, 0x6180, 0x6180, 0x6180, 0x3300, 0x3F00, 0x1E00, 0x0000, 0x0000, 0x0000,   // 0
0x0000, 0x0600, 0x0E00, 0x1E00, 0x3600, 0x2600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0000, 0x0000, 0x0000,   // 1
0x0000, 0x1E00, 0x3F00, 0x7380, 0x6180, 0x6180, 0x0180, 0x0300, 0x0600, 0x0C00, 0x1800, 0x3000, 0x6000, 0x7F80, 0x7F80, 0x0000, 0x0000, 0x0000,   // 2
0x0000, 0x1C00, 0x3E00, 0x6300, 0x6300, 0x0300, 0x0E00, 0x0E00, 0x0300, 0x0180, 0x0180, 0x6180, 0x7380, 0x3F00, 0x1E00, 0x0000, 0x0000, 0x0000,   // 3
0x0000, 0x0600, 0x0E00, 0x0E00, 0x1E00, 0x1E00, 0x1600, 0x3600, 0x3600, 0x6600, 0x7F80, 0x7F80, 0x0600, 0x0600, 0x0600, 0x0000, 0x0000, 0x0000,   // 4
0x0000, 0x7F00, 0x7F00, 0x6000, 0x6000, 0x6000, 0x6E00, 0x7F00, 0x6380, 0x0180, 0x0180, 0x6180, 0x7380, 0x3F00, 0x1E00, 0x0000, 0x0000, 0x0000,   // 5
0x0000, 0x1E00, 0x3F00, 0x3380, 0x6180, 0x6000, 0x6E00, 0x7F00, 0x7380, 0x6180, 0x6180, 0x6180, 0x3380, 0x3F00, 0x1E00, 0x0000, 0x0000, 0x0000,   // 6
0x0000, 0x7F80, 0x7F80, 0x0180, 0x0300, 0x0300, 0x0600, 0x0600, 0x0C00, 0x0C00, 0x0C00, 0x0800, 0x1800, 0x1800, 0x1800, 0x0000, 0x0000, 0x0000,   // 7
0x0000, 0x1E00, 0x3F00, 0x6380, 0x6180, 0x6180, 0x2100, 0x1E00, 0x3F00, 0x6180, 0x6180, 0x6180, 0x6180, 0x3F00, 0x1E00, 0x0000, 0x0000, 0x0000,   // 8
0x0000, 0x1E00, 0x3F00, 0x7300, 0x6180, 0x6180, 0x6180, 0x7380, 0x3F80, 0x1D80, 0x0180, 0x6180, 0x7300, 0x3F00, 0x1E00, 0x0000, 0x0000, 0x0000,   // 9
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0C00, 0x0C00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0C00, 0x0C00, 0x0000, 0x0000, 0x0000,   // :
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0C00, 0x0C00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0C00, 0x0C00, 0x0400, 0x0400, 0x0800,   // ;
0x0000, 0x0000, 0x0000, 0x0000, 0x0080, 0x0380, 0x0E00, 0x3800, 0x6000, 0x3800, 0x0E00, 0x0380, 0x0080, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // <
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7F80, 0x7F80, 0x0000, 0x0000, 0x7F80, 0x7F80, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // =
0x0000, 0x0000, 0x0000, 0x0000, 0x4000, 0x7000, 0x1C00, 0x0700, 0x0180, 0x0700, 0x1C00, 0x7000, 0x4000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // >
0x0000, 0x1F00, 0x3F80, 0x71C0, 0x60C0, 0x00C0, 0x01C0, 0x0380, 0x0700, 0x0E00, 0x0C00, 0x0C00, 0x0000, 0x0C00, 0x0C00, 0x0000, 0x0000, 0x0000,   // ?
0x0000, 0x1E00, 0x3F00, 0x3180, 0x7180, 0x6380, 0x6F80, 0x6D80, 0x6D80, 0x6F80, 0x6780, 0x6000, 0x3200, 0x3E00, 0x1C00, 0x0000, 0x0000, 0x0000,   // @
0x0000, 0x0E00, 0x0E00, 0x1B00, 0x1B00, 0x1B00, 0x1B00, 0x3180, 0x3180, 0x3F80, 0x3F80, 0x3180, 0x60C0, 0x60C0, 0x60C0, 0x0000, 0x0000, 0x0000,   // A
0x0000, 0x7C00, 0x7E00, 0x6300, 0x6300, 0x6300, 0x6300, 0x7E00, 0x7E00, 0x6300, 0x6180, 0x6180, 0x6380, 0x7F00, 0x7E00, 0x0000, 0x0000, 0x0000,   // B
0x0000, 0x1E00, 0x3F00, 0x3180, 0x6180, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6180, 0x3180, 0x3F00, 0x1E00, 0x0000, 0x0000, 0x0000,   // C
0x0000, 0x7C00, 0x7F00, 0x6300, 0x6380, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6300, 0x6300, 0x7E00, 0x7C00, 0x0000, 0x0000, 0x0000,   // D
0x0000, 0x7F80, 0x7F80, 0x6000, 0x6000, 0x6000, 0x6000, 0x7F00, 0x7F00, 0x6000, 0x6000, 0x6000, 0x6000, 0x7F80, 0x7F80, 0x0000, 0x0000, 0x0000,   // E
0x0000, 0x7F80, 0x7F80, 0x6000, 0x6000, 0x6000, 0x6000, 0x7F00, 0x7F00, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x0000, 0x0000, 0x0000,   // F
0x0000, 0x1E00, 0x3F00, 0x3180, 0x6180, 0x6000, 0x6000, 0x6000, 0x6380, 0x6380, 0x6180, 0x6180, 0x3180, 0x3F80, 0x1E00, 0x0000, 0x0000, 0x0000,   // G
0x0000, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x7F80, 0x7F80, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x0000, 0x0000, 0x0000,   // H
0x0000, 0x3F00, 0x3F00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x3F00, 0x3F00, 0x0000, 0x0000, 0x0000,   // I
0x0000, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x6180, 0x6180, 0x7380, 0x3F00, 0x1E00, 0x0000, 0x0000, 0x0000,   // J
0x0000, 0x60C0, 0x6180, 0x6300, 0x6600, 0x6600, 0x6C00, 0x7800, 0x7C00, 0x6600, 0x6600, 0x6300, 0x6180, 0x6180, 0x60C0, 0x0000, 0x0000, 0x0000,   // K
0x0000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x7F80, 0x7F80, 0x0000, 0x0000, 0x0000,   // L
0x0000, 0x71C0, 0x71C0, 0x7BC0, 0x7AC0, 0x6AC0, 0x6AC0, 0x6EC0, 0x64C0, 0x60C0, 0x60C0, 0x60C0, 0x60C0, 0x60C0, 0x60C0, 0x0000, 0x0000, 0x0000,   // M
0x0000, 0x7180, 0x7180, 0x7980, 0x7980, 0x7980, 0x6D80, 0x6D80, 0x6D80, 0x6580, 0x6780, 0x6780, 0x6780, 0x6380, 0x6380, 0x0000, 0x0000, 0x0000,   // N
0x0000, 0x1E00, 0x3F00, 0x3300, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x3300, 0x3F00, 0x1E00, 0x0000, 0x0000, 0x0000,   // O
0x0000, 0x7E00, 0x7F00, 0x6380, 0x6180, 0x6180, 0x6180, 0x6380, 0x7F00, 0x7E00, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x0000, 0x0000, 0x0000,   // P
0x0000, 0x1E00, 0x3F00, 0x3300, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6580, 0x6780, 0x3300, 0x3F80, 0x1E40, 0x0000, 0x0000, 0x0000,   // Q
0x0000, 0x7E00, 0x7F00, 0x6380, 0x6180, 0x6180, 0x6380, 0x7F00, 0x7E00, 0x6600, 0x6300, 0x6300, 0x6180, 0x6180, 0x60C0, 0x0000, 0x0000, 0x0000,   // R
0x0000, 0x0E00, 0x1F00, 0x3180, 0x3180, 0x3000, 0x3800, 0x1E00, 0x0700, 0x0380, 0x6180, 0x6180, 0x3180, 0x3F00, 0x1E00, 0x0000, 0x0000, 0x0000,   // S
0x0000, 0xFFC0, 0xFFC0, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0000, 0x0000, 0x0000,   // T
0x0000, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x7380, 0x3F00, 0x1E00, 0x0000, 0x0000, 0x0000,   // U
0x0000, 0x60C0, 0x60C0, 0x60C0, 0x3180, 0x3180, 0x3180, 0x1B00, 0x1B00, 0x1B00, 0x1B00, 0x0E00, 0x0E00, 0x0E00, 0x0400, 0x0000, 0x0000, 0x0000,   // V
0x0000, 0xC0C0, 0xC0C0, 0xC0C0, 0xC0C0, 0xC0C0, 0xCCC0, 0x4C80, 0x4C80, 0x5E80, 0x5280, 0x5280, 0x7380, 0x6180, 0x6180, 0x0000, 0x0000, 0x0000,   // W
0x0000, 0xC0C0, 0x6080, 0x6180, 0x3300, 0x3B00, 0x1E00, 0x0C00, 0x0C00, 0x1E00, 0x1F00, 0x3B00, 0x7180, 0x6180, 0xC0C0, 0x0000, 0x0000, 0x0000,   // X
0x0000, 0xC0C0, 0x6180, 0x6180, 0x3300, 0x3300, 0x1E00, 0x1E00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0000, 0x0000, 0x0000,   // Y
0x0000, 0x3F80, 0x3F80, 0x0180, 0x0300, 0x0300, 0x0600, 0x0C00, 0x0C00, 0x1800, 0x1800, 0x3000, 0x6000, 0x7F80, 0x7F80, 0x0000, 0x0000, 0x0000,   // Z
0x0F00, 0x0F00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0F00, 0x0F00,   // [
0x0000, 0x1800, 0x1800, 0x1800, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0600, 0x0600, 0x0600, 0x0600, 0x0300, 0x0300, 0x0300, 0x0000, 0x0000, 0x0000,   /* \ */
0x1E00, 0x1E00, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x1E00, 0x1E00,   // ]
0x0000, 0x0C00, 0x0C00, 0x1E00, 0x1200, 0x3300, 0x3300, 0x6180, 0x6180, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // ^
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFE0, 0x0000,   // _
0x0000, 0x3800, 0x1800, 0x0C00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // `
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1F00, 0x3F80, 0x6180, 0x0180, 0x1F80, 0x3F80, 0x6180, 0x6380, 0x7F80, 0x38C0, 0x0000, 0x0000, 0x0000,   // a
0x0000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6E00, 0x7F00, 0x7380, 0x6180, 0x6180, 0x6180, 0x6180, 0x7380, 0x7F00, 0x6E00, 0x0000, 0x0000, 0x0000,   // b
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1E00, 0x3F00, 0x7380, 0x6180, 0x6000, 0x6000, 0x6180, 0x7380, 0x3F00, 0x1E00, 0x0000, 0x0000, 0x0000,   // c
0x0000, 0x0180, 0x0180, 0x0180, 0x0180, 0x1D80, 0x3F80, 0x7380, 0x6180, 0x6180, 0x6180, 0x6180, 0x7380, 0x3F80, 0x1D80, 0x0000, 0x0000, 0x0000,   // d
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1E00, 0x3F00, 0x7300, 0x6180, 0x7F80, 0x7F80, 0x6000, 0x7180, 0x3F00, 0x1E00, 0x0000, 0x0000, 0x0000,   // e
0x0000, 0x07C0, 0x0FC0, 0x0C00, 0x0C00, 0x7F80, 0x7F80, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0000, 0x0000, 0x0000,   // f
0x0000, 0x0000, 0x0000, 0x0000, 0x1D80, 0x3F80, 0x7380, 0x6180, 0x6180, 0x6180, 0x6180, 0x7380, 0x3F80, 0x1D80, 0x0180, 0x6380, 0x7F00, 0x3E00,   // g
0x0000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6F00, 0x7F80, 0x7180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x0000, 0x0000, 0x0000,   // h
0x0000, 0x0600, 0x0600, 0x0000, 0x0000, 0x3E00, 0x3E00, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0000, 0x0000, 0x0000,   // i
0x0600, 0x0600, 0x0000, 0x0000, 0x3E00, 0x3E00, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x4600, 0x7E00, 0x3C00,   // j
0x0000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6180, 0x6300, 0x6600, 0x6C00, 0x7C00, 0x7600, 0x6300, 0x6300, 0x6180, 0x60C0, 0x0000, 0x0000, 0x0000,   // k
0x0000, 0x3E00, 0x3E00, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0000, 0x0000, 0x0000,   // l
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xDD80, 0xFFC0, 0xCEC0, 0xCCC0, 0xCCC0, 0xCCC0, 0xCCC0, 0xCCC0, 0xCCC0, 0xCCC0, 0x0000, 0x0000, 0x0000,   // m
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6F00, 0x7F80, 0x7180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x0000, 0x0000, 0x0000,   // n
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1E00, 0x3F00, 0x7380, 0x6180, 0x6180, 0x6180, 0x6180, 0x7380, 0x3F00, 0x1E00, 0x0000, 0x0000, 0x0000,   // o
0x0000, 0x0000, 0x0000, 0x0000, 0x6E00, 0x7F00, 0x7380, 0x6180, 0x6180, 0x6180, 0x6180, 0x7380, 0x7F00, 0x6E00, 0x6000, 0x6000, 0x6000, 0x6000,   // p
0x0000, 0x0000, 0x0000, 0x0000, 0x1D80, 0x3F80, 0x7380, 0x6180, 0x6180, 0x6180, 0x6180, 0x7380, 0x3F80, 0x1D80, 0x0180, 0x0180, 0x0180, 0x0180,   // q
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6700, 0x3F80, 0x3900, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x0000, 0x0000, 0x0000,   // r
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1E00, 0x3F80, 0x6180, 0x6000, 0x7F00, 0x3F80, 0x0180, 0x6180, 0x7F00, 0x1E00, 0x0000, 0x0000, 0x0000,   // s
0x0000, 0x0000, 0x0800, 0x1800, 0x1800, 0x7F00, 0x7F00, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1F80, 0x0F80, 0x0000, 0x0000, 0x0000,   // t
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6180, 0x6380, 0x7F80, 0x3D80, 0x0000, 0x0000, 0x0000,   // u
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x60C0, 0x3180, 0x3180, 0x3180, 0x1B00, 0x1B00, 0x1B00, 0x0E00, 0x0E00, 0x0600, 0x0000, 0x0000, 0x0000,   // v
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xDD80, 0xDD80, 0xDD80, 0x5500, 0x5500, 0x5500, 0x7700, 0x7700, 0x2200, 0x2200, 0x0000, 0x0000, 0x0000,   // w
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6180, 0x3300, 0x3300, 0x1E00, 0x0C00, 0x0C00, 0x1E00, 0x3300, 0x3300, 0x6180, 0x0000, 0x0000, 0x0000,   // x
0x0000, 0x0000, 0x0000, 0x0000, 0x6180, 0x6180, 0x3180, 0x3300, 0x3300, 0x1B00, 0x1B00, 0x1B00, 0x0E00, 0x0E00, 0x0E00, 0x1C00, 0x7C00, 0x7000,   // y
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FC0, 0x7FC0, 0x0180, 0x0300, 0x0600, 0x0C00, 0x1800, 0x3000, 0x7FC0, 0x7FC0, 0x0000, 0x0000, 0x0000,   // z
0x0380, 0x0780, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0E00, 0x1C00, 0x1C00, 0x0E00, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0780, 0x0380,   // {
0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600,   // |
0x3800, 0x3C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0E00, 0x0700, 0x0700, 0x0E00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x0C00, 0x3C00, 0x3800,   // }
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3880, 0x7F80, 0x4700, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // ~
};
__attribute__((section(".table"))) static const uint16_t Font16x26 [] = {
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [ ]
0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03C0,0x03C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x0000,0x0000,0x0000,0x03E0,0x03E0,0x03E0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [!]
0x1E3C,0x1E3C,0x1E3C,0x1E3C,0x1E3C,0x1E3C,0x1E3C,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = ["]
0x01CE,0x03CE,0x03DE,0x039E,0x039C,0x079C,0x3FFF,0x7FFF,0x0738,0x0F38,0x0F78,0x0F78,0x0E78,0xFFFF,0xFFFF,0x1EF0,0x1CF0,0x1CE0,0x3CE0,0x3DE0,0x39E0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [#]
0x03FC,0x0FFE,0x1FEE,0x1EE0,0x1EE0,0x1EE0,0x1EE0,0x1FE0,0x0FE0,0x07E0,0x03F0,0x01FC,0x01FE,0x01FE,0x01FE,0x01FE,0x01FE,0x01FE,0x3DFE,0x3FFC,0x0FF0,0x01E0,0x01E0,0x0000,0x0000,0x0000, // Ascii = [$]
0x3E03,0xF707,0xE78F,0xE78E,0xE39E,0xE3BC,0xE7B8,0xE7F8,0xF7F0,0x3FE0,0x01C0,0x03FF,0x07FF,0x07F3,0x0FF3,0x1EF3,0x3CF3,0x38F3,0x78F3,0xF07F,0xE03F,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [%]
0x07E0,0x0FF8,0x0F78,0x1F78,0x1F78,0x1F78,0x0F78,0x0FF0,0x0FE0,0x1F80,0x7FC3,0xFBC3,0xF3E7,0xF1F7,0xF0F7,0xF0FF,0xF07F,0xF83E,0x7C7F,0x3FFF,0x1FEF,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [&]
0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03C0,0x01C0,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [']
0x003F,0x007C,0x01F0,0x01E0,0x03C0,0x07C0,0x0780,0x0780,0x0F80,0x0F00,0x0F00,0x0F00,0x0F00,0x0F00,0x0F00,0x0F80,0x0780,0x0780,0x07C0,0x03C0,0x01E0,0x01F0,0x007C,0x003F,0x000F,0x0000, // Ascii = [(]
0x7E00,0x1F00,0x07C0,0x03C0,0x01E0,0x01F0,0x00F0,0x00F0,0x00F8,0x0078,0x0078,0x0078,0x0078,0x0078,0x0078,0x00F8,0x00F0,0x00F0,0x01F0,0x01E0,0x03C0,0x07C0,0x1F00,0x7E00,0x7800,0x0000, // Ascii = [)]
0x03E0,0x03C0,0x01C0,0x39CE,0x3FFF,0x3F7F,0x0320,0x0370,0x07F8,0x0F78,0x1F3C,0x0638,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [*]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0xFFFF,0xFFFF,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [+]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x03E0,0x03E0,0x03E0,0x03E0,0x01E0,0x01E0,0x01E0,0x01C0,0x0380, // Ascii = [,]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x3FFE,0x3FFE,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [-]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x03E0,0x03E0,0x03E0,0x03E0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [.]
0x000F,0x000F,0x001E,0x001E,0x003C,0x003C,0x0078,0x0078,0x00F0,0x00F0,0x01E0,0x01E0,0x03C0,0x03C0,0x0780,0x0780,0x0F00,0x0F00,0x1E00,0x1E00,0x3C00,0x3C00,0x7800,0x7800,0xF000,0x0000, // Ascii = [/]
0x07F0,0x0FF8,0x1F7C,0x3E3E,0x3C1E,0x7C1F,0x7C1F,0x780F,0x780F,0x780F,0x780F,0x780F,0x780F,0x780F,0x7C1F,0x7C1F,0x3C1E,0x3E3E,0x1F7C,0x0FF8,0x07F0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [0]
0x00F0,0x07F0,0x3FF0,0x3FF0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x3FFF,0x3FFF,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [1]
0x0FE0,0x3FF8,0x3C7C,0x003C,0x003E,0x003E,0x003E,0x003C,0x003C,0x007C,0x00F8,0x01F0,0x03E0,0x07C0,0x0780,0x0F00,0x1E00,0x3E00,0x3C00,0x3FFE,0x3FFE,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [2]
0x0FF0,0x1FF8,0x1C7C,0x003E,0x003E,0x003E,0x003C,0x003C,0x00F8,0x0FF0,0x0FF8,0x007C,0x003E,0x001E,0x001E,0x001E,0x001E,0x003E,0x1C7C,0x1FF8,0x1FE0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [3]
0x0078,0x00F8,0x00F8,0x01F8,0x03F8,0x07F8,0x07F8,0x0F78,0x1E78,0x1E78,0x3C78,0x7878,0x7878,0xFFFF,0xFFFF,0x0078,0x0078,0x0078,0x0078,0x0078,0x0078,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [4]
0x1FFC,0x1FFC,0x1FFC,0x1E00,0x1E00,0x1E00,0x1E00,0x1E00,0x1FE0,0x1FF8,0x00FC,0x007C,0x003E,0x003E,0x001E,0x003E,0x003E,0x003C,0x1C7C,0x1FF8,0x1FE0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [5]
0x01FC,0x07FE,0x0F8E,0x1F00,0x1E00,0x3E00,0x3C00,0x3C00,0x3DF8,0x3FFC,0x7F3E,0x7E1F,0x3C0F,0x3C0F,0x3C0F,0x3C0F,0x3E0F,0x1E1F,0x1F3E,0x0FFC,0x03F0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [6]
0x3FFF,0x3FFF,0x3FFF,0x000F,0x001E,0x001E,0x003C,0x0038,0x0078,0x00F0,0x00F0,0x01E0,0x01E0,0x03C0,0x03C0,0x0780,0x0F80,0x0F80,0x0F00,0x1F00,0x1F00,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [7]
0x07F8,0x0FFC,0x1F3E,0x1E1E,0x3E1E,0x3E1E,0x1E1E,0x1F3C,0x0FF8,0x07F0,0x0FF8,0x1EFC,0x3E3E,0x3C1F,0x7C1F,0x7C0F,0x7C0F,0x3C1F,0x3F3E,0x1FFC,0x07F0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [8]
0x07F0,0x0FF8,0x1E7C,0x3C3E,0x3C1E,0x7C1F,0x7C1F,0x7C1F,0x7C1F,0x3C1F,0x3E3F,0x1FFF,0x07EF,0x001F,0x001E,0x001E,0x003E,0x003C,0x38F8,0x3FF0,0x1FE0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [9]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x03E0,0x03E0,0x03E0,0x03E0,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x03E0,0x03E0,0x03E0,0x03E0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [:]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x03E0,0x03E0,0x03E0,0x03E0,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x03E0,0x03E0,0x03E0,0x03E0,0x01E0,0x01E0,0x01E0,0x03C0,0x0380, // Ascii = [;]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0003,0x000F,0x003F,0x00FC,0x03F0,0x0FC0,0x3F00,0xFE00,0x3F00,0x0FC0,0x03F0,0x00FC,0x003F,0x000F,0x0003,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [<]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xFFFF,0xFFFF,0x0000,0x0000,0x0000,0xFFFF,0xFFFF,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [=]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xE000,0xF800,0x7E00,0x1F80,0x07E0,0x01F8,0x007E,0x001F,0x007E,0x01F8,0x07E0,0x1F80,0x7E00,0xF800,0xE000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [>]
0x1FF0,0x3FFC,0x383E,0x381F,0x381F,0x001E,0x001E,0x003C,0x0078,0x00F0,0x01E0,0x03C0,0x03C0,0x07C0,0x07C0,0x0000,0x0000,0x0000,0x07C0,0x07C0,0x07C0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [?]
0x03F8,0x0FFE,0x1F1E,0x3E0F,0x3C7F,0x78FF,0x79EF,0x73C7,0xF3C7,0xF38F,0xF38F,0xF38F,0xF39F,0xF39F,0x73FF,0x7BFF,0x79F7,0x3C00,0x1F1C,0x0FFC,0x03F8,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [@]
0x0000,0x0000,0x0000,0x03E0,0x03E0,0x07F0,0x07F0,0x07F0,0x0F78,0x0F78,0x0E7C,0x1E3C,0x1E3C,0x3C3E,0x3FFE,0x3FFF,0x781F,0x780F,0xF00F,0xF007,0xF007,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [A]
0x0000,0x0000,0x0000,0x3FF8,0x3FFC,0x3C3E,0x3C1E,0x3C1E,0x3C1E,0x3C3E,0x3C7C,0x3FF0,0x3FF8,0x3C7E,0x3C1F,0x3C1F,0x3C0F,0x3C0F,0x3C1F,0x3FFE,0x3FF8,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [B]
0x0000,0x0000,0x0000,0x01FF,0x07FF,0x1F87,0x3E00,0x3C00,0x7C00,0x7800,0x7800,0x7800,0x7800,0x7800,0x7C00,0x7C00,0x3E00,0x3F00,0x1F83,0x07FF,0x01FF,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [C]
0x0000,0x0000,0x0000,0x7FF0,0x7FFC,0x787E,0x781F,0x781F,0x780F,0x780F,0x780F,0x780F,0x780F,0x780F,0x780F,0x780F,0x781F,0x781E,0x787E,0x7FF8,0x7FE0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [D]
0x0000,0x0000,0x0000,0x3FFF,0x3FFF,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3FFE,0x3FFE,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3FFF,0x3FFF,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [E]
0x0000,0x0000,0x0000,0x1FFF,0x1FFF,0x1E00,0x1E00,0x1E00,0x1E00,0x1E00,0x1E00,0x1FFF,0x1FFF,0x1E00,0x1E00,0x1E00,0x1E00,0x1E00,0x1E00,0x1E00,0x1E00,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [F]
0x0000,0x0000,0x0000,0x03FE,0x0FFF,0x1F87,0x3E00,0x7C00,0x7C00,0x7800,0xF800,0xF800,0xF87F,0xF87F,0x780F,0x7C0F,0x7C0F,0x3E0F,0x1F8F,0x0FFF,0x03FE,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [G]
0x0000,0x0000,0x0000,0x7C1F,0x7C1F,0x7C1F,0x7C1F,0x7C1F,0x7C1F,0x7C1F,0x7C1F,0x7FFF,0x7FFF,0x7C1F,0x7C1F,0x7C1F,0x7C1F,0x7C1F,0x7C1F,0x7C1F,0x7C1F,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [H]
0x0000,0x0000,0x0000,0x3FFF,0x3FFF,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x3FFF,0x3FFF,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [I]
0x0000,0x0000,0x0000,0x1FFC,0x1FFC,0x007C,0x007C,0x007C,0x007C,0x007C,0x007C,0x007C,0x007C,0x007C,0x007C,0x007C,0x0078,0x0078,0x38F8,0x3FF0,0x3FC0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [J]
0x0000,0x0000,0x0000,0x3C1F,0x3C1E,0x3C3C,0x3C78,0x3CF0,0x3DE0,0x3FE0,0x3FC0,0x3F80,0x3FC0,0x3FE0,0x3DF0,0x3CF0,0x3C78,0x3C7C,0x3C3E,0x3C1F,0x3C0F,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [K]
0x0000,0x0000,0x0000,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3FFF,0x3FFF,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [L]
0x0000,0x0000,0x0000,0xF81F,0xFC1F,0xFC1F,0xFE3F,0xFE3F,0xFE3F,0xFF7F,0xFF77,0xFF77,0xF7F7,0xF7E7,0xF3E7,0xF3E7,0xF3C7,0xF007,0xF007,0xF007,0xF007,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [M]
0x0000,0x0000,0x0000,0x7C0F,0x7C0F,0x7E0F,0x7F0F,0x7F0F,0x7F8F,0x7F8F,0x7FCF,0x7BEF,0x79EF,0x79FF,0x78FF,0x78FF,0x787F,0x783F,0x783F,0x781F,0x781F,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [N]
0x0000,0x0000,0x0000,0x07F0,0x1FFC,0x3E3E,0x7C1F,0x780F,0x780F,0xF80F,0xF80F,0xF80F,0xF80F,0xF80F,0xF80F,0x780F,0x780F,0x7C1F,0x3E3E,0x1FFC,0x07F0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [O]
0x0000,0x0000,0x0000,0x3FFC,0x3FFF,0x3E1F,0x3E0F,0x3E0F,0x3E0F,0x3E0F,0x3E1F,0x3E3F,0x3FFC,0x3FF0,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [P]
0x0000,0x0000,0x0000,0x07F0,0x1FFC,0x3E3E,0x7C1F,0x780F,0x780F,0xF80F,0xF80F,0xF80F,0xF80F,0xF80F,0xF80F,0x780F,0x780F,0x7C1F,0x3E3E,0x1FFC,0x07F8,0x007C,0x003F,0x000F,0x0003,0x0000, // Ascii = [Q]
0x0000,0x0000,0x0000,0x3FF0,0x3FFC,0x3C7E,0x3C3E,0x3C1E,0x3C1E,0x3C3E,0x3C3C,0x3CFC,0x3FF0,0x3FE0,0x3DF0,0x3CF8,0x3C7C,0x3C3E,0x3C1E,0x3C1F,0x3C0F,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [R]
0x0000,0x0000,0x0000,0x07FC,0x1FFE,0x3E0E,0x3C00,0x3C00,0x3C00,0x3E00,0x1FC0,0x0FF8,0x03FE,0x007F,0x001F,0x000F,0x000F,0x201F,0x3C3E,0x3FFC,0x1FF0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [S]
0x0000,0x0000,0x0000,0xFFFF,0xFFFF,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [T]
0x0000,0x0000,0x0000,0x7C0F,0x7C0F,0x7C0F,0x7C0F,0x7C0F,0x7C0F,0x7C0F,0x7C0F,0x7C0F,0x7C0F,0x7C0F,0x7C0F,0x7C0F,0x3C1E,0x3C1E,0x3E3E,0x1FFC,0x07F0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [U]
0x0000,0x0000,0x0000,0xF007,0xF007,0xF807,0x780F,0x7C0F,0x3C1E,0x3C1E,0x3E1E,0x1E3C,0x1F3C,0x1F78,0x0F78,0x0FF8,0x07F0,0x07F0,0x07F0,0x03E0,0x03E0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [V]
0x0000,0x0000,0x0000,0xE003,0xF003,0xF003,0xF007,0xF3E7,0xF3E7,0xF3E7,0x73E7,0x7BF7,0x7FF7,0x7FFF,0x7F7F,0x7F7F,0x7F7E,0x3F7E,0x3E3E,0x3E3E,0x3E3E,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [W]
0x0000,0x0000,0x0000,0xF807,0x7C0F,0x3E1E,0x3E3E,0x1F3C,0x0FF8,0x07F0,0x07E0,0x03E0,0x03E0,0x07F0,0x0FF8,0x0F7C,0x1E7C,0x3C3E,0x781F,0x780F,0xF00F,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [X]
0x0000,0x0000,0x0000,0xF807,0x7807,0x7C0F,0x3C1E,0x3E1E,0x1F3C,0x0F78,0x0FF8,0x07F0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x03E0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [Y]
0x0000,0x0000,0x0000,0x7FFF,0x7FFF,0x000F,0x001F,0x003E,0x007C,0x00F8,0x00F0,0x01E0,0x03E0,0x07C0,0x0F80,0x0F00,0x1E00,0x3E00,0x7C00,0x7FFF,0x7FFF,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [Z]
0x07FF,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x07FF,0x07FF,0x0000, // Ascii = [[]
0x7800,0x7800,0x3C00,0x3C00,0x1E00,0x1E00,0x0F00,0x0F00,0x0780,0x0780,0x03C0,0x03C0,0x01E0,0x01E0,0x00F0,0x00F0,0x0078,0x0078,0x003C,0x003C,0x001E,0x001E,0x000F,0x000F,0x0007,0x0000, // Ascii = [\]
0x7FF0,0x00F0,0x00F0,0x00F0,0x00F0,0x00F0,0x00F0,0x00F0,0x00F0,0x00F0,0x00F0,0x00F0,0x00F0,0x00F0,0x00F0,0x00F0,0x00F0,0x00F0,0x00F0,0x00F0,0x00F0,0x00F0,0x00F0,0x7FF0,0x7FF0,0x0000, // Ascii = []]
0x00C0,0x01C0,0x01C0,0x03E0,0x03E0,0x07F0,0x07F0,0x0778,0x0F78,0x0F38,0x1E3C,0x1E3C,0x3C1E,0x3C1E,0x380F,0x780F,0x7807,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [^]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xFFFF,0xFFFF,0x0000,0x0000,0x0000, // Ascii = [_]
0x00F0,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [`]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0FF8,0x3FFC,0x3C7C,0x003E,0x003E,0x003E,0x07FE,0x1FFE,0x3E3E,0x7C3E,0x783E,0x7C3E,0x7C7E,0x3FFF,0x1FCF,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [a]
0x3C00,0x3C00,0x3C00,0x3C00,0x3C00,0x3C00,0x3DF8,0x3FFE,0x3F3E,0x3E1F,0x3C0F,0x3C0F,0x3C0F,0x3C0F,0x3C0F,0x3C0F,0x3C1F,0x3C1E,0x3F3E,0x3FFC,0x3BF0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [b]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x03FE,0x0FFF,0x1F87,0x3E00,0x3E00,0x3C00,0x7C00,0x7C00,0x7C00,0x3C00,0x3E00,0x3E00,0x1F87,0x0FFF,0x03FE,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [c]
0x001F,0x001F,0x001F,0x001F,0x001F,0x001F,0x07FF,0x1FFF,0x3E3F,0x3C1F,0x7C1F,0x7C1F,0x7C1F,0x781F,0x781F,0x7C1F,0x7C1F,0x3C3F,0x3E7F,0x1FFF,0x0FDF,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [d]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x03F8,0x0FFC,0x1F3E,0x3E1E,0x3C1F,0x7C1F,0x7FFF,0x7FFF,0x7C00,0x7C00,0x3C00,0x3E00,0x1F07,0x0FFF,0x03FE,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [e]
0x01FF,0x03E1,0x03C0,0x07C0,0x07C0,0x07C0,0x7FFF,0x7FFF,0x07C0,0x07C0,0x07C0,0x07C0,0x07C0,0x07C0,0x07C0,0x07C0,0x07C0,0x07C0,0x07C0,0x07C0,0x07C0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [f]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x07EF,0x1FFF,0x3E7F,0x3C1F,0x7C1F,0x7C1F,0x781F,0x781F,0x781F,0x7C1F,0x7C1F,0x3C3F,0x3E7F,0x1FFF,0x0FDF,0x001E,0x001E,0x001E,0x387C,0x3FF8, // Ascii = [g]
0x3C00,0x3C00,0x3C00,0x3C00,0x3C00,0x3C00,0x3DFC,0x3FFE,0x3F9E,0x3F1F,0x3E1F,0x3C1F,0x3C1F,0x3C1F,0x3C1F,0x3C1F,0x3C1F,0x3C1F,0x3C1F,0x3C1F,0x3C1F,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [h]
0x01F0,0x01F0,0x0000,0x0000,0x0000,0x0000,0x7FE0,0x7FE0,0x01E0,0x01E0,0x01E0,0x01E0,0x01E0,0x01E0,0x01E0,0x01E0,0x01E0,0x01E0,0x01E0,0x01E0,0x01E0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [i]
0x00F8,0x00F8,0x0000,0x0000,0x0000,0x0000,0x3FF8,0x3FF8,0x00F8,0x00F8,0x00F8,0x00F8,0x00F8,0x00F8,0x00F8,0x00F8,0x00F8,0x00F8,0x00F8,0x00F8,0x00F8,0x00F8,0x00F8,0x00F0,0x71F0,0x7FE0, // Ascii = [j]
0x3C00,0x3C00,0x3C00,0x3C00,0x3C00,0x3C00,0x3C1F,0x3C3E,0x3C7C,0x3CF8,0x3DF0,0x3DE0,0x3FC0,0x3FC0,0x3FE0,0x3DF0,0x3CF8,0x3C7C,0x3C3E,0x3C1F,0x3C1F,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [k]
0x7FF0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [l]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xF79E,0xFFFF,0xFFFF,0xFFFF,0xFBE7,0xF9E7,0xF1C7,0xF1C7,0xF1C7,0xF1C7,0xF1C7,0xF1C7,0xF1C7,0xF1C7,0xF1C7,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [m]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x3DFC,0x3FFE,0x3F9E,0x3F1F,0x3E1F,0x3C1F,0x3C1F,0x3C1F,0x3C1F,0x3C1F,0x3C1F,0x3C1F,0x3C1F,0x3C1F,0x3C1F,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [n]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x07F0,0x1FFC,0x3E3E,0x3C1F,0x7C1F,0x780F,0x780F,0x780F,0x780F,0x780F,0x7C1F,0x3C1F,0x3E3E,0x1FFC,0x07F0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [o]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x3DF8,0x3FFE,0x3F3E,0x3E1F,0x3C0F,0x3C0F,0x3C0F,0x3C0F,0x3C0F,0x3C0F,0x3C1F,0x3E1E,0x3F3E,0x3FFC,0x3FF8,0x3C00,0x3C00,0x3C00,0x3C00,0x3C00, // Ascii = [p]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x07EE,0x1FFE,0x3E7E,0x3C1E,0x7C1E,0x781E,0x781E,0x781E,0x781E,0x781E,0x7C1E,0x7C3E,0x3E7E,0x1FFE,0x0FDE,0x001E,0x001E,0x001E,0x001E,0x001E, // Ascii = [q]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x1F7F,0x1FFF,0x1FE7,0x1FC7,0x1F87,0x1F00,0x1F00,0x1F00,0x1F00,0x1F00,0x1F00,0x1F00,0x1F00,0x1F00,0x1F00,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [r]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x07FC,0x1FFE,0x1E0E,0x3E00,0x3E00,0x3F00,0x1FE0,0x07FC,0x00FE,0x003E,0x001E,0x001E,0x3C3E,0x3FFC,0x1FF0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [s]
0x0000,0x0000,0x0000,0x0780,0x0780,0x0780,0x7FFF,0x7FFF,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x0780,0x07C0,0x03FF,0x01FF,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [t]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x3C1E,0x3C1E,0x3C1E,0x3C1E,0x3C1E,0x3C1E,0x3C1E,0x3C1E,0x3C1E,0x3C1E,0x3C3E,0x3C7E,0x3EFE,0x1FFE,0x0FDE,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [u]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xF007,0x780F,0x780F,0x3C1E,0x3C1E,0x3E1E,0x1E3C,0x1E3C,0x0F78,0x0F78,0x0FF0,0x07F0,0x07F0,0x03E0,0x03E0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [v]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xF003,0xF1E3,0xF3E3,0xF3E7,0xF3F7,0xF3F7,0x7FF7,0x7F77,0x7F7F,0x7F7F,0x7F7F,0x3E3E,0x3E3E,0x3E3E,0x3E3E,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [w]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x7C0F,0x3E1E,0x3E3C,0x1F3C,0x0FF8,0x07F0,0x07F0,0x03E0,0x07F0,0x07F8,0x0FF8,0x1E7C,0x3E3E,0x3C1F,0x781F,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [x]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xF807,0x780F,0x7C0F,0x3C1E,0x3C1E,0x1E3C,0x1E3C,0x1F3C,0x0F78,0x0FF8,0x07F0,0x07F0,0x03E0,0x03E0,0x03C0,0x03C0,0x03C0,0x0780,0x0F80,0x7F00, // Ascii = [y]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x3FFF,0x3FFF,0x001F,0x003E,0x007C,0x00F8,0x01F0,0x03E0,0x07C0,0x0F80,0x1F00,0x1E00,0x3C00,0x7FFF,0x7FFF,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [z]
0x01FE,0x03E0,0x03C0,0x03C0,0x03C0,0x03C0,0x01E0,0x01E0,0x01E0,0x01C0,0x03C0,0x3F80,0x3F80,0x03C0,0x01C0,0x01E0,0x01E0,0x01E0,0x03C0,0x03C0,0x03C0,0x03C0,0x03E0,0x01FE,0x007E,0x0000, // Ascii = [{]
0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x01C0,0x0000, // Ascii = [|]
0x3FC0,0x03E0,0x01E0,0x01E0,0x01E0,0x01E0,0x01C0,0x03C0,0x03C0,0x01C0,0x01E0,0x00FE,0x00FE,0x01E0,0x01C0,0x03C0,0x03C0,0x01C0,0x01E0,0x01E0,0x01E0,0x01E0,0x03E0,0x3FC0,0x3F00,0x0000, // Ascii = [}]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x3F07,0x7FC7,0x73E7,0xF1FF,0xF07E,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [~]
};

FontDef Font_11x18 = {11,18,Font11x18};
FontDef Font_16x26 = {16,26,Font16x26};


