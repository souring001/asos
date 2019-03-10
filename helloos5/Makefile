# デフォルト動作

default :
	../z_tools_osx/make img

# ファイル生成規則

ipl.bin : ipl.nas Makefile
	../z_tools_osx/nask ipl.nas ipl.bin ipl.lst

helloos.img : ipl.bin Makefile
	../z_tools_osx/edimg   imgin:../z_tools_osx/fdimg0at.tek \
	wbinimg src:ipl.bin len:512 from:0 to:0   imgout:helloos.img

# コマンド

asm :
	../z_tools_osx/make -r ipl.bin

img :
	../z_tools_osx/make -r helloos.img

run :
	../z_tools_osx/make img
	cp helloos.img ../z_tools_osx/qemu/fdimage0.bin
	../z_tools_osx/make -C ../z_tools_osx/qemu

#フロッピーディスクに書き込み
install :
	../z_tools_osx/make img
	../z_tools_osx/imgtol.com w a: helloos.img

clean :
	rm -f ipl.bin
	rm -f ipl.lst

src_only :
	../z_tools_osx/make clean
	rm -f helloos.img
