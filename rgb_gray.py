import numpy as np
import cv2 as cv
import sys

img_syh = cv.imread('syh_glove.jpg')

if img_syh is None:
    sys.exit('파일을 찾을 수 없습니다.')

cv.imshow('original_RGB', img_syh)
cv.imshow('Upper left half', img_syh[0:img_syh.shape[0]//2, 0:img_syh.shape[1]//2, :])
cv.imshow('Center half', img_syh[img_syh.shape[0]//4:3*img_syh.shape[0]//4, img_syh.shape[1]//4:3*img_syh.shape[1]//4, :])

cv.imshow('R channel', img_syh[:, :, 2])
cv.imshow('G channel', img_syh[:, :, 1])
cv.imshow('B channel', img_syh[:, :, 0])

R = img_syh[:, :, 2]
G = img_syh[:, :, 1]
B = img_syh[:, :, 0]

gray_syh = 0.299 * R + 0.587 * G + 0.114 * B
gray_syh = gray_syh.astype(np.uint8)  

cv.imshow('Gray Image', gray_syh)

cv.waitKey()
cv.destroyAllWindows()