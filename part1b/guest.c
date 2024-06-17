#include <stddef.h>
#include <stdint.h>

static char helper1[100];
static char helper2[100];
uint32_t count = 0;

static void outb(uint16_t port, uint8_t value) {
	asm("outb %0,%1" :: "a" (value), "Nd" (port));
}

static void outInt(uint16_t port, uint32_t value) {
	asm("out %0,%1" :: "a" (value), "Nd" (port));
}

static uint32_t inExit(uint16_t port) {
	uint32_t no_of_exits;
	asm("in %1, %0" : "=a"(no_of_exits) : "Nd"(port) : "memory" );
	return no_of_exits;
}

char* inExitType(uint16_t port, char *answer) {
	// char *answer = "";
	uint32_t distance = answer - (char *)NULL;
	asm("out %0,%1" : /* empty */ : "a" (distance), "Nd" (port) : "memory");
	return answer;
}

void HC_print8bit(uint8_t val)
{
	outb(0xE9, val);
}

void HC_print32bit(uint32_t val)
{
	outInt(0xEA, val);
}

uint32_t HC_numExits()
{
	uint32_t numExits = inExit(0xEB);
	return numExits;
}

void HC_printStr(char *str)
{
	uint32_t distance = str - (char *)NULL; // the distance b/w two addresses str and null(0)
	outInt(0xEC, distance);
}

char *HC_numExitsByType()
{
	char *str = "";
	str = inExitType(0xED, str);
	if(count == 0){
		int i = 0;
		while(str[i] != '\0'){
			helper1[i] = str[i];
			i++;
		}
		count = 1;
		return helper1;
	}
	else return str;
}

uint32_t HC_gvaToHva(uint32_t gva)
{
	outInt(0xEE, gva);
	return inExit(0xEE);
}

void
__attribute__((noreturn))
__attribute__((section(".start")))
_start(void) {
	const char *p;

	for (p = "Hello 695!\n"; *p; ++p){
		HC_print8bit(*p);
	}
		


	/*----------Don't modify this section. We will use grading script---------*/
	/*---Your submission will fail the testcases if you modify this section---*/
	HC_print32bit(2048);
	HC_print32bit(4294967295);

	uint32_t num_exits_a, num_exits_b;
	num_exits_a = HC_numExits();

	char *str = "CS695 Assignment 2\n";
	HC_printStr(str);

	num_exits_b = HC_numExits();

	HC_print32bit(num_exits_a);
	HC_print32bit(num_exits_b);

	char *firststr = HC_numExitsByType();
	uint32_t hva;
	hva = HC_gvaToHva(1024);
	HC_print32bit(hva);
	hva = HC_gvaToHva(4294967295);
	HC_print32bit(hva);
	char *secondstr = HC_numExitsByType();

	HC_printStr(firststr);
	HC_printStr(secondstr);
	/*------------------------------------------------------------------------*/

	*(long *) 0x400 = 42;

	for (;;)
		asm("hlt" : /* empty */ : "a" (42) : "memory");
}
