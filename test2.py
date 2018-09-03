import PrintBinImgBits
import cv2
import numpy as np

img=cv2.imread("test.jpg")
grayImg=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
binImg=cv2.inRange(grayImg,np.array([128]),np.array([255]))
PrintBinImgBits.printBinImgBits(binImg)