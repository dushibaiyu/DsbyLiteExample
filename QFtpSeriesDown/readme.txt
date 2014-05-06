基于qt5、、、QFtp类来自：https://qt.gitorious.org/qt/qtftp/source/8f60c8c0adca6e6183fb31b528d306439ca2d2c1：

更改qftp类中get函数，添加REST命令，实现断点续传，但是需要ftp服务器支持，server-U 10.x表示支持。