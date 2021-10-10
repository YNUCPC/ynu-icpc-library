# Contribution Guide

このライブラリを管理するためのガイドです。

## 準備

このライブラリはC++及びLaTeXで構成されています．また、GitHubで管理するためGitを利用しています。
そのため、これらを実行できる環境を構築してください。

また、LaTeXで`jlisting.sty`パッケージを利用しているため追加する必要があります。([参考](https://qiita.com/ocian/items/28bbbec6c44b9b6b44c4))

## 追加・修正の送り方

簡単な誤字程度であればGitHub上で直接修正することも可能です。

ローカルで作業する場合は基本的に以下の手順で行います。

1. ローカルにClone/Pullする
1. `develop`ブランチに移動する (`git checkout develop`)
1. 作業用のBranchをつくる (例： `git checkout -b add-new-algrithm`)
1. ライブラリの追加・修正を行う
1. 変更をPushする
1. Pull Requestを送る
1. ReviewしてMergeする

## 変更の確認方法

ドキュメントはLaTeXで作成されています。そのため、PDFにコンパイルすることで内容を確認できます。
コンパイルの設定は`.latexmkrc`に記述されているため、以下の`latexmk`コマンドでコンパイルできます。
手動でコンパイルする場合は`platex`で複数回コンパイルします。

```bash
latexmk main.tex
```

## ライブラリの追加方法

ライブラリの追加は基本的に以下の手順で行います。

また、追加するファイル名は`src/`以下と`docs/`以下で対応するようにしてください。

1. `src/<hoge>/<fuga>.hpp`を作成する

    ソースコードを記述したファイルを作成します。
    テスト（予定）のためインクルードガードを書いてください。
    詳細な命名規則は[こちら](#C++スタイルガイド)を参考にしてください。

    ```c++
    #pragma once
    #include "template.hpp"

    struct Fuga{
        ...
    };
    ```

1. `docs/<hoge>/<fuga>.tex`を作成する

    ドキュメントの内容をここに書きます。

    ```latex
    \subsection{Fuga}

    % ここに使い方や計算量を書く

    \lstinputlisting{src/<hoge>/<fuga>.hpp}
    ```

1. `docs/<hoge>.tex`に追記する

    `\input{}`コマンドで先ほど追加したドキュメントを追加します。

    ```latex
    \section{Hoge}

    ...
    \input{docs/<hoge>/<fuga>.tex}
    ```

## C++スタイルガイド

ライブラリ全体で読みやすさと統一感を持たせるためのガイドです。

### 命名規則

- 分かりやすい名前にする
- 省略形は競技プログラミングの文脈で広く使われているものの範囲にする

|項目|つづり方|記号|例|
|:-:|:-:|:-:|:-:|
| ファイル名 |snake_case|`_`|`hoge_fuga.hpp`, `hogefuga.hpp`|
| クラス名   |PascalCase|なし|`HogeFuga`|
| 変数名     |snake_case|`_`|`hoge_fuga`, `hogefuga`|
| 関数名     |snake_case|`_`|`hoge_fuga()`|
| 定数       |すべて大文字|`_`|`HOGE_FUGA`|

### コードスタイル

コードスタイルを統一するために`clang-format`でフォーマットします。ソースコードが書き終わったらこれをしておきましょう。
設定は`.clang-format`に記述されています。

VS Codeであれば、`Shift + Alt + F`でフォーマットできます。

### その他

標準的な競技プログラミングライブラリとして[AtCoder Library](https://github.com/atcoder/ac-library)を参考にしているため、実装方法や機能をこちらに合わせると良いと思います。

## Issue

「このような修正/改善はどうでしょう？」という疑問がある場合は、Issueを立てて相談してください。

- 誤字の修正
- ソースコード・命名の変更
- 説明の改善
- ライブラリ運営について

## Pull Request

大丈夫そうならMergeして変更を反映します

## Review

### レビュー後にやること

- 作業用ブランチを削除します。
