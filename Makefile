CC=C:\Users\Hamid.Kisha\avrGcc\bin\avr-g++
LD=C:\Users\Hamid.Kisha\avrGcc\bin\avr-ld
OBJCOPY="C:\Users\Hamid.Kisha\avrGcc\bin\avr-objcopy"
OBJDUMP="C:\Users\Hamid.Kisha\avrGcc\bin\avr-objdump"
AVRSIZE="C:\Users\Hamid.Kisha\avrGcc\bin\avr-size"
OBJISP="C:\Users\Hamid.Kisha\avrGcc\bin\avrdude"
MCU=atmega328p
CFLAGS=-Wall -Wextra  -Wundef -pedantic \
		-Os -std=gnu99 -DF_CPU=16000000UL -mmcu=${MCU} -DBAUD=19200
LDFLAGS=-mmcu=$(MCU)
PORT=\\\\.\\COM3
BIN=avrdemo
OUT=${BIN}.hex
SOURCES = main.cpp lcd.cpp Billboard.cpp Customer.cpp Advertisement.cpp

DEBUG?=1

ifeq ($(DEBUG), 1)
	OUTPUTDIR=bin/debug
else
	OUTPUTDIR=bin/release
endif

OBJS =  $(addprefix $(OUTPUTDIR)/,$(SOURCES:.cpp=.o))

all: $(OUTPUTDIR)  $(OUT) 

$(OBJS): Makefile

$(OUTPUTDIR)/%.o:%.cpp
	$(CC) $(CFLAGS) -MD -o $@ -c $<

%.lss: %.elf
	$(OBJDUMP) -h -S -s $< > $@

%.elf: $(OBJS)
	$(CC) -Wl,-Map=$(@:.elf=.map) $(LDFLAGS) -o $@ $^
	$(AVRSIZE) $@


$(OBJS):$(SOURCES)

%.hex: %.elf
	$(OBJCOPY) -O ihex -R .fuse -R .lock -R .user_signatures -R .comment $< $@

isp: ${BIN}.hex
	$(OBJISP) -F -V -c arduino -p ${MCU} -P ${PORT} -U flash:w:$<


clean:
	del "$(OUT)"  *.map *.P *.d

$(OUTPUTDIR): 
	@mkdir "$(OUTPUTDIR)"
		   	
.PHONY: clean dirs
