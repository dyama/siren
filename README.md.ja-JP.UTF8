 siren - 簡易 CAD ビューア
============================================================

 siren とは
------------------------------------------------------------

siren は、Microsoft Windows 向けの簡易 CAD ビューアです。
便利な機能や簡単な操作を提供します。

 ビルド方法
------------------------------------------------------------

ビルド環境:

* Open CASCADE 6.6.0
* Microsoft Visual Studio 2008

1. 次のように siren の Git リポジトリから clone します。

    git clone https//:github.com/dyama/siren.git

2. 環境に合わせてバッチファイルを修正します。

    editor tool/occenv.bat
    
    SET "OCCBASE=E:\\occ" # Change this variable!
    
例えば、Open CASCADE 6.6.0 が C:\opencascade\660 に
インストールされている場合、
    
    SET "OCCBASE=C:\\opencascade"
    
パスに含まれるバージョン文字列の「660」は、スクリプトによって
自動的に追加されます。
お使いの環境がこのケースに当てはまらない場合は、シンボリック
リンクなどをご利用ください。

同様に

    editor tool/mruby-vs9-occ660.bat

    SET "MRUBYROOT=%SCRIPTPATH%\..\..\mruby_w32"

環境変数 MRUBYROOT を mruby のインストールパスに設定します。

3. 次のようにバッチファイルを実行します。

    start tool/mruby-vs9-occ660.bat

違う環境でビルドする場合、適宜バッチファイルの内容を書き換え
て利用することができます。

4. sirenenv.dll と siren.exe をビルドします。

 機能概要
------------------------------------------------------------

* マウス操作による三次元モデルの表示。
* ファイル形式の変換機能。

 使い方
------------------------------------------------------------

次のように実行します。

    > siren.exe [filename]

現在、読み込むことができるファイル形式は次のとおりです。

* IGES 形式
* OpenCASCADE BREP 形式
* STEP 形式
* CSFDB 形式

 サードパーティ・ライブラリ
------------------------------------------------------------

* Open CASCADE Technorogy by Open CASCADE S.A.S.
* ISO C9x compliant stdint.h for Visual Studio by Alexander Chemeris.
* mruby by Ruby Association

 ライセンス
------------------------------------------------------------

MIT ライセンス

 作者
------------------------------------------------------------
メイン メンテナー:
    dyama, Daisuke YAMAGUCHI <dyama@member.fsf.org>

デバッグ・サブメンテナー:
    kuyon

