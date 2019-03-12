TOOLPATH = ../z_tools_osx/
MAKE     = $(TOOLPATH)make -r
NASK     = $(TOOLPATH)nask
EDIMG    = $(TOOLPATH)edimg
IMGTOL   = $(TOOLPATH)imgtol.com
COPY     = cp
DEL      = rm -f

# デフォルト動作

default :
	$(MAKE) img

# ファイル生成規則

ipl.bin : ipl.nas Makefile
	$(NASK) ipl.nas ipl.bin ipl.lst

haribote.img : ipl.bin Makefile
	$(EDIMG)   imgin:../z_tools_osx/fdimg0at.tek \
		wbinimg src:ipl.bin len:512 from:0 to:0   imgout:haribote.img

# コマンド

asm :
	$(MAKE) ipl.bin

img :
	$(MAKE) haribote.img

run :
	$(MAKE) img
	$(COPY) haribote.img ../z_tools_osx/qemu/fdimage0.bin
	$(MAKE) -C ../z_tools_osx/qemu

install :
	$(MAKE) img
	$(IMGTOL) w a: haribote.img

clean :
	$(DEL) ipl.bin
	$(DEL) ipl.lst

src_only :
	$(MAKE) clean
	$(DEL) haribote.img
