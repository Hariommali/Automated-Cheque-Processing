            


import cv2
img = cv2.imread("omr.jpg")
# [rows, columns]

crop = img[ 0:391,220:275]
cv2.imwrite('lal4.jpg', crop)



