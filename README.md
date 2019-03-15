# asos
30日でできる！OS自作入門による、自作OS:ASOSの開発

## 0日目
読みました。

## 1日目
参考

http://hrb.osask.jp/

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

これを使えばnaskをNASMに書き換えることなく本書と同等のことができる。Makefileを`.exe`消したり`del`を`rm`に書き直すなどで`make run`を実行できるようになる。

https://github.com/HariboteOS/z_tools_osx

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
    * terminalのgitのcommiterがなぜか違うメールアドレスとユーザ名になっておりそれを以下で訂正
    * `git config --global user.email "hoge@mail"`
    * `git config --global user.name "hogename"`
    * gitignoreの作成
        * https://qiita.com/anqooqie/items/110957797b3d5280c44f

先駆者のMac, Linux翻訳がすごい...。

## 3日目
Makefileの翻訳で終わった。C言語でOSを書けるようになったらしい。

* できたこと
    * 変数付きMakefileのMac化
        * `.exe`消す
        * `-$(DEL)`の`-`を消す
        * `copy`を`cp`
        * `del`を`rm -f`
        * `cc1`を`gocc1`
        * `cp /B asmhead.bin+bootpack.hrb haribote.sys`
        * `cat asmhead.bin bootpack.hrb > haribote.sys`
        * フォルダ名`z_tools_osx`ってしていたけれどこれ`z_tools`にしなきゃダメだった
    * 真っ黒画面表示
* できなかった
* 得たこと
    * NASM命令
        * JC
        * JNC
        * JAE
        * JBE
        * EQU
        * 三重ループ
    * BIOSとはBasic Input Output SystemでOS製作者がよく使いそうなプログラムをPCメーカが用意したもの(2-2より)
    * VRAMはそれぞれの番地が画面上の画素に対応していて、画面に絵を出すことができるklasdkf

## 4日目
参考
* できたこと
* できなかった
* 得たこと
    * 関数のn番目の引数は[ESP+4n]にある
    * 16ビットレジスタを使うとき[CX]とかできないのに32ビットレジスタは[ECX]とかOK
    * C言語と連携する場合は、EAX, ECX, EDXのみ自由に使ってよくて、他は大事な値があって変更しちゃいけない
    * CPUは古い順に8086 -> 286 -(ここから32bit)-> 386 -> 486 -> Pentium


## n日目
参考
* できたこと
* できなかった
* 得たこと

## 30日OSあるある
* Windowsなの...?
* LinuxやMacでやった先駆者に感心する
* なんで\が¥じゃないと動作しないんだろうって思ったらShift-JIS

## 今後

読みたい
https://adventar.org/calendars/1666
