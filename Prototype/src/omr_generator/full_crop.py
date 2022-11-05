            


import cv2
img = cv2.imread("sample.jpg")
# [rows, columns]

crop = img[ 265:650,1552:1943]
cv2.imwrite('un_prfy_omr.jpg', crop)



