            


import cv2

img = cv2.imread("omr.jpg")

# [rows, columns]

crop = img[ 0:391,50:110]
cv2.imwrite('lal1.jpg', crop)



