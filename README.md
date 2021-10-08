# YNU ICPC Library

横浜国立大学競技プログラミング部のICPC用のライブラリです。

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

## コンパイル

パッケージ`jlisting.sty`を追加する。([参考](https://qiita.com/ocian/items/28bbbec6c44b9b6b44c4))

以下のコマンドでPDFを生成できる。
```bash
latexmk main.tex
```
