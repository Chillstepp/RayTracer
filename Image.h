//
// Created by Chillstep on 2022/12/25.
//

#ifndef CPPPRACTICE_IMAGE_H
#define CPPPRACTICE_IMAGE_H


class Image {
public:
    Image(int ImageWidth, int ImageHeight):Width(ImageWidth), Height(ImageHeight),
    AspectRatio(static_cast<double>(ImageWidth)/static_cast<double>(ImageHeight)){}

public:
    const int Width;
    const int Height;
    const double AspectRatio;
};


#endif //CPPPRACTICE_IMAGE_H
