 siren - 簡易 CAD ビューア
============================================================

 siren とは
------------------------------------------------------------

siren は、Microsoft Windows 向けの簡易 CAD ビューアです。
便利な機能や簡単な操作を提供します。

 ビルド方法
------------------------------------------------------------

ビルド環境:

* Open CASCADE 6.7.0
* Microsoft Visual Studio 2008

1. 次のように siren の Git リポジトリから clone します。

    git clone https//:github.com/dyama/siren.git

2. 環境に合わせて tool ディレクトリ内のバッチファイルを修正し
ます。(OCCTとMRUBYのインストールパスを設定してください。)

3. バッチファイルを実行します。

4. Visual Studio で sirenenv.dll と siren.exe をビルドします。

 機能概要
------------------------------------------------------------

* マウス操作による三次元モデルの表示。
* コマンドによるモデルの作成、編集。
* 各種ファイル形式の読み込みと保存。

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

