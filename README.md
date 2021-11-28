# YNU ICPC Library

[![verify](https://github.com/YNUCPC/ynu-icpc-library/actions/workflows/verify.yml/badge.svg)](https://github.com/YNUCPC/ynu-icpc-library/actions/workflows/verify.yml) [![make PDF](https://github.com/YNUCPC/ynu-icpc-library/actions/workflows/make_pdf.yml/badge.svg)](https://github.com/YNUCPC/ynu-icpc-library/actions/workflows/make_pdf.yml)
[![MIT](https://img.shields.io/github/license/YNUCPC/ynu-icpc-library)](https://github.com/YNUCPC/ynu-icpc-library/blob/main/LICENSE)

横浜国立大学競技プログラミング部のICPC用のライブラリです。

ライブラリの内容は以下のリンクから参照できます。

- [YNU ICPC Library (PDF, 縦1段組ver)](https://ynucpc.github.io/ynu-icpc-library/main_1col.pdf)
- [YNU ICPC Library (PDF, 横2段組ver)](https://ynucpc.github.io/ynu-icpc-library/main_2col.pdf)

## ライブラリの方向性

このライブラリはICPC形式のコンテストにおいて利用しやすくするため、手写しが容易なアルゴリズム実装を目指しています。そのため、実装が複雑になる過度な一般化や高速化は行っていません。
また、アルゴリズムの正確さと実行速度を保証するため、[verification-helper](https://github.com/online-judge-tools/verification-helper) を使用したテストを行っています。

一方で、簡単なアルゴリズム(Dijkstra法、Kraskal法等)は紙面の都合上、ライブラリには載せない方針です。

## ドキュメント生成

ドキュメントはLaTeXで書かれているため、PDFの生成にはLaTeX環境が必要です。
また、`jlisting.sty`パッケージを利用しているため追加する必要があります。([参考](https://qiita.com/ocian/items/28bbbec6c44b9b6b44c4))

以下のコマンドでPDFにコンパイルできます。

```bash
latexmk main.tex
```

## ライブラリ開発

このライブラリは横浜国立大学競技プログラミング部によって開発されています。

開発ガイドは [CONTRIBUTING.md](https://github.com/YNUCPC/ynu-icpc-library/blob/main/CONTRIBUTING.md) を参照してください。

## License

YNU ICPC Library は、[MIT License](https://opensource.org/licenses/MIT) のもとで公開されています。
ただし、プログラミングコンテストや Online Judge のジャッジサーバーに提出する目的でこのライブラリを使用する場合は、提出物に著作権表示や許諾表示をすることなく、このライブラリを使用することができます。
ライセンス全文は [LICENSE](https://github.com/YNUCPC/ynu-icpc-library/blob/main/LICENSE) を参照してください。

YNU ICPC Library is licensed under the [MIT License](https://opensource.org/licenses/MIT).
However, you can use this library for submission to the judge server of a programming contest or online judges without any copyright or permission notices on your submission.
See [LICENSE](https://github.com/YNUCPC/ynu-icpc-library/blob/main/LICENSE) for the full license text.
