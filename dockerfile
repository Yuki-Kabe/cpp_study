# ベースイメージとしてUbuntu 20.04を使用
FROM ubuntu:20.04

# 非対話型モードを設定
ENV DEBIAN_FRONTEND=noninteractive

# 必要なパッケージをインストール
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake \
    gdb \
    vim \
    && apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# 作業ディレクトリの設定
WORKDIR /usr/src/app

# コンテナ起動時にbashシェルを起動
CMD ["/bin/bash"]
