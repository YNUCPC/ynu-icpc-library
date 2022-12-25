# YNU ICPC Library

[![verify](https://github.com/YNUCPC/ynu-icpc-library/actions/workflows/verify.yml/badge.svg)](https://github.com/YNUCPC/ynu-icpc-library/actions/workflows/verify.yml)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://ynucpc.github.io/ynu-icpc-library)
[![MIT](https://img.shields.io/github/license/YNUCPC/ynu-icpc-library)](https://github.com/YNUCPC/ynu-icpc-library/blob/main/LICENSE)

横浜国立大学競技プログラミング部のICPC用のライブラリです。

ライブラリの内容は以下のリンクから参照できます。

- [YNU ICPC Library (PDF, 縦1段組ver)](https://github.com/YNUCPC/ynu-icpc-library/blob/main/main_1col.pdf)
- [YNU ICPC Library (PDF, 横2段組ver)](https://github.com/YNUCPC/ynu-icpc-library/blob/main/main_2col.pdf)

## ライブラリの方向性

このライブラリはICPC形式のコンテストにおいて利用しやすくするため、手写しが容易なアルゴリズム実装を目指しています。そのため、実装が複雑になる過度な一般化や高速化は行っていません。
また、アルゴリズムの正確さと実行速度を保証するため、[verification-helper](https://github.com/online-judge-tools/verification-helper) を使用したテストを行っています。

一方で、簡単なアルゴリズム(Dijkstra法、Kruskal法等)は紙面の都合上、ライブラリには載せない方針です。

## 使用方法

アルゴリズムのソースコードは `src/` にあり、ジャンル毎にフォルダ分けされています。

ライブラリのドキュメント部分は `docs/` 下にあるLaTeXファイルで記述されています。
ルートファイルは、`main_1col.tex`, `main_2col.tex` でそれぞれ縦向き1段組と横向き2段組に対応しています。
また、コードブロックに `jlisting` パッケージを使用しています。

ライブラリPDFの生成は `latexmk` コマンドで行えます。

```bash
latexmk main_2col.tex
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
