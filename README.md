# asos
30日でできる！OS自作入門による、自作OS:ASOSの開発

## 0日目
読みました。

## 1日目
* できたこと
    * バイナリエディタで地道にhelloos.imgを作る
    * cmpコマンドで正解と等しいことを確認
    * `helloos2.nas`の理解
* できなかった
    * フロッピーディスクからhelloOSの起動
    * アセンブラの記述・実行
* 得たこと
    * NASMのアセンブリ命令
        * DB 1バイト書く
        * RESB nバイト0を書く
        * DW 2バイト書く
        * DD 4バイト書く

Macではどうしたらいいんだろう、サポートのURLのリンク切れてるし。
Linuxでやるか？

## 2日目
Macでするなら以下のコマンド

アセンブル

`nasm -o helloos.img helloos.nas`

qemuでブート

`qemu-system-i386 -drive file=helloos.img,format=raw,if=floppy`

参考

http://oswiki.osask.jp/?(AT)memorymap

http://hrb.osask.jp/wiki/?tools/nask

https://hikalium.com/page/note/20161202.md

* できたこと
    * nasmで`helloos.nas`をアセンブル
    * qemuで`helloos.img`を起動
        * https://admarimoin.hatenablog.com/entry/2018/09/03/225406
* できなかった
    * Mac環境におけるMakefileの作り方
* 得たこと
    * naskとNASMの違い
    * $$はセクションの最初が何バイト目か
    * $はこの行の最初が何バイト目か
    * $-$$で先頭から何バイト目かを表す
    * NASM命令
        * ORG
        * MOV
        * CMP
        * JE
        * INT
        * HLT    
    * レジスタの仕組み
        * HとLに分けられる(AX,CX,DX,BX)
        * 番地の指定に使えるレジスタは限られている(BX,BP,SI,DI)
    * BIOSのビデオカードで文字を表示している
    * Makefileの仕組み
        * 必要なものだけ作り直してくれる
        * 特に指定しない場合は一番上のものを実行
        * http://shin.hateblo.jp/entry/2012/05/26/231036
    * gitの名前が違くて別人がcommitしたことになってることに気づく

## n日目
参考
* できたこと
* できなかった
* 得たこと

## 30日OSあるある
* Windowsなの...?

## 今後

読みたい
https://adventar.org/calendars/1666
