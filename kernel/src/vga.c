#include "kernel/vga.h"

vga_entry_t format_vga_entry(vga_color_t fg, vga_color_t bg, unsigned char c) {
    return (uint16_t)fg << 8 | (uint16_t)bg << 12 | (uint16_t)c;
}

void vga_put_char(vga_entry_t entry, size_t row, size_t column) {
	uint16_t* ptr = (uint16_t*)VGA_TEXT_BUFFER;
	ptr[row * VGA_TEXT_WIDTH + column] = entry;
}

void vga_clear_textbuf_color(vga_color_t color) {
	vga_entry_t entry = format_vga_entry(color, color, ' ');
	uint16_t* ptr = (uint16_t*)VGA_TEXT_BUFFER;

	for (size_t i = 0; i < VGA_TEXT_HEIGHT; i++)
	{
		for (size_t j = 0; j < VGA_TEXT_WIDTH; j++)
		{
			ptr[i * VGA_TEXT_WIDTH + j] = entry;
		}
	}
}

void vga_clear_textbuf() {
	vga_clear_textbuf_color(VGA_COLOR_BLACK);
}

