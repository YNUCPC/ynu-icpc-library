# YNU ICPC Library

横浜国立大学競技プログラミング部のICPC用のライブラリです。

## 方針

このライブラリはICPC大会において手写しでライブラリを利用することを前提として作成します。

そのため、次の項目を目標とします。

- 手写しが容易な実装
- 競技プログラミングにおける利便性
- アルゴリズムの充実

一方で、この目標のため次のようなことを行う可能性があります。（要検討）

- とりあえず`long long`を使う
- コンパイル最適化のための指定子などを省略する
- ...

また、標準的な競技プログラミングのライブラリとして[AtCoder Library](https://github.com/atcoder/ac-library)を参考にします。

## ドキュメント生成

ドキュメントはLaTeXで書かれているため、PDFの生成にはLaTeX環境が必要です。
また、`jlisting.sty`パッケージを利用しているため追加する必要があります。([参考](https://qiita.com/ocian/items/28bbbec6c44b9b6b44c4))

以下のコマンドでPDFにコンパイルできます。

```bash
latexmk main.tex
```

## ライブラリの追加方法

1. `src/<hoge>/<fuga>.hpp`を作成

    ここにソースコードを書く。

    ```c++
    #pragma once
    #include "template.hpp"

    struct Fuga{
        ...
    };
    ```

1. `docs/<hoge>/<fuga>.tex`を作成

    ドキュメントの内容をここに書く。

    ```latex
    \subsection{Fuga}

    % ここに使い方や計算量を書く

    \lstinputlisting{src/<hoge>/<fuga>.hpp}
    ```

1. `docs/<hoge>.tex`に追記

    ```latex
    \section{Hoge}

    ...
    \input{docs/<hoge>/<fuga>.tex}
    ```
