# 使用官方的 Ubuntu 作为基础镜像
FROM ubuntu:20.04

# 设置时区（可选）
ENV TZ=Asia/Shanghai
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# 安装必要的软件包，包括 Qt 相关的开发环境和依赖
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    qt5-default \
    qtbase5-dev \
    qtdeclarative5-dev \
    qml-module-qtquick-controls2 \
    qml-module-qtquick-dialogs \
    qml-module-qtquick-layouts \
    qml-module-qt-labs-settings \
    git \
    apt-utils \
    fonts-wqy-zenhei

# 清理无用的缓存
RUN apt-get clean && rm -rf /var/lib/apt/lists/*

# 设置工作目录
WORKDIR /app

# 复制当前目录下的所有内容到工作目录
COPY . /app

# 运行 CMake 生成 Makefile 并编译项目
RUN cmake . && make

# 设置容器启动时执行的命令
CMD ["./hello"]

