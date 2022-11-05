            


import cv2
img = cv2.imread("omr.jpg")
# [rows, columns]

crop = img[ 0:391,110:165]
cv2.imwrite('lal2.jpg', crop)



