            


import cv2
img = cv2.imread("omr.jpg")
# [rows, columns]

crop = img[ 0:391,275:333]
cv2.imwrite('lal5.jpg', crop)



