/*
    @file   LinkerScript.ld
    @author Mohamed Tarek
    @brief  Linker script for STM32F401RCT6 Device from STM32F4 series
*/
MEMORY
{
    FLASH (xr) : ORIGIN = 0x0800 0000, LENGTH = 256K
    SRAM  (xwr): ORIGIN = 0x2000 0000, LENGTH = 64K
}

SECTIONS
{
    .isr_vector :
    {
	. = ALIGN(4);
	*(.isr_vector)
	*(.isr_vector*)
	* = ALIGN(4);
    } > FLASH

    .text :
    {
	. = ALIGN(4);
	*(.text)
	*(.text*)
	. = ALIGN(4);
    }>FLASH

    .rodata :
    {
	. = ALIGN(4);
	*(.rodata)
	*(.rodata*)
	. = ALIGN(4);
    }>FLASH
   
    _sidata = LOADDR(.data);

    .data :
    {
	_sdata = .;
	. = ALIGN(4);
	*(.data)
	*(.data*)
	. = ALIGN(4);
	_.edata = .;
    }>SRAM AT > FLASH

    .bss :
    {
	_sbss = .;
   	. = ALIGN(4);
	*(.bss)
	*(.bss*)
	. = ALIGN(4);
	_ebss = .;
    }>FLASH
    ._user_heap_stack :
    {
    	. = ALIGN(8);
   	. = . + _Min_Heap_Size;
    	. = . + _Min_Stack_Size;
    	. = ALIGN(8);
    } >RAM

}