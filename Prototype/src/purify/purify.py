import cv2
import numpy as np
import imutils
from imutils import contours
import four_point
                                                                                                                               
image= cv2.imread("un_prfy_omr.jpg")
gray= cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
blurred= cv2.GaussianBlur(gray, (5,5), 0)
edged= cv2.Canny(blurred, 75, 200)
cnts= cv2.findContours(edged, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
cnts= imutils.grab_contours(cnts)
docCnt= None

if len(cnts)>0:
    cnts= sorted(cnts, key=cv2.contourArea, reverse=True)

    for c in cnts:
        peri= cv2.arcLength(c, True)
        approx= cv2.approxPolyDP(c, 0.02*peri, True)

        if(len(approx) == 4):
            docCnt= approx
            break

paper= four_point.four_point_transform(image, docCnt.reshape(4, 2))
warped=  four_point.four_point_transform(gray, docCnt.reshape(4, 2))                
thresh= cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY_INV| cv2.THRESH_OTSU)[1]
cnts= cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
cnts= imutils.grab_contours(cnts)
questionCnts=[]

cv2.imwrite('omr.jpg', gray)
