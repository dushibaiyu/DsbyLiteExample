#ifndef ImageWrapper_H
#define ImageWrapper_H

#include <QImage>
#include <QString>
#include <zxing/LuminanceSource.h>

class ImageWrapper : public zxing::LuminanceSource
{
public:
    ImageWrapper(const QImage& image);
    ~ImageWrapper();

    // Callers take ownership of the returned memory and must call delete [] on it themselves.
    virtual zxing::ArrayRef<char> getRow(int y, zxing::ArrayRef<char> row) const;
    virtual zxing::ArrayRef<char> getMatrix() const;
    virtual bool isCropSupported() const;
    virtual zxing::Ref<zxing::LuminanceSource> crop(int left, int top, int width, int height) const;
private:
    QImage image;
};

#endif //CAMERAIMAGE_H
