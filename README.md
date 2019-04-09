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

https://hikalium.com/pages/note/20161202.html

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

VGAのページ http://oswiki.osask.jp/?VGA

* できたこと
    * 白い画面表示
    * しましま表示
    * しましま表示 〜番地変数(ポインタ)を使って〜
    * カラーモードの色番号の指定
    * 四角形の描画
* 得たこと
    * 関数のn番目の引数は[ESP+4n]にある
    * 16ビットレジスタを使うとき[CX]とかできないのに32ビットレジスタは[ECX]とかOK
    * C言語と連携する場合は、EAX, ECX, EDXのみ自由に使ってよくて、他は大事な値があって変更しちゃいけない
    * CPUは古い順に8086 -> 286 -(ここから32bit)-> 386 -> 486 -> Pentium
    * for文はifとgotoで書ける
    * ポインタの型宣言はメモリ番地変数だった
    * `p[i] = *(p+i) = *(i+p) = i[p]`
    * static宣言はMOV命令でなくDB命令を使うのでバイト数を節約できる
    * NASM命令
        * CLI
        * STI
        * PUSHFD
        * POPFD
    * EFLAGSレジスタにはキャリーフラグや割り込みフラグがある
    * C言語ではRETした時にEAXに入っていた値が関数の値となる
* 疑問
    * `set_palette`で`rgb[0]/4`と4で割る理由がわからない、6ビットにする必要があるの？

## 5日目
* できたこと
    * 構造体を使って`asmhead.nas`の情報をC言語で取得
    * `A`の表示
    * フォントファイルのリンク
    * マウスカーソルの表示
* 得たこと
    * extern宣言でソースプログラム以外で準備したデータを扱える
    * `sprintf`でメモリに文字列書き出せる
    * セグメンテーションとはメモリを分割してそれぞれのブロックの最初の番地を0として扱う機能
    * GDT: セグメント記述子表
    * IDT: 割り込み記述子表
* 疑問
    * メインの名前が`HariMain`でないとコンパイルされない、コンパイラがそう設定してる？

## 6日目
参考

Makefile覚書　https://qiita.com/Shigets/items/27170827707e5136ee89
* できたこと
    * ソースファイル`bootpack.c`の分割
    * Makefileに一般規則を追加
    * ヘッダファイル`bootpack.h`の追加
    * PIC初期化`int.c`
    * 割り込みハンドラ作成
    * `io_sti()`で割り込み許可してる
* 得たこと
    * ソースファイル分割のメリット
        * 変更する時に目的の場所を探しやすい
        * 書き換えたファイルのみがコンパイルされるので、makeが速くなる
    * Makefileでの一般規則
        * `%`: パターンルール内でワイルドカードのようなもの
        * `$*`: ターゲットファイルの拡張子を除いた名前
        ```
        %.gas : %.c Makefile
        	$(CC1) -o $*.gas $*.c
        ```
    * `#include "..."`はソースファイルと同じフォルダにある場合
    * `#include <...>`はコンパイラにおまけでついてくるフォルダにある場合
    * ヘッダファイル追加してもMakefile変更しなくて大丈夫だった
    * GDTレジスタ
        * セグメントのベース番地
        * リミット
        * セグメント属性(セグメントのアクセス権)
    * PIC(programmable interrupt controller)
        * 割り込みを監視するためのチップ
        * 割り込み信号をマスタとスレーブで15個扱える
        * PICにはレジスタがある
            * IMR
            * ICW
    * 割り込みハンドラはレジスタを割り込み前の状態に戻すために`PUSHAD`でスタックに全部レジスタを詰め込む
    * IMR(inturrupt mask register)
    * ICW(initial control word)
    * NASM命令
        * IRETD
        * CALL
        * PUSHAD
* 疑問
    * IMRとICWがよくわかってない
    * 以下でキーボードとマウスが許可される理由
    ```c    
    io_out8(PIC0_IMR, 0xf9); /* PIC1とキーボードを許可(11111001) */
	io_out8(PIC1_IMR, 0xef); /* マウスを許可(11101111) */
    ```

## 7日目
参考

http://oswiki.osask.jp/?(PIC)8259A

http://oswiki.osask.jp/?(AT)keyboard

* できたこと
    * キーコードの取得
    * FIFO構造体の作成
* 得たこと
    * 割り込み処理は手早く
    * `io_stihlt`の存在価値は、STI命令の後にHLTした場合はこの間に割り込みを受け付けないから
    * NASM命令
        * NOP: 何もしない、1クロック休憩
* 疑問

## 8日目
参考
* できたこと
    * マウスのデータ解読
    * マウスを動かす
* 得たこと
    * データがずれてもしばらくしたら直るようにチェック
    * `asmhead.nas`の解説
    * NASM命令
        * LGDT: GDTやIDTにロードする？
        * SHR: 右シフト 2のべき乗で割るのと同じ
        * JZ: 直前の計算結果が0ならジャンプ
        * JNZ: 0じゃなければジャンプ
        * ALIGMB: 切りが良くなるまでDB 0を入れなさい
    * CR0(コントロールレジスタ0): OS以外がいじっては行けないレジスタ
    * プロテクトモードに切り替えた場合すぐにJMPを実行するのはパイプラインの解釈をリセットするため
    * メモリマップ一覧あり
        * メモリマップを最初に作っておくと順調にOSを作っていくことができる
* 疑問
    * どのタイミングで割り込みが発生してそのデータを`mouse_decode`へ渡されるのか
        * 割り込みまくったらマウスのデータ消えない？
    * CSってなんだっけ

## 9日目
参考
* できたこと
* 得たこと
* 疑問

## n日目
参考
* できたこと
* 得たこと
* 疑問

## NASM命令一覧
|命令|内容|
|:-:|:-:|
|SHR| 右シフト 2のべき乗で割るのと同じ|

## 30日OSあるある
* Windowsなの...?
* LinuxやMacでやった先駆者に感心する
* なんで\が¥じゃないと動作しないんだろうって思ったらShift-JISだった
* マウス動かせるまでに3日もかかるんかい
* GDTレジスタが現れたあたりから図を描かないと理解できなくなってくる

## 今後
* Makefileをグラフ化
    * Graphvizとかでできるみたい

* 昔のOSXみたいなの再現したいな

* 読みたい https://adventar.org/calendars/1666

* PCを自作してみた動画、OS、コンパイラ、CPUから作ってみたいもの

* 「CPUの創りかた」を読む
