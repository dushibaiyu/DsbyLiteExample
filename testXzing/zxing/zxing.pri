
INCLUDEPATH += $$PWD

DEFINES += \
    ZXING_ICONV_CONST \
    NOFMAXL
win32:DEFINES += NO_ICONV

HEADERS += \
    $$PWD/zxing/*.h \
    $$PWD/zxing/aztec/*.h \
    $$PWD/zxing/aztec/decoder/*.h \
    $$PWD/zxing/aztec/detector/*.h \
    $$PWD/zxing/common/*.h \
    $$PWD/zxing/common/detector/*.h \
    $$PWD/zxing/common/reedsolomon/*.h \
    $$PWD/zxing/datamatrix/*.h \
    $$PWD/zxing/datamatrix/decoder/*.h \
    $$PWD/zxing/datamatrix/detector/*.h \
    $$PWD/zxing/oned/*.h \
    $$PWD/zxing/multi/*.h \
    $$PWD/zxing/multi/qrcode/*.h \
    $$PWD/zxing/multi/qrcode/detector/*.h \
    $$PWD/zxing/pdf417/*.h \
    $$PWD/zxing/pdf417/decoder/*.h \
    $$PWD/zxing/pdf417/decoder/ec/*.h \
    $$PWD/zxing/pdf417/detector/*.h \
    $$PWD/zxing/qrcode/*.h \
    $$PWD/zxing/qrcode/decoder/*.h \
    $$PWD/zxing/qrcode/detector/*.h \
    $$PWD/bigint/*.hh

SOURCES += \
    $$PWD/zxing/*.cpp \
    $$PWD/zxing/aztec/*.cpp \
    $$PWD/zxing/aztec/decoder/*.cpp \
    $$PWD/zxing/aztec/detector/*.cpp \
    $$PWD/zxing/common/*.cpp \
    $$PWD/zxing/common/detector/*.cpp \
    $$PWD/zxing/common/reedsolomon/*.cpp \
    $$PWD/zxing/datamatrix/*.cpp \
    $$PWD/zxing/datamatrix/decoder/*.cpp \
    $$PWD/zxing/datamatrix/detector/*.cpp \
    $$PWD/zxing/oned/*.cpp \
    $$PWD/zxing/multi/*.cpp \
    $$PWD/zxing/multi/qrcode/*.cpp \
    $$PWD/zxing/multi/qrcode/detector/*.cpp \
    $$PWD/zxing/pdf417/*.cpp \
    $$PWD/zxing/pdf417/decoder/*.cpp \
    $$PWD/zxing/pdf417/decoder/ec/*.cpp \
    $$PWD/zxing/pdf417/detector/*.cpp \
    $$PWD/zxing/qrcode/*.cpp  \
    $$PWD/zxing/qrcode/decoder/*.cpp \
    $$PWD/zxing/qrcode/detector/*.cpp \
    $$PWD/bigint/*.cc

win32 : {
    HEADERS += $$PWD/win32/zxing/*.h
    SOURCES += $$PWD/win32/zxing/*.c
}
