            


import cv2
img = cv2.imread("omr.jpg")
# [rows, columns]

crop = img[ 0:391,165:220]
cv2.imwrite('lal3.jpg', crop)



