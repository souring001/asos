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

* できたこと
    * nasmで`helloos.nas`をアセンブル
        * 参考: https://admarimoin.hatenablog.com/entry/2018/09/03/225406
* できなかった
* 得たこと

## 今後

読みたい
https://adventar.org/calendars/1666
