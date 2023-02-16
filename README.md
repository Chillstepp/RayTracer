# A Tiny RayTracer

## Final 

![image-20230216145512397](https://raw.githubusercontent.com/Chillstepp/MyPicBed/master/master/image-20230216145512397.png)

## Process

![Normal](https://raw.githubusercontent.com/Chillstepp/MyPicBed/master/master/image-20221227174539161.png)



![diffuse](https://raw.githubusercontent.com/Chillstepp/MyPicBed/master/master/%E4%B8%8B%E8%BD%BD.png)

Metal Material/Lambertian Material：

![image-20230214014050843](https://raw.githubusercontent.com/Chillstepp/MyPicBed/master/master/image-20230214014050843.png)

Fuzzy Metal Material：

![image-20230214210411745](https://raw.githubusercontent.com/Chillstepp/MyPicBed/master/master/image-20230214210411745.png)

Dielectric Material(glass): 

reflect: 

1. reflectivity that varies with angle
2. Snell's law may occur to $sin(\theta ')$ may > 1

![image-20230215011521835](https://raw.githubusercontent.com/Chillstepp/MyPicBed/master/master/image-20230215011521835.png)

ChangeCameraPos/Vup:

![image-20230215205236260](https://raw.githubusercontent.com/Chillstepp/MyPicBed/master/master/image-20230215205236260.png)

## Some Tips

### Fixing Shadow Acne

球面出现黑点点的问题怎么解决？为什么会出来黑点点？如下图: 

1. 为什么是黑色？

   主要是因为 每次衰减一半，衰减到最后就颜色就成黑色了

2. 为什么会出现黑色点点？ 

   r是个反射光，他的起点可能因为误差并正好在圆表面上，而也可能在内部/外部很近的地方，如果是圆内很近的地方，t=0会发现永远会和圆表面有交点，导致光线很难出来，这也是运行慢的原因。

解决方法: 很简单我们把从内部射出的光线和表面接触的点排除即可，即t > 0.01 以上再计算相交即可。

![image-20230212175446861](https://raw.githubusercontent.com/Chillstepp/MyPicBed/master/master/image-20230212175446861.png)

修正后正常:

![diffuse](https://raw.githubusercontent.com/Chillstepp/MyPicBed/master/master/%E4%B8%8B%E8%BD%BD.png)

修正后我们还可以发现运行速度快了不少，这是因为光线不再被困在球内，减少了光线反射的计算量。